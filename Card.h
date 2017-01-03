#ifndef CARD_H
#define CARD_H

enum pinta{trebol=1,corazon=2,pica=3,diamante=4,nada=-1};
class Card
{
  pinta pintas;
  int number;
  bool inUse;
public:
  Card(int n=-1, pinta p = nada) : number(n),pintas(p), inUse(false) {}

  void setCard(int numero,pinta pintica);
  
  pinta getPinta(){return pintas;}
  
  int getNumero(){return number;}
  
  int getNumeroS();
  
  int getNumeroS(int n);
  
  void setUso();
  
  bool getUso(){return inUse;}
  //~Card();
  //ESTO DE ABAJO ES SOBRE ESCRITURA DE OPERADORES!
  int operator+(const Card& a);
  
  int operator=(const Card& a);
};

#endif