#include <stdio.h>
#include <iostream>
#include <fstream>
#include "json.hpp"


using json = nlohmann::json;

int main()  {
    std::cout << "Songbibliothek\n";
    std::string songfile;
    std::cin >> songfile;

    std::ifstream file(songfile);

    json song;
    file >> song;


    return 0;
}
