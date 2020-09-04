#include "Mikrokontroler.h"
#include <string>
#include <string.h>
#include <locale.h>
#include <iostream>
#include <stdio.h>

using namespace std;
#define bledna_temperatura -274
#define rozmiar_rozkazu_i_echa 1
const char rozkaz_wlaczenia = 'n';
const char rozkaz_wylaczenia = 'f';
const char rozkaz_temperatury = 't';
const char echo_pozytywne = 'k';
const char poczatek_temperatury = '(';
const char koniec_temperatury = ')';


Mikrokontroler::Mikrokontroler(char nazwa_portu[])

{
	setlocale(LC_ALL, "polish");
	Arduino = new SerialPort(nazwa_portu);
	if (Arduino->isConnected())
		{
		cout << "Ustanowiono połączenie" << endl;
		stan_polaczenia = true;
		}
	else
		{ 
		cout << "Nie ustanowiono połączenia" << endl;
		stan_polaczenia = false;
		}
}


Mikrokontroler::~Mikrokontroler()
{
}


const bool Mikrokontroler::Wlacz_chlodzenie()
{
	char rozkaz = rozkaz_wlaczenia;
	char echo = 'x';
	Arduino->writeSerialPort(&rozkaz, rozmiar_rozkazu_i_echa);
	Sleep(10);
	setlocale(LC_ALL, "en_GB");
	while (true)
	{
		if (Arduino->readSerialPort(&echo, rozmiar_rozkazu_i_echa))
		{
			break;
		}	
	};
	if (echo == echo_pozytywne) return true;
	else return false;
		
}

const bool Mikrokontroler::Wylacz_chlodzenie()
{
	char rozkaz = rozkaz_wylaczenia;
	char echo = 'x';
	Arduino->writeSerialPort(&rozkaz, rozmiar_rozkazu_i_echa);
	Sleep(10);
	setlocale(LC_ALL, "en_GB");
	while (true)
	{
		if (Arduino->readSerialPort(&echo, rozmiar_rozkazu_i_echa))
		{
			break;
		}
	};
	if (echo == echo_pozytywne) return true;
	else return false;
}

const bool Mikrokontroler::Odczytaj_temperature()
{
	temperatura = 0;
	string temp;
	char c;
	char rozkaz = rozkaz_temperatury;
	Arduino->writeSerialPort(&rozkaz, rozmiar_rozkazu_i_echa);
	while(true)
		{
		if (Arduino->readSerialPort(&c, 1))
			{
			if (c == poczatek_temperatury)
				{
				while (true)
					{
					if (Arduino->readSerialPort(&c, 1))
						{
						if (c != koniec_temperatury)
							{
							temp += c;
							}
						else
							{
							setlocale(LC_ALL, "en_GB");
							temperatura = stod(temp, NULL);
							temp.clear();
							return true;
							}
						}
					}
						
				}
			}
		}
	}

const double Mikrokontroler::Podaj_temperature()
{
	if(Odczytaj_temperature()) return temperatura;
	else return bledna_temperatura;
}