#include "Job.h"
#include "Player.h"


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
    player.statsManager->takeDamage(Warrior::winPenalty);
}

void Warrior::startGameAttributes(Player& player) const {
    player.statsManager->setMaxHp(Warrior::initialHp);
}

void Archer::startGameAttributes(Player& player) const {
    player.statsManager->gainCoinsBy(Archer::addedCoins);
}