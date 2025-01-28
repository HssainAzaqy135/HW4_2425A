#pragma once

#include <string>
#include <stdexcept>

using std::string;
using std::runtime_error;

const string INVALID_PLAYERS_FILE = "Invalid Players File";
const string INVALID_EVENTS_FILE = "Invalid Events File";
const string CANT_PAY_COINS = "Can't Pay Coins";

class InvalidPlayersFile : public runtime_error{
public:
    InvalidPlayersFile(const string& what = INVALID_PLAYERS_FILE) : runtime_error(what) {};
};

class InvalidEventsFile : public runtime_error {
public:
    InvalidEventsFile(const string& what = INVALID_EVENTS_FILE) : runtime_error(what) {};
};

class CantPayCoins : public runtime_error {
public:
    CantPayCoins(const string& what = CANT_PAY_COINS) : runtime_error(what) {};
};