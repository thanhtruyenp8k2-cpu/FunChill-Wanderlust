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
#include <mutex>
#include "manager.h"
std::mutex mutex;

std::vector<std::string> getWorldMessages() {
    return {
        // --- Chủ đề Kinh dị / Quái vật ---
        "Siren Head đang hú vang ở phía sau dãy núi Cà Mau...",
        "Cartoon Cat vừa để lại một dấu chân đen ngòm trên màn hình.",
        "Tiếng bước chân lạ vang lên trong hành lang tối...",
        "Một đôi mắt đỏ rực đang nhìn bạn từ phía sau mã nguồn.",
        "Đừng quay xe, có thứ gì đó đang đứng ngay sau lưng bạn!",
        "Hơi thở lạnh lẽo phả vào gáy... nhưng phòng bạn đang bật quạt mà?",
        "Cẩn thận, thực thể 'Null Pointer' đang đi săn đêm nay.",
        "Tiếng radio rè rè phát ra những tọa độ bí ẩn...",
        "Bóng tối đang dần xâm chiếm các dòng lệnh của bạn.",
        "Một tiếng cười khẽ vang lên khi bạn vừa đánh bại quái vật.",
        
        // --- Chủ đề Arm Wrestling (Vật tay) ---
        "Cảm giác cơ cẳng tay đang căng cứng, sẵn sàng cho một cú Toproll!",
        "Bạn vừa thắng một trận vật tay tưởng tượng với Denis Cyplenkov.",
        "Đừng quên tập Pronation, nếu không muốn bị đè bẹp!",
        "Lực cổ tay của bạn hôm nay có vẻ 'uy tín' hơn hôm qua.",
        "Devon Larratt vừa gật đầu tán thưởng kỹ thuật của bạn.",
        "Cầm vào tay nắm cửa cũng thấy giống như đang cầm tay đối thủ...",
        "Một cú Hook sấm sét vừa được tung ra trong tâm trí bạn.",
        "Xương trụ của bạn đang kêu gào: 'Cho tôi đi tập đi!'",
        "Luyện tập Riser curls là chìa khóa để trở thành trùm trường.",
        "Vật tay với quái vật? Bạn cần một cái bàn đấu vững chắc hơn.",

        // --- Chủ đề Programming / Reverse Engineering ---
        "Đang thực hiện lệnh 'mov x0, #success' cho cuộc đời bạn...",
        "Hacker lỏ nào đó đang cố gắng 'nop' hàm trừ máu của bạn.",
        "L3 Cache đang đầy, hãy bình tĩnh xử lý đừng để tràn bộ đệm.",
        "Lỗi Segfault vừa xảy ra trong giấc mơ của bạn.",
        "Hệ thống báo cáo: Code của bạn đẹp trai gần bằng chủ nhân.",
        "Đang biên dịch vận may cho lần đánh quái tiếp theo...",
        "Registers x0 đến x30 đều đang sẵn sàng thực chiến.",
        "Bạn vừa tìm thấy một lỗ hổng trong phòng thủ của quái vật.",
        "Reverse engineering trái tim của boss... Error: Không tìm thấy!",
        "Stack pointer đang trỏ vào một kho báu bí mật.",

        // --- Chủ đề Hài hước / Đời sống lớp 8 ---
        "Đứa em của bạn vừa lén nhìn trộm code và cười khẩy.",
        "Thầy cô đang đi tuần tra... à nhầm, đó là boss đấy!",
        "Bạn chợt nhận ra mình chưa làm bài tập về nhà...",
        "Một ly trà sữa vừa xuất hiện trong trí tưởng tượng của bạn.",
        "Game đang chạy nhanh hơn vì bạn vừa mới đi tắm xong.",
        "Thông báo: Bạn là người đẹp trai nhất trong cái thư mục này.",
        "Cà Mau hôm nay nắng to, rất thích hợp để... ngồi code.",
        "Bạn cảm thấy mình mạnh mẽ như lúc vừa nhận được giấy khen.",
        "Lệnh 'sudo' cũng không thể giúp bạn thoát khỏi bài kiểm tra toán.",
        "Bí kíp chiến thắng: Ăn no, ngủ kỹ và không để máy hết pin.",

        // --- Chủ đề Thế giới Game ---
        "Một thương nhân bí ẩn vừa đi ngang qua nhưng bạn không thấy.",
        "Máu của quái vật đang tự hồi phục... đùa thôi, nó đang sợ bạn đấy.",
        "Cấp độ 1500 chỉ là khởi đầu, hãy tiến tới Sea 3 thôi nào!",
        "Thanh kiếm Absolute Sword Path đang tỏa ra hào quang màu xanh.",
        "Pickaxe Emerald của bạn đang rung lên vì gặp quặng quý.",
        "Bản lưu game (Save) vừa được kiểm tra tính toàn vẹn.",
        "Bạn vừa nhặt được một mẩu giấy ghi: 'Truyền là trùm C++'.",
        "Có một kho báu bị ẩn dưới lệnh 'clear' màn hình.",
        "Quái vật đang họp bàn cách để không bị bạn bắt nạt.",
        "Màn hình của bạn đang sáng lên vì hào quang của nhân vật chính.",

        // --- Thông điệp ngẫu nhiên ---
        "Tình trạng hệ thống: Ổn định (giống như tâm lý của bạn).",
        "Dòng thông báo thứ 52 này không có ý nghĩa gì cả.",
        "Hãy uống nước đi, lập trình viên không sống bằng code không đâu.",
        "Nhịp tim của bạn đang đồng bộ với nhịp của bộ vi xử lý.",
        "Bạn vừa nhận được 0 vàng vì... chẳng làm gì cả.",
        "Thời gian trôi qua thật nhanh khi bạn đang 'lắp não' vào game.",
        "Một con muỗi vừa hạ cánh xuống tay bạn, hãy cẩn thận!",
        "Nếu game bị lỗi, hãy đổ lỗi cho đứa em của bạn.",
        "Bạn đang chơi phiên bản FunGame 2026 - Đỉnh cao công nghệ.",
        "Thông điệp cuối cùng: Bạn thực sự là một huyền thoại!"
    };
}
std::atomic<bool> isManyWorldAnnouncements(true);
void worldAnnouncements(std::atomic<bool> &running) {
    std::vector<std::string> messages = getWorldMessages();
    srand(time(0));
    while (running) {
        std::this_thread::sleep_for(std::chrono::minutes(1));
        if (running) {
            std::lock_guard<std::mutex> lock(mutex);
            std::string pick = messages[rand() % messages.size()];
            std::cout << "\033[s\033[2;1H\033[K\033[1;32m[World]: " << pick << "\033[0m\033[u" << std::flush;
        }
    }
}
std::atomic<bool> isMonitoring(true);
void antiCheatScanner(Player &player) {
    while (isMonitoring) {
        if (player.returnToMaximumHealth() > 999999999 || 
            player.returnsDamage() > 999999999 || 
            player.returnsMoney() > 999999999 || 
            player.returnsHealth() > 999999999) {
            
            std::cout << "\n[!] Security Alert: Memory modification detected!" << std::endl;
            std::cout << "[!] Game will be terminated immediately." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            exit(1);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
inline std::string playerRanking(Player* player) {
	int total = (*player).returnsHealth() + (*player).returnsDamage();
	if (total >= 500) return "Novice";
	if (total >= 1000) return "Squire";
	if (total >= 2000) return "Soldier";
	if (total >= 4000) return "Warrior";
	if (total >= 8000) return "Veteran";
	if (total >= 12000) return "Elite";
	if (total >= 16000) return "Slayer";
	if (total >= 25000) return "Hunter";
	if (total >= 32000) return "Gladiator";
	if (total >= 42000) return "Vanguard";
	if (total >= 52000) return "Commander";
	if (total >= 64000) return "Warlord";
	if (total >= 70000) return "Paladin";
	if (total >= 99000) return "Hero";
	if (total >= 106000) return "Champion";
	if (total >= 116000) return "Conqueror";
	if (total >= 128000) return "Mythic";
	if (total >= 256000) return "Immortal";
	if (total >= 512000) return "Apex";
	if (total >= 1024000) return "Demigod";
	if (total >= 2048000) return "Ascendant";
	if (total >= 4096000) return "Divinity";
	if (total >= 8192000) return "Overlord";
	if (total >= 16384000) return "Celestial";
	if (total >= 32768000) return "Ethereal";
	if (total >= 65536000) return "Astral";
	if (total >= 131072000) return "Eternity";
	if (total >= 262144000) return "Dominator";
	if (total >= 524288000) return "Omniscient";
	if (total >= 524288001) return "Zenith";
	if (total >= 1048576000) return "\033[1;37mThe Fist \033[1;37mof the \033[1;37mGod \033[1;37mof \033[1;37mDestruction\033[0m";
	return "Newbie";
}
inline std::string timeSeries() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%H:%M:%S - %d/%m", ltm);
    return std::string(buffer);
}
inline void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
        std::cout << "\033[H" << std::flush;
    #endif
}
inline void saveGame(Player &player, bool inspectLargeShips) {
    std::ofstream file("save_data.bin", std::ios::out | std::ios::binary);
    if (file.is_open()) {
        std::string name = player.returnsName();
        size_t lenName = name.size();
        int health = player.returnsHealth();
        int maxHealth = player.returnToMaximumHealth();
        int damage = player.returnsDamage();
        int money = player.returnsMoney();
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

inline void loadGame(Player &player, bool &inspectLargeShips) {
	try {
    	std::ifstream file("save_data.bin", std::ios::in | std::ios::binary);
    	size_t lenName;
    	char* pName = nullptr;
    	int health = 0, maxHealth = 0, damage = 0, money = 0;
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
    		player.setName(name);
    		player.healthSetting(health);
    		player.settingMaximumHealth(maxHealth);
    		player.setDamage(damage);
    		player.moneySetting(money);
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
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "Time: " << timeSeries() << std::endl;
	std::cout << "Player Ranking: " << playerRanking(&player) << std::endl;
	std::cout << "Name: " << player.returnsName() << std::endl;
	std::cout << "Health: " << player.returnsHealth() << std::endl;
	std::cout << "Damage: " << player.returnsDamage() << std::endl;
	std::cout << "Coins: " << player.returnsMoney() << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
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
        std::cout << "7.  The Painter           (HP: 7    | DMG: 0)\n";
        std::cout << "8.  Siren Head            (HP: 175  | DMG: 16)\n";
        std::cout << "9.  Cartoon Cat           (HP: 250  | DMG: 25)\n";
        std::cout << "10. Superman              (HP: 500  | DMG: 50)\n";
        std::cout << "11. Saltwater Crocodile   (HP: 1000 | DMG: 125)\n";
        std::cout << "12. Carcharodon Carcharias(HP: 1500 | DMG: 250)\n";
        std::cout << "13. [BOSS] Large Ship     (HP: 2500 | DMG: 520)\n";
        std::cout << "14. The Prototype         (HP: 5000 | DMG: 1024)\n"; // Đã thêm
        std::cout << "15. Happy                 (HP: 7000 | DMG: 1402)\n"; // Đã thêm
        std::cout << "16. Obunga                (HP: 10000| DMG: 1802)\n"; // Đã thêm
        std::cout << "17. Sanic                 (HP: 16000| DMG: 2402)\n"; // Đã thêm
        std::cout << "18. Armstrong             (HP: 25000| DMG: 3402)\n"; // Đã thêm
        std::cout << "19. Unknown               (HP: 43000| DMG: 6402)\n"; // Đã thêm
        std::cout << "20. Engineergaming        (HP: 80000| DMG: 10402)\n";// Đã thêm
        std::cout << "21. Partygoers =)         (HP: 122k | DMG: 14k)\n";  // Đã thêm
        std::cout << "22. Hounds                (HP: 177k | DMG: 20k)\n";  // Đã thêm
        std::cout << "23. Deathmoths            (HP: 207k | DMG: 31k)\n";  // Đã thêm
        std::cout << "24. Facelings             (HP: 230k | DMG: 40k)\n";  // Đã thêm
        std::cout << "25. Howlers               (HP: 260k | DMG: 50k)\n";  // Đã thêm
        std::cout << "26. The Shaper of Reality (HP: 337k | DMG: 72k)\n";  // Đã thêm
        std::cout << "27. Scarlet King          (HP: 400k | DMG: 81k)\n";  // Đã thêm
        std::cout << "28. G-Man                 (HP: 470k | DMG: 100k)\n"; // Đã thêm
        std::cout << "29. Magnetar              (HP: 500k | DMG: 201k)\n"; // Đã thêm
        std::cout << "30. [GOD] TON 618         (HP: 70M  | DMG: 16k)\n";  // Đã thêm
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
        else if (select == "1")  { Entity e("Husk", 50, 5, 5); combatLogic(player, e); }
        else if (select == "2")  { Entity e("Creeper", 75, 7, 10); combatLogic(player, e); }
        else if (select == "3")  { Entity e("Charged Creeper", 100, 10, 25); combatLogic(player, e); }
        else if (select == "4")  { Entity e("Rush", 125, 15, 30); combatLogic(player, e); }
        else if (select == "5")  { Entity e("Ambush", 150, 15, 45); combatLogic(player, e); }
        else if (select == "6")  { Entity e("Bus", 520, 520, 520); combatLogic(player, e); }
        else if (select == "7")  { Entity e("The Painter", 7, 0, 7); combatLogic(player, e); }
        else if (select == "8")  { Entity e("Siren Head", 175, 16, 55); combatLogic(player, e); }
        else if (select == "9")  { Entity e("Cartoon Cat", 250, 25, 70); combatLogic(player, e); }
        else if (select == "10") { Entity e("Superman", 500, 50, 125); combatLogic(player, e); }
        else if (select == "11") { Entity e("Saltwater Crocodile", 1000, 125, 225); combatLogic(player, e); }
        else if (select == "12") { Entity e("Carcharodon Carcharias", 1500, 250, 400); combatLogic(player, e); }
		else if (select == "13") {
			Entity largeShip("Large Ship", 2500, 520, 700);
			combatLogic(player, largeShip);
			if (largeShip.returnsHealth() <= 0) {
				if ((*inspectLargeShips) == true) {
					std::cout << "\n==========================================" << std::endl;
					std::cout << "CRITICAL VICTORY!" << std::endl;
					std::cout << "It's surprising you were able to destroy the Large Ship." << std::endl;
					std::cout << "You have scavenged advanced weaponry from the wreckage." << std::endl;
					std::cout << "Gained: +1600 Permanent Damage buff!" << std::endl;
					std::cout << "Press Enter to continue..." << std::endl;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin.get();
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
        else if (select == "14") { Entity e("The Prototype", 5000, 1024, 1600); combatLogic(player, e); }
        else if (select == "15") { Entity e("Happy", 7000, 1402, 2639); combatLogic(player, e); }
        else if (select == "16") { Entity e("Obunga", 10000, 1802, 4639); combatLogic(player, e); }
        else if (select == "17") { Entity e("Sanic", 16000, 2402, 6039); combatLogic(player, e); }
        else if (select == "18") { Entity e("Armstrong", 25000, 3402, 10639); combatLogic(player, e); }
        else if (select == "19") { Entity e("Unknown", 43000, 6402, 22639); combatLogic(player, e); }
        else if (select == "20") { Entity e("Engineergaming", 80000, 10402, 42639); combatLogic(player, e); }
        else if (select == "21") { Entity e("Partygoers =)", 122000, 14092, 82639); combatLogic(player, e); }
        else if (select == "22") { Entity e("Hounds", 177000, 20402, 122639); combatLogic(player, e); }
        else if (select == "23") { Entity e("Deathmoths", 207000, 31402, 144639); combatLogic(player, e); }
        else if (select == "24") { Entity e("Facelings", 230000, 40402, 182639); combatLogic(player, e); }
        else if (select == "25") { Entity e("Howlers", 260000, 50402, 222639); combatLogic(player, e); }
        else if (select == "26") { Entity e("The Shaper of Reality", 337000, 72142, 332639); combatLogic(player, e); }
        else if (select == "27") { Entity e("Scarlet King", 400000, 81402, 382639); combatLogic(player, e); }
        else if (select == "28") { Entity e("G-Man", 470090, 100402, 432639); combatLogic(player, e); }
        else if (select == "29") { Entity e("Magnetar", 500000, 201402, 802639); combatLogic(player, e); }
        else if (select == "30") { Entity e("TON 618", 70000000, 16000, 52000000); combatLogic(player, e); }
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
    isMonitoring = true;
    isManyWorldAnnouncements = true;
    std::thread cheatWatcher(antiCheatScanner, std::ref(steve));
    std::thread world(worldAnnouncements, std::ref(isManyWorldAnnouncements));
    cheatWatcher.detach();
    world.detach();
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
        	while(true) {
        		std::string select;
        		std::cout << "Do you really want to quit the game? ( Y/n )" << std::endl;
        		std::cout << "Enter a number or letter to select: " << std::endl;
        		std::cin >> select;
        		if (select == "Y" || select == "y") {
					saveGame(steve, inspectLargeShips);
        	    	exit(0);
          	  }
        	    else if (select == "N" || select == "n") {
            		break;
          	  }
          	  else { std::cout << "Error, please re-enter!" << std::endl;}
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
#endif