#pragma once
#include "SerialPort.h"
class Mikrokontroler
{
private:
	SerialPort* Arduino;
	double temperatura;
	bool stan_polaczenia;
public:
	Mikrokontroler(char nazwa_portu[]);
	~Mikrokontroler();
	const bool Wlacz_chlodzenie();
	const bool Wylacz_chlodzenie();
	const bool Odczytaj_temperature();
	const double Podaj_temperature();
	inline const bool Sprawdz_stan()
	{
		return stan_polaczenia;
	}
};

