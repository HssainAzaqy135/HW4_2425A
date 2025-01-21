//
// Created by kingh on 21/01/2025.
//
#include "Player.h"

Player::Player(const std::string name, std::unique_ptr<Job> job, std::unique_ptr<Character>
        character) : name(name) ,character(std::move(character)),job(std::move(job))
{
    this->job->startGameAttributes(*this);
}

string Player::getDescription() const {
    string nameString, jobString, characterString, levelString, forceString;
    nameString = this->name;
    levelString = std::to_string(this->getLevel());
    forceString = std::to_string((this->getForce()));
    jobString = this->job->getJob();
    characterString = this->character->getBehavior();
    string stringToPrint = nameString + ", " + jobString + " with " + characterString + " character (level "
           + levelString + ", force " + forceString + ")";
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
