#include "Card.h"

CardArt Card::cardArt = CardArt();

Card::Card(int id, int suit) : suit(suit), id(id)
{
    art = CardArt::arts[id][suit];

    if (id >= 0 && id < 9)
        value = id + 2;
    else if (id < 13)
        value = 10;
    else
        value = 11;
}

int Card::getId()
{
    return id;
}

int Card::getSuit()
{
    return suit;
}

int Card::getValue()
{
    return value;
}

std::string Card::getArt()
{
    return art;
}

bool Card::isAce()
{
    return (id == 13);
}

