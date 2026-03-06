#include <iostream>
#include <string>
#include "Manager.h"
#include "CoreFunctions.h"
void startGame() {
	std::string initialName;
	std::cout << "Welcome to FunGame!!!" << std::endl;
	std::cout << "[You can type 'clear' to clear the screen in the main lobby]" << std::endl;
	std::cout << "Please enter your name to start: " << std::endl;
	std::getline(std::cin, initialName);
	if (initialName.empty()) {
		initialName = "Player";
	}
	clearConsole();
    Player steve(initialName, 100, 1, 0, 100);
    static bool inspectLargeShips = true;
    while (true) {
        std::string select;
        std::cout << "E: Exit the game!" << std::endl;
        std::cout << "SG: Save the game" << std::endl;
        std::cout << "IG: Import games" << std::endl;
        std::cout << "1: Player VS. Entity" << std::endl;
        std::cout << "2: Upgrade damage" << std::endl;
        std::cout << "3: Restore health" << std::endl;
        std::cout << "4: Your own information" << std::endl;
        std::cout << "5: Upgrade your health" << std::endl;
        std::cout << "6: Change your name" << std::endl;
        std::cout << "Enter a number or letter to select: ";
        std::cin >> select;
		if (select == "E" || select == "e" || select == "Exit")
        {
            break;
        }
        else if (select == "SG" || select == "sg") {
        	saveGame(steve, inspectLargeShips);
		}
        else if (select == "IG" || select == "ig") {
        	loadGame(steve, inspectLargeShips);
		}
        else if (select == "1") {
        	monsterMenu(steve, &inspectLargeShips);
        }
        else if (select == "2") {
        	damageUpgrade(steve);
        	
		}
		else if (select == "3") {
			restoreHealth(steve);
			
		}
		else if (select == "clear") {
			clearConsole();
		}
		else if (select == "4") {
			playerInformation(steve);
			
		}
		else if (select == "5") {
			healthUpgrade(steve);
			
		}
		else if (select == "6") {
			changePlayerName(steve);
			
		}
		else {
			std::cout << "You have entered a number or letter that does not exist in the list. Please re-enter the correct one!\n";
		}
    } /* End of game loop */
}
int main(int argc, char *argv[], char *envp[]) {
    startGame();
    return 0;
}