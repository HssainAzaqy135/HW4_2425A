#pragma once
#include <string>


class PlayerStatsManager {
private:
        // ----------- Constants ------------
        static const unsigned int INIT_MAX_HP = 100;
        static const unsigned int INIT_LVL = 1;
        static const unsigned int INIT_FORCE = 5;
        static const unsigned int INIT_COINS = 10;
        // ----------------------------------
        std::string name;
        unsigned int maxHp = INIT_MAX_HP;
        unsigned int currentHp = INIT_MAX_HP;
        bool isAwake = true; // inverting this for isKnockedOut()
        unsigned int level = INIT_LVL;
        unsigned int force = INIT_FORCE;
        unsigned int coins = INIT_COINS;
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

