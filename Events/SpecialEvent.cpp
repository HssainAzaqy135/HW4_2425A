
#include "SpecialEvent.h"

string SpecialEvent::getDescription() const {
    return this->description;
}

string SolarEclipse::playEvent(Player &player) {
    int effect;
    // player.job.handleSolarEclipseEvent()

    return getSolarEclipseMessage(player, effect);
}

string PotionsMerchant::playEvent(Player &player) {
    unsigned int amount = player.character->maxBuyablePotions(player);
    for (unsigned int i = 0; i < amount; i++) {
        player.statsManager->payCoins(Player::POTION_PRICE);
        player.statsManager->gainCurrentHpBy(Player::POTION_HEAL);
    }

    return getPotionsPurchaseMessage(player, amount);
}
