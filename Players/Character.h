#pragma once
#include <string>
using std::string;

class Player; // pre declaring to solve include cycle instead of include
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
public:
    Responsible();
    ~Responsible() override = default;
    unsigned int maxBuyablePotions(const Player& player) const override;
};

class RiskTaking : public Character {
public:
    RiskTaking();
    ~RiskTaking() override = default;
    unsigned int maxBuyablePotions(const Player& player) const override;
};