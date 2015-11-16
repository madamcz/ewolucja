#include "ewolucja.h"
#include <iostream>

//TODO
//pamietac o randomie przy wersji rownoleglej
//zrobic mutacje zalezna od najlepszego osobnika??
//chodzi o to, ze mutacja powyzej 1 wplywa na szybsze zbieganie w poczatkowych fazach
//ale gdy wymiary sa juz blisko zera, tak duza zmiana pogarsza wynik (niewazne czy + czy -)
//bo oddala rozwiazanie od 0, wtedy lepsza by byla zmiana na poziomie ulamkow

//auto dopasowanie
//stworzyc plik z wygenerowanymi chechami (dla n osobnikow i w wymiarow)
//i na tym samym zestawie przeprowadzic automatyczne testy zeby dobrac parametry
//takie jak szanse mutacji czy wartosci o jakie mutuja sie cechy

int main()
{
	Ewolucja ewo(300, 50, 100);
	for( int i = 0; i < 10000; i++)
	{
		ewo.ewoluuj();
		if(! (i % 20) )
			ewo.pokazNajlepszego();
	}
	//ewo.Wypisz();
	cout << endl << "Tadam! Oto wynik: " << endl;
	ewo.pokazNajlepszego();

	system("PAUSE");
	return 0;
}