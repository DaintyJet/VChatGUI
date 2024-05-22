#include <cstdio>
#include <chrono>
#include <windows.h>
#include <thread>

#define BUFFSIZE 4096

int main(int argc, char* argv[])
{
	using namespace std::chrono_literals;

	char buff[] = "THIS IS JUST A TEST\r\n";
	DWORD dwRead, dwWritten;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	while (1) {
		std::this_thread::sleep_for(2000ms);
		fprintf(stdout, "Child Processess Says Hello\r\n");
		WriteFile(hStdout, buff, strlen(buff), &dwWritten, NULL);
	}
	return 0;
}