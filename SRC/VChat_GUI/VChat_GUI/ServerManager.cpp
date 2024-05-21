#include "ServerManager.h"

/*
* Purpose:
* 
* Return:
* 
* Based on https://learn.microsoft.com/en-us/windows/win32/debug/retrieving-the-last-error-code
*/
void server_manage::ServerManager::errMsg(PCTSTR  lpszFunction) {
	// Pull in error message 
	DWORD dw = GetLastError();
	std::cout << "\n" << dw << "\n";
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&(this->lpMsgBuf),
		0, NULL);
	// Signal Error Message Box for WinForm, 

	/* Temp Error Message*/
	std::cout << lpszFunction;
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

	if (!CreatePipe(&(this->g_hChildStd_OUT_Rd), &(this->g_hChildStd_OUT_Wr), &saAttr, 0)) {
		errMsg(TEXT("initPipes: Failed To Create STD_OUT unnamed pipe"));
		return -1;
	}

	// Ensure the read handle to the pipe for STDOUT is not inherited.
	if (!SetHandleInformation(this->g_hChildStd_OUT_Rd, HANDLE_FLAG_INHERIT, 0)) {
		errMsg(TEXT("initPipes: Failed To Configure STD_OUT unnamed pipe"));
		return -1;
	}
		

	// Create a pipe for the child process's STDIN. 
	if (!CreatePipe(&(this->g_hChildStd_IN_Rd), &(this->g_hChildStd_IN_Wr), &saAttr, 0)) {
		errMsg(TEXT("initPipes: Failed To Create STD_IN unnamed pipe"));
		return -1;
	}
	
	// Ensure the write handle to the pipe for STDIN is not inherited. 
	if (!SetHandleInformation(this->g_hChildStd_IN_Wr, HANDLE_FLAG_INHERIT, 0)) {
		errMsg(TEXT("initPipes: Failed To Configure STD_IN unnamed pipe"));
		return -1;
	}

		
	return 1;

}

/*
Initalize the Unnamed Pipe handles

Returns Error Coded Integer

Based on https://learn.microsoft.com/en-us/windows/win32/procthread/creating-a-child-process-with-redirected-input-and-output?redirectedfrom=MSDN
*/
int server_manage::ServerManager::CreateServerProcess(LPSTR  cmd) {
	// Local Management Info
	STARTUPINFO siStartInfo;
	bool bSuccess = FALSE;
	wchar_t* convt_cmd;

	// Setup convt_cmd so we send over a WideChar Str
	convt_cmd = (wchar_t*)malloc(sizeof(wchar_t)* strlen(cmd));
	mbstowcs(convt_cmd, cmd, strlen(cmd) + 1);//Plus null


	// Set up members of the PROCESS_INFORMATION structure. 
	ZeroMemory(&(this->server_proc), sizeof((this->server_proc)));

	// Set up members of the STARTUPINFO structure. 
	// This structure specifies the STDIN and STDOUT handles for redirection.
	ZeroMemory(&siStartInfo, sizeof(siStartInfo));
	siStartInfo.cb = sizeof(siStartInfo);
	siStartInfo.hStdError = this->g_hChildStd_OUT_Wr;
	siStartInfo.hStdOutput = this->g_hChildStd_OUT_Wr;
	siStartInfo.hStdInput = this->g_hChildStd_IN_Rd;
	siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

	bSuccess = CreateProcess(NULL,
		convt_cmd,     // command line 
		NULL,          // process security attributes 
		NULL,          // primary thread security attributes 
		TRUE,          // handles are inherited 
		0,             // creation flags 
		NULL,          // use parent's environment 
		NULL,          // use parent's current directory 
		&siStartInfo,  // STARTUPINFO pointer 
		&(server_proc));  // receives PROCESS_INFORMATION 


	// If an error occurs, exit the application. 
	if (bSuccess == FALSE) {
		errMsg(TEXT("CreateServerProcess: Failed to create process"));
		std::cout << "\nFAILED\n";
		return -1;
	}
	else
	{

		// Close handles to the child process and its primary thread.
		// Some applications might keep these handles to monitor the status
		// of the child process, for example. 
		// CloseHandle((*(this->server_proc)).hProcess);
		// CloseHandle((*(this->server_proc)).hThread);

		// Close handles to the stdin and stdout pipes no longer needed by the child process.
		// If they are not explicitly closed, there is no way to recognize that the child process has ended.
		CloseHandle(this->g_hChildStd_OUT_Wr);
		CloseHandle(this->g_hChildStd_IN_Rd);
	}

	//TerminateProcess((this->server_proc)->hProcess, 0);
	return 1;

}

int server_manage::ServerManager::killServer() {

	if (this->isStarted)
		return TerminateProcess((this->server_proc).hProcess, 0);
	return 1;
}