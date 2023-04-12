#pragma once

#include <iostream>
#include <string>
#include "player.hpp"
#include "card.hpp"

namespace ariel
{
    class Game
    {
        private:
            Player& player1;
            Player& player2;
            Player* winer;
            string lastTurn;
            string log;
            int turn;
            int totaldraws;
            int p1wins;
            int p2wins;

        public:
            Game(Player& firstPlr, Player& secondPlr);

            void playTurn();

            void playAll();

            void printWiner() const;

            void printLastTurn() const {
                cout << lastTurn;
            }

            void printLog() const {
                cout << log << endl;
            }

            void printStats() const;
    };
}