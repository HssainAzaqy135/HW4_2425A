
#pragma once

class MonsterStatsManager {
    unsigned int combatPower;
    unsigned int loot;
    unsigned int damage;

public:
    ~MonsterStatsManager() = default;
    MonsterStatsManager(unsigned int CombatPower, unsigned int Loot, unsigned int Damage);
    unsigned int getCombatPower() const;
    unsigned int getLoot() const;
    unsigned int getDamage() const;

    void setCombatPower(unsigned int value);
    void setLoot(unsigned int value);
    void setDamage(unsigned int value);
};