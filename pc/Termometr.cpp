#include "Termometr.h"


Termometr::Termometr(Mikrokontroler &Uno)
{
	Arduino = &Uno;
}


Termometr::~Termometr()
{
}

double Termometr::Zmierz_temperature()
{
	aktualna_temperatura = Arduino->Podaj_temperature();
	return aktualna_temperatura;
}