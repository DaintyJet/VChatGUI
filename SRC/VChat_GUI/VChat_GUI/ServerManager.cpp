#include "ServerManager.h"

/*
* Purpose:
* 
* Return:
* 
* Based on https://learn.microsoft.com/en-us/windows/win32/debug/retrieving-the-last-error-code
*/
void exit_func(LPCTSTR lpszFunction) {
	// Pull in error message 
	// Signal Error Message Box for WinForm, 
	return;

}
/*
* Purpose: This function will return the current server status
* 
* Return: boolean, 1 if the server is started, 0 otherwise.
*/
bool server_manage::ServerManager::get_isStarted() {
	return this->isStarted;
}

/*
Initalize the Unnamed Pipe handles

Returns Error Coded Integer

Implementation based on https://learn.microsoft.com/en-us/windows/win32/procthread/creating-a-child-process-with-redirected-input-and-output?redirectedfrom=MSDN
*/
int server_manage::ServerManager::initPipes() {
	// https://learn.microsoft.com/en-us/dotnet/api/microsoft.visualstudio.ole.interop.security_attributes?view=visualstudiosdk-2022
	SECURITY_ATTRIBUTES saAttr;
	
	// Set Size in bytes of the structure
	saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
	// Child processes will inherit this handle when created. (non-zero Value)
	saAttr.bInheritHandle = TRUE;
	// We are not assigning it a security descriptor (https://learn.microsoft.com/en-us/windows/win32/api/winnt/ns-winnt-security_descriptor)
	saAttr.lpSecurityDescriptor = NULL;

	if (!CreatePipe(&(this->g_hChildStd_OUT_Rd), &(this->g_hChildStd_OUT_Wr), &saAttr, 0))
		exit_func(TEXT("initPipes: Failed To Create STD_OUT unnamed pipe"));
	

	// Ensure the read handle to the pipe for STDOUT is not inherited.
	if (!SetHandleInformation(this->g_hChildStd_OUT_Rd, HANDLE_FLAG_INHERIT, 0))
		exit_func(TEXT("initPipes: Failed To Configure STD_OUT unnamed pipe"));

		

	// Create a pipe for the child process's STDIN. 
	if (!CreatePipe(&(this->g_hChildStd_IN_Rd), &(this->g_hChildStd_IN_Wr), &saAttr, 0))
		exit_func(TEXT("initPipes: Failed To Create STD_IN unnamed pipe"));
	
	// Ensure the write handle to the pipe for STDIN is not inherited. 
	if (!SetHandleInformation(this->g_hChildStd_IN_Wr, HANDLE_FLAG_INHERIT, 0))
		exit_func(TEXT("initPipes: Failed To Configure STD_IN unnamed pipe"));

		
	return 1;

}

/*
Initalize the Unnamed Pipe handles

Returns Error Coded Integer
*/
int server_manage::ServerManager::CreateServerProcess() {

	return 1;

}