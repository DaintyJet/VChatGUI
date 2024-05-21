#include <stdio.h>
#include <chrono>
#include <thread>

#define BUFFSIZE 4096

int main(int argc, char* argv[])
{
	using namespace std::chrono_literals;

	char buff[BUFFSIZE];

	while (1) {
		std::this_thread::sleep_for(2000ms);
		printf("Child Processess Says Hello\r\n");
	}
	return 0;
}