#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include "Card.h"
#include "Player.h"
using namespace std;

Card& find_Card(Card * deck); 
void resetCards(Card * deck);
void initCards(Card * deck);
void resetPlayers(Player * players);
void initPlayers(Player * players, Card *deck);
bool play(Player & player, Card * deck);

int main()
{
  Card deck[Card::CANT_MAXIMUN_CARDS];
  Player players[Player::PLAYERS];
  bool game_over=false;
  srand(time(NULL));
  bool winner = false;
  char name[20];
  int election=0,pop=0;

  initCards(deck);

  for (int i = 0; i < Player::PLAYERS; i++)
  {
    cout<<"Please, enter the name of the player: "<<i+1<<endl;
    cin.getline(name, 20, '\n');
    players[i].setName(name);
  }

  while(game_over!=true)
  {
    initPlayers(players, deck);

    for(int i=0; i<Player::PLAYERS; i++) // Principal loop of the game
    {
      cout<<players[i].getName()<<" It's your turn"<<endl;
      while(players[i].gameIsFinished())
        winner = play(players[i], deck); 
      
      if (winner)
        break;       
    }

    cout<<"Do you want to play again?"<<endl;
    cout<<"1: Yes, 2: No"<<endl;
    cin>>election;

    if(election!=1)
      game_over=true;

    winner = false;

    resetPlayers(players);
    resetCards(deck);
  }
}

Card & find_Card(Card * deck)
{
  int i = rand()%Card::CANT_MAXIMUN_CARDS;
  bool stop = false;
  while(stop!=true)
  {
    if(!deck[i].getUse())
        stop=true;
    else
      i= rand() % Card::CANT_MAXIMUN_CARDS;
  }
  deck[i].setUse();
  return deck[i];
}

void initCards(Card * deck)
{
  for(int i=0; i<Card::CANT_MAXIMUN_CARDS; i++)
  {
    switch((i/Card::MAXIMUN_SUIT)+1)
    {
      case 1:
        deck[i].setCard(i+1, club);
      break;
      case 2:
        deck[i].setCard((i+1)-Card::MAXIMUN_SUIT, heart);
      break;
      case 3:
        deck[i].setCard((i+1)-26, spade);
      break;
      case 4:
        deck[i].setCard((i+1)-39, diamond);
      break;
    }
  }
}

void initPlayers(Player * players, Card * deck)
{
  for (int i = 0; i < Player::PLAYERS; i++)
  {
    players[i].deliverCards(find_Card(deck));
    players[i].deliverCards(find_Card(deck));
  }
}

bool play(Player & player, Card * deck)
{
  int election = 0;
  
  cout<<"Your total:"<<player.getTotal()<<endl;
  cout <<"1: To take another card, 2: To stay"<<endl;
  cin>>election;
  switch(election)
  {
    case 1:
      player.deliverCards(find_Card(deck));
      cout<<"Your total:"<<player.getTotal()<<endl;
      if(player.getTotal()>21)
        cout<<"You lost"<<endl;
      else if(player.getTotal()==21)
      {
        cout<<"YOU WON!!"<<endl;
        return true;
      }
      break;
    case 2:
      player.setStay(true);
      break;
  }
  return false;
}

void resetCards(Card * deck)
{
    for(int i=0; i<Card::CANT_MAXIMUN_CARDS; i++)
    {
      if(deck[i].getUse())
         deck[i].setUse();
    }
}

void resetPlayers(Player * players)
{
  for(int i=0;i<Player::PLAYERS;i++)
    players[i].reset();
}








