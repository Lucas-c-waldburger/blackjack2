#pragma once
#include <iostream>
#include <list>

const int SURRENDER = -2, BUST = -1, NOT_PLAYED_OUT = 0, HIT = 1, STAND = 2;

const double NATURAL_BLACKJACK = 1.5;

namespace CardUtils
{
    template <class T>
	void moveTop(std::list<T>& donor, std::list<T>& recipient)
	{
		recipient.push_back(std::move(donor.front()));
		donor.pop_front();
	}

    bool askPlayerYes(std::string question)
    {
        char decision;
        std::cout << question <<  " Y/N: ";
        std::cin >> decision;
        std::cout << '\n';

        return (std::tolower(decision) == 'y');
    }

    int handleMisspelledHandOptions(std::string& decision)
    {
        int hitCertainty = 0, standCertainty = 0, surrenderCertainty = 0;

        if (decision.length() <= 4)
            hitCertainty += 1;
        if (decision.length() > 3 && decision.length() <= 6)
            standCertainty += 1;
        else if (decision.length() > 6)
            surrenderCertainty += 1;

        for (char c : decision)
        {
            switch(c)
            {
                case 'h': case 'i':
                {
                    hitCertainty += 1;
                    break;
                }
                case 'a':
                {
                    standCertainty += 1;
                    break;
                }
                case 'u': case 'r': case 'e':
                    surrenderCertainty += 1;
            }
        }

        if (hitCertainty > standCertainty)
        {
            if (hitCertainty >= surrenderCertainty)
                return HIT;
        }
        else
        {
            if (standCertainty >= surrenderCertainty)
                return STAND;
        }

        return SURRENDER;
    }





    int askPlayerHandOptions()
    {
        std::string rawDecision, loweredDecision;
        std::cout << "hit, stand, or surrender?: ";
        std::cin >> rawDecision;
        std::cout << '\n';

        for (char c : rawDecision)
            loweredDecision += std::tolower(c);

        if (loweredDecision == "hit")
            return HIT;
        if (loweredDecision == "stand")
            return STAND;
        if (loweredDecision == "surrender")
            return SURRENDER;

        return handleMisspelledHandOptions(loweredDecision);
    }

    enum Suits
    {
        diamonds = 0,
        hearts = 1,
        clubs = 2,
        spades = 3
    };



}