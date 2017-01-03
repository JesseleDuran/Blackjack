#include <string.h>
#include "Player.h"

void Player::reset()
{
  total=0;
  nCards=0;
  stay=false;
  for(int i=0; i<12; i++)
  {
    hand[i]=NULL;
  }
}

Player::Player()
{
  strcpy(name,"  ");
  total=0;
  nCards=0;
  stay=false;
  for(int i=0; i<12; i++)
  {
    hand[i]=NULL;
  }
}

void Player::deliverCards(Card &a)
{
  hand[nCards]=&a;
  nCards++;
}

void Player::toAdd()
{
  total=0;
  int g;
  int as=0;
  for(int i=0;i<nCards; i+=2)
  {
    if(hand[i]->getNumberS()==1)
      as++;
    if(hand[i+1])
    {
      g=*hand[i]+*hand[i+1];
        if(hand[i+1]->getNumberS()==1)
          as++;
    }
    else
      if(hand[i]->getNumberS()==1)
      {
        if(total+hand[i]->getNumberS()>21)
            g=1;
        else
            g=11;
      }
      else
        g=hand[i]->getNumberS();
    total+=g;
  }
  if(total>21)
    total=total-(11*as)+(as);
}

bool Player::gameIsFinished()
{
  return getTotal()<21 && getStay()!=true;
}