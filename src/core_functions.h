#ifndef CORE_FUNCTION_H
#define CORE_FUNCTION_H
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <thread>
#include <chrono>
#include "manager.h"

inline void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
        std::cout << "\033[H" << std::flush;
    #endif
}
inline void saveGame(Player &player, bool inspectLargeShips) {
    std::ofstream file("saveGame.txt");
    if (file.is_open()) {
        file << player.returnsName() << "\n";
        file << player.returnsHealth() << "\n";
        file << player.returnToMaximumHealth() << "\n";
        file << player.returnsDamage() << "\n";
        file << player.returnsMoney() << "\n";
        file << inspectLargeShips << "\n";
        file.close();
        std::cout << "Game saved successfully!" << std::endl;
    }
}

inline void loadGame(Player &player, bool &inspectLargeShips) {
    std::ifstream file("saveGame.txt");
    if (file.is_open()) {
        std::string name;
        int health, maxHealth, damage, money;
        bool shipFlag;

        if (file >> name >> health >> maxHealth >> damage >> money >> shipFlag) {
            player.setName(name);
            player.settingMaximumHealth(maxHealth);
            player.healthSetting(health);
            player.setDamage(damage);
            player.moneySetting(money);
            inspectLargeShips = shipFlag;

            std::cout << "Game loaded! Welcome back, " << name << "." << std::endl;
        }
        file.close();
    } else {
        std::cout << "No save file found!" << std::endl;
    }
}
inline void changePlayerName(Player &player) {
    std::string newName;
    std::cout << "Enter your new name: ";
    std::cin.ignore();
    std::getline(std::cin, newName);
    
    if (!newName.empty()) {
        player.setName(newName);
        std::cout << "Your name has been successfully changed to: " << player.returnsName() << "!" << std::endl;
    } else {
        std::cout << "Invalid name. Please try again!" << std::endl;
    }
}
inline int HEALTH_UPGRADE_PRICES = 16;
inline int HEALTH_IMPROVEMENT_INDEX = 25;
inline void healthUpgrade(Player &player) {
	while (true) {
		std::string select;
		std::cout << "Do you want to increase your maximum health? This will help you survive longer." << std::endl;
		std::cout << "Upgrading your health costs " << HEALTH_UPGRADE_PRICES << " coins." << std::endl;
		std::cout << "Y: Yes, N: No (N = Exit Menu)" << std::endl;
		std::cout << "Enter a number or letter to select: ";
		std::cin >> select;
		if (select == "Y" || select == "y") {
			if (player.returnToMaximumHealth() >= 999999999) { std::cout << "Your health is already at MAX LEVEL (999999999)!" << std::endl; continue; }
			if (player.returnsMoney() >= HEALTH_UPGRADE_PRICES) {
				player.settingMaximumHealth(player.returnToMaximumHealth() + HEALTH_IMPROVEMENT_INDEX);
				player.healthSetting(player.returnToMaximumHealth());
				player.reduceMoney(HEALTH_UPGRADE_PRICES);
				HEALTH_UPGRADE_PRICES += 1;
				HEALTH_IMPROVEMENT_INDEX += 25;
				std::cout << "You have successfully improved your health!" << std::endl;
			}
			else {
				std::cout << "You don't have enough coins to upgrade your health!" << std::endl;
			}
		}
		else if (select == "N" || select == "n") {
			break;
		}
		else {
			std::cout << "Incorrect syntax entered. Please re-enter!" << std::endl;
		}
	}
}
inline void playerInformation(Player &player) {
	std::cout << "Name: " << player.returnsName() << std::endl;
	std::cout << "Health: " << player.returnsHealth() << std::endl;
	std::cout << "Damage: " << player.returnsDamage() << std::endl;
	std::cout << "Coins: " << player.returnsMoney() << std::endl;
}
inline const int HEALTH_RECOVERY_PRICE = 10;
inline void restoreHealth(Player &player) {
	while(true) {
		std::string select;
		std::cout << "Do you want to recover your health? It costs coins, but you will be restored to full strength." << std::endl;
		std::cout << "The cost for health recovery is " << HEALTH_RECOVERY_PRICE << " coins." << std::endl;
		std::cout << "Y: Yes, N: No ( No = Exit Menu )" << std::endl;
		std::cout << "Enter a number or letter to select: ";
		std::cin >> select;
		if (select == "Y" || select == "y") {
			if (player.returnsMoney() >= HEALTH_RECOVERY_PRICE) {
				if (player.returnsHealth() < player.returnToMaximumHealth()) {
					player.healthSetting(player.returnToMaximumHealth());
					player.reduceMoney(HEALTH_RECOVERY_PRICE);
					std::cout << "You have successfully recovered. Your current health is " << player.returnsHealth() << "." << std::endl;
				}
				else { std::cout << "Your health is already at its peak; it cannot be restored!" << std::endl; }
			}
			else { std::cout << "You don't have enough coins to recover your health!" << std::endl; }
		}
		else if (select == "N" || select == "n") {
			break;
		}
		else { std::cout << "Incorrect syntax entered. Please re-enter!" << std::endl; }
	}
}
inline int DAMAGE_UPGRADE_PRICE = 0;
inline void damageUpgrade(Player &player) {
	while(true) {
		std::string select;
		std::cout << "Want to upgrade your damage? This will make you stronger than when you started." << std::endl;
		std::cout << "The cost to upgrade damage is " << DAMAGE_UPGRADE_PRICE << " coins." << std::endl;
		std::cout << "Y: Yes, N: No ( No = Exit Menu )" << std::endl;
		std::cout << "Enter a number or letter to select: ";
		std::cin >> select;
		if (select == "Y" || select == "y") {
			if (player.returnsMoney() >= DAMAGE_UPGRADE_PRICE) {
				player.increasedDamage(1);
				player.reduceMoney(DAMAGE_UPGRADE_PRICE);
				DAMAGE_UPGRADE_PRICE += 1;
				std::cout << "You have successfully upgraded your damage! You now have " << player.returnsMoney() << " coins." << std::endl;
			}
			else if (player.returnsMoney() < DAMAGE_UPGRADE_PRICE) {
				std::cout << "You no longer have coins to upgrade your damage :)" << std::endl;
			}
			else {
				std::cout << "You have entered a number or letter that does not exist in the list. Please re-enter the correct one!" << std::endl;
			}
		}
		else if (select == "N" || select == "n") {
			break;
		}
		else { std::cout << "Incorrect syntax entered. Please re-enter!" << std::endl; }
	}
}
inline void combatLogic(Player &player, Entity &entity) {
	while (player.returnsHealth() > 0 && entity.returnsHealth() > 0) {
		std::string select;
		std::cout << player.returnsName() << " met the monster " << entity.returnsName() << ". Fight it or run!" << std::endl;
		std::cout << "1: Attack, R: Run" << std::endl;
		std::cout << "Enter a number or letter to select: ";
		std::cin >> select;
		if (select == "1" || select == "A" || select == "a") {
			
			entity.reducedHealth(player.returnsDamage());
			std::cout << player.returnsName() << " attacked the monster " << entity.returnsName() << ". " << entity.returnsName() << " now has " << entity.returnsHealth() << " health points." << std::endl;
			if (entity.returnsHealth() <= 0) {
				player.entityIsDead(entity);
				std::cout << player.returnsName() << " defeated the monster " << entity.returnsName() << ". " << player.returnsName() << " earned " << entity.returnsPrice() << " coins from the monster " << entity.returnsName() << "." << std::endl;
				std::cout << "Press Enter to continue..." << std::endl;
				std::cin.ignore();
				std::cin.get();
				break;
			}
			
			player.reducedHealth(entity.returnsDamage());
			std::cout << "The monster " << entity.returnsName() << " counterattacked " << player.returnsName() << " and dealt " << entity.returnsDamage() << " damage to " << player.returnsName() << "." << std::endl;
			
			if (player.returnsHealth() <= 0) {
				std::cout << player.returnsName() << " is dead!";
				exit(0);
			}
		}
		
		else if (select == "R" || select == "r" || select == "2") { 
			std::cout << player.returnsName() << " successfully escaped." << std::endl;
			break;
		}
		else {
			std::cout << "Incorrect syntax entered. Please re-enter!" << std::endl;
		}
	}
}
inline void monsterMenu(Player &player, bool* inspectLargeShips) {
	while (true) {
		std::string select;
		std::cout << "\n========== MONSTER BOUNTY BOARD ==========\n";
        std::cout << "P: Player Info | E: Exit Menu\n";
        std::cout << "------------------------------------------\n";
        std::cout << "1.  Husk                  (HP: 50   | DMG: 5)\n";
        std::cout << "2.  Creeper               (HP: 75   | DMG: 7)\n";
        std::cout << "3.  Charged Creeper       (HP: 100  | DMG: 10)\n";
        std::cout << "4.  Rush                  (HP: 125  | DMG: 15)\n";
        std::cout << "5.  Ambush                (HP: 150  | DMG: 15)\n";
        std::cout << "6.  Bus                   (HP: 520  | DMG: 520)\n";
        std::cout << "7.  The Painter           (HP: 0    | DMG: 0)\n";
        std::cout << "8.  Siren Head            (HP: 175  | DMG: 16)\n";
        std::cout << "9.  Cartoon Cat           (HP: 250  | DMG: 25)\n";
        std::cout << "10. Superman              (HP: 500  | DMG: 50)\n";
        std::cout << "11. Saltwater Crocodile   (HP: 1000 | DMG: 125)\n";
        std::cout << "12. Carcharodon Carcharias(HP: 1500 | DMG: 250)\n";
        std::cout << "13. [BOSS] Large Ship     (HP: 2500 | DMG: 520)\n";
        std::cout << "14. [GOD] TON 618         (HP: 16000| DMG: 1600)\n";
        std::cout << "------------------------------------------\n";
        std::cout << "Enter a number or letter to select: ";
        std::cin >> select;
        if (select == "E" || select == "e") {
        	break;
        }
        else if (select == "P" || select == "p") {
			playerInformation(player);
			std::cout << "Press Enter to continue..." << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
			continue;
		}
        else if (select == "1") {
        	Entity husk("Husk", 50, 5, 5);
            combatLogic(player, husk);
        }
        else if (select == "2") {
        	Entity creeper("Creeper", 75, 7, 10);
			combatLogic(player, creeper);
		}
        else if (select == "3") {
        	Entity chargedCreeper("Charged Creeper", 100, 10, 25);
        	combatLogic(player, chargedCreeper);
		}
        else if (select == "4") {
        	Entity rush("Rush", 125, 15, 30);
            combatLogic(player, rush);
		}
        else if (select == "5") {
        	Entity ambush("Ambush", 150, 15, 45);
            combatLogic(player, ambush);
        }
        else if (select == "6") {
        	Entity bus("Bus", 520, 520, 520);
            combatLogic(player, bus);
        }
        else if (select == "7") {
            Entity thePainter("The Painter", 7, 0, 7);
            combatLogic(player, thePainter);
        }
        else if (select == "8") {
            Entity sirenHead("Siren Head", 175, 16, 55);
            combatLogic(player, sirenHead);
        }
        else if (select == "9") {
            Entity cartoonCat("Cartoon Cat", 250, 25, 70);
            combatLogic(player, cartoonCat);
		}
		else if (select == "10") {
			Entity superman("Superman", 500, 50, 125);
			combatLogic(player, superman);
		}
		else if (select == "11") {
			Entity saltwaterCrocodile("Saltwater Crocodile", 1000, 125, 225);
			combatLogic(player, saltwaterCrocodile);
		}
		else if (select == "12") {
			Entity carcharodonCarcharias("Carcharodon Carcharias", 1500, 250, 400);
			combatLogic(player, carcharodonCarcharias);
		}
		else if (select == "13") {
			Entity largeShip("Large Ship", 2500, 520, 16);
			combatLogic(player, largeShip);
			if (largeShip.returnsHealth() <= 0) {
				if ((*inspectLargeShips) == true) {
					std::cout << "\n==========================================" << std::endl;
					std::cout << "CRITICAL VICTORY!" << std::endl;
					std::cout << "It's surprising you were able to destroy the Large Ship." << std::endl;
					std::cout << "You have scavenged advanced weaponry from the wreckage." << std::endl;
					std::cout << "Gained: +1600 Permanent Damage buff!" << std::endl;
					std::cout << "==========================================" << std::endl;
					
					player.increasedDamage(1600);
					(*inspectLargeShips) = false;
				}
				else { 
					std::cout << "\nThe wreckage is empty. You've already looted this ship, haha." << std::endl; 
				}
			}
			else {
				std::cout << "\nThe enemy ship retreated! No spoils for cowards." << std::endl;
			}
		}
		else if (select == "14") {
			Entity ton618("TON 618", 16000, 1600, 700);
			combatLogic(player, ton618);
		}
        else {
            std::cout << "Incorrect syntax entered. Please re-enter!" << std::endl;
		}
	}
}

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
    	if (steve.returnToMaximumHealth() > 999999999 || steve.returnsDamage() > 999999999) {
    		std::cout << "\n\033[1;31m[!] The system detects code modification and tampering in the game!\033[0m" << std::endl;
    		std::this_thread::sleep_for(std::chrono::seconds(3));
    		exit(1);
    	}
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
#endif