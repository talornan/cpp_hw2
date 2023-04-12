#include "card.hpp"

namespace ariel
{
    Card::Card(Suit csuit, Value cvalue) : suit(csuit), value(cvalue) {}

    string Card::toString() const
    {
        string ret;

        switch (this->value)
        {
            case Ace:
                ret = "Ace";
                break;
            case Jack:
                ret = "Jack";
                break;
            case Queen:
                ret = "Queen";
                break;
            case King:
                ret = "King";
                break;
            default:
                ret = to_string(this->getValue());
                break;
        }

        ret += " of ";

        switch (this->suit)
        {
            case Clubs:
                ret += "Clubs";
                break;
            case Spades:
                ret += "Spades";
                break;
            case Hearts:
                ret += "Hearts";
                break;
            case Diamonds:
                ret += "Diamonds";
                break;
        }

        return ret;
    }

    bool Card::operator<(const Card &other) const
    {
        if (this->value == Ace && other.value == Two)
            return true;

        else if (this->value != Ace && this->value != Two && other.value == Ace)
            return true;

        return (this->value < other.value);
    }
}