#include <iostream>
#include <cstdlib>
#include <ctime>
#include "manager.h"
#include "core_functions.h"
int main(int argc, char *argv[], char *envp[]) {
	srand(time(0));
    startGame();
    return 0;
}