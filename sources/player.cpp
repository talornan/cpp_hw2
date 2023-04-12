#include "player.hpp"
#include "game.hpp"
using namespace std;

namespace ariel {
    Player::Player(string name) : name(name), cardsPTake(0) ,
     playsNow(false) {};

    bool Player::hasCard(Card card) const {
        for (size_t i = 0; i < this->stacksize(); ++i)
        {
            Card t = this->cards.at(i);

            if (t.getSuit() == card.getSuit() && t.getValue() == card.getValue())
                return true;
        }

        return false;
    }

    void Player::addCard(Card& card) { 
        if (this->hasCard(card))
            throw invalid_argument("Player already has this card (hand)!");

        this->cards.push_back(card); 
    }
}

            

  

          