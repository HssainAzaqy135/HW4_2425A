//
// Created by areg1 on 1/23/2025.
//
#pragma once

#include "../Players/Player.h"
#include "../Players/Character.h"
#include "../Players/Job.h"
#include "../Players/OurExceptions.h"
#include "Monster.h"
#include "Encounter.h"
#include "SpecialEvent.h"

// Include for mapping strings to constructors
#include <iostream>
#include <memory>
#include <algorithm>
#include <map>
#include <functional>
#include <cctype>

using std::unique_ptr;
using std::shared_ptr;
using std::string;
using std::istream;
using std::vector;

class ItemFactory {
private:
    const unsigned int MIN_PLAYER_NAME_LEN = 3;
    const unsigned int MAX_PLAYER_NAME_LEN = 15;

    const unsigned int MIN_PLAYERS = 2;
    const unsigned int MAX_PLAYERS = 6;
    bool playerParametersCheck(string name,string job, string character)const;
    const std::map<std::string, std::function<std::unique_ptr<Job>()>> jobMakingFunctions = {
        {"Magician", []() { return std::make_unique<Magician>(); }},
        {"Archer", []() { return std::make_unique<Archer>(); }},
        {"Warrior", []() { return std::make_unique<Warrior>(); }}
    };
    const std::map<std::string, std::function<std::unique_ptr<Character>()>> characterMakingFunctions = {
        {"Responsible", []() { return std::make_unique<Responsible>(); }},
        {"RiskTaking", []() { return std::make_unique<RiskTaking>(); }}
    };


    static const unsigned int MIN_EVENTS_NUM = 2;
    static const unsigned int MIN_PACK_SIZE = 2;

    std::unique_ptr<Monster> makePack(istream &stream) const;
    const std::map<std::string, std::function<std::unique_ptr<Event>()>> specialEventsMakingFunctions = {
        {"SolarEclipse", []() { return std::make_unique<SolarEclipse>(); }},
        {"PotionsMerchant", []() { return std::make_unique<PotionsMerchant>(); }},
    };

    const std::map<std::string, std::function<std::unique_ptr<Monster>(istream &)>> monstersMakingFunctions = {
        {"Snail", [](istream &) { return std::make_unique<Snail>(); }},
        {"Slime", [](istream &) { return std::make_unique<Slime>(); }},
        {"Balrog", [](istream &) { return std::make_unique<Balrog>(); }},
        {"Pack", [this](istream &stream) { return makePack(stream);/* special case, need the rest of the stream */ }}
    };
public:
    ItemFactory() = default;
    ~ItemFactory() = default;

    // Creation functions
    std::vector<shared_ptr<Player>> createPlayers(istream& playersStream) const;
    std::vector<unique_ptr<Event>> createEvents(istream& eventsStream) const;
};

