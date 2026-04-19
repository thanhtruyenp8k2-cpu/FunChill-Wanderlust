#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <string>
#include <limits>
enum common_attribute_id {
    NAME = 0x00,
    HEALTH = 0x01,
    DAMAGE = 0x02,
    PRICE = 0x03,
    MONEY = 0x04,
    MAXIMUM_HEALTH = 0x05
};
class Entity
{
    protected:
    std::string name;
    long long health;
    long long damage;
    long long price;
    public:
    Entity();
    Entity(const std::string& _name, long long _health, long long _damage, long long _price);
    virtual void adjust(long long val, common_attribute_id id);
    virtual void set(long long val, common_attribute_id id);
    virtual void set_up_name(std::string& _name);
    virtual long long get(common_attribute_id id) const;
    virtual std::string get_name() const;
    virtual ~Entity();
    /*This function is for developers; it will be removed once the game is released!*/
    friend std::string* deep_intervention(Entity* object);

};
class Player: public Entity
{
    private:
    long long money;
    long long maximum_health;
    public:
    Player();
    Player(const std::string& _name, long long _health, long long _damage, long long _money);
    void adjust(long long val, common_attribute_id id) override;
    void set(long long val, common_attribute_id id) override;
    void set_up_name(std::string& _name) override;
    long long get(common_attribute_id id) const override;
    std::string get_name() const override;
    void entity_is_dead(Entity* entity);
};
#endif