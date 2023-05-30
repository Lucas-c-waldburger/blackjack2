#include "Player.h"


Player::Player(std::shared_ptr<Deck>& deckPtr, int startingCredits) : deckPtr(deckPtr), credits(startingCredits)
{}

int Player::getCredits()
{
    return credits;
}

void Player::adjustCredits(int adjustment)
{
    credits += adjustment;
}



void Player::draw(Hand& pHand, int number)
{
	for (int i = 0; i < number; i++)
	{
        moveTop<Card>(deckPtr->cards, pHand.cards);
	}
}


void Player::triggerSplit()
{
    moveTop<Card>(hand.cards, splitHand.cards);
    draw(hand); draw(splitHand);
}

int Player::playOutHand(Hand& pHand, bool singleDraw)
{
    pHand.displayArt();

    int finalScore = pHand.score();

    if (finalScore < 21)
    {
        switch (askPlayerHandOptions()) {
            case HIT:
                draw(pHand);

                if (singleDraw) {
                    finalScore = pHand.score();
                    break;
                }

                finalScore = playOutHand(pHand);
                break;

            case SURRENDER:
                finalScore = SURRENDER;
                break;

            case STAND:
                break;
        }
    }

    if (finalScore > 21)
        finalScore = BUST;

    return finalScore;
}



