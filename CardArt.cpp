#include "CardArt.h"

#include <iostream>


std::string CardArt::arts[13][4];

CardArt::CardArt() {
    populateArts();
}

std::string CardArt::getSuitIcon(int suitEnumVal)
{
    switch (suitEnumVal)
    {
        case 0:
            return "^";
        case 1:
            return "v";
        case 2:
            return "&";
        case 3: 
            return "o";
        default:
            throw std::invalid_argument("Only enter an integer between 0-3");
    }
}

std::string CardArt::combineLines() {
    return line1 + line2 + line3 + line4 + line5 + line6;
}

std::string CardArt::make2(const std::string& suit) {
    line2 = "|2      |\n";
    line3 = "|   " + suit + "   |\n";
    line4 = "|       |\n";
    line5 = line3;
    line6 = "|______2|";
    return combineLines();
}

std::string CardArt::make3(const std::string& suit) {
    line2 = "|3      |\n";
    line3 = "| " + suit + "   " + suit + " |\n";
    line4 = "|       |\n";
    line5 = "|   " + suit + "   |\n";
    line6 = "|______3|";
    return combineLines();
}
std::string CardArt::make4(const std::string& suit) {
    line2 = "|4      |\n";
    line3 = "| " + suit + "   " + suit + " |\n";
    line4 = "|       |\n";
    line5 = line3;
    line6 = "|______4|";
    return combineLines();
}
std::string CardArt::make5(const std::string& suit) {
    line2 = "|5      |\n";
    line3 = "| " + suit + "   " + suit + " |\n";
    line4 = "|   " + suit + "   |\n";
    line5 = line3;
    line6 = "|______5|";
    return combineLines();
}
std::string CardArt::make6(const std::string& suit) {
    line2 = "|6      |\n";
    line3 = "| " + suit + "   " + suit + " |\n";
    line4 = line3;
    line5 = line3;
    line6 = "|______6|";
    return combineLines();
}
std::string CardArt::make7(const std::string& suit) {
    line2 = "|7      |\n";
    line3 = "| " + suit + "   " + suit + " |\n";
    line4 = "| " + suit + " " + suit + " " + suit + " |\n";
    line5 = line3;
    line6 = "|______7|";
    return combineLines();
}
std::string CardArt::make8(const std::string& suit) {
    line2 = "|8      |\n";
    line3 = "| " + suit + " " + suit + " " + suit + " |\n";
    line4 = "|  " + suit + " " + suit + "  |\n";
    line5 = line3;
    line6 = "|______8|";
    return combineLines();
}
std::string CardArt::make9(const std::string& suit) {
    line2 = "|9      |\n";
    line3 = "| " + suit + " " + suit + " " + suit + " |\n";
    line4 = line3;
    line5 = line3;
    line6 = "|______9|";
    return combineLines();
}
std::string CardArt::make10(const std::string& suit) {
    line2 = "|10  " + suit + "  |\n";
    line3 = "| " + suit + " " + suit + " " + suit + " |\n";
    line4 = line3;
    line5 = line3;
    line6 = "|_____10|";
    return combineLines();
}
std::string CardArt::makeJack(const std::string& suit) {
    line2 = "|J      |\n";
    line3 = "|   " + suit + "   |\n";
    line4 = "| " + suit + " J " + suit + " |\n";
    line5 = line3;
    line6 = "|______J|";
    return combineLines();
}
std::string CardArt::makeQueen(const std::string& suit) {
    line2 = "|Q      |\n";
    line3 = "|   " + suit + "   |\n";
    line4 = "| " + suit + " Q " + suit + " |\n";
    line5 = line3;
    line6 = "|______Q|";
    return combineLines();
}
std::string CardArt::makeKing(const std::string& suit) {
    line2 = "|K      |\n";
    line3 = "|   " + suit + "   |\n";
    line4 = "| " + suit + " K " + suit + " |\n";
    line5 = line3;
    line6 = "|______K|";
    return combineLines();
}
std::string CardArt::makeAce(const std::string& suit) {
    line2 = "|A      |\n";
    line3 = "|   " + suit + "   |\n";
    line4 = "| " + suit + " A " + suit + " |\n";
    line5 = line3;
    line6 = "|______A|";
    return combineLines();
}


void CardArt::populateArts() {
    for (int i = 0; i < 4; i++) {
        arts[0][i] = make2(suits[i]);
        arts[1][i] = make3(suits[i]);
        arts[2][i] = make4(suits[i]);
        arts[3][i] = make5(suits[i]);
        arts[4][i] = make6(suits[i]);
        arts[5][i] = make7(suits[i]);
        arts[6][i] = make8(suits[i]);
        arts[7][i] = make9(suits[i]);
        arts[8][i] = make10(suits[i]);
        arts[9][i] = makeJack(suits[i]);
        arts[10][i] = makeQueen(suits[i]);
        arts[11][i] = makeKing(suits[i]);
        arts[12][i] = makeAce(suits[i]);
    }
}