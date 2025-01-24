//
// Created by kingh on 18/01/2025.
//
#include <string>
#include <iostream>
#include <fstream>

int main() {
    std::string name = "Noder";
    char * name_char_star = name.data();
    std::cout << name_char_star[0] << std::endl;
    return 0;
}