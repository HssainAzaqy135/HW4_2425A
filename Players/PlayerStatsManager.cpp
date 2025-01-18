#include "PlayerStatsManager.h"

#include <stdexcept>

//  ------------------- getters and setters --------------------------
std::string PlayerStatsManager::getName() const {
    return this->name;
}
unsigned int PlayerStatsManager::getMaxHp() const {
    return this->maxHp;
}
void PlayerStatsManager::setMaxHp(unsigned int new_maxHp) {
    this->maxHp = new_maxHp;
    this->setCurrentHp(this->getCurrentHp());//clamping with min in the setter
}
unsigned int PlayerStatsManager::getCurrentHp() const {
    return this->currentHp;
}
void PlayerStatsManager::setCurrentHp(unsigned int hp) {
    this->currentHp = (this->maxHp < hp) ? this->maxHp : hp;
    if (this->currentHp == 0) {
        this->playerKnockedOut();
    }
}
bool PlayerStatsManager::isKnockedOut() const {
    return !(this->isAwake);
}
unsigned int PlayerStatsManager::getLevel() const {
    return this->level;
}
unsigned int PlayerStatsManager::getForce() const {
    return this->force;
}
unsigned int PlayerStatsManager::getCoins() const {
    return this->coins;
}
//------------------- Modifiers ------------------------

void PlayerStatsManager::gainCurrentHpBy(unsigned int amount) {
    this->setCurrentHp(this->getCurrentHp() + amount);
}
void PlayerStatsManager::gainForceBy(unsigned int amount) {
    this->force = this->force + amount; // no setter here
}
void PlayerStatsManager::gainCoinsBy(unsigned int amount) {
    this->coins = this->coins + amount;
}

void PlayerStatsManager::takeDamage(unsigned int amount) {
    if(amount < this->currentHp) {
        this->setCurrentHp(this->getCurrentHp() - amount);
    }else {
        this->setCurrentHp(0);
        this->playerKnockedOut();
    }

}
void PlayerStatsManager::loseForceBy(unsigned int amount) { //more readable code
    this->force = (this->force < amount) ? 0 : (this->force - amount); // clamping with zero
}
void PlayerStatsManager::payCoins(unsigned int amount) {
    if(this->coins < amount) {
        //can't pay
        throw std::runtime_error("Can't pay coins");// shouldn't get here
    }else {
        this->coins -= amount;
    }
}

void PlayerStatsManager::levelUp() {
    this->level += 1;
}
void PlayerStatsManager::playerKnockedOut() {
    this->isAwake = false;
}