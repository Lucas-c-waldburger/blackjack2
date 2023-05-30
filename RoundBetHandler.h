
#ifndef BLACKJACK_ROUNDBETHANDLER_H
#define BLACKJACK_ROUNDBETHANDLER_H

#include "Dealer.h"
#include <iostream>

struct RoundBetHandler
{
    int currentBet = 0;
    bool betValid = false;

    void promptBet(Player& player);
    void promptDoubleDown(Player& player);

    void payout(Player& player, double multiplier);

    void clearBet();

    static void handleBetExceptions();

};


#endif //BLACKJACK_ROUNDBETHANDLER_H
