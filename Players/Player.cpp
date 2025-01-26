//
// Created by kingh on 21/01/2025.
//
#include "Player.h"

Player::Player(const std::string name, std::unique_ptr<Job> job, std::unique_ptr<Character>
        character) : name(name) ,statsManager(std::make_unique<PlayerStatsManager>()),
        character(std::move(character)),job(std::move(job))
{
    this->job->startGameAttributes(*this);
}

string Player::getDescription() const {
    string stringOfName = this->name;
    string stringOfLevel = std::to_string(this->getLevel());
    string stringOfForce = std::to_string((this->getForce()));
    string stringOfJob = this->job->getJob();
    string stringOfCharacter = this->character->getBehavior();
    string stringToPrint = stringOfName + ", " + stringOfJob + " with " + stringOfCharacter + " character (level "
           + stringOfLevel + ", force " + stringOfForce + ")";
    return stringToPrint;
}

string Player::getName() const {
    return this->name;
}

int Player::getLevel() const {
    return this->statsManager->getLevel();
}

int Player::getForce() const {
    return this->statsManager->getForce();
}

int Player::getHealthPoints() const {
    return this->statsManager->getCurrentHp();
}

int Player::getCoins() const {
    return this->statsManager->getCoins();
}
