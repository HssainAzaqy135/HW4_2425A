
#include "Monster.h"

unsigned int Monster::getCombatPower() const{
    return this->statsManager->getCombatPower();
}

unsigned int Monster::getLoot() const {
    return this->statsManager->getLoot();
}

unsigned int Monster::getDamage() const{
    return this->statsManager->getDamage();
}
std::string Monster::getName() const {
    return this->Name;
}
void Monster::applyPostEncounterChanges() {

}

Monster::Monster(unsigned int CombatPower, unsigned int Loot, unsigned int Damage)
        : statsManager(std::make_unique<MonsterStatsManager>(CombatPower, Loot, Damage)) {}

// Specific implementations
unsigned int Balrog::getCombatPower() const  {
    return Balrog::BALROG_COMBAT_POWER + this->num_encounters * Balrog::BALROG_STRENGTH_MULTIPLIER;
}
void Balrog::applyPostEncounterChanges() {
    this->num_encounters += 1;
}

unsigned int Pack::getCombatPower() const {
    unsigned int total_combatPower = 0;
    for (const std::unique_ptr<Monster> &monster : this->packMonsters) {
        total_combatPower += monster->getCombatPower();
    }
    return total_combatPower;
}

unsigned int Pack::getLoot() const {
    unsigned int total_loot = 0;
    for (const std::unique_ptr<Monster> &monster : this->packMonsters) {
        total_loot += monster->getLoot();
    }
    return total_loot;
}

unsigned int Pack::getDamage() const {
    unsigned int total_damage = 0;
    for (const std::unique_ptr<Monster> &monster : this->packMonsters) {
        total_damage += monster->getDamage();
    }
    return total_damage;
}

void Pack::applyPostEncounterChanges() {
    for (const std::unique_ptr<Monster> &monster : this->packMonsters) {
        monster->applyPostEncounterChanges();
    }
}

unsigned int Pack::getPackSize() const {
    unsigned int total_pack_size = this->packMonsters.size();
    return total_pack_size;
}

Pack::Pack(std::vector<std::unique_ptr<Monster>> monsters) :Monster(0,0,0),
packMonsters(std::move(monsters)) {}