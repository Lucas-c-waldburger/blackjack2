#include "Hand.h"

void Hand::displayArt()
{
    for (auto& card : cards)
        std::cout << card.getArt() << '\n';
}

bool Hand::splitValid()
{
    return (cards.size() == 2 && cards.front().getValue() == cards.back().getValue());
}

bool Hand::naturalBlackJack()
{
    return (cards.size() == 2 && score() == 21);
}


int Hand::score()
{
	int score = 0;

	for (auto it = cards.begin(); it != cards.end(); it++)
		score += it->getValue();

	return score;
}

std::list<Card> Hand::operator()()
{
	return cards;
}





