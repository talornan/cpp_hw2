#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel
{
    class Player
    {
        private:
            string plrName;
            vector<Card> hand;
            int takencards;
            bool isInGame;

        public:
            Player(string name = "Bobby Botten");

            int stacksize() const {
                return (int)hand.size();
            }

            int cardesTaken() const {
                return takencards;
            }

            bool isPlrInGame() const {
                return isInGame;
            }

            void setInGame(bool st) {
                isInGame = st;
            }

            string getName() const {
                return plrName;
            }

            void updateTakenCards() {
                ++takencards;
            }

            void addCardToHand(Card& card) {
                hand.push_back(card);
            }

            Card& takeCard();

            string toString() const {
                return "Player " + plrName + " has " + to_string(stacksize()) + " cards in hand and " + to_string(cardesTaken()) + " taken cards.";
            }
    };
}