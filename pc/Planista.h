#pragma once
#include "Sterownik.h"
class Planista
{
private:
	Sterownik * komputer;
	int czas_cyklu;
	int znak_pierwszy, znak_drugi;
	void Zbierz_znak();
	const int Decyduj();
	void Pokaz_konsole();
public:
	Planista(Sterownik &podany_komputer);
	~Planista();
	void Aktualizuj();
	
};

