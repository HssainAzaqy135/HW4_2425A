
#pragma once

#include "Events/ItemFactory.h"
#include "Players/Player.h"
#include "Events/Event.h"
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::vector;

class MatamStory{
private:
    unsigned int m_turnIndex;
    vector<shared_ptr<Player>> players;
    vector<unique_ptr<Event>> events;
    vector<unique_ptr<Event>>::iterator currentEvent;
    unique_ptr<ItemFactory> factory;
    void printSortedLeaderBoardEntries() const;
    vector<shared_ptr<Player>> getSortedPlayers() const;
    /**
     * Playes a single turn for a player
     *
     * @param player - the player to play the turn for
     *
     * @return - void
    */
    void playTurn(Player& player);

    /**
     * Plays a single round of the game
     *
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     *
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

public:
    /**
     * Constructor of MatamStory class
     *
     * @param eventsStream - events input stream (file)
     * @param playersStream - players input stream (file)
     *
     * @return - MatamStory object with the given events and players
     *
    */
    MatamStory(std::istream& eventsStream, std::istream& playersStream);

    /**
     * Plays the entire game
     *
     * @return - void
    */
    void play();
};
