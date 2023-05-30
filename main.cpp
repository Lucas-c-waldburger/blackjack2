#include <iostream>
#include "RoundBetHandler.h"



/*
 * HOW TO AVOID CIRCULAR REFERENCES?
 *
*/

using namespace CardUtils;


void dealBack(Player& player)
{
    while (!player.hand().empty() && !player.splitHand().empty())
        moveTop(player.hand.cards, player.deckPtr->cards);
}

void reset(Player& player, Player& dealer, RoundBetHandler& betHandler)
{
    dealBack(player); dealBack(dealer);
    player.deckPtr->shuffle();
    betHandler.clearBet();
}










int main()
{
    // initialize objects
    std::shared_ptr<Deck> deck = std::make_shared<Deck>();

    Player player(deck, 100);
    Dealer dealer(deck);
    RoundBetHandler betHandler;

    bool keepPlaying = true;

    while (keepPlaying)
    {
        while (!betHandler.betValid)
        {
            try
            {
                betHandler.promptBet(player);
            }

            catch (...)
            {
                RoundBetHandler::handleBetExceptions();
            }
        }

        int playerFinalScore = 0, playerSplitFinalScore = 0, dealerFinalScore = 0;

        player.draw(player.hand,2);

        // display cards

        // check blackjack
        if (player.hand.naturalBlackJack())
            player.hand.displayArt();

        // PLAYER TURN
        else if (player.hand.splitValid() && askPlayerYes("Split your hand?"))
        {
            player.triggerSplit();
            playerFinalScore = player.playOutHand(player.hand, true);
            playerSplitFinalScore = player.playOutHand(player.splitHand, true);
        }

        else
            playerFinalScore = player.playOutHand(player.hand);

        // DEALER TURN
        if (playerFinalScore != BUST && playerSplitFinalScore != BUST)
            dealerFinalScore = dealer.playOutHand();


        // FINAL SCORING


//        if (player.hand.naturalBlackJack() || player.hand.score() > dealer.hand.score())


        // ASK PLAY AGAIN

        if (!askPlayerYes("Play Again?"))
            keepPlaying = false;
        else
            reset(player, dealer, betHandler);

    }

    return 0;
}