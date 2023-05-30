#pragma once

#include <memory>
#include "Hand.h"


using namespace CardUtils;


class Player
{

public:
    Player(std::shared_ptr<Deck>& deckPtr, int startingCredits);
	Hand hand, splitHand;
	std::shared_ptr<Deck> deckPtr;

    int getCredits();
    void adjustCredits(int adjustment);

	void draw(Hand& pHand, int number = 1);
    int playOutHand(Hand& pHand, bool singleDraw = false);

    void triggerSplit();

private:
    int credits;

};

