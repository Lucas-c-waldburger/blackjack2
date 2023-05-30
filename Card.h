#pragma once

#include <iostream>
#include "CardArt.h"



class Card
{
public:
	
	Card(int id, int suit);

    int getId();
	int getSuit();
	int getValue();
    std::string getArt();

    bool isAce();

    static CardArt cardArt;

private:

    int id;
	int suit;
	int value;
    std::string art;
};

