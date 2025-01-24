//
// Created by areg1 on 1/23/2025.
//
#pragma once

#include <memory>
#include "../Players/Player.h"
#include "../Players/Character.h"
#include "../Players/Job.h"
#include "Monster.h"
#include "Encounter.h"
#include "SpecialEvent.h"

// Include for mapping strings to constructors
#include <algorithm>
#include <unordered_map>
#include <functional>


using std::unique_ptr;
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
    const std::unordered_map<std::string, std::function<std::unique_ptr<Job>()>> jobMakingFunctions = {
        {"Warrior", []() { return std::make_unique<Warrior>(); }},
        {"Magician", []() { return std::make_unique<Magician>(); }},
        {"Archer", []() { return std::make_unique<Archer>(); }}
    };
    const std::unordered_map<std::string, std::function<std::unique_ptr<Character>()>> characterMakingFunctions = {
        {"Responsible", []() { return std::make_unique<Responsible>(); }},
        {"RiskTaking", []() { return std::make_unique<RiskTaking>(); }}
    };


    static const unsigned int MIN_EVENTS_NUM = 2;
    static const unsigned int MIN_PACK_SIZE = 2;

    std::unique_ptr<Monster> makePack(std::istream &stream);
    const std::unordered_map<std::string, std::function<std::unique_ptr<Event>()>> specialEventsMap = {
        {"SolarEclipse", []() { return std::make_unique<SolarEclipse>(); }},
        {"PotionsMerchant", []() { return std::make_unique<PotionsMerchant>(); }},
    };

    const std::unordered_map<std::string, std::function<std::unique_ptr<Monster>(std::istream &)>> monstersMap = {
        {"Snail", [](std::istream &) { return std::make_unique<Snail>(); }},
        {"Slime", [](std::istream &) { return std::make_unique<Slime>(); }},
        {"Balrog", [](std::istream &) { return std::make_unique<Balrog>(); }},
        {"Pack", [](std::istream &stream) { return makePack(stream);/* special case, need the rest of the stream */ }}
    };
public:
    ItemFactory() = default;
    ~ItemFactory() = default;

    // Creation functions
    std::vector<unique_ptr<Player>> createPlayers(istream& playersStream) const;
    std::vector<unique_ptr<Event>> createEvents(istream& eventsStream) const;
};

