// Diploma.cpp : Programsko ogordje za razvoj stohastičnih algoritmov
// Avtor       : Klemen Ledinek
// Datum	   : 28.02.2019
#include <stdio.h>
#include <stdlib.h>

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <time.h>
#include <iterator>


using namespace std;


int randNum() {
	int range = (100 - 0) + 1;
	return  0 + (rand()% range) ;
}

int main()
{
	srand(time(NULL)); //seed of random numbers
	int w_vector[5] = { randNum(),randNum() ,randNum() ,randNum() ,randNum() };
	cout << "\n Izpis vrednosti vektorja ";
	for(int i = 0; i < size(w_vector); i++)
	{
		cout << w_vector[i];	
	}
	
}


