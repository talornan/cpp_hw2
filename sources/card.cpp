#include "card.hpp"

namespace ariel{
    

    string Card :: suitName (Suit suit ) {
        switch(suit) {
            case Clubs: return "Clubs";
            case Diamonds: return "Diamonds";
            case Hearts: return "Hearts";
            case Spades: return "Spades";
            default: throw std::out_of_range("Suit value out of range");
        }
    }

    string Card :: valueName (Value value) {
        switch(value) {
        case Ace: return "Ace";
        case Two: return "Two";
        case Three: return "Three";
        case Four: return "Four";
        case Five: return "Five";
        case Six:  return "Six";
        case Seven: return "Seven";
        case Eight: return "Eight";
        case Nine: return "Nine";
        case Ten: return "Ten";
        case Jack: return "Jack";
        case Queen: return "Queen";
        case King: return "King";
        default: throw std::out_of_range("Face value out of range");
        }
    }
    void Card :: flip() {
        m_is_face_up = !this->m_is_face_up;
    }

    bool Card :: is_face_up() const {
        return  this->m_is_face_up;
    }


    };
  
