cmake_minimum_required(VERSION 3.24)
project(blackjack)

set(CMAKE_CXX_STANDARD 17)

add_executable(blackjack main.cpp Card.h Card.cpp CardArt.h CardArt.cpp Deck.h Deck.cpp Hand.h Hand.cpp utils.h Player.h Player.cpp RoundBetHandler.h RoundBetHandler.cpp Dealer.cpp Dealer.h)
