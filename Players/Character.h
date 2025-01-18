#pragma once
#include <string>
#include "Player.h"

using std::string;

class Character {

protected:
    string behavior;
    static unsigned int computeHpToHeal(const Player& player);

public:
    string getBehavior() const;
    virtual ~Character() = default;
    virtual unsigned int maxBuyablePotions(const Player& player) const = 0;
};

class Responsible : public Character {
    ~Responsible() override = default;
    unsigned int maxBuyablePotions(const Player& player) const override;
};

class RiskTaking : public Character {
    ~RiskTaking() override = default;
    unsigned int maxBuyablePotions(const Player& player) const override;
};