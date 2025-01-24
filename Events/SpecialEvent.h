#pragma once

#include "Event.h"

class SpecialEvent : public Event {
protected:
    string description;

public:
    string getDescription() const override;
};

class SolarEclipse : public SpecialEvent {
    virtual string playEvent(Player& player) override;
};

class PotionsMerchant : public SpecialEvent {

    virtual string playEvent(Player& player) override;
};
