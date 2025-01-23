
#pragma once

#include <string>
#include <stdexcept>
#include <memory>
#include "PlayerStatsManager.h"
#include "Character.h"
#include "Job.h"

using std::string;
using std::unique_ptr;

class Player {

public:
    static const unsigned int POTION_PRICE = 5;
    static const unsigned int POTION_HEAL = 10;
    static const unsigned int RISKY_HEAL_THRESHOLD = 50;

    static const int maxPlayerLevel = 10;
    // ---------------- Public fields -----------------------------------
    string name;
    unique_ptr<PlayerStatsManager> statsManager;
    unique_ptr<Character> character;
    unique_ptr<Job> job;
    // ---------------- Constructors and destructors --------------------

    Player(const string name, unique_ptr<Job> job, unique_ptr<Character> character); // Assume inputs are valid at this stage
    ~Player() = default;
    Player() = delete;

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
