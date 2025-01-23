
#include "MonsterStatsManager.h"

MonsterStatsManager::MonsterStatsManager(unsigned int CombatPower, unsigned int Loot, unsigned int Damage) :
        combatPower(CombatPower), loot(Loot), damage(Damage)
{}

unsigned int MonsterStatsManager::getCombatPower() const {
    return this->combatPower;
}

unsigned int MonsterStatsManager::getLoot() const {
    return this->loot;
}

unsigned int MonsterStatsManager::getDamage() const {
    return this->damage;
}

void MonsterStatsManager::setCombatPower(unsigned int value) {
    this->combatPower = value;
}

void MonsterStatsManager::setLoot(unsigned int value) {
    this->loot = value;
}

void MonsterStatsManager::setDamage(unsigned int value) {
    this->damage = value;
}




