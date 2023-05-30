#pragma once
#include <random>
#include <list>
#include "Card.h"

const int NUM_SUITS = 4, NUM_IDS = 13;

class Deck
{
public:
	Deck();

	std::list<Card> cards;

    void populate();
	void shuffle();

	std::list<Card> operator()();


private:



};

