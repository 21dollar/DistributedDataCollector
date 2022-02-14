#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <tchar.h>
#include <string>
#include <malloc.h>
#include <aclapi.h>
#include "My_int.h"
#include <malloc.h>
#pragma comment (lib,"Rpcrt4.lib")

HCRYPTKEY hSessionKey;
int N_len, shutup = 0;

int fake(int num)
{
	while (num)
	{
		printf("%d\n", num--);
	}
	return num;
}

int impersonation(unsigned char *name,unsigned char *pass)
{
	handle_t phToken;
	if (!LogonUserA((LPCSTR)name, NULL, (LPCSTR)pass, LOGON32_LOGON_INTERACTIVE, LOGON32_PROVIDER_DEFAULT, &phToken))
	{
		printf("err: auth_%d", GetLastError());
		return 1;
	}
	if (!ImpersonateLoggedOnUser(phToken))
	{
		printf("err: auth_%d", GetLastError());
		return 1;
	}
	printf("Authorized client: %s\n", name);
	return 0;
}

void to_serv(int sz_buff, unsigned char *buff, unsigned char *serv_path)
{
	FILE *serv;
	serv = fopen((char*)serv_path, "wb");
	fwrite(buff, 1, sz_buff, serv);
	fclose(serv);
	printf("File %s was uploaded\n", serv_path);
}

int to_cli(int *sz_buff, unsigned char *send_buff, unsigned char *serv_path, int offset)
{

	FILE * serv;
	serv = fopen((char*)serv_path, "rb");
	if (serv)
	{
		//fseek(serv, offset, SEEK_SET);
		*sz_buff = fread(send_buff, 1, *sz_buff, serv);
		printf("Part of file %s was downloaded\n", serv_path);
		fclose(serv);
		return *sz_buff;
	}
	else
	{
		return -1;
 	}
}

int del_f(unsigned char *serv_path)
{
	printf("File %s was deleted\n", serv_path);
	return DeleteFileA((LPCSTR)serv_path);
}

void key_send(unsigned char pbPublicKey[1024], int *dwPublicLen) //midl
{
	HCRYPTPROV hProv_ses;

	DWORD dwSessionLen;
	if (!CryptAcquireContext(&hProv_ses, NULL, MS_DEF_PROV, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
		printf("csp_err\n");
	if (!CryptGenKey(hProv_ses, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey))//Ãåíåðàöèÿ ñåññèîííîãî êëþ÷à
		printf("gen_err\n");
	if (!CryptExportKey(hSessionKey, 0, OPAQUEKEYBLOB, 0, 0, &dwSessionLen)) //Íàõîäèì ðàçìåð êëþ÷à íà ýêñïîðò
		printf("keylen_err\n");

	char pbSessionKey[128];
	if (!CryptExportKey(hSessionKey, 0, OPAQUEKEYBLOB, 0, (BYTE*)pbSessionKey, &dwSessionLen))//Ýêñïîðò ñåññèîííîãî
		printf("exp_err\n");

	HCRYPTKEY hPubKey;
	if (!CryptImportKey(hProv_ses, (BYTE*)pbPublicKey, 148, 0, 0, &hPubKey))//Èìïîðò ïîëó÷åííîãî ïóáëè÷íîãî êëþ÷à
		printf("imp_err\n");

	DWORD ses_num;
	if (!CryptEncrypt(hPubKey, 0, TRUE, 0, (BYTE*)pbSessionKey, &dwSessionLen, 128))
		printf("enc_err\n");
	printf("A key exchange has occurred\n");
	memcpy(pbPublicKey, pbSessionKey, 148);
	shutup = 1;
}

char *take_os_vers()
{
	HKEY reg_key;
	char path1[] = { "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion" };
	char path2[] = { "ProductName" };
	DWORD send_len;
	char *send_buf;
	RegOpenKeyExA(HKEY_LOCAL_MACHINE, path1, 0, KEY_READ, &reg_key);
	RegGetValueA(reg_key, NULL, path2, RRF_RT_REG_SZ, 0, NULL, &send_len);
	send_buf = (char*)malloc(sizeof(char*) * send_len + 4);
	strcpy(send_buf, "tov");
	RegGetValueA(reg_key, NULL, path2, RRF_RT_REG_SZ, 0, &send_buf[3], &send_len);
	N_len = send_len + 3;
	return send_buf;
}

char *take_cur_time()
{
	int i = 1;
	char *send_buf;
	send_buf = (char*)malloc(sizeof(char) * 28);
	strcpy(send_buf, "tct ");
	SYSTEMTIME sm;
	GetSystemTime(&sm);
	((int*)send_buf)[i++] = sm.wSecond;
	((int*)send_buf)[i++] = sm.wMinute;
	((int*)send_buf)[i++] = sm.wHour + 3;
	((int*)send_buf)[i++] = sm.wDay;
	((int*)send_buf)[i++] = sm.wMonth;
	((int*)send_buf)[i++] = sm.wYear;
	send_buf[28] = '\0';

	N_len = 28;
	//SEND
	return send_buf;
}

char *take_run_time()
{
	int hour, min, sec, msec, i = 1;
	char send_buf[17];
	strcpy(send_buf, "trt ");
	msec = GetTickCount();
	hour = msec / (1000 * 60 * 60);
	min = msec / (1000 * 60) - hour * 60;
	sec = (msec / 1000) - (hour * 60 * 60) - min * 60;
	if (hour > 100)
	{
		hour -= 103;
	}
	((int*)send_buf)[i++] = hour;
	((int*)send_buf)[i++] = min;
	((int*)send_buf)[i++] = sec;
	send_buf[16] = '\0';

	//SEND
	return send_buf;
}

char *take_mem_status()
{
	int i = 1;
	long long k = 0;
	char send_buf[73];
	strcpy(send_buf, "tms     ");
	MEMORYSTATUS stat;
	GlobalMemoryStatus(&stat);

	((long long*)send_buf)[i++] = stat.dwLength;       // -äëèíà ñòðóêòóðû â áàéòàõ
	((long long*)send_buf)[i++] = stat.dwMemoryLoad;   // -çàãðóçêà ïàìÿòè â ïðîöåíòàõ
	((long long*)send_buf)[i++] = stat.dwTotalPhys;    // -ìàêñèìàëüíîå êîëè÷åñòâî ôèçè÷åñêîé ïàìÿòè â áàéòàõ
	((long long*)send_buf)[i++] = stat.dwAvailPhys;    // -ñâîáîäíîå êîëè÷åñòâî ôèçè÷åñêîé ïàìÿòè â áàéòàõ
	((long long*)send_buf)[i++] = stat.dwTotalPageFile;// -ìàêñèìàëüíîå êîëè÷åñòâî ïàìÿòè äëÿ ïðîãðàìì â áàéòàõ
	((long long*)send_buf)[i++] = stat.dwAvailPageFile;// -ñâîáîäíîå êîëè÷åñòâî ïàìÿòè äëÿ ïðîãðàìì â áàéòàõ
	((long long*)send_buf)[i++] = stat.dwTotalVirtual; // -ìàêñèìàëüíîå êîëè÷åñòâî âèðòóàëüíîé ïàìÿòè â áàéòàõ
	((long long*)send_buf)[i++] = stat.dwAvailVirtual; // -ñâîáîäíîå êîëè÷åñòâî âèðòóàëüíîé ïàìÿòè â áàéòàõ
	send_buf[72] = '\0';

	//SEND
	return send_buf;
}

char *take_loc_dr()
{
	int i, n = 8, count = 0, N = 8, NN = 1;
	char *send_buf;
	char disk[3] = { 0 };
	send_buf = (char*)malloc(sizeof(char) * N + 1);
	strcpy(send_buf, "tld     ");

	DWORD dr = GetLogicalDrives();
	for (i = 0; i< 26; i++)
	{
		if (((dr >> i) & 0x00000001) == 1)
		{
			disk[0] = char(65 + i);
			disk[1] = ':';
			disk[2] = '\0';
			count++;
			if (GetDriveTypeA(disk) == DRIVE_FIXED)
			{
				NN += 2;
				send_buf = (char*)realloc(send_buf, (sizeof(char) * (N * NN)) + 1);
				strcpy(&send_buf[n], disk);
				DWORD s, b, f, c;
				double freeSpace;
				GetDiskFreeSpaceA(disk, &s, &b, &f, &c);
				freeSpace = (double)f * (double)s * (double)b / 1024.0 / 1024.0 / 1024.0;
				((double*)send_buf)[NN - 1] = freeSpace;
				n += N * 2;
			}
		}
	}
	NN /= 2;
	((int*)send_buf)[1] = NN;
	send_buf[n] = '\0';
	N_len = n;

	//SEND
	return send_buf;
}

char *take_type_dr()
{
	int i, n = 3;
	char send_buf[82] = { 0 };
	char disk[3] = { 0 };
	strcpy(send_buf, "ttd");

	DWORD dr = GetLogicalDrives();
	for (i = 0; i< 26; i++)
	{
		//if (((dr >> i) & 0x00000001) == 1)
		{
			disk[0] = char(65 + i);
			disk[1] = ':';
			disk[2] = '\0';
			strcpy(&send_buf[n], disk);
			n += 2;
			send_buf[n++] = GetDriveTypeA(disk) + 48;
		}
	}
	send_buf[n] = '\0';
	N_len = n;
	//SEND
	return send_buf;
}

char *take_file_prior(char *path)
{
	int i, n = 4;
	char *send_buf;
	send_buf = (char*)malloc(sizeof(char)* n);
	strcpy(send_buf, "tfpN");
	PSECURITY_DESCRIPTOR pSD;
	PSID pOwnerSid;
	GetNamedSecurityInfoA(path, SE_FILE_OBJECT, OWNER_SECURITY_INFORMATION, &pOwnerSid, NULL, NULL, NULL, &pSD);

	char user_name[50] = "", domain[50] = "";
	SID_NAME_USE SidName;
	DWORD domainLen = sizeof(domain);
	DWORD userLen = sizeof(user_name);
	LookupAccountSidA(NULL, pOwnerSid, user_name, &userLen, domain, &domainLen, &SidName);
	//printf("\nuser_name = %s\ndomain = %s\n", user_name, domain);
	send_buf = (char*)realloc(send_buf, sizeof(char)* (n + strlen(user_name) + strlen(domain) + 2));
	strcpy(&send_buf[n], user_name);
	n += strlen(user_name);
	send_buf[n++] = '!';
	strcpy(&send_buf[n], domain);
	n += strlen(domain);
	send_buf[n++] = '!';

	PACL a;
	GetNamedSecurityInfoA(path, SE_FILE_OBJECT, DACL_SECURITY_INFORMATION, NULL, NULL, &a, NULL, &pSD);

	ACL_SIZE_INFORMATION asi;
	GetAclInformation(a, &asi, sizeof(asi), AclSizeInformation);
	send_buf[3] = asi.AceCount + 48;

	void *pAce;
	CHAR acc_name[256];
	for (i = 0; i < asi.AceCount; i++)
	{
		GetAce(a, i, &pAce);
		CHAR domain_name[256];
		PSID pSID;
		SID_NAME_USE peUse;
		DWORD size_domain_name = sizeof(domain_name);
		DWORD size_acc_name = sizeof(acc_name);
		pSID = (PSID)(&(((ACCESS_ALLOWED_ACE*)pAce)->SidStart));

		LookupAccountSidA(NULL, pSID, acc_name, &size_acc_name, domain_name, &size_domain_name, &peUse);
		//printf("%s\t::\t%X\n", acc_name, ((ACCESS_ALLOWED_ACE*)pAce)->Mask);
		send_buf = (char*)realloc(send_buf, sizeof(char)* (5 + n + strlen(acc_name)));
		strcpy(&send_buf[n], acc_name);
		n += strlen(acc_name);
		send_buf[n++] = '!';
		send_buf[n++] = peUse + 48;
		send_buf[n++] = '!';
		send_buf[n++] = ((ACE_HEADER*)pAce)->AceType + 48;
		send_buf[n++] = '!';
		char mask_buf[20];
		//mask_buf = (char*)malloc(sizeof(char*) * 8);
		long long num, k = 0, j = 0;
		num = ((ACCESS_ALLOWED_ACE*)pAce)->Mask;
		while (num != 0)
		{
			mask_buf[k++] = num % 10 + 48;
			num /= 10;
		}
		mask_buf[k] = '\0';
		char *mask_buf2 = (char*)malloc(sizeof(char*) * (k + 1));
		k--;
		for (k; k >= 0; k--)
		{
			mask_buf2[j++] = mask_buf[k];
		}
		mask_buf2[j] = '\0';
		send_buf = (char*)realloc(send_buf, sizeof(char)* (1 + n + strlen(mask_buf2)));
		strcpy(&send_buf[n], mask_buf2);
		n += strlen(mask_buf2);
		send_buf[n++] = '!';
	}

	send_buf[n] = '\0';
	//printf("%s", send_buf);
	N_len = n;
	return send_buf;
}

char *take_reg_prior(char *path)
{
	int i, n = 4;
	char *send_buf, HKEY_buf[30], path1[1000];
	send_buf = (char*)malloc(sizeof(char)* n);
	strcpy(send_buf, "tfpN");
	PSECURITY_DESCRIPTOR pSD;
	PSID pOwnerSid;
	HKEY key_path;

	for (i = 0; path[i] != '\\'; i++)
	{
		HKEY_buf[i] = path[i];
	}
	HKEY_buf[i++] = '\0';
	strcpy(path1, &path[i]);

	if (!strcmp(HKEY_buf, "HKEY_CLASSES_ROOT")) RegOpenKeyA(HKEY_CLASSES_ROOT, path1, &key_path);
	else if (!strcmp(HKEY_buf, "HKEY_CURRENT_USER")) RegOpenKeyA(HKEY_CURRENT_USER, path1, &key_path);
	else if (!strcmp(HKEY_buf, "HKEY_LOCAL_MACHINE")) RegOpenKeyA(HKEY_LOCAL_MACHINE, path1, &key_path);
	else if (!strcmp(HKEY_buf, "HKEY_USERS")) RegOpenKeyA(HKEY_USERS, path1, &key_path);
	else if (!strcmp(HKEY_buf, "HKEY_CURRENT_CONFIG")) RegOpenKeyA(HKEY_CURRENT_CONFIG, path1, &key_path);
	else { printf("err_reg_key\n"); return 0; }

	GetSecurityInfo(key_path, SE_REGISTRY_KEY, OWNER_SECURITY_INFORMATION, &pOwnerSid, NULL, NULL, NULL, &pSD);

	char user_name[50] = "", domain[50] = "";
	SID_NAME_USE SidName;
	DWORD domainLen = sizeof(domain);
	DWORD userLen = sizeof(user_name);
	LookupAccountSidA(NULL, pOwnerSid, user_name, &userLen, domain, &domainLen, &SidName);
	//printf("\nuser_name = %s\ndomain = %s\n", user_name, domain);
	send_buf = (char*)realloc(send_buf, sizeof(char)* (n + strlen(user_name) + strlen(domain) + 2));
	strcpy(&send_buf[n], user_name);
	n += strlen(user_name);
	send_buf[n++] = '!';
	strcpy(&send_buf[n], domain);
	n += strlen(domain);
	send_buf[n++] = '!';

	PACL a;
	GetSecurityInfo(key_path, SE_REGISTRY_KEY, DACL_SECURITY_INFORMATION, NULL, NULL, &a, NULL, &pSD);

	ACL_SIZE_INFORMATION asi;
	GetAclInformation(a, &asi, sizeof(asi), AclSizeInformation);
	send_buf[3] = asi.AceCount + 48;

	void *pAce;
	CHAR acc_name[256];
	for (i = 0; i < asi.AceCount; i++)
	{
		GetAce(a, i, &pAce);
		CHAR domain_name[256];
		PSID pSID;
		SID_NAME_USE peUse;
		DWORD size_domain_name = sizeof(domain_name);
		DWORD size_acc_name = sizeof(acc_name);
		pSID = (PSID)(&(((ACCESS_ALLOWED_ACE*)pAce)->SidStart));

		LookupAccountSidA(NULL, pSID, acc_name, &size_acc_name, domain_name, &size_domain_name, &peUse);
		//printf("%s\t::\t%X\n", acc_name, ((ACCESS_ALLOWED_ACE*)pAce)->Mask);
		send_buf = (char*)realloc(send_buf, sizeof(char)* (5 + n + strlen(acc_name)));
		strcpy(&send_buf[n], acc_name);
		n += strlen(acc_name);
		send_buf[n++] = '!';
		send_buf[n++] = peUse + 48;
		send_buf[n++] = '!';
		send_buf[n++] = ((ACE_HEADER*)pAce)->AceType + 48;
		send_buf[n++] = '!';
		char mask_buf[20];
		//mask_buf = (char*)malloc(sizeof(char*) * 8);
		long long num, k = 0, j = 0;
		num = ((ACCESS_ALLOWED_ACE*)pAce)->Mask;
		while (num != 0)
		{
			mask_buf[k++] = num % 10 + 48;
			num /= 10;
		}
		mask_buf[k] = '\0';
		char *mask_buf2 = (char*)malloc(sizeof(char*) * (k + 1));
		k--;
		for (k; k >= 0; k--)
		{
			mask_buf2[j++] = mask_buf[k];
		}
		mask_buf2[j] = '\0';
		send_buf = (char*)realloc(send_buf, sizeof(char)* (1 + n + strlen(mask_buf2)));
		strcpy(&send_buf[n], mask_buf2);
		n += strlen(mask_buf2);
		send_buf[n++] = '!';
	}

	send_buf[n] = '\0';
	//printf("%s", send_buf);
	N_len = n;
	return send_buf;
}

void msg_trade(unsigned char scom_buf[1024])
{
	if (shutup == 0)
	{
		if (hSessionKey)
		{
			CryptDestroyKey(hSessionKey);
		}
		//init_crypt(key);
		shutup = 1;
	}
	else
	{
		DWORD le = 1024;
		
		if (!CryptDecrypt(hSessionKey, 0, TRUE, 0, (BYTE*)scom_buf, &le))
		{
			printf("Err1\n");
		}
		unsigned char *send_buf;
		if (!strncmp((char*)scom_buf, "tov", 3))
		{
			printf("tov\n");
			send_buf = (unsigned char*)take_os_vers();
			DWORD send_len = N_len + 1;
			printf("send_len = %d\n", send_len);
			if (!CryptEncrypt(hSessionKey, 0, TRUE, 0, (BYTE*)send_buf, &send_len, send_len))
			printf("Err1\n");
			N_len = 0;
			memcpy(scom_buf, send_buf, 1024);
		}
		else if (!strncmp((char*)scom_buf, "tct", 3))
		{
			printf("tct\n");
			send_buf = (unsigned char*)take_cur_time();
			DWORD send_len = N_len;
			if (!CryptEncrypt(hSessionKey, 0, TRUE, 0, (BYTE*)send_buf, &send_len, send_len))
				printf("Err1\n");
			N_len = 0;
			memcpy(scom_buf, send_buf, 1024);
		}
		else if (!strncmp((char*)scom_buf, "trt", 3))
		{
			printf("trt\n");
			send_buf = (unsigned char*)take_run_time();
			DWORD send_len = 29;
			if (!CryptEncrypt(hSessionKey, 0, TRUE, 0, (BYTE*)send_buf, &send_len, send_len))
				printf("Err1\n");
			N_len = 0;
			memcpy(scom_buf, send_buf, 1024);
		}
		else if (!strncmp((char*)scom_buf, "tms", 3))
		{
			printf("tms\n");
			send_buf = (unsigned char*)take_mem_status();
			DWORD send_len = 72;
			if (!CryptEncrypt(hSessionKey, 0, TRUE, 0, (BYTE*)send_buf, &send_len, send_len))
				printf("Err1\n");
			N_len = 0;
			memcpy(scom_buf, send_buf, 1024);
		}
		else if (!strncmp((char*)scom_buf, "tld", 3))
		{
			printf("tld\n");
			send_buf = (unsigned char*)take_loc_dr();
			DWORD send_len = N_len;
			if (!CryptEncrypt(hSessionKey, 0, TRUE, 0, (BYTE*)send_buf, &send_len, send_len))
				printf("Err1\n");
			N_len = 0;
			memcpy(scom_buf, send_buf, 1024);
		}
		else if (!strncmp((char*)scom_buf, "ttd", 3))
		{
			printf("ttd\n");
			send_buf = (unsigned char*)take_type_dr();
			DWORD send_len = N_len;
			if (!CryptEncrypt(hSessionKey, 0, TRUE, 0, (BYTE*)send_buf, &send_len, send_len))
				printf("Err1\n");
			N_len = 0;
			memcpy(scom_buf, send_buf, 1024);
		}
		else if (!strncmp((char*)scom_buf, "tfp", 3))
		{
			char *path;
			path = &((char*)scom_buf)[3];
			printf("tfp %s\n", path);
			send_buf = (unsigned char*)take_file_prior(path);
			DWORD send_len = N_len;
			if (!CryptEncrypt(hSessionKey, 0, TRUE, 0, (BYTE*)send_buf, &send_len, send_len))
				printf("Err1\n");
			N_len = 0;
			memcpy(scom_buf, send_buf, 1024);
		}
		else if (!strncmp((char*)scom_buf, "trp", 3))
		{
			char *path;
			path = &((char*)scom_buf)[3];
			printf("trp %s\n", path);
			send_buf = (unsigned char*)take_reg_prior(path);
			DWORD send_len = N_len;
			if (!CryptEncrypt(hSessionKey, 0, TRUE, 0, (BYTE*)send_buf, &send_len, send_len))
				printf("Err1\n");
			N_len = 0;
			memcpy(scom_buf, send_buf, 1024);
		}
		else
		{
			strcpy((char*)scom_buf, "Unknown comand");
			DWORD send_len = 16;
			if (!CryptEncrypt(hSessionKey, 0, TRUE, 0, (BYTE*)scom_buf, &send_len, send_len))
				printf("Err1\n");
			
			printf("Unknown comand\n");
		}
	}
}

RPC_STATUS CALLBACK SecurityCallback(RPC_IF_HANDLE, void*)
{
	return RPC_S_OK; 
}

void rpc_init()
{
	printf("SERVER\n");
	RPC_STATUS status;
	status = RpcServerRegisterIfEx(My_int_v1_0_s_ifspec, NULL, NULL, RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH, RPC_C_LISTEN_MAX_CALLS_DEFAULT, SecurityCallback);
	if (status != 0) printf("err0 = %d\n", status);

	status = RpcServerUseProtseqW((RPC_WSTR)(L"ncacn_ip_tcp"), RPC_C_PROTSEQ_MAX_REQS_DEFAULT, NULL);
	if (status != 0) printf("err1 = %d\n", status);

	RPC_BINDING_VECTOR *binding_vector;
	status = RpcServerInqBindings(&binding_vector);
	if (status != 0) printf("err2 = %d\n", status);

	status = RpcEpRegister(My_int_v1_0_s_ifspec, binding_vector, NULL, NULL);
	if (status != 0) printf("err3 = %d\n", status);

	status = RpcServerListen(1, RPC_C_LISTEN_MAX_CALLS_DEFAULT, 0);
	if (status != 0) printf("err4 = %d\n", status);

}

void* __RPC_USER midl_user_allocate(size_t size)
{
	return malloc(size);
}

void __RPC_USER midl_user_free(void* p)
{
	free(p);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	rpc_init();
	return 0;
}
