#pragma once
#include <memory>
#include <vector>
#include <string>

#include "MonsterStatsManager.h"

class Monster {

protected:
    static std::string formatStatsHelper(unsigned int CombatPower, unsigned int Loot, unsigned int Damage);
    std::unique_ptr<MonsterStatsManager> statsManager;
    std::string Name;

    Monster(unsigned int CombatPower, unsigned int Loot, unsigned int Damage,std::string name = "");

public:
    Monster() = delete;
    virtual ~Monster() = default;

    virtual unsigned int getCombatPower() const;
    virtual unsigned int getLoot() const;
    virtual unsigned int getDamage() const;
    virtual void applyPostEncounterChanges();

    std::string getName() const;
    virtual std::string getEncounterString() const;
    virtual unsigned int MonsterCount() const;
};

class Snail : public Monster {
protected:
    // snail stats
    static const unsigned int SNAIL_COMBAT_POWER = 5;
    static const unsigned int SNAIL_LOOT = 2;
    static const unsigned int SNAIL_DAMAGE = 10;

public:
    Snail() : Monster(SNAIL_COMBAT_POWER, SNAIL_LOOT, SNAIL_DAMAGE,"Snail") {};

};

class Slime : public Monster {
protected:
    // slime stats
    static const unsigned int SLIME_COMBAT_POWER = 12;
    static const unsigned int SLIME_LOOT = 5;
    static const unsigned int SLIME_DAMAGE = 25;

public:
    Slime() : Monster(SLIME_COMBAT_POWER, SLIME_LOOT, SLIME_DAMAGE,"Slime") {};

};

class Balrog : public Monster {
protected:
    // balrog stats
    static const unsigned int BALROG_COMBAT_POWER = 15;
    static const unsigned int BALROG_LOOT = 100;
    static const unsigned int BALROG_DAMAGE = 9001;
    static const unsigned int BALROG_STRENGTH_MULTIPLIER = 2;

    unsigned int num_encounters = 0;
public:
    Balrog() : Monster(BALROG_COMBAT_POWER, BALROG_LOOT, BALROG_DAMAGE,"Balrog") {};
    unsigned int getCombatPower() const override;
    void applyPostEncounterChanges() override;
};

class Pack : public Monster {
protected:
    std::vector<std::unique_ptr<Monster>> packMonsters;
public:
    Pack(std::vector<std::unique_ptr<Monster>> monsters);

    unsigned int getCombatPower() const override;
    unsigned int getLoot() const override;
    unsigned int getDamage() const override;
    void applyPostEncounterChanges() override;
    virtual std::string getEncounterString() const override;
    unsigned int MonsterCount() const override;
};