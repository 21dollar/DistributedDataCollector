#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "My_int.h"
#pragma comment (lib,"Rpcrt4.lib")


void rcp_init()
{
	/*char addr_buf[20] = { 0 };
	printf("Enter server IP: ");
	scanf("%s", addr_buf);*/

	//wchar_t w_addr[16] = { 0 };
	//mbstowcs(w_addr, addr, 16);

	// Creates a string binding handle. This function is nothing more than a printf. Connection is not done here.
	char *pszStringBinding = NULL;
	RPC_STATUS status = RpcStringBindingComposeA(NULL, (RPC_CSTR)"ncacn_ip_tcp", (RPC_CSTR)"127.0.0.1", (RPC_CSTR)("9000"), NULL, &pszStringBinding);
	printf("err1 = %d\n", status);
	printf("szStringBinding = %s\n", pszStringBinding);
	status = RpcBindingFromStringBindingA((RPC_CSTR)pszStringBinding, &My_int_handler);
	printf("err2 = %d\n", status);

	// Free the memory allocated by a string.
	status = RpcStringFreeA((RPC_CSTR*)&pszStringBinding);
	printf("err3 = %d\n", status);

	printf("!!!\n");
	while (1)
	{
		fake(5);
	}

	//char addr[16] = { 0 };
	//printf("Enter destination IP-address\n");
	//scanf("%s", addr);

	//wchar_t w_addr[16] = { 0 };
	//mbstowcs(w_addr, addr, 16);

	//// Creates a string binding handle. This function is nothing more than a printf. Connection is not done here.
	//wchar_t *szStringBinding = NULL;
	//RPC_STATUS status = RpcStringBindingCompose(NULL, // UUID
	//	(RPC_WSTR)(L"ncacn_ip_tcp"),
	//	(RPC_WSTR)w_addr,
	//	(RPC_WSTR)(L"9000"),
	//	NULL,
	//	(RPC_WSTR*)&szStringBinding);

	//printf("err0 = %d\n", status);

	//// Validates the format of the string binding handle and converts
	//// it to a binding handle. Connection is not done here either.
	//status = RpcBindingFromStringBinding((RPC_WSTR)szStringBinding, &My_int_handler);

	//printf("err1 = %d\n", status);

	//// Free the memory allocated by a string.
	//status = RpcStringFree((RPC_WSTR*)&szStringBinding);
	//printf("err2 = %d\n", status);

	//printf("!!!\n");
	///*while (1)
	//{
	//	fake(5);
	//}*/
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
	rcp_init();
	while (1)
	{

	}
	return 0;
}
