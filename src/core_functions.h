#ifndef CORE_FUNCTION_H
#define CORE_FUNCTION_H
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <atomic>
#include <vector>
#include <map>
#include <mutex>
#include "manager.h"

extern std::mutex mutex;
extern std::atomic < bool > isMonitoring;
extern long long HEALTH_UPGRADE_PRICES;
extern long long HEALTH_IMPROVEMENT_INDEX;
extern const long long HEALTH_RECOVERY_PRICE;
extern long long DAMAGE_IMPROVEMENT_INDEX;
extern long long DAMAGE_UPGRADE_PRICE;

std::map < long long, Entity > getMonsterList();
void antiCheatScanner(Player &player);
std::string playerRanking(Player* player);
std::string timeSeries();
void clearConsole();
void saveGame(Player &player, bool inspectLargeShips);
void loadGame(Player &player, bool &inspectLargeShips);
void changePlayerName(Player &player);
void healthPurchaseOptions(Player* player);
void healthUpgrade(Player &player);
void playerInformation(Player &player);
void restoreHealth(Player &player);
void damagePurchaseOptions(Player* player);
void damageUpgrade(Player &player);
void combatLogic(Player &player, Entity &entity);
void monsterMenu(Player &player, bool* inspectLargeShips);
void startGame();
#endif