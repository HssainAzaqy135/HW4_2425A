
#include "Encounter.h"

string Encounter::getDescription() const {
    return this->monster->getEncounterString();
}

string Encounter::playEvent(Player &player) {
    unsigned int playerCombatPower = player.job->computeCombatPower(player);
    unsigned int monsterCombatPower = this->monster->getCombatPower();
    string retString;
    if (playerCombatPower <= monsterCombatPower) {
        player.statsManager->takeDamage(this->monster->getDamage());
        retString = getEncounterLostMessage(player, this->monster->getDamage());
    } else {
        player.statsManager->gainCoinsBy(this->monster->getLoot());
        player.statsManager->levelUp();
        player.job->postWinImplications(player);
        retString = getEncounterWonMessage(player, this->monster->getLoot());
    }
    this->monster->applyPostEncounterChanges();
    return retString;
}

