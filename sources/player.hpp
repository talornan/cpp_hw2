#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"

using namespace std;
using std :: string;
using std :: vector;

namespace ariel
{
    class Player
    {
        private:
            vector <Card> cards;
            vector <Card> winCards;
            size_t cardsPTake;
            bool playsNow;

        public:
            string name;        
        
            Player(string name = "guest");

            size_t stacksize()const {
                return this->cards.size();
            }
            
            int cardesTaken() const {
                return this->cardsPTake;
            }

            bool GetPlayerStatus()const {
                return this->playsNow;
            }

            void setPlayerStatus(bool ans){
                this->playsNow = ans;
            }
          
            string getName() const {
                return this->name;
            }
            void setName(string namep){
                this->name = namep;
            }

            void increaseCardesTake(){
                this->cardsPTake++;
            }
            void addCard(Card &card);
           
            void removeCard(){
                this->cards.pop_back();
            }
            
            bool operator == (const Player &rhs) const {
                return this->name == rhs.name;
            }
            

            bool hasCard(Card card) const;

            /*
             * Returns a string representation of the player.
             * @return A string representation of the player.
             * @note The function is const and can be called on a const object.
             * @note The function is inline.
            */
            string toString() const {
                return "Player " + this->name + " has " + to_string(this->stacksize()) + " cards in hand and " + to_string(this->cardesTaken()) + " cards taken.";
            }

            void placeTop(Card c)
            {
                //Insert the card at the beginning of the deck
                cards.insert(cards.begin(), c);
            }

            void placeBottom(Card c)
            {
                cards.push_back(c);
            }

            };
            
    }
