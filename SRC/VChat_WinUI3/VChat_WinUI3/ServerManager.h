#pragma once
#include <iostream>
#include <windows.h> 

#define _CRT_SECURE_NO_WARNINGS

namespace server_manage {

	class ServerManager {
	private:
		bool isStarted; // Is the server started
		PROCESS_INFORMATION server_proc; // Pointer to unmanaged type since we need to get around restrinctions, need to handle deallocation in destructor. 

		// Local Helper to Store error message into the local variable.
		void errMsg(PCTSTR  lpszFunction);

	public:
		HANDLE g_hChildStd_IN_Rd = NULL; // Input and Output Pipes
		HANDLE g_hChildStd_IN_Wr = NULL;
		HANDLE g_hChildStd_OUT_Rd = NULL;
		HANDLE g_hChildStd_OUT_Wr = NULL;
		LPTSTR  lpMsgBuf;
	public:
		// Constructor
		ServerManager(int port) : isStarted(0) {
			//server_proc = (PROCESS_INFORMATION*)malloc(sizeof(PROCESS_INFORMATION)); // Allocate space for Process Info

		}

		void set_isStarted(bool val) { isStarted = val; }

		bool get_isStarted();

		/*
		Initalize the Unnamed Pipe handles

		Returns Error Coded Integer
		*/
		int initPipes();

		/*
		Initalize the Unnamed Pipe handles

		Returns Error Coded Integer
		*/
		int CreateServerProcess(LPSTR cmd);

		int killServer();

		int serverRead(char* buffObj, DWORD size);

		~ServerManager() {
			if (isStarted == 0)
				return;

			this->killServer();
			//if (this->lpMsgBuf != NULL)
				//free(this->lpMsgBuf);
		}
	};


}