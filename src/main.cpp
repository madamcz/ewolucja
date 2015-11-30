#include "ewolucja.h"
#include <iostream>
#include <sstream>
#include <omp.h>
#include <limits>

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


void start(int &m, int &l, int &w, int &i, bool &c);
int convArgv(char* argv);
void wait();

int main(int argc, char **argv)
{
	bool czesciowe = false;
	if (argc < 4) {
		std::cout << "\nNieprawidłowa liczba argumentów!" << std::endl;
		return 1;
	}
	int mi = convArgv(argv[1]);
	int lambda = convArgv(argv[2]);
	int dim = convArgv(argv[3]);
	int i = convArgv(argv[4]); 

	double time_run, time_start = omp_get_wtime();
	Ewolucja ewo(mi, lambda, dim);
	for(; i > 0; i--)
	{
		ewo.ewoluuj();
		if(czesciowe && (! (i % 20)) )
			ewo.pokazNajlepszego();
	}
	time_run = omp_get_wtime() - time_start;
	//ewo.Wypisz();
	std::cout << "Wynik: " << std::endl;
	ewo.pokazNajlepszego();
	std::cout << "Czas: " << time_run << std::endl;

	wait();
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

int convArgv(char* argv) {
    int temp;
    std::istringstream ss(argv);
    if (ss >> temp) {
        return temp;
    } else {
        std::cout << "\nNieprawidłowy argument" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void wait() {
    std::cout << std::endl << "Nacisnij ENTER aby kontynuuować..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}