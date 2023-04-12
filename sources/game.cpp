#include <stdexcept>
#include <algorithm>
#include <random>
#include <cstdlib>
#include "game.hpp"

namespace ariel
{
    Game::Game(Player &firstPlr, Player &secondPlr) : player1(firstPlr), player2(secondPlr), winer(nullptr), turn(0), totaldraws(0), p1wins(0), p2wins(0)
    {
        if (this->player1.isPlrInGame() || this->player2.isPlrInGame())
            throw invalid_argument("One of the player is already in game!");

        vector<Card> cards;

        this->player1.setInGame(true);
        this->player2.setInGame(true);

        for (int i = 0; i < 14; i++)
            cards.push_back(Card(Clubs, (Value)i));

        for (int i = 0; i < 14; i++)
            cards.push_back(Card(Diamonds, (Value)i));

        for (int i = 0; i < 14; i++)
            cards.push_back(Card(Hearts, (Value)i));

        for (int i = 0; i < 14; i++)
            cards.push_back(Card(Spades, (Value)i));

        unsigned seed = (unsigned) time(NULL);
        auto rng = default_random_engine(seed);
        shuffle(cards.begin(), cards.end(), rng);

        for (int i = 0; i < 52; i++)
        {
            if (i % 2 == 0)
                this->player1.addCardToHand(cards.back());

            else
                this->player2.addCardToHand(cards.back());

            cards.pop_back();
        }
    }

    void Game::playTurn()
    {
        if (&this->player1 == &this->player2)
            throw invalid_argument("Player 1 and player 2 are the same player!");

        else if (!this->player1.isPlrInGame() || !this->player2.isPlrInGame())
            throw logic_error("Game is already finished!");

        else if (++this->turn > 26)
            throw logic_error("Game can't continue with more then 26 turns!");

        Card &c1 = this->player1.takeCard();
        Card &c2 = this->player2.takeCard();

        int onTable = 2;

        this->lastTurn = this->player1.getName() + " played " + c1.toString() + " and " 
                        + this->player2.getName() + " played " + c2.toString() + ". ";

        while (c1 == c2)
        {
            this->lastTurn += "Draw!\n";

            if (this->player1.stacksize() <= 1 || this->player2.stacksize() <= 1)
            {
                while (onTable > 0)
                {
                    onTable -= 2;
                    this->player1.updateTakenCards();
                    this->player2.updateTakenCards();
                }

                break;
            }

            this->player1.takeCard();
            this->player2.takeCard();

            c1 = this->player1.takeCard();
            c2 = this->player2.takeCard();

            onTable += 4;

            this->lastTurn += this->player1.getName() + " played " + c1.toString() + " and " 
                        + this->player2.getName() + " played " + c2.toString() + ". ";
        }

        if (c2 < c1)
        {
            this->lastTurn += this->player1.getName() + " won!\n";

            while (onTable > 0)
            {
                onTable--;
                this->player1.updateTakenCards();
            }
        }

        else if (c1 < c2)
        {
            this->lastTurn += this->player2.getName() + " won!\n";

            while (onTable > 0)
            {
                onTable--;
                this->player2.updateTakenCards();
            }
        }

        else
            this->lastTurn += "Draw!\n";

        this->log += this->lastTurn;

        if (!this->player1.stacksize() || !this->player2.stacksize())
        {
            this->player1.setInGame(false);
            this->player2.setInGame(false);

            if (this->player1.cardesTaken() > this->player2.cardesTaken())
                this->winer = &this->player1;

            else
                this->winer = &this->player2;
        }
    }

    void Game::playAll()
    {
        while (this->player1.stacksize() > 0 && this->player2.stacksize() > 0)
            this->playTurn();    
    }

    void Game::printWiner() const
    {
        if (this->winer == nullptr)
            cout << "No winner yet!" << endl;

        else
            cout << "The winner is " << this->winer->getName() << endl;
    }

    void Game::printStats() const
    {
        cout << this->player1.getName() << " stats:\n" <<
                "Win rate: " << ((float) this->p1wins / this->turn) <<
                "\nCards won: " << this->player1.cardesTaken() <<
                "\nStack size: " << this->player1.stacksize() <<
                endl;

        cout << this->player2.getName() << " stats:\n" <<
                "Win rate: " << ((float) this->p2wins/ this->turn) <<
                "\nCards won: " << this->player2.cardesTaken() <<
                "\nStack size: " << this->player2.stacksize() <<
                endl;

        cout << "Draw rate: " << ((float) this->totaldraws / this->turn) <<
                "\nDraws: " << this->totaldraws <<
                "\nTurns: " << this->turn <<
                endl;
    }
}