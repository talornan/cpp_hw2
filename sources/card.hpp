#pragma once

// use at https://github.com/Class-Warfare/War-Card-Game/blob/master/Hand.cpp
#include <iostream>
#include <string>

enum Suit {Clubs, Diamonds, Hearts, Spades};
enum Value {Ace,Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

using std :: string;
using namespace std;

namespace ariel{

    class Card{
        private:
            Value m_value;
            Suit m_suit;
            bool m_is_face_up;

        public:
            static string suitName (Suit s);
            static string valueName (Value v);
            Card(Value value = Ace , Suit suit = Clubs):
                 m_value(value) , m_suit(suit) , m_is_face_up(false){}


            Value getValue() const{
                return this->m_value;
            }

            Suit getSuit() const {
                return this->m_suit;
            }
            
            string name() { 
                return valueName (m_value) + " of " + suitName(m_suit);
                }

            // use in https://www.tutorialspoint.com/cplusplus/relational_operators_overloading.htm
            // overloaded < operator
            bool operator < (const Value& cardVal) {
                if(this->m_value == Ace and  cardVal == Two ){
                    return true;
                }
               
                if(this->m_value > Two and  cardVal == Ace){
                    return true;
                }
                if(this->m_value and cardVal){
                    return true;
                }
                else{
                    return false;
                }

              

            };

            // return (value == Ace and rhs.value == Two) 
            // or (value > Two and rhs.value < Three) or (value < rhs.value);

            // use in https://www.geeksforgeeks.org/how-to-overload-operator-in-cpp/
            bool operator == (const Card &cardValue)
            {
                return m_value == cardValue.getValue() and
                m_suit == cardValue.getSuit();
            
            };

            void flip();
            bool is_face_up() const;

    };
}




