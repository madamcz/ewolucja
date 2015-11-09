#include "ewolucja.h"

float randomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

Ewolucja::Ewolucja(int mi, int lambda, int wymiar)
	:mi(mi)
	,lambda(lambda)
	,wymiar(wymiar)
{
	for(int i = 0; i < mi; i++)
	{
		PopulacjaP.push_back(osobnik(wymiar));
	}

}

void Ewolucja::ewoluuj()
{
	reprodukcja();
	krzyzowanie();
	mutacja();
}

void Ewolucja::Wypisz()
{
	for(int i = 0; i < PopulacjaP.size(); i++)
	{
		cout << "Osobnik " << i << " puntky: ";
		for(int j = 0; j < PopulacjaP[i].punkty.size(); j++)
		{
			cout << PopulacjaP[i].punkty[j] << ", ";
		}
		cout << endl;
	}

	cout << "populacja potomkow" << endl;
	for(int i = 0; i < PopulacjaT.size(); i++)
	{
		cout << "Osobnik " << i << " puntky: ";
		for(int j = 0; j < PopulacjaT[i].punkty.size(); j++)
		{
			cout << PopulacjaT[i].punkty[j] << ", ";
		}
		cout << endl;
	}
}

void Ewolucja::funkcjaPrzystosowania(vector<osobnik> osVec)
{
	vector<osobnik>::iterator it = osVec.begin();

	for(; it < osVec.end(); ++it)
	{
		float suma = 0.0, iloczyn = 0.0;
		for(int i = 0; i < (*it).punkty.size(); i++)
		{
			suma += (*it).punkty[i] * (*it).punkty[i];
			iloczyn *= std::cos((*it).punkty[i]/i);
		}
		(*it).przystosowanie = (1/40) * suma + 1 - iloczyn;
	}
}

void Ewolucja::reprodukcja()
{
	for(int i = 0; i < lambda; i++)
	{
		int ran = rand() % mi;
		PopulacjaT.push_back(PopulacjaP[ran]);
	}
}

void Ewolucja::krzyzowanie()
{
	int locus = wymiar/2;
	for(int i = 0; i < PopulacjaT.size(); i+=2)
	{
		//int locus = rand() % (wymiar - 1) + 1;

		vector<float>::iterator it1 = PopulacjaT[i].punkty.begin();
		vector<float>::iterator it2 = PopulacjaT[i+1].punkty.begin();
		vector<float> potomek1, potomek2;

		//krzyzowanie osobnikow
		potomek1.reserve(wymiar);
		potomek1.insert(potomek1.begin(), it1, it1 + locus);
		potomek1.insert(potomek1.begin() + locus, it2 + locus, it2 + wymiar);

		potomek2.reserve(wymiar);
		potomek2.insert(potomek2.begin(), it1 + locus, it1 + wymiar);
		potomek2.insert(potomek2.begin() + (wymiar - locus), it2, it2 + locus);

		PopulacjaT[i].punkty = potomek1;
		PopulacjaT[i+1].punkty = potomek2;
	}
}

void Ewolucja::mutacja()
{

}

float standardDeviation(vector<float> v)
{
	double sum = std::accumulate(std::begin(v), std::end(v), 0.0);
	double m =  sum / v.size();

	double accum = 0.0;
	std::for_each (std::begin(v), std::end(v), [&](const double d) {
		accum += (d - m) * (d - m);
	});

	float stdev = sqrt(accum / (v.size()-1));

	return stdev;
}