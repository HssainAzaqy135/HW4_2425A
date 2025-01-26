
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
    if(jobMakingFunctions.find(job) == jobMakingFunctions.end()) { // changed to ==, was !=, I think that was a mistake, not sure
        return false;
    }
    // character check
    if(characterMakingFunctions.find(character) == characterMakingFunctions.end()) { // same here
        return false;
    }
    return true;
}

std::vector<shared_ptr<Player>> ItemFactory::createPlayers(istream &playersStream) const {
    std::vector<shared_ptr<Player>> players;
    string playerName;
    string characterName;
    string jobName;
    while(playersStream >> playerName >> jobName >> characterName) { // fixed this issue (we didn't include <iostream> hehe...)
        if(!playerParametersCheck(playerName, jobName, characterName)) {
            throw std::runtime_error("Invalid Players File");
        }
        // All valid, now make stuff
        std::unique_ptr<Job> job = jobMakingFunctions.at(jobName)();
        std::unique_ptr<Character> character = characterMakingFunctions.at(characterName)();
        players.push_back(std::make_shared<Player>(playerName, std::move(job), std::move(character)));
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

    while (eventsStream >> eventName) {
        if (specialEventsMakingFunctions.find(eventName) == specialEventsMakingFunctions.end()) { //encounter
            std::unique_ptr<Monster> monster_ptr = monstersMakingFunctions.at(eventName)(eventsStream);
            events.push_back(std::make_unique<Encounter>(std::move(monster_ptr)));
        } else {
            events.push_back(specialEventsMakingFunctions.at(eventName)());
        }
    }
    if(events.size() < MIN_EVENTS_NUM){
        throw std::runtime_error("Invalid Events File");
    }
    return events;
}

std::unique_ptr<Monster> ItemFactory::makePack(istream &stream) const {
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
    if(size < MIN_PACK_SIZE){
        throw std::runtime_error("Invalid Events File");
    }
    // ALL good, make the pack
    string currMonsterName;
    for (unsigned int i = 0; i < size; ++i) {
        stream >> currMonsterName;
        if(currMonsterName.empty()){ // changed this as well
            throw std::runtime_error("Invalid Events File");
        }else{
            monstersVector.push_back(monstersMakingFunctions.at(currMonsterName)(stream));
        }
    }
    return std::make_unique<Pack>(std::move(monstersVector));
}
