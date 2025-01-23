
#include "Character.h"
#include "Player.h" // here instead of at header to prevent cycle

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
    unsigned int hpBottleneck = (hpToHeal % Player::POTION_HEAL != 0) ? ((hpToHeal / Player::POTION_HEAL) + 1) :
            (hpToHeal / Player::POTION_HEAL);
    unsigned int coinBottleneck = player.statsManager->getCoins() / Player::POTION_PRICE;
    return (coinBottleneck > hpBottleneck) ? (hpBottleneck) : (coinBottleneck);

}

unsigned int RiskTaking::maxBuyablePotions(const Player &player) const {
    if (player.statsManager->getCurrentHp() == player.statsManager->getMaxHp())
        return 0;
    if (player.statsManager->getCurrentHp() < Player::RISKY_HEAL_THRESHOLD && player.statsManager->getCoins() >= Player::POTION_PRICE)
        return 1;
    return 0;
}