#include "manager.h"
Entity::Entity(): name("Unk"), health(0), damage(0), price(0) {}
Entity::Entity(const std::string& _name, long long _health, long long _damage, long long _price): name(_name), health(_health), damage(_damage), price(_price) {}
void Entity::adjust(long long val, common_attribute_id id) {
    if (val > 999999999999999) {
        val = 999999999999999;
    }
    if (id > PRICE) {
        return;
    }
    if (id == NAME) {
        return;
    }
    else if (id == HEALTH) {
        health += val;
    }
    else if (id == DAMAGE) {
        damage += val;
    }
    else if (id == PRICE) {
        price += val;
    }
}
void Entity::set(long long val, common_attribute_id id) {
    if (val > 999999999999999) val = 999999999999999;
    if (id > PRICE) return;
    if (id == NAME) return;
    else if (id == HEALTH) health = val;
    else if (id == DAMAGE) damage = val;
    else if (id == PRICE) price = val;
}
void Entity::set_up_name(std::string& _name) {
    name = _name;
}
long long Entity::get(common_attribute_id id) const {
    if (id > PRICE) return -1;
    if (id == NAME) return -1;
    else if (id == HEALTH) return health;
    else if (id == DAMAGE) return damage;
    else if (id == PRICE) return price;
}
std::string Entity::get_name() const {
    return name;
}
Entity::~Entity() {}

Player::Player(): Entity(), money(0), maximum_health(0) {}
Player::Player(const std::string& _name, long long _health, long long _damage, long long _money): Entity(_name, _health, _damage, 0), money(_money), maximum_health(_health) {}
void Player::adjust(long long val, common_attribute_id id) {
    if (val > 999999999999999) {
        val = 999999999999999;
    }
    if (id > MAXIMUM_HEALTH) {
        return;
    }
    if (id == NAME) {
        return;
    }
    else if (id == MONEY) {
        money += val;
    }
    else if (id == MAXIMUM_HEALTH) {
        maximum_health += val;
    }
    else {
        Entity::adjust(val, id);
    }
}
void Player::set(long long val, common_attribute_id id) {
    if (val > 999999999999999) val = 999999999999999;
    if (id > MAXIMUM_HEALTH) return;
    if (id == NAME) return;
    else if (id == MONEY) money = val;
    else if (id == MAXIMUM_HEALTH) maximum_health = val;
    else {
        Entity::set(val, id);
    }
}
void Player::set_up_name(std::string& _name) {
    name = _name;
}
long long Player::get(common_attribute_id id) const {
    if (id > MAXIMUM_HEALTH) return -1;
    if (id == NAME) return -1;
    else if (id == MONEY) return money;
    else if (id == MAXIMUM_HEALTH) return maximum_health;
    else {
        return Entity::get(id);
    }
}
std::string Player::get_name() const {
    return name;
}
void Player::entity_is_dead(Entity* entity) {
    if(entity->get(HEALTH) <= 0) {
        this->adjust(entity->get(PRICE), MONEY);
    }
}
std::string* deep_intervention(Entity* object) {
    return &((*object).name);
}