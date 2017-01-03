#include "Card.h"

int Card::getNumberS()
{
  if(getNumber()>10 && getNumber()<=13)
    return 10;
  else
    return number;
}

int Card::getNumberS(int n)
{
  if(n>10 && n<=13)
    return 10;
  else
    return n;
}

void Card::setCard(int number,suit otherSuit)
{
  this->number=number;
  this->suits=otherSuit;
}

void Card::setUse()
{
  if(this->inUse)
    inUse=false;
}

int Card::operator+(const Card& a)
{
	int total;
	if(this->getNumberS()==1 && this->getNumberS(a.number)==1)
	{
	  total=12;
	}
	else if(this->getNumberS()==1)
	{
	  if(11+this->getNumberS(a.number)<=21)
	    total=11+this->getNumberS(a.number);
	  else
	    total=this->getNumberS()+this->getNumberS(a.number);
	}
	else if(this->getNumberS(a.number)==1)
	{
	   if(11+this->getNumberS()<=21)
	    total=11+this->getNumberS();
	  else
	    total=this->getNumberS()+this->getNumberS(a.number);
	}
	else
	{
	  total=this->getNumberS()+this->getNumberS(a.number);
	}

	 return total;
}