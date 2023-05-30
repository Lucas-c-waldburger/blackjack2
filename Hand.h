#pragma once
#include "Deck.h"


struct Hand
{
	std::list<Card> cards;

    void displayArt();

    bool splitValid();
    bool naturalBlackJack();

	int score();

	std::list<Card> operator()();

};

