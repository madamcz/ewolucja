#ifndef EWOLUCJA_H
#define EWOLUCJA_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <omp.h>
#include <stdlib.h>
#include <thread>
#include <random>

using namespace std;

const float lowerb = -40;
const float upperb = 40;
const float prawd_mutacji1 = 0.3;
const float prawd_mutacji2 = 0.3;
const float mutacja_lowerb = -3;
const float mutacja_upperb = 3;

float randomFloat(float a, float b);
float standardDeviation(vector<float> v);


//struktura osobnika, ktory ma cechy (wymiary) i wartosc przystosowania
struct osobnik
{
	vector<float> punkty;
	float przystosowanie;
	osobnik(int wymiar)
	{
		for(int i = 0; i < wymiar; i++)
		{
			punkty.push_back(randomFloat(lowerb, upperb));
		}
	}
	osobnik() {}
	//przeladowanie operatora < do sortowania
	bool operator <(const osobnik& o)
	{
		return (this->przystosowanie < o.przystosowanie);
	}
};

//klasa algorytmu ewolucyjnego
class Ewolucja
{
public:
	Ewolucja(int mi, int lambda, int wymiar);
	~Ewolucja();
	void ewoluuj();
	void Wypisz();
	void pokazNajlepszego();
	
private:
	int mi, lambda, wymiar;
	void funkcjaPrzystosowania(vector<osobnik>* osVec);
	void reprodukcja();
	void krzyzowanie();
	void mutacja();
	void selekcja();
	vector<osobnik> PopulacjaP, PopulacjaT, PopulacjaR;
	osobnik* najlepszy;
};


#endif