//
// Created by Lower School Music on 5/30/23.
//

#include "Dealer.h"

Dealer::Dealer(std::shared_ptr<Deck> &deckPtr) : Player(deckPtr, 0)
{}

int Dealer::playOutHand() {
    hand.displayArt();

    int finalScore = hand.score();

    if (finalScore > 21) // pseudo-return condition for the recursion
        finalScore = BUST;
    else
        if (finalScore < 17)
        {
            draw(hand);
            finalScore = playOutHand();
        }
        else
            finalScore = STAND;

    return finalScore;
}
