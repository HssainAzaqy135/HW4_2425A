
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
unsigned int Monster::MonsterCount() const {
    return 1; //base behaviour for a non pack monster
}

std::string Monster::formatStatsHelper(unsigned int CombatPower, unsigned int Loot, unsigned int Damage) {
    std::string monsterStats = "(power " + std::to_string(CombatPower) +
                               ", loot " + std::to_string(Loot) +
                               ", damage " + std::to_string(Damage) + ")";
    return monsterStats;
}

Monster::Monster(unsigned int CombatPower, unsigned int Loot, unsigned int Damage,std::string name)
        : statsManager(std::make_unique<MonsterStatsManager>(CombatPower, Loot, Damage)), Name(name) {}

std::string Monster::getEncounterString() const {
    std::string retString;
    std::string statsString = Monster::formatStatsHelper(this->getCombatPower(),
                                                         this->statsManager->getLoot(),this->statsManager->getDamage());
    retString = this->getName() + " " + statsString;
    return  retString;
}

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

unsigned int Pack::MonsterCount() const {
    unsigned int total_pack_size = 0;
    for (const std::unique_ptr<Monster> &monster : this->packMonsters) {
        total_pack_size += monster->MonsterCount();
    }
    return total_pack_size;
}

Pack::Pack(std::vector<std::unique_ptr<Monster>> monsters) :Monster(0,0,0,"Pack")//not relevant here
,packMonsters(std::move(monsters)) {
}

std::string Pack::getEncounterString() const {
    std::string retString;
    std::string statsString = Monster::formatStatsHelper(this->getCombatPower(), this->getLoot(), this->getDamage());
    std::string packAddedString = "of " + std::to_string(this->MonsterCount()) + " " + "members";
    retString = this->getName() + " " + packAddedString + " " + statsString;
    return retString;
}
