#include <iostream>
#include <cstdlib>
#include <ctime>
#include "manager.h"
#include "core_functions.h"
#ifdef _WIN32
#include <windows.h>
#endif
int main(int argc, char *argv[], char *envp[]) {
	#ifdef _WIN32
	SetConsoleOutputCP(65001);
	#endif
	srand(time(0));
    startGame();
    return 0;
}