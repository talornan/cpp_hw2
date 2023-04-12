#pragma once

// use at https://github.com/Class-Warfare/War-Card-Game/blob/master/Hand.cpp
#include <iostream>
#include <string>

using namespace std;

namespace ariel
{
    enum Suit
    {
        Clubs = 0,
        Diamonds,
        Hearts,
        Spades
    };

    enum Value
    {
        Ace = 1,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King
    };

    class Card
    {
        private:
            Suit suit;
            Value value;

        public:
            Card(Suit csuit = Clubs, Value cvalue = Ace);

            int getSuit() const {
                return (int)suit;
            }

            int getValue() const {
                return (int)value;
            }

            string toString() const;

            bool operator<(const Card &other) const;

            bool operator==(const Card &other) const {
                return (value == other.value);
            }
    };
}