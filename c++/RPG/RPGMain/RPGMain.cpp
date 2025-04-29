// RPGMain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "Hero.h"

int main()
{
  Hero *borec = new Hero(100, 20, "Borec");
  Monster *drak = new Monster(100, 10, 20);
  borec->shout(drak);
  while (drak->isAlive())
  {
    borec->attack(drak);
  }

    return 0;
}

