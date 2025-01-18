#pragma once

#include <string>
#include "Player.h"

using std::string;

class Job {
private:
    string jobName;

public:
    string getJob() const;
    virtual ~Job();
    virtual unsigned int computeCombatPower(Player& player) const;
    virtual void postBattleImplications() const {};
    virtual void startGameAttributes(Player& player) const {};
};

class Warrior : public Job {
public:
    unsigned int computeCombatPower(Player& player) const override;
    void postBattleImplications(Player& player) const override;
    void startGameAttributes(Player& player) const override;
};

class Archer : public Job {
public:
    void startGameAttributes(Player& player) const override;
};

class Magician : public Job {

};