#include "ewolucja.h"
#include <iostream>
#include <sstream>

//TODO
//zrobic mutacje zalezna od najlepszego osobnika??
//chodzi o to, ze mutacja powyzej 1 wplywa na szybsze zbieganie w poczatkowych fazach
//ale gdy wymiary sa juz blisko zera, tak duza zmiana pogarsza wynik (niewazne czy + czy -)
//bo oddala rozwiazanie od 0, wtedy lepsza by byla zmiana na poziomie ulamkow

//auto dopasowanie
//stworzyc plik z wygenerowanymi chechami (dla n osobnikow i w wymiarow)
//i na tym samym zestawie przeprowadzic automatyczne testy zeby dobrac parametry
//takie jak szanse mutacji czy wartosci o jakie mutuja sie cechy


void start(int &m, int &l, int &w, int &i, bool &c);

int main(int argc, char* argv[])
{
	int m, l, w, iter = 0;
	bool czesciowe = false;
	//start(m, l, w, iter, czesciowe);			//zapytaj o parametry
	if (argc < 9)
	{
		cout << "not enough parameters" << endl << "usage: -m <mi> -l <lambda> -w <dimensions> -i <iterations>";
		cout << endl;
		system("PAUSE");
		exit(1);
	}

	//rozpoznaj podane parametry
	for (int i = 1; i < (argc - 1);i++)
	{
		if (string(argv[i]) == "-m")
		{
			m = atoi(argv[i + 1]);
		}
		if (string(argv[i]) == "-l")
		{
			l = atoi(argv[i + 1]);
		}
		if (string(argv[i]) == "-w")
		{
			w = atoi(argv[i + 1]);
		}
		if (string(argv[i]) == "-i")
		{
			iter = atoi(argv[i + 1]);
		}
	}//for argv
	cout << "m: " << m << " l: " << l << " w: " << w << " i: " << iter << endl;

	Ewolucja ewo(m, l, w);
	for(; iter > 0; iter--)
	{
		ewo.ewoluuj();
		if(czesciowe && (! (iter % 20)) )
			ewo.pokazNajlepszego();
	}
	//ewo.Wypisz();
	cout << endl << "Tadam! Oto wynik: " << endl;
	ewo.pokazNajlepszego();

	system("PAUSE");
	return 0;
}


void start(int &m, int &l, int &w, int &i, bool &c)
{
	string in;
	cout << "Algorytm ewolucyjny. Podaj wartosci parametrow." << endl;

	cout << "mi: " << endl;
	cin >> in;
	istringstream iss(in);
	iss >> m;

	cout << "lambda: " << endl;
	cin >> in;
	istringstream iss1(in);
	iss1 >> l;

	cout << "wymiar: " << endl;
	cin >> in;
	istringstream iss2(in);
	iss2 >> w;

	cout << "liczba iteracji: " << endl;
	cin >> in;
	istringstream iss3(in);
	iss3 >> i;

	cout << "czy drukowac wyniki czesciowe? (t/n): " << endl;
	cin >> in;
	if(in == "t")
		c = true;
	else 
		c = false;
}