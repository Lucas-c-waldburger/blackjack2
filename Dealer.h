#ifndef BLACKJACK_DEALER_H
#define BLACKJACK_DEALER_H

#include "Player.h"

class Dealer : public Player
{
public:
    explicit Dealer(std::shared_ptr<Deck>& deckPtr);

    int playOutHand();

private:

};


#endif //BLACKJACK_DEALER_H
