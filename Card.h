#ifndef CARD_H
#define CARD_H

/*
  Card: It is the class that represents the cards of the game (cards of poker), also, It is the responsible 
  to perform the correct operations for the sum of cards in BlackJack.
*/

enum suit{club=1,heart=2,spade=3,diamond=4,nothing=-1};
class Card
{
  suit suits;
  int number;
  bool inUse;
  
public:
  static const int CANT_MAXIMUN_CARDS = 52;

  static const int MAXIMUN_SUIT = 13;

  Card(int n=-1, suit p = nothing) : number(n),suits(p), inUse(false) {}

  void setCard(int numero,suit otherSuit);
  
  suit getSuit(){return suits;}
  
  int getNumber(){return number;}
  
  int getNumberS();
  
  int getNumberS(int n);
  
  void setUse();
  
  bool getUse(){return inUse;}
  //~Card();
  int operator+(const Card& a);
  
  int operator=(const Card& a);
};

#endif