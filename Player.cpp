#include <string.h>
#include "Player.h"

void Player::reset()
{
  suma=0;
  cCards=0;
  plantado=false;
  for(int i=0; i<12; i++)
  {
    man[i]=NULL;
  }
}

Player::Player(){
  strcpy(nombre,"  ");
  suma=0;
  ganadas=0;
  cCards=0;
  plantado=false;
  for(int i=0; i<12; i++){
    man[i]=NULL;
  }
}

void Player::darCard(Card &a)
{
  man[cCards]=&a;
  cCards++;
}

void Player::sumar()
{
  suma=0;
  int g;
  int as=0;
  for(int i=0;i<cCards; i+=2){
    if(man[i]->getNumeroS()==1)
      as++;
    if(man[i+1]){
    g=*man[i]+*man[i+1];
    if(man[i+1]->getNumeroS()==1)
      as++;
  }
    else
      if(man[i]->getNumeroS()==1){
        if(suma+man[i]->getNumeroS()>21)
            g=1;
        else
            g=11;
      }
      else
        g=man[i]->getNumeroS();
    suma+=g;
  }
  if(suma>21)
    suma=suma-(11*as)+(as);
}