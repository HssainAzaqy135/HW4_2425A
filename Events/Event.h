
#pragma once

#include "Monster.h"
#include "../Players/Player.h"
// #include "../Utilities.h" //can't include here? add to all subclasses?

class Event {
public:
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    virtual ~Event() = default;
    virtual string getDescription() const = 0;
    virtual string playEvent(Player& player) = 0;

};


