#pragma once
#include <string>

const unsigned int MAX_HP = 100;

// do this later...

class PlayerStatsManager {
private:
        std::string name;
        unsigned int maxHp = MAX_HP;
        unsigned int currentHp = maxHp;
        bool isAwake = true; // inverting this for isKnockedOut()
        unsigned int level = 1;
        unsigned int force = 5;
        unsigned int coins = 10;
public:
        // Constructors and destructors
        PlayerStatsManager(std::string playerName): name(playerName) {} // Don't need const here because name is taken by value
        PlayerStatsManager() = delete; // can't init this with no name
        ~PlayerStatsManager() = default; // should work like this, no dynamic allocations

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

