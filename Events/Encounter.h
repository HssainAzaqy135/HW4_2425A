
#pragma once

#include "Event.h"

class Encounter : public Event {
    unique_ptr<Monster> monster;

public:
    Encounter() = delete;
    Encounter(unique_ptr<Monster> monster) : monster(std::move(monster)) {};
    ~Encounter() = default;

    string getDescription() const override;
    string playEvent(Player& player) override;
};

