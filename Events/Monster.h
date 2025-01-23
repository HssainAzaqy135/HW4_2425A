#pragma once
#include <memory>
#include <vector>
#include <string>

#include "MonsterStatsManager.h"

class Monster {

protected:
    std::unique_ptr<MonsterStatsManager> statsManager;
    std::string Name;

    Monster(unsigned int CombatPower, unsigned int Loot, unsigned int Damage);


public:
    virtual ~Monster() = default;

    virtual unsigned int getCombatPower() const;
    virtual unsigned int getLoot() const;
    virtual unsigned int getDamage() const;
    virtual void applyPostEncounterChanges();
    std::string getName() const;
};

class Snail : public Monster {
protected:
    // snail stats
    static const unsigned int SNAIL_COMBAT_POWER = 5;
    static const unsigned int SNAIL_LOOT = 2;
    static const unsigned int SNAIL_DAMAGE = 10;

    std::string Name = "Snail";
public:
    Snail() : Monster(SNAIL_COMBAT_POWER, SNAIL_LOOT, SNAIL_DAMAGE) {};

};

class Slime : public Monster {
protected:
    // slime stats
    static const unsigned int SLIME_COMBAT_POWER = 12;
    static const unsigned int SLIME_LOOT = 5;
    static const unsigned int SLIME_DAMAGE = 25;

    std::string Name = "Slime";
public:
    Slime() : Monster(SLIME_COMBAT_POWER, SLIME_LOOT, SLIME_DAMAGE) {};

};

class Balrog : public Monster {
protected:
    // balrog stats
    static const unsigned int BALROG_COMBAT_POWER = 15;
    static const unsigned int BALROG_LOOT = 100;
    static const unsigned int BALROG_DAMAGE = 9001;
    static const unsigned int BALROG_STRENGTH_MULTIPLIER = 2;

    std::string Name = "Balrog";
    unsigned int num_encounters = 0;
public:
    Balrog() : Monster(BALROG_COMBAT_POWER, BALROG_LOOT, BALROG_DAMAGE) {};
    unsigned int getCombatPower() const override;
    void applyPostEncounterChanges() override;
};

class Pack : public Monster {
protected:
    std::string Name = "Pack";
    std::vector<std::unique_ptr<Monster>> packMonsters;
public:
    Pack(std::vector<std::unique_ptr<Monster>> monsters);

    unsigned int getCombatPower() const override;
    unsigned int getLoot() const override;
    unsigned int getDamage() const override;
    void applyPostEncounterChanges() override;
    unsigned int getPackSize() const;
};