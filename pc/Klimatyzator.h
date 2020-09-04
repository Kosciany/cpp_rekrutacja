#pragma once
#include "Mikrokontroler.h"


class Klimatyzator
{
private:
	Mikrokontroler * Arduino;
	bool stan;
public:
	Klimatyzator(Mikrokontroler &Uno);
	~Klimatyzator();
	void Wlacz();
	void Wylacz();
	inline const bool SprawdzStan()
	{
		return stan;
	}
};
