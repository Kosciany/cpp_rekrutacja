
#include "Klimatyzator.h"
#include <iostream>


Klimatyzator::Klimatyzator(Mikrokontroler &Uno)
{
	Arduino = &Uno;
	Arduino->Wylacz_chlodzenie();
	stan = false;
}


Klimatyzator::~Klimatyzator()
{
	Arduino->Wylacz_chlodzenie();
}

void Klimatyzator::Wlacz()
{
	if (Arduino->Wlacz_chlodzenie()) stan = true;
}

void Klimatyzator::Wylacz()
{
	if (Arduino->Wylacz_chlodzenie()) stan = false;
}
