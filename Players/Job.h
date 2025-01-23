#pragma once

#include <string>

class Player;
using std::string;

class Job {
private:
    string jobName;
public:
    Job(const string& name) : jobName(name) {}
    virtual ~Job() = default;

    string getJob() const;
    virtual unsigned int computeCombatPower(Player& player) const;
    virtual void postWinImplications(Player& player) const {};
    virtual void startGameAttributes(Player& player) const {};
};

class Warrior : public Job {
    string jobName;
    static const unsigned int INITIAL_HP = 150;
    static const unsigned int WIN_PENALTY = 10;
    static const unsigned int FORCE_MULT = 2;
public:
    // ------------------ Constructors -----------------------
    Warrior() : Job("Warrior") {}
    // ------------------ Methods ----------------------------
    unsigned int computeCombatPower(Player& player) const override;
    void postWinImplications(Player& player) const override;
    void startGameAttributes(Player& player) const override;
};

class Archer : public Job {
    string jobName;
    static const unsigned int ADDED_COINS = 10;
public:
    // ------------------ Constructors -----------------------
    Archer() : Job("Archer") {}
    // ------------------ Methods ----------------------------
    void startGameAttributes(Player& player) const override;
};

class Magician : public Job {
    string jobName;
public:
    // ------------------ Constructors -----------------------
    Magician() : Job("Magician") {}
    // Effectively default
};