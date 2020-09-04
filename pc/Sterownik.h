#pragma once
#include "Klimatyzator.h"
#include "Termometr.h"
#define minimalna_granica_zadanej_temperatury 18
#define maksymalna_granica_zadaniej_temperatury 30
#define maskymalna_polszerokosc_histerezy 2
class Sterownik
{
private:
	Klimatyzator* wiatraczek;
	Termometr* ds18b20;
	double temperatura_zadana;
	double korekta_temperatury;
	double dolna_granica = minimalna_granica_zadanej_temperatury, gorna_granica = maksymalna_granica_zadaniej_temperatury, granica_histerezy = maskymalna_polszerokosc_histerezy;
public:
	Sterownik(Klimatyzator &klimatyzator, Termometr &termomierz, double zadana, double korekta);
	~Sterownik();
	double Pobierz_temperature();
	void Wlacz_klimatyzator();
	void Wylacz_klimatyzator();
	const double Dzialaj_pokaz_aktualna_temperature();
	void Zmien_temperature_zadana(double skladnik_dodawany);
	void Zmien_korekte_temperatury(double skladnik_dodawany);
	inline const double Zwroc_zadana_temperature()
	{
		return temperatura_zadana;
	}
	inline const double Zwroc_zadana_histereze()
	{
		return korekta_temperatury;
	}
	inline bool Stan_klimatyzatora()
	{
		return wiatraczek->SprawdzStan();
	}
};

