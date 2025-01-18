
#include "Character.h"
#include "Player.h" // here instead of at header to prevent cycle

const unsigned int POTION_PRICE = 5;
const unsigned int POTION_HEAL = 10;
const unsigned int RISKY_HEAL_THRESHOLD = 50;

unsigned int Character::computeHpToHeal(const Player& player) {
    unsigned int playerMaxHp = player.statsManager->getMaxHp();
    unsigned int playerCurrentHp = player.statsManager->getCurrentHp();
    return playerMaxHp - playerCurrentHp;
}

string Character::getBehavior() const {
    return this->behavior;
}

unsigned int Responsible::maxBuyablePotions(const Player &player) const {
    unsigned int hpToHeal = computeHpToHeal(player);
    unsigned int hpBottleneck = (hpToHeal % POTION_HEAL != 0) ? ((hpToHeal / POTION_HEAL) + 1) : (hpToHeal / POTION_HEAL);
    unsigned int coinBottleneck = player.statsManager->getCoins() / POTION_PRICE;
    return (coinBottleneck > hpBottleneck) ? (hpBottleneck) : (coinBottleneck);

}

unsigned int RiskTaking::maxBuyablePotions(const Player &player) const {
    if (player.statsManager->getCurrentHp() == player.statsManager->getMaxHp())
        return 0;
    if (player.statsManager->getCurrentHp() < RISKY_HEAL_THRESHOLD && player.statsManager->getCoins() >= POTION_PRICE)
        return 1;
    return 0;
}