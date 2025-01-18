//
// Created by kingh on 18/01/2025.
//

#pragma once
#include <string>

class PlayerStatsManager {
private:
        std::string name;
        unsigned int maxHp = 100;
        unsigned int currentHp = maxHp;
        bool isAwake = true; // inverting this for isFainted()
        unsigned int level = 1;
        unsigned int force = 5;
        unsigned int coins = 10;
public:
        // Constructors and destructors
        PlayerStatsManager(std::string playerName): name(playerName) {} // Don't need const here because name is taken by value
        PlayerStatsManager() = delete; // can't init this with no name
        ~PlayerStatsManager() = delete; // should work like this, no dynamic allocations

        //getters
        std::string getName() const;

        unsigned int getLevel() const;

        unsigned int getForce() const;

        unsigned int getCurrentHp() const;

        unsigned int getMaxHp() const;

        unsigned int getCoins() const;

        bool isKnockedOut() const;

        // Setters and modifiers
        void setMaxHp(unsigned int new_maxHp);
        void setCurrentHp(unsigned int hp);

        void gainCurrentHpBy(unsigned int amount);
        void gainForceBy(unsigned int amount);
        void gainCoinsBy(unsigned int amount);

        void takeDamage(unsigned int amount);
        void loseForceBy(unsigned int amount);
        void payCoins(unsigned int amount);

        void levelUp();
        void playerKnockedOut();

};

