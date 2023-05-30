//
// Created by Lower School Music on 5/30/23.
//

#include "RoundBetHandler.h"


void RoundBetHandler::promptBet(Player& player)
{
    std::cout << "CURRENT CREDITS: " << player.getCredits()
              << "\nPlace your bet: ";
    std::cin >> currentBet;
    std::cout << "\n\n";

    if (currentBet > player.getCredits())
        throw std::out_of_range("Bet exceeds credit amount!");
    if (currentBet == 0)
        throw std::invalid_argument("Bet cannot be 0 credits!");

    player.adjustCredits(currentBet * -1);
    betValid = true;
}

void RoundBetHandler::promptDoubleDown(Player& player)
{
    if (currentBet <= player.getCredits()) {
        std::cout << "CURRENT CREDITS: " << player.getCredits();

        if (askPlayerYes("Double Down?"))
            player.adjustCredits(currentBet * -1);
    }
}


void RoundBetHandler::clearBet()
{
    currentBet = 0; betValid = false;
}


void RoundBetHandler::handleBetExceptions()
{
    try { throw; }
    catch (const std::out_of_range& ex)
    {
        std::cout << ex.what() << '\n';
    }
    catch (const std::invalid_argument& ex)
    {
        std::cout << ex.what() << '\n';
    }
}

void RoundBetHandler::payout(Player &player, double multiplier)
{
    player.adjustCredits(currentBet * multiplier);
}

