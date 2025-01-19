#pragma once
#include <memory>
#include <vector>

// snail stats
const unsigned int SNAIL_COMBAT_POWER = 5;
const unsigned int SNAIL_LOOT = 2;
const unsigned int SNAIL_DAMAGE = 10;

// slime stats
const unsigned int SLIME_COMBAT_POWER = 12;
const unsigned int SLIME_LOOT = 5;
const unsigned int SLIME_DAMAGE = 25;

// balrog stats
const unsigned int BALROG_COMBAT_POWER = 15;
const unsigned int BALROG_LOOT = 100;
const unsigned int BALROG_DAMAGE = 9001;

class Monster {

protected:
    unsigned int CombatPower;
    unsigned int Loot;
    unsigned int Damage;

    Monster(unsigned int CombatPower, unsigned int Loot, unsigned int Damage);


public:
    virtual ~Monster();

    virtual unsigned int getCombatPower();
    virtual unsigned int getLoot();
    virtual unsigned int getDamage();
};

class Snail : public Monster {
    Snail() : Monster(SNAIL_COMBAT_POWER, SNAIL_LOOT, SNAIL_DAMAGE) {};

    unsigned int getCombatPower() override;
    unsigned int getLoot() override;
    unsigned int getDamage() override;
};

class Slime : public Monster {
    Slime() : Monster(SLIME_COMBAT_POWER, SLIME_LOOT, SLIME_DAMAGE) {};

    unsigned int getCombatPower() override;
    unsigned int getLoot() override;
    unsigned int getDamage() override;
};

class Balrog : public Monster {
    Balrog() : Monster(BALROG_COMBAT_POWER, BALROG_LOOT, BALROG_DAMAGE) {};

    unsigned int getCombatPower() override;
    unsigned int getLoot() override;
    unsigned int getDamage() override;
};

class Pack : public Monster {
    std::vector<std::unique_ptr<Monster>> packMonsters;
};