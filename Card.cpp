#include "Card.h"

int Card::getNumeroS()
{
  if(getNumero()>10 && getNumero()<=13)
    return 10;
  else
    return number;
}

int Card::getNumeroS(int n)
{
  if(n>10 && n<=13)
    return 10;
  else
    return n;
}

void Card::setCard(int number,pinta pintica)
{
  this->number=number;
  this->pintas=pintica;
}

void Card::setUso()
{
  if(this->inUse)
    inUse=false;
}


int Card::operator+(const Card& a)
{
	int suma;
	if(this->getNumeroS()==1 && this->getNumeroS(a.number)==1){
	  suma=12;
	  }
	else if(this->getNumeroS()==1){
	  if(11+this->getNumeroS(a.number)<=21)
	    suma=11+this->getNumeroS(a.number);
	  else
	    suma=this->getNumeroS()+this->getNumeroS(a.number);
	}
	else if(this->getNumeroS(a.number)==1){
	   if(11+this->getNumeroS()<=21)
	    suma=11+this->getNumeroS();
	  else
	    suma=this->getNumeroS()+this->getNumeroS(a.number);
	}
	else{
	  suma=this->getNumeroS()+this->getNumeroS(a.number);
	}

	 return suma;
}