
#include "MatamStory.h"
#include "Utilities.h"

MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {
    this->factory = std::make_unique<ItemFactory>();

    /*===== TODO: Open and read events file =====*/
    try {
        this->events = factory->createEvents(eventsStream);
    } catch (...) {
        throw std::runtime_error("Invalid Events File");
    }
    /*==========================================*/

    /*===== TODO: Open and Read players file =====*/
    try {
        this->players = factory->createPlayers(playersStream);
    } catch (...) {
        throw std::runtime_error("Invalid Players File");
    }
    this->currentEvent = this->events.begin(); // to be cyclically reset to events. begin when reaching end
    /*============================================*/

    this->m_turnIndex = 1;
}

void MatamStory::playTurn(Player& player) {

    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Get the next event from the events list
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the event
     * 4. Print the turn outcome with "printTurnOutcome"
    */

    printTurnDetails(m_turnIndex,player,*(*(this->currentEvent)));
    string eventOutcome = (*(this->currentEvent))->playEvent(player);
    // ----------------
    this->currentEvent++;
    if (this->currentEvent == events.end()) {
        this->currentEvent = events.begin();
    }
    m_turnIndex++;
}

// helpers for play round
bool playersOrder(Player& player1, Player& player2) {
    // TODO: Implement
    return true;
}

void MatamStory::printSortedLeaderBoardEntries() const {
    vector<shared_ptr<Player>> sortedPlayers;
    // copying and sorting , can't sort locally since it would change players turns
    for (const shared_ptr<Player> &player : players) {
        sortedPlayers.push_back(player);
    }
    std::sort(sortedPlayers.begin(), sortedPlayers.end(), playersOrder);
    for (size_t i = 0; i < sortedPlayers.size(); ++i) {
        printLeaderBoardEntry(i + 1, *sortedPlayers[i]);
    }

}
void MatamStory::playRound() {

    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/
    for(shared_ptr<Player> player: this->players) {
        if(!player->statsManager->isKnockedOut()) {
            playTurn(*player);
        }else {
            continue;
        }
    }
    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();

    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/
    // sort players by condition and print entries
    this->printSortedLeaderBoardEntries();
    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const {
    /*===== TODO: Implement the game over condition =====*/
    return false; // Replace this line
    /*===================================================*/
}

void MatamStory::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/

    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/

    /*========================================================================*/
}
