#include <stdexcept>
#include "player.hpp"

namespace ariel
{
    Player::Player(string name): plrName(name), takencards(0), isInGame(false) { }

    void Player::addCardToHand(Card& card) {
        //if (this->stacksize() >= 26)
            //throw logic_error("Player already has full stack (26 cards!)");

        this->hand.push_back(card);
    }

    Card& Player::takeCard() {
        if (this->stacksize() == 0)
            throw logic_error("Player's stack is empty!");

        Card& ret = this->hand.back();
        this->hand.pop_back();

        return ret;
    }
}