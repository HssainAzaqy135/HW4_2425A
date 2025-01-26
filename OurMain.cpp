
#include <string>
#include <iostream>
#include <fstream>

#include "MatamStory.h"

using std::string;
using std::cout;
using std::endl;
using std::exception;
using std::ifstream;

int main() {
    char str1[] = "C:/Users/areg1/Documents/GitHub/HW4_2425A/tests/test1.events";
    char str2[] = "C:/Users/areg1/Documents/GitHub/HW4_2425A/tests/test1.players";
    ifstream eventsStream(str1);
    ifstream playersStream(str2);

    try {
        MatamStory game(eventsStream, playersStream);
        game.play();
    }
    catch (const exception& e) {
        cout << e.what() << endl;
        return 1;
    }
}
