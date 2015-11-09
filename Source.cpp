#include "ewolucja.h"
#include <iostream>

//TODO
//pamietac o randomie przy wersji rownoleglej

int main()
{
	Ewolucja ewo(10, 4, 4);
	ewo.ewoluuj();
	ewo.Wypisz();

	system("PAUSE");
	return 0;
}