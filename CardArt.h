#pragma once

#include <iostream>
#include <vector>
#include "utils.h"


class CardArt {
public:

    CardArt();

    static std::string arts[13][4];

private:

    std::string getSuitIcon(int suitEnumVal);
    const std::string suits[4] = { "^", "v", "&", "o"};

    std::string line1 = " _______ \n";
    std::string line2;
    std::string line3;
    std::string line4;
    std::string line5;
    std::string line6;

    std::string make2(const std::string& suit);
    std::string make3(const std::string& suit);
    std::string make4(const std::string& suit);
    std::string make5(const std::string& suit);
    std::string make6(const std::string& suit);
    std::string make7(const std::string& suit);
    std::string make8(const std::string& suit);
    std::string make9(const std::string& suit);
    std::string make10(const std::string& suit);
    std::string makeJack(const std::string& suit);
    std::string makeQueen(const std::string& suit);
    std::string makeKing(const std::string& suit);
    std::string makeAce(const std::string& suit);

    std::string combineLines();
    void populateArts();
};

