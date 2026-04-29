#include "core_functions.h"
std::mutex mutex;

std::map < long long, Entity > getMonsterList() {
    std::map < long long,
    Entity > ml;
    ml[1] = Entity("Husk", 50, 5, 5);
    ml[2] = Entity("Creeper", 75, 7, 10);
    ml[3] = Entity("Charged Creeper", 100, 10, 25);
    ml[7] = Entity("The Painter", 150, 16, 34);
    ml[8] = Entity("Blue-Eyes White Dragon", 300, 25, 43);
    ml[9] = Entity("Exodia the Forbidden One", 170, 16, 36);
    ml[10] = Entity("SGR 1806-20", 500, 3000, 52);
    ml[11] = Entity("Mosquito", 1, 1, 1);
    ml[12] = Entity("Chicxulub", 1000, 1000, 100);
    ml[13] = Entity("Large Ship", 2500, 520, 700);
    ml[14] = Entity("The Solar Flare", 52000000, 16000, 5200000);
    ml[15] = Entity("Firecracker", 30, 60, 20);
    ml[16] = Entity("Bamboo Sentinel", 200, 15, 45);
    ml[17] = Entity("Golden Starfish", 80, 30, 30);
    ml[18] = Entity("Super Wasp", 15, 25, 5);
    ml[19] = Entity("Giant Isopod", 450, 10, 60);
    ml[20] = Entity("Honey Badger", 350, 45, 80);
    ml[21] = Entity("Red-Eyes Black Dragon", 280, 22, 40);
    ml[22] = Entity("Slime King", 600, 20, 120);
    ml[23] = Entity("Cerberus", 850, 65, 200);
    ml[24] = Entity("Cthulhu Junior", 5000, 800, 1500);
    ml[25] = Entity("Mountain Golem", 5000, 150, 800);
    ml[26] = Entity("Nuclear Slime", 8000, 1200, 1500);
    ml[27] = Entity("Cyber Dragon", 12000, 3500, 5000);
    ml[28] = Entity("The Fallen Angel", 50000, 8500, 12000);
    ml[29] = Entity("Supernova", 1000000, 50000, 200000);
    ml[30] = Entity("TON 618", 70000000, 43000, 7000000);
    ml[31] = Entity("Stephenson 2-18", 250000, 700000, 6700000);
    ml[32] = Entity("Phoenix Cluster", 120000000, 95000, 10000000);
    ml[33] = Entity("Void Reaver", 0, 999999, 0);
    ml[34] = Entity("The Big Bang", 999999999, 999999999, 999999999);
    ml[35] = Entity("Keyboard Warrior", 10, 100, 1);
    ml[36] = Entity("The Debt Collector", 9999, 50, 1000);
    ml[37] = Entity("The Kraken", 7777, 777, 777);
    return ml;
}
std::atomic < bool > isMonitoring(true);
void antiCheatScanner(Player &player) {
    while (isMonitoring) {
        if (player.get(MAXIMUM_HEALTH) > 999999999999999 ||
            player.get(DAMAGE) > 999999999999999 ||
            player.get(MONEY) > 999999999999999 ||
            player.get(HEALTH) > 999999999999999) {

            std::cout << "\n[!] Security Alert: Memory modification detected!" << std::endl;
            std::cout << "[!] Game will be terminated immediately." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            exit(1);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
std::string playerRanking(Player* player) {
    // Dùng long long để cộng tổng máu và damage cho an toàn
    long long total = (long long)((*player).get(MAXIMUM_HEALTH)) + (long long)((*player).get(DAMAGE));

    // KIỂM TRA TỪ RANK CAO NHẤT XUỐNG THẤP NHẤT
    if (total >= 1048576000) return "The Fist of the God of Destruction";
    if (total >= 724288000) return "Zenith";
    if (total >= 524288000) return "Omniscient";
    if (total >= 262144000) return "Dominator";
    if (total >= 131072000) return "Eternity";
    if (total >= 65536000) return "Astral";
    if (total >= 32768000) return "Ethereal";
    if (total >= 16384000) return "Celestial";
    if (total >= 8192000) return "Overlord";
    if (total >= 4096000) return "Divinity";
    if (total >= 2048000) return "Ascendant";
    if (total >= 1024000) return "Demigod";
    if (total >= 512000) return "Apex";
    if (total >= 256000) return "Immortal";
    if (total >= 128000) return "Mythic";
    if (total >= 116000) return "Conqueror";
    if (total >= 106000) return "Champion";
    if (total >= 99000) return "Hero";
    if (total >= 70000) return "Paladin";
    if (total >= 64000) return "Warlord";
    if (total >= 52000) return "Commander";
    if (total >= 42000) return "Vanguard";
    if (total >= 32000) return "Gladiator";
    if (total >= 25000) return "Hunter";
    if (total >= 16000) return "Slayer";
    if (total >= 12000) return "Elite";
    if (total >= 8000) return "Veteran"; // Với 8324 điểm, nó sẽ khớp ở đây và thoát hàm luôn!
    if (total >= 4000) return "Warrior";
    if (total >= 2000) return "Soldier";
    if (total >= 1000) return "Squire";
    if (total >= 500) return "Novice";

    return "Newbie";
}
std::string timeSeries() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%H:%M:%S - %d/%m", ltm);
    return std::string(buffer);
}
void clearConsole() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    std::cout << "\033[H" << std::flush;
    #endif
}
void saveGame(Player &player, bool inspectLargeShips) {
    std::ofstream file("save_data.bin", std::ios::out | std::ios::binary);
    if (file.is_open()) {
        std::string name = player.get_name();
        size_t lenName = name.size();
        long long health = player.get(HEALTH);
        long long maxHealth = player.get(MAXIMUM_HEALTH);
        long long damage = player.get(DAMAGE);
        long long money = player.get(MONEY);
        bool iLS = inspectLargeShips;
        /*------- WRITE -------*/
        file.write((char*)&lenName, sizeof(lenName));
        file.write(name.c_str(), lenName);
        file.write((char*)&health, sizeof(health));
        file.write((char*)&maxHealth, sizeof(maxHealth));
        file.write((char*)&damage, sizeof(damage));
        file.write((char*)&money, sizeof(money));
        file.write((char*)&iLS, sizeof(iLS));
        std::cout << "Game saved successfully!" << std::endl;
    }
}

void loadGame(Player &player, bool &inspectLargeShips) {
    try {
        std::ifstream file("save_data.bin", std::ios::in | std::ios::binary);
        size_t lenName;
        char* pName = nullptr;
        long long health = 0,
        maxHealth = 0,
        damage = 0,
        money = 0;
        bool iLS;
        if (file.is_open()) {
            /*------- READ -------*/
            file.read((char*)&lenName, sizeof(lenName));
            pName = new char[lenName + 1];
            file.read(pName, lenName);
            *((char*)(pName + lenName)) = 0x00;
            std::string name(pName, lenName);
            delete[] pName;
            file.read((char*)&health, sizeof(health));
            file.read((char*)&maxHealth, sizeof(maxHealth));
            file.read((char*)&damage, sizeof(damage));
            file.read((char*)&money, sizeof(money));
            file.read((char*)&iLS, sizeof(iLS));
            std::cout << "Game loaded! Welcome back, " << name << "." << std::endl;
            player.set_up_name(name);
            player.set(health, HEALTH);
            player.set(maxHealth, MAXIMUM_HEALTH);
            player.set(damage, DAMAGE);
            player.set(money, MONEY);
            inspectLargeShips = iLS;
            file.close();
        } else {
            std::cout << "No save file found!" << std::endl;
        }
    } catch (const std::bad_alloc& error) {
        std::cout << "Error: Save file is corrupted (Too large)! Loading default stats... >> " << error.what() << std::endl;
    } catch (...) {
        std::cout << "Error: Something went wrong while loading. Let's start over!" << std::endl;
    }
}
void changePlayerName(Player &player) {
    std::string newName;
    std::cout << "Enter your new name: ";
    std::cin.ignore();
    std::getline(std::cin, newName);

    if (!newName.empty()) {
        player.set_up_name(newName);
        std::cout << "Your name has been successfully changed to: " << player.get_name() << "!" << std::endl;
    } else {
        std::cout << "Invalid name. Please try again!" << std::endl;
    }
}
long long HEALTH_UPGRADE_PRICES = 100;
long long HEALTH_IMPROVEMENT_INDEX = 25;
void healthPurchaseOptions(Player* player) {
    unsigned long long totalHealth;
    std::cout << "Enter the number of TIMES you want to upgrade: ";
    if(!(std::cin >> totalHealth)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
        std::cout << "Character input error! You must enter a number (Enter 0 to cancel purchase)" << std::endl;
        return;
    }
    unsigned long long totalHealthPrice = (totalHealth*(2*HEALTH_UPGRADE_PRICES+(totalHealth-1)))/2;
    unsigned long long overallHealthImprovement = (totalHealth*HEALTH_IMPROVEMENT_INDEX)+(25*totalHealth*(totalHealth-1))/2;
    if ((*player).get(MONEY) >= (long long)totalHealthPrice) {
        if ((unsigned long long)(*player).get(MAXIMUM_HEALTH) + overallHealthImprovement >= 999999999999999) {
            std::cout << "You've reached your health limit!" << std::endl;
            return;
        }
        (*player).set((*player).get(MAXIMUM_HEALTH) + (long long)overallHealthImprovement, MAXIMUM_HEALTH);
        (*player).set((*player).get(MAXIMUM_HEALTH), HEALTH);
        (*player).adjust(-((long long)totalHealthPrice), MONEY);
        HEALTH_UPGRADE_PRICES += (long long)totalHealth;
        HEALTH_IMPROVEMENT_INDEX += (long long)(totalHealth*25);
        std::cout << "You have successfully improved your health!" << std::endl;
    }
    else {
        std::cout << "You don't have enough money!" << std::endl;
        return;
    }
}
void healthUpgrade(Player &player) {
    while (true) {
        std::string select;
        std::cout << "Do you want to increase your maximum health? This will help you survive longer." << std::endl;
        std::cout << "Upgrading your health costs " << HEALTH_UPGRADE_PRICES << " coins." << std::endl;
        std::cout << "Y: Yes, O: Option, N: No (N = Exit Menu)" << std::endl;
        std::cout << "Enter a number or letter to select: ";
        std::cin >> select;
        if (select == "Y" || select == "y") {
            if (player.get(MAXIMUM_HEALTH) >= 999999999999999) {
                std::cout << "Your health is already at MAX LEVEL (999999999999999)!" << std::endl; continue;
            }
            if (player.get(MONEY) >= HEALTH_UPGRADE_PRICES) {
                player.set(player.get(MAXIMUM_HEALTH) + HEALTH_IMPROVEMENT_INDEX, MAXIMUM_HEALTH);
                player.set(player.get(MAXIMUM_HEALTH), HEALTH);
                player.adjust(-(HEALTH_UPGRADE_PRICES), MONEY);
                HEALTH_UPGRADE_PRICES += 1;
                HEALTH_IMPROVEMENT_INDEX += 25;
                std::cout << "You have successfully improved your health!" << std::endl;
            }
            else {
                std::cout << "You don't have enough coins to upgrade your health!" << std::endl;
            }
        }
        else if (select == "O" || select == "o") {
            healthPurchaseOptions(&player);
        }
        else if (select == "N" || select == "n") {
            break;
        }
        else {
            std::cout << "Incorrect syntax entered. Please re-enter!" << std::endl;
        }
    }
}
void playerInformation(Player &player) {
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Time: " << timeSeries() << std::endl;
    std::cout << "Player Ranking: " << playerRanking(&player) << std::endl;
    std::cout << "Name: " << player.get_name() << std::endl;
    std::cout << "Health: " << player.get(HEALTH) << std::endl;
    std::cout << "Damage: " << player.get(DAMAGE) << std::endl;
    std::cout << "Coins: " << player.get(MONEY) << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
}
const long long HEALTH_RECOVERY_PRICE = 10;
void restoreHealth(Player &player) {
    while(true) {
        std::string select;
        std::cout << "Do you want to recover your health? It costs coins, but you will be restored to full strength." << std::endl;
        std::cout << "The cost for health recovery is " << HEALTH_RECOVERY_PRICE << " coins." << std::endl;
        std::cout << "Y: Yes, N: No ( No = Exit Menu )" << std::endl;
        std::cout << "Enter a number or letter to select: ";
        std::cin >> select;
        if (select == "Y" || select == "y") {
            if (player.get(MONEY) >= HEALTH_RECOVERY_PRICE) {
                if (player.get(HEALTH) < player.get(MAXIMUM_HEALTH)) {
                    player.set(player.get(MAXIMUM_HEALTH), HEALTH);
                    player.adjust(-(HEALTH_RECOVERY_PRICE), MONEY);
                    std::cout << "You have successfully recovered. Your current health is " << player.get(HEALTH) << "." << std::endl;
                }
                else {
                    std::cout << "Your health is already at its peak; it cannot be restored!" << std::endl;
                }
            }
            else {
                std::cout << "You don't have enough coins to recover your health!" << std::endl;
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
long long DAMAGE_IMPROVEMENT_INDEX = 1;
long long DAMAGE_UPGRADE_PRICE = 10;
void damagePurchaseOptions(Player* player) {
    unsigned long long totalDamage = 0;
    std::cout << "Enter the amount of damage you want to upgrade: ";
    if(!(std::cin >> totalDamage)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
        std::cout << "Character input error! You must enter a number (Enter 0 to cancel purchase)" << std::endl;
        return;
    }
    unsigned long long priceDamage = (totalDamage*(2*DAMAGE_UPGRADE_PRICE+(totalDamage-1)))/2;
    unsigned long long overallDamageGain = (totalDamage * DAMAGE_IMPROVEMENT_INDEX) + (totalDamage * (totalDamage - 1)) / 2;
    if ((*player).get(MONEY) >= (long long)priceDamage) {
        if ((*player).get(DAMAGE) + (long long)overallDamageGain >= 999999999999999) {
            std::cout << "You've reached your damage limit!" << std::endl;
            return;
        }
        (*player).adjust((long long)overallDamageGain, DAMAGE);
        (*player).adjust(-((long long)priceDamage), MONEY);
        DAMAGE_UPGRADE_PRICE += (long long)totalDamage;
        DAMAGE_IMPROVEMENT_INDEX += (long long)totalDamage;
        std::cout << "You have successfully upgraded your damage!" << std::endl;
    }
    else {
        std::cout << "You don't have enough money!" << std::endl;
    }
}
void damageUpgrade(Player &player) {
    while(true) {
        std::string select;
        std::cout << "Want to upgrade your damage? This will make you stronger than when you started." << std::endl;
        std::cout << "The cost to upgrade damage is " << DAMAGE_UPGRADE_PRICE << " coins." << std::endl;
        std::cout << "Y: Yes, O: Option, N: No ( No = Exit Menu )" << std::endl;
        std::cout << "Enter a number or letter to select: ";
        std::cin >> select;
        if (select == "Y" || select == "y") {
            if (player.get(MONEY) >= DAMAGE_UPGRADE_PRICE) {
                player.adjust(DAMAGE_IMPROVEMENT_INDEX, DAMAGE);
                player.adjust(-(DAMAGE_UPGRADE_PRICE), MONEY);
                DAMAGE_UPGRADE_PRICE += 1;
                DAMAGE_IMPROVEMENT_INDEX += 1;
                std::cout << "You have successfully upgraded your damage! You now have " << player.get(MONEY) << " coins." << std::endl;
            }
            else if (player.get(MONEY) < DAMAGE_UPGRADE_PRICE) {
                std::cout << "You no longer have coins to upgrade your damage :)" << std::endl;
            }
            else {
                std::cout << "You have entered a number or letter that does not exist in the list. Please re-enter the correct one!" << std::endl;
            }
        }
        else if (select == "O" || select == "o") {
            damagePurchaseOptions(&player);
        }
        else if (select == "N" || select == "n") {
            break;
        }
        else {
            std::cout << "Incorrect syntax entered. Please re-enter!" << std::endl;
        }
    }
}
void combatLogic(Player &player, Entity &entity) {
    while (player.get(HEALTH) > 0 && entity.get(HEALTH) > 0) {
        std::string select;
        std::cout << player.get_name() << " met the monster " << entity.get_name() << ". Fight it or run!" << std::endl;
        std::cout << "1: Attack, R: Run" << std::endl;
        std::cout << "Enter a number or letter to select: ";
        std::cin >> select;
        if (select == "1" || select == "A" || select == "a") {

            entity.adjust(-(player.get(DAMAGE)), HEALTH);
            std::cout << player.get_name() << " attacked the monster " << entity.get_name() << ". " << entity.get_name() << " now has " << entity.get(HEALTH) << " health polong longs." << std::endl;
            if (entity.get(HEALTH) <= 0) {
                player.entity_is_dead(&entity);
                std::cout << player.get_name() << " defeated the monster " << entity.get_name() << ". " << player.get_name() << " earned " << entity.get(PRICE) << " coins from the monster " << entity.get_name() << "." << std::endl;
                std::cout << "Press Enter to continue..." << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            }

            player.adjust(-(entity.get(DAMAGE)), HEALTH);
            std::cout << "The monster " << entity.get_name() << " counterattacked " << player.get_name() << " and dealt " << entity.get(DAMAGE) << " damage to " << player.get_name() << "." << std::endl;

            if (player.get(HEALTH) <= 0) {
                std::cout << player.get_name() << " is dead!";
                exit(0);
            }
        }

        else if (select == "R" || select == "r" || select == "2") {
            std::cout << player.get_name() << " successfully escaped." << std::endl;
            break;
        }
        else {
            std::cout << "Incorrect syntax entered. Please re-enter!" << std::endl;
        }
    }
}
void monsterMenu(Player &player, bool* inspectLargeShips) {
    std::map < long long,
    Entity > entities = getMonsterList();
    while (true) {
        std::string select;
        std::cout << "\n========== MONSTER BOUNTY BOARD ==========\n";
        std::cout << "P: Player Info | E: Exit Menu\n";
        std::cout << "------------------------------------------\n";
        for(auto const& [id, monster]: entities) {
            std::cout << id << ". " << monster.get_name() << " (HP: " << monster.get(HEALTH) << " | DMG: " << monster.get(DAMAGE) << ")" << std::endl;
        }
        std::cout << "------------------------------------------\n";
        std::cout << "Enter a number or letter to select: ";
        std::cin >> select;
        if (select == "E" || select == "e") {
            break;
        }
        if (select == "P" || select == "p") {
            playerInformation(player);
            std::cout << "Press Enter to continue..." << std::endl;
            std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
            std::cin.get();
            continue;
        }
        try {
            long long id = std::stoll(select);
            if(entities.find(id) != entities.end()) {
                if(id == 13) {
                    Entity largeShip = entities[id];
                    combatLogic(player, largeShip);
                    if (largeShip.get(HEALTH) <= 0) {
                        if ((*inspectLargeShips) == true) {
                            std::cout << "\n==========================================" << std::endl;
                            std::cout << "CRITICAL VICTORY!" << std::endl;
                            std::cout << "It's surprising you were able to destroy the Large Ship." << std::endl;
                            std::cout << "You have scavenged advanced weaponry from the wreckage." << std::endl;
                            std::cout << "Gained: +1600 Permanent Damage buff!" << std::endl;
                            std::cout << "Press Enter to continue..." << std::endl;
                            std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
                            std::cin.get();
                            std::cout << "==========================================" << std::endl;

                            player.adjust(1600, DAMAGE);
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
                else if(id == 10) {
                    Entity sgr = entities[id];
                    combatLogic(player, sgr);
                    if (sgr.get(HEALTH) > 0) {
                        player.adjust(-777777, HEALTH);
                        if(player.get(HEALTH) <= 0) {
                            std::cout << "You were hit by the extremely strong magnetic field of SGR 1806-20 which sucked -777777 of your health! You are dead!" << std::endl;
                            exit(1);
                        } else {}
                    }
                }
                else {
                    Entity monster = entities[id];
                    combatLogic(player, monster);
                }
            }
            else {
                std::cout << "The identifier does not exist, please re-enter!" << std::endl;
            }
        } catch (...) {
            std::cout << "Please enter the monster identifier!" << std::endl;
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
    Player steve(initialName, 100, 1, 100);
    static bool inspectLargeShips = true;
    isMonitoring = true;
    std::thread cheatWatcher(antiCheatScanner, std::ref(steve));
    cheatWatcher.detach();
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
        if (select == "E" || select == "e" || select == "Exit") {
            while(true) {
                std::string select;
                std::cout << "Do you really want to quit the game? ( Y/n )" << std::endl;
                std::cout << "Enter a number or letter to select: ";
                std::cin >> select;
                if (select == "Y" || select == "y") {
                    saveGame(steve, inspectLargeShips);
                    exit(0);
                }
                else if (select == "N" || select == "n") {
                    break;
                }
                else {
                    std::cout << "Error, please re-enter!" << std::endl;
                }
            }
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