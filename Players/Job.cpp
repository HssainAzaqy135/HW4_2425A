
#include "Job.h"

// add const
// magic numbers

string Job::getJob() const {
    return this->jobName;
}

unsigned int Job::computeCombatPower(Player& player) const {
    return player.statsManager->getForce() + player.statsManager->getLevel();
}

unsigned int Warrior::computeCombatPower(Player& player) const {
    return Job::computeCombatPower(player) + player.statsManager->getForce();
}

void Warrior::postBattleImplications(Player& player) const {
    player.statsManager->takeDamage(10);
}

void Warrior::startGameAttributes(Player& player) const {
    player.statsManager->setMaxHp(150);
}

void Archer::startGameAttributes(Player& player) const {
    player.statsManager->gainCoinsBy(10);
}