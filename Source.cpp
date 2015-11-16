#include "ewolucja.h"
#include <iostream>

//TODO
//pamietac o randomie przy wersji rownoleglej

int main()
{
	Ewolucja ewo(300, 50, 10);
	for( int i = 0; i < 1000; i++)
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