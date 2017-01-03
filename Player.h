#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"

class Player
{
 	private:
	  Card * man[12]; // Mano cantidad de cartas maximas en la mano de un jugador?? 
	  int cCards;//cantidad de Cards
	  int suma;
	  int ganadas;
	  char nombre[20];
	  bool plantado;
	public:
	  Player();
	  //~Player();
	  void setName(char name[20]){strcpy(nombre,name);}
	  void darCard(Card & a);
	  char * getName(){return nombre;}
	  int getCCards(){return cCards;}
	  void sumar();
	  int getGanar(){return ganadas;}
	  int getSuma(){sumar();return suma;}
	  bool getPlantado(){return plantado;}
	  bool setPlantado(bool a){plantado=a;}
	  void reset();
};

#endif