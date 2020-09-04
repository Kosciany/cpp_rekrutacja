
#include <iostream>
#include <conio.h>
#include "Mikrokontroler.h"
#include "Termometr.h"
#include "Klimatyzator.h"
#include "Sterownik.h"
#include "Planista.h"
#include <locale.h>

using namespace std;
char nazwa_portu[] = "\\\\.\\COM3";
#define temperatura_poczatkowa 25
#define histereza_poczatkowa 0.5


int main()
{
	Mikrokontroler Uno(nazwa_portu);
	if (Uno.Sprawdz_stan())
	{
		Termometr termometr(Uno);
		Klimatyzator klimatyzator(Uno);
		Sterownik komputer(klimatyzator, termometr, temperatura_poczatkowa, histereza_poczatkowa);
		Planista szef(komputer);
		szef.Aktualizuj();
		return 0;
	}
	else
	{
		setlocale(LC_ALL, "polish");
		cout << "Brak Arduino. Program umiera." << endl << "Naciśnij dowolny klawisz, aby kontynuować..." << endl;
		_getch();
		return -1;
	}
}


