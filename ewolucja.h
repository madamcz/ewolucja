#ifndef EWOLUCJA_H
#define EWOLUCJA_H

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

const int lowerb = -40;
const int upperb = 40;

float randomFloat(float a, float b);
float standardDeviation(vector<float> v);

struct osobnik
{

	vector<float> punkty;
	vector<float> odchylenia;
	float przystosowanie;
	osobnik(int wymiar)
	{
		for(int i = 0; i < wymiar; i++)
		{
			punkty.push_back(randomFloat(lowerb, upperb));
		}
		odchylenia = vector<float>(wymiar, standardDeviation(punkty));
		cout << "Odchylenie: " << odchylenia[0] << endl;
	}
};

class Ewolucja
{
public:
	Ewolucja(int mi, int lambda, int wymiar);
	void ewoluuj();
	void Wypisz();
private:
	int mi, lambda, wymiar;
	void funkcjaPrzystosowania(vector<osobnik> osVec);
	void reprodukcja();
	void krzyzowanie();
	void mutacja();
	vector<osobnik> PopulacjaP, PopulacjaT, PopulacjaR;
};


#endif