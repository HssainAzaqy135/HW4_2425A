//
// Created by areg1 on 1/23/2025.
//

#include "ItemFactory.h"
// Player Making

using std::find;

bool ItemFactory::playerParametersCheck(string name, string job, string character) const {
    // name check
    if(name.length() < MIN_PLAYER_NAME_LEN || name.length() > MAX_PLAYER_NAME_LEN)
    {
        return false;
    }
    // job check
    if(jobMakingFunctions.find(job) != jobMakingFunctions.end()) {
        return false;
    }
    // character check
    if(characterMakingFunctions.find(character) != characterMakingFunctions.end()) {
        return false;
    }
    return true;
}

std::vector<unique_ptr<Player>> ItemFactory::createPlayers(istream &playersStream) const {
    std::vector<unique_ptr<Player>> players;
    string playerName;
    string characterName;
    string jobName;
    playersStream >> playerName;
    while(playerName.data()) {
        playersStream >> jobName;
        playersStream >> characterName;
        if(!playerParametersCheck(playerName, jobName, characterName)) {
            throw std::runtime_error("Invalid Players File");
        }
        // All valid, now make stuff
        std::unique_ptr<Job> job = jobMakingFunctions.at(jobName)();
        std::unique_ptr<Character> character = characterMakingFunctions.at(characterName)();
        players.push_back(std::make_unique<Player>(playerName, std::move(job), std::move(character)));
        // next name
        playersStream >> playerName;
    }
    // Check if too many players
    if(players.size() < MIN_PLAYERS || players.size() > MAX_PLAYERS) {
        throw std::runtime_error("Invalid Players File");
    }

    return players;
}

// Event Making
std::vector<unique_ptr<Event>> ItemFactory::createEvents(istream &eventsStream) const {
    std::vector<unique_ptr<Event>> events;
    string eventName;
    eventsStream >> eventName;
    while (eventName.data()) {
        if (specialEventsMap.find(eventName) == specialEventsMap.end()) { //encounter
            std::unique_ptr<Monster> monster_ptr = monstersMap.at(eventName)(eventsStream);
            events.push_back(std::make_unique<Encounter>(std::move(monster_ptr)));
        } else {
            events.push_back(specialEventsMap.at(eventName)());
        }

        eventsStream >> eventName;
    }
    if(events.size() < MIN_EVENTS_NUM){
        throw std::runtime_error("Invalid Events File");
    }
    return events;
}

std::unique_ptr<Monster> ItemFactory::makePack(istream &stream) {
    std::vector<std::unique_ptr<Monster>> monstersVector;
    //validity check
    unsigned int size;
    string sizeStr;
    stream >> sizeStr;
    try{
        size = std::stoi(sizeStr);
    }catch(...){
        throw std::runtime_error("Invalid Events File");
    }
    if(size <= MIN_PACK_SIZE){
        throw std::runtime_error("Invalid Events File");
    }
    // ALL good, make the pack
    string currMonsterName;
    for (int i = 0; i < size; ++i) {
        stream >> currMonsterName;
        if(!currMonsterName.data()){
            throw std::runtime_error("Invalid Events File");
        }else{
            monstersVector.push_back(monstersMap.at(currMonsterName)(stream));
        }
    }

    return std::make_unique<Pack>(std::move(monstersVector));
}
