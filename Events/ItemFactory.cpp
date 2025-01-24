//
// Created by areg1 on 1/23/2025.
//

#include "ItemFactory.h"
// Player Making

using std::find;

bool ItemFactory::playerParametersCheck(string name, string job, string character) const {
    // name check
    if(name.length() < 3 || name.length() > 15)
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
        playersStream>> jobName;
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

}
