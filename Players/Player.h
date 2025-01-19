
#pragma once

#include <string>
#include <memory>
#include "PlayerStatsManager.h"
#include "Character.h"
#include "Job.h"

using std::string;
using std::unique_ptr;

class Player {

public:
    static const int maxPlayerLevel = 10;
    // ---------------- Public fields -----------------------------------
    unique_ptr<PlayerStatsManager> statsManager; // I don't think this need to be a unique pointer.
    unique_ptr<Character> character;
    unique_ptr<Job> job; // added this, I think we forgot.
    // ---------------- Constructors and destructors --------------------

    Player(const string &name, unique_ptr<Job> job, unique_ptr<Character> character); // Assume inputs are valid at this stage
    ~Player() = default;
    void initializePlayer();



    //---------------------- Assignment methods -----------------
    /**
     * Gets the description of the player
     *
     * @return - description of the player
    */
    string getDescription() const;

    /**
     * Gets the name of the player
     *
     * @return - name of the player
    */
    string getName() const;

    /**
     * Gets the current level of the player
     *
     * @return - level of the player
    */
    int getLevel() const;

    /**
     * Gets the of force the player has
     *
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
    */
    int getHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
    */
    int getCoins() const;
};
