#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"

/*
	Player: It is the class representing the players, this class has a "hand" of cards which are automatically 
	added to the score of the player in question.
*/

class Player
{
 	private:
	  Card * hand[12];
	  int nCards;//Number of Cards
	  int total;
	  char name[20];
	  bool stay;
	public:
	  Player();
	  //~Player();
	  static const int PLAYERS = 4;
	  void setName(char name[20]){strcpy(this->name,name);}
	  void deliverCards(Card & a);
	  char * getName(){return name;}
	  int getnCards(){return nCards;}
	  void toAdd();
	  int getTotal(){toAdd();return total;}
	  bool getStay(){return stay;}
	  bool setStay(bool a){stay=a;}
	  void reset();
	  bool gameIsFinished();
};

#endif