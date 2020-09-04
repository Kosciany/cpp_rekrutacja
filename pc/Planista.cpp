#include "Planista.h"
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>

using namespace std;

#define poczatkowy_czas_cyklu 5
#define wartosc_korekcji_temperatury 0.1
#define wartosc_zmiany_temperatury_zadanej 0.5
#define gorna_granica_cyklu 100
#define bledna_temperatura -274

#define STRALKA_W_GORE 72
#define STRZALKA_W_DOL 80
#define STRZALKA_W_LEWO 75
#define STRZALKA_W_PRAWO 77
#define STRZALKA_WCISNIETA 224
#define ESC 27

Planista::Planista(Sterownik &podany_komputer)
{
	komputer = &podany_komputer;
	czas_cyklu = poczatkowy_czas_cyklu;
}



Planista::~Planista()
{
}

void Planista::Zbierz_znak()
{
if (_kbhit())
	{
	znak_pierwszy = _getch();
	znak_drugi = _getch();
	
	}
}

const int Planista::Decyduj()
{
	if ((znak_pierwszy == STRZALKA_WCISNIETA) && (znak_drugi == STRZALKA_W_LEWO))
	{
		komputer->Zmien_korekte_temperatury(-wartosc_korekcji_temperatury);
		return 1;
	}//<-
	if ((znak_pierwszy == STRZALKA_WCISNIETA) && (znak_drugi == STRZALKA_W_PRAWO))
	{
		komputer->Zmien_korekte_temperatury(wartosc_korekcji_temperatury);
		return 1;
	}//->
	if ((znak_pierwszy == STRZALKA_WCISNIETA) && (znak_drugi == STRALKA_W_GORE))
	{
		komputer->Zmien_temperature_zadana(wartosc_zmiany_temperatury_zadanej);
		return 1;
	}// ^
	if ((znak_pierwszy == STRZALKA_WCISNIETA) && (znak_drugi == STRZALKA_W_DOL))
	{
		komputer->Zmien_temperature_zadana(-wartosc_zmiany_temperatury_zadanej);
		return 1;
	}//v
	if ((znak_pierwszy == '+') && (znak_drugi == 0))
	{
	if (czas_cyklu <= gorna_granica_cyklu)czas_cyklu++;
	return 1;
	}//+
	if ((znak_pierwszy == '-') && (znak_drugi == 0))
	{
		if (czas_cyklu > 1) czas_cyklu--;
		return 1;
	}//-
	if ((znak_pierwszy == ESC) && (znak_drugi == 0)) return 0; //ESC
	else return 2;
}

void Planista::Pokaz_konsole()
{	
	double akt_temp = komputer->Dzialaj_pokaz_aktualna_temperature();
	double zad_temp = komputer->Zwroc_zadana_temperature();
	double hist = komputer->Zwroc_zadana_histereze();
	setlocale(LC_ALL, "polish");
	system("cls");
	cout << "Aktualna temperatura: \t" << akt_temp << endl;
	cout << "Zadana temperatura: \t" << zad_temp << endl;
	cout << "Zadana histereza: \t" << hist << endl;
	cout << "Stan klimatyzatora \t";
	if (komputer->Stan_klimatyzatora()) cout << "W??czony";
	else cout << "Wy??czony";
	cout << endl;
	cout << "Czas od?wie?ania: \t~" << double(double(czas_cyklu) / 10) << "[s]" << endl;
	cout << endl << endl << "Naci?nij ESC zeby wyj??";
	
}


void Planista::Aktualizuj()
{
	setlocale(LC_ALL, "polish");
	int decyzja;
	while (true)
		{
		for (int i = 0; i < 100; i++)
			{
			Zbierz_znak();
			decyzja = Decyduj();
			if (decyzja == 0)
			{
				cout << "koniec" << endl;
				return;
			}
			else if (decyzja == 1)
			{
				Pokaz_konsole();
			}
			znak_pierwszy = 0;
			znak_drugi = 0;
			Sleep(czas_cyklu);
			}
		Pokaz_konsole();
	}
}

