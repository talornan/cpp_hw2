
#include <iostream>
#include <stdexcept>
#include "game.hpp"

using namespace std;

namespace ariel {

Game::Game(Player& p1, Player& p2) : Player1(p1), Player2(p2) 
,timesOfWinP1 = 0,timesOfWinP2 = 0 , gameLog = "" 
, lastTurnStatus = "", turn = 1 , timeOfDrow = 0 {
       
        if (p1 == p2)
            throw invalid_argument("Player 1 and Player 2 are the same player!");         
       
        if (p1.isInGame())
            throw invalid_argument("Player 1 is already in a game!");

        if (p2.isInGame())
            throw invalid_argument("Player 2 is already in a game!");

    
        initialize_deck();
        shuffle_deck();
        deal_cards();
   
        p1.setPlayerStatus (true); 
        p1.setPlayerStatus (true); 

}

void playTurn() { 
     if (p1.isInGame() && p2.isInGame())
        {
            if (++this->turn > 26)
                throw logic_error("Game cannot continue with more than 26 turns!");

            unsigned int drawsinthisturn = 0;
            this->lastTurnStats = "";

            Card p1Card = p1.getCard();
            Card p2Card = p2.getCard();
            p1.removeCard();
            p2.removeCard();

            cout << p1.getName() << " played " << p1Card.toString() << " " << p2.getName() << " played " << p2Card.toString() << ". ";
            this->lastTurnStats = "Turn " + to_string(this->turn) + ":\n" + p1.getName() + " played " + p1Card.toString() + " " + p2.getName() + " played " + p2Card.toString() + ". ";

    }
     while (p1Card == p2Card)
            {
                war ();
            }
            if(p1.cards.value < p2.cards.value ){


            }
            if (p2.cards.value < p1.cards.value){

            }
            is_game_over();
            this->gameLog += this->lastTurnStats;

    else{
        throw logic_error("Game is over!");
    }        
}

void Game::initialize_deck() {
    for (int i = 1; i < 14; i++) {
        deck.push_back(Card(i, Suit::Hearts));
        deck.push_back(Card(i, Suit::Diamonds));
        deck.push_back(Card(i, Suit::Clubs));
        deck.push_back(Card(i, Suit::Spades));
    }
}
//A function that shuffles the deck.
void Game::shuffle_deck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

// This function is responsible for dealing the cards to each player at the start of the game.
void Game::deal_cards() {
    for (int i = 0; i < deck.size(); i++) {
        players[i % num_players].add_card(deck[i]);
    }
}

//This function checks if the game is over by examining the state of the game board. 
//It takes no input parameters and returns a boolean value.
bool Game::is_game_over() {
    for (const auto& player : players) {
        if (player.get_num_cards() == 0) {
            return true;
        }
    }
    return false;
}


int Game ::war()
{
	Card p1Card, p2Card;
	int winner = 0;

	do
	{
		cout << "WAR!!" << endl;
		
		//If a player is out of cards, then SHUFFLE THE CARDS HE HAVE AND TAKE ON OF THEM
		if (player1.empty())
		{
			cout << nameP1 << " is out of cards." << endl;
			winner = 2;
			break;
		}
		else if (player2.empty())
		{
			cout << nameP2 << " is out of cards." << endl;
			winner = 1;
			break;
		}

		//Put down three extra cards for each player
		for (int i = 0; i < 3; i++)
		{
			//Save one card for the comparison
			if (player1.size() > 1) warPile.placeBottom(player1.drawTop());
			if (player2.size() > 1) warPile.placeBottom(player2.drawTop());
		}
		
		//We'll compare the next two cards
		p1Card = player1.drawTop();
		p2Card = player2.drawTop();
		warPile.placeBottom(p1Card);
		warPile.placeBottom(p2Card);
		
		printCards(p1Card.name(), p2Card.name());
	} while (p1Card.getValue() == p2Card.getValue());
	
	//Give the spoils to the winner
	if (p1Card.getValue() > p2Card.getValue() || winner == 1)
	{
		int pile_size = warPile.size();
		for (int i = 0; i < pile_size; i++)
			player1.placeBottom(warPile.drawTop());
		
		winner = 1;
	}
	else if (p2Card.getValue() > p1Card.getValue() || winner == 2)
	{
		int pile_size = warPile.size();
		for (int i = 0; i < pile_size; i++)
			player2.placeBottom(warPile.drawTop());
		
		winner = 2;
	}

	return winner;
}


}

void printLastTurn() { 
}

void playAll() { 
    while (this->Player1.GetPlayerStatus() == true and this->Player2.GetPlayerStatus() == true)
    {
        playTurn();
    }
    
}

void printWiner() { 

}

void printLog() { 
    return this.log;
}

void printStats() {



 }




