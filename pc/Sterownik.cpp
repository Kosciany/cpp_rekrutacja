#include "Sterownik.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
Sterownik::Sterownik(Klimatyzator &klimatyzator, Termometr &termometr, double zadana, double korekta)
{
	wiatraczek = &klimatyzator;
	ds18b20 = &termometr;
	temperatura_zadana = zadana;
	korekta_temperatury = korekta;
}


Sterownik::~Sterownik()
{
}

double Sterownik::Pobierz_temperature()
{
	return ds18b20->Zmierz_temperature();
}

void Sterownik::Wlacz_klimatyzator()
{

	wiatraczek->Wlacz();
}

void Sterownik::Wylacz_klimatyzator()
{
	wiatraczek->Wylacz();
}

const double Sterownik::Dzialaj_pokaz_aktualna_temperature()
{
	const double temperatura = Pobierz_temperature();
	if (wiatraczek->SprawdzStan())
		{
		if (temperatura <= (temperatura_zadana - korekta_temperatury)) Wylacz_klimatyzator();
		}
	else
		{
		if (temperatura > (temperatura_zadana + korekta_temperatury)) Wlacz_klimatyzator();
		}
	return temperatura;
}

void Sterownik::Zmien_temperature_zadana(double skladnik_dodawany)
{
	if (((temperatura_zadana + skladnik_dodawany) < dolna_granica) || ((temperatura_zadana + skladnik_dodawany) > gorna_granica)) return;
	else temperatura_zadana += skladnik_dodawany;
}

void Sterownik::Zmien_korekte_temperatury(double skladnik_dodawany)
{
	if (korekta_temperatury + skladnik_dodawany > granica_histerezy || korekta_temperatury + skladnik_dodawany < 0.1) return;
	else korekta_temperatury += skladnik_dodawany;
}