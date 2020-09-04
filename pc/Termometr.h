#pragma once
#include "Mikrokontroler.h"
class Termometr
{
private:
	Mikrokontroler * Arduino;
	double aktualna_temperatura;
public:
	Termometr(Mikrokontroler &Uno);
	~Termometr();
	double Zmierz_temperature();
};

