
#pragma once

#include "Monster.h"
#include "../Players/Player.h"

class Event {
public:
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    string getDescription() const;
};

class Encounter : public Event {
    unique_ptr<Monster> monster;



};

