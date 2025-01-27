#include "Job.h"
#include "Player.h"


string Job::getJob() const {
    return this->jobName;
}

unsigned int Job::computeCombatPower(Player& player) const {
    return player.statsManager->getForce() + player.statsManager->getLevel();
}

int Job::postSolarEclipseImplications(Player &player) const {
    if(player.statsManager->getForce() == 0) {
        // no force to lose, return no effect
        return 0;
    }
    player.statsManager->loseForceBy(Job::BASE_SOLAR_ECLIPSE_DEBUFF); //add const
    return -Job::BASE_SOLAR_ECLIPSE_DEBUFF;
}

unsigned int Warrior::computeCombatPower(Player& player) const {
    return player.statsManager->getLevel() + player.statsManager->getForce() * Warrior::FORCE_MULT;
}

void Warrior::postWinImplications(Player& player) const {
    player.statsManager->takeDamage(Warrior::WIN_PENALTY);
}

void Warrior::startGameAttributes(Player& player) const {
    player.statsManager->setMaxHp(Warrior::INITIAL_HP);
    player.statsManager->setCurrentHp(Warrior::INITIAL_HP);
}

void Archer::startGameAttributes(Player& player) const {
    player.statsManager->gainCoinsBy(Archer::ADDED_COINS);
}

int Magician::postSolarEclipseImplications(Player &player) const {
    if(player.statsManager->getForce() == 0) {
        // no force to lose, return no effect
        return 0;
    }
    player.statsManager->gainForceBy(Magician::MAGICIAN_SOLAR_ECLIPSE_BUFF); //add const
    return Magician::MAGICIAN_SOLAR_ECLIPSE_BUFF;
}
