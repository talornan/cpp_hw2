#pragma once

// use at https://github.com/Class-Warfare/War-Card-Game/blob/master/Hand.cpp
#include <iostream>
#include <string>
#include "player.hpp"
#include "card.hpp"
#include <ctime>
#include <cstdlib>

namespace ariel
{
    class Game
    {
        private:
            Player Player1;
            Player Player2;
            unsigned timesOfWinP1;
            unsigned timesOfWinP2;
            unsigned timeOfDrow ;
            string lastTurnStatus;
            string gameLog;
            int turn;



        public:
            Game(Player& p1, Player& p2);

            void printLastTurn(){

            }
            void playAll(){

            } //playes the game untill the end
            void printWiner(); // prints the name of the winning player
            void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
            void printStats();
            void playTurn();
             //Mixes up the cards
            void shuffle(){

            }
            //Returns the card from the top or bottom of the hand, removes that card
            Card drawTop();
            Card drawBottom();
            //Places the card on the top or bottom of the hand
            void placeTop(Card c);
            void placeBottom(Card c);
            //Returns true if the hand is empty, returns false otherwise
            bool empty();

            void getNames();
            
           

    };
}