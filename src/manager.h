#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <string>
class Entity
{
	protected:
		std::string name;
		int health;
		int damage;
		int price;
	public:
		Entity(const std::string &_name, int _health, int _damage, int _price) : name(_name), health(_health), damage(_damage), price(_price) {}
		/* Return method */
		std::string returnsName() const { return name; }
		int returnsHealth() const { return health; }
		int returnsDamage() const { return damage; }
		int returnsPrice() const { return price; }
		/* Setup method */
		void setName(const std::string _name) { name = _name; }
		void healthSetting(int _health) { health = _health; if (health > 999999999) { health = 999999999; }}
		void setDamage(int _damage) { damage = _damage; if (damage > 999999999) { damage = 999999999; }}
		void priceSetting(int _price) { price = _price; }
		/* Reduction method */
		void reducedHealth(int value) { health -= value; if (health < 0) { health = 0; }}
		void reductionDamage(int value) { damage -= value; if (damage < 7) { damage = 7; }}
		void reduceCost(int value) { price -= value; }
		/* Increment method */
		void increaseHealth(int value) { health += value; if (health > 999999999) { health = 999999999; }}
		void increasedDamage(int value) { damage += value; if (damage > 999999999) { damage = 999999999; }}
		void priceIncrease(int value) { price += value; }
};
class Player : public Entity
{
	private:
		int money;
		int maximumHealth;
	public:
		Player(const std::string &_name, int _health, int _damage, int _price, int _money) : Entity(_name, _health, _damage, _price), money(_money), maximumHealth(_health) {}
		void entityIsDead(Entity &entity) { if (entity.returnsHealth() <= 0) { money += entity.returnsPrice(); }}
		/* Return method */
		int returnsMoney() const { return money; }
		int returnToMaximumHealth() const { return maximumHealth; }
		/* Setup method */
		void moneySetting(int value) { money = value; if (money > 999999999) { money = 999999999; }}
		void settingMaximumHealth( int value) { maximumHealth = value; if (maximumHealth > 999999999) { maximumHealth = 999999999; }}
		/* Reduction method */
		void reduceMoney(int value) { money -= value; if (money < 0) { money = 0; }}
		/* Increment method */
		void increaseMoney(int value) { money += value; if (money > 999999999) { money = 999999999; }}
};
#endif