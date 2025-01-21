#include "Job.h"
#include "Player.h"


string Job::getJob() const {
    return this->jobName;
}

unsigned int Job::computeCombatPower(Player& player) const {
    return player.statsManager->getForce() + player.statsManager->getLevel();
}

unsigned int Warrior::computeCombatPower(Player& player) const {
    return Job::computeCombatPower(player) + player.statsManager->getForce() * Warrior::FORCE_MULT;
}

void Warrior::postBattleImplications(Player& player) const {
    player.statsManager->takeDamage(Warrior::WIN_PENALTY);
}

void Warrior::startGameAttributes(Player& player) const {
    player.statsManager->setMaxHp(Warrior::INITIAL_HP);
    player.statsManager->setCurrentHp(Warrior::INITIAL_HP);
}

void Archer::startGameAttributes(Player& player) const {
    player.statsManager->gainCoinsBy(Archer::ADDED_COINS);
}