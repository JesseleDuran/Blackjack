#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include "Card.h"
#include "Player.h"
using namespace std;

Card& conseguir_Card(Card * mazo);

int main()
{
  Card mazo[52];
  Player players[4];
  bool game_over=false;
  srand(time(NULL));
  bool winner = false;
  //Aqui iniciamos las Cards :)
  for(int i=0; i<52; i++)
  {
    switch((i/13)+1)
    {
      case 1:
        mazo[i].setCard(i+1,trebol);
      break;
      case 2:
        mazo[i].setCard((i+1)-13,corazon);
      break;
      case 3:
        mazo[i].setCard((i+1)-26,pica);
      break;
      case 4:
        mazo[i].setCard((i+1)-39,diamante);
      break;
    }
  }
  char name[20];

  for (int i = 0; i < 4; i++)
  {
    cout<<"porfavor Digite su nombre Player numero "<<i+1<<endl;
    cin.getline(name, 20, '\n');
    players[i].setName(name);
  }
  bool gano=false;
  int turno=0;
  int eleccion=0,pop=0;
  while(game_over!=true)
  {
    for (int i = 0; i < 4; i++)
    {
        players[i].darCard(conseguir_Card(mazo));
        players[i].darCard(conseguir_Card(mazo));
    }

    for(int i=0; i<4; i++)
    {
      if(winner != true)
      {  
        while(players[i].getSuma()<21 && players[i].getPlantado()!=true)
        { 
          cout<<players[i].getName()<<" es tu turno"<<endl;
          cout<<"Tu suma :"<<players[i].getSuma()<<endl;
          cout <<"1 para Pedir, 2 para plantarte"<<endl;
          cin>>eleccion;
          switch(eleccion)
          {
            case 1:
              players[i].darCard(conseguir_Card(mazo));
              cout<<"Tu suma :"<<players[i].getSuma()<<endl;
              if(players[i].getSuma()>21)
                cout<<"perdiste"<<endl;
              else if(players[i].getSuma()==21)
              {
                cout<<"YOU WIN MTFK!!!"<<endl;
                winner = true;
              }
              break;
            case 2:
              players[i].setPlantado(true);
              break;
          }
        }
      }else
      {
        break;
      }
    }
    cout<<"Quiere Volver a Jugar??"<<endl;
    cout<<"1 Si, 2 No"<<endl;
    cin>>eleccion;
    if(eleccion!=1)
      game_over=true;

    winner = false;
    for(int i=0;i<4;i++)
      players[i].reset();
    for(int i=0; i<52; i++)
    {
      if(mazo[i].getUso())
         mazo[i].setUso();
    }
     //reseteto todas las Cards
  }
}

Card & conseguir_Card(Card * mazo)
{
  int esta=rand()%52;
  bool ya=false;
  while(ya!=true)
  {
    if(!mazo[esta].getUso())
        ya=true;
    else
      esta=rand()%52;
  }
  mazo[esta].setUso();
  return mazo[esta];
}
