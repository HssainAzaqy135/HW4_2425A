
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
    this->currentEvent = this->events.begin(); // to be cyclically reset to events. begin when reaching end
    /*==========================================*/

    /*===== TODO: Open and Read players file =====*/
    try {
        this->players = factory->createPlayers(playersStream);
    } catch (...) {
        throw std::runtime_error("Invalid Players File");
    }
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
    printTurnOutcome(eventOutcome);
    // ----------------
    this->currentEvent++;
    if (this->currentEvent == events.end()) {
        this->currentEvent = events.begin();
    }
    m_turnIndex++;
}

// helpers for play round
std::vector<std::shared_ptr<Player>> MatamStory::getSortedPlayers() const {
    std::vector<std::shared_ptr<Player>> sortedPlayers = this->players;

    std::sort(sortedPlayers.begin(), sortedPlayers.end(),
        [](const std::shared_ptr<Player>& player1, const std::shared_ptr<Player>& player2) {
            if (player1->statsManager->getLevel() > player2->statsManager->getLevel()) {
                return true;
            }
            if (player1->statsManager->getLevel() < player2->statsManager->getLevel()) {
                return false;
            }
            if (player1->statsManager->getCoins() > player2->statsManager->getCoins()) {
                return true;
            }
            if (player1->statsManager->getCoins() < player2->statsManager->getCoins()) {
                return false;
            }
            return player1->getName() < player2->getName(); // strings have built in "<" operator
        });

    return sortedPlayers;
}

void MatamStory::printSortedLeaderBoardEntries() const {
    vector<shared_ptr<Player>> sortedPlayers = this->getSortedPlayers();
    for (size_t i = 0; i < sortedPlayers.size(); ++i) {
        printLeaderBoardEntry(i + 1, *(sortedPlayers[i]));
    }
}

void MatamStory::playRound() {

    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/
    for(const shared_ptr<Player>& player: this->players) { // changed to const reference to avoid copying
        if(!player->statsManager->isKnockedOut()) { // play only if not Knocked out
            playTurn(*player);
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
    unsigned int knockedOutPlayersCount = 0;
    for (const shared_ptr<Player>& player : this->players) {
        if(player->statsManager->getLevel() == Player::maxPlayerLevel) {
            return true;
        }
    }
    for (const shared_ptr<Player>& player : this->players) {
        if(player->statsManager->isKnockedOut()) {
            knockedOutPlayersCount++;
        }
    }
    if(knockedOutPlayersCount == players.size()) {
        return true;
    }
    return false;

    /*===================================================*/
}

void MatamStory::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/
    for (unsigned int i = 0; i < this->players.size(); ++i) {
        printStartPlayerEntry(i+1, *(this->players[i]));
    }
    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/
    vector<shared_ptr<Player>> sortedPlayers = this->getSortedPlayers();
    if(sortedPlayers[0]->statsManager->getLevel() != Player::maxPlayerLevel) {
        printNoWinners();
    }else {
        printWinner(*(sortedPlayers[0]));
    }
    /*========================================================================*/
}
