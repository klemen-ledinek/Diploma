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
#include <iomanip>


using namespace std;


int randNum() {
	int range = (30 - 0) + 1;
	return  0 + (rand()% range) ;
}
float randNumFloat() {
	return 0.0+ (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
}
int** randomChromosome() {
	int** p_chromosome;
	p_chromosome = new int *[6];
	for (int i = 0; i < 6; i++) {
		p_chromosome[i] = new int[4];
		for (int j = 0; j < 4; j++) {
			p_chromosome[i][j] = randNum();
		}
	}
	return p_chromosome;
}

int getSumChromosome(int** p_chromosome, int* p_vector,int p_chormosome_num) {
	int w_vrni = 0;
	for (int j = 0; j < 4; j++) {
			w_vrni += p_chromosome[p_chormosome_num][j] * p_vector[j];
	}
	
	return w_vrni;
}

int* evaluation(int** p_chromosome, int p_vector[5]) {
	int* w_vrni = new int[6];

	for (int i = 0; i < 6; i++) {
		w_vrni[i] = getSumChromosome(p_chromosome, p_vector, i);
	}

	return w_vrni;
}
float* selection(int* p_evaluation) {
	float* w_vrni = new float[6];
	for (int i = 0; i < 6; i++) {
		w_vrni[i] = 1.0 / (1.0 + p_evaluation[i]);
	}
	return w_vrni;
}

float* probability(float* p_fitness, float p_total_fitness) {
	float* w_vrni = new float[6];

	for (int i = 0; i < 6; i++) {
		w_vrni[i] = p_fitness[i] / p_total_fitness;
	}
	return w_vrni;
}

float* chance(float* probability) {
	float* w_vrni = new float[6];
	w_vrni[0] = 0.0;
	for (int i = 0; i < 6; i++)
	{
		if (i == 0) {
			w_vrni[i] = w_vrni[i] + probability[i];
		}
		else {
			w_vrni[i] = w_vrni[i - 1] + probability[i];
		}
	}
	return w_vrni;
}

int** new_chromosomes(float* p_chance, int** p_chromosome) {
	int** w_vrni = new int*[6];
	float w_chance = randNumFloat();
	for (int i = 0; i < 6; i++)
	{
		w_chance = randNumFloat();
		if (w_chance > p_chance[0] && w_chance < p_chance[1]) {

		}
		else if (w_chance > p_chance[1] && w_chance < p_chance[2]) {

		}
		else if (w_chance > p_chance[2] && w_chance < p_chance[3]) {

		}
		else if (w_chance > p_chance[3] && w_chance < p_chance[4]) {

		}
		else if (w_chance > p_chance[4] && w_chance < p_chance[5]) {

		}
		else if (w_chance > p_chance[5] && w_chance < p_chance[6]) {

		}
	}
	
	return w_vrni;
}
int main()
{
	srand(time(NULL)); //seed of random numbers
	int w_vector[5] = { 1,2 ,3 ,4, 30 };
	cout << "\n Izpis vrednosti vektorja ";
	cout <<endl<< w_vector[0]<<"a + "<< w_vector[1]<< "b + "<< w_vector[2]<< "c + "<< w_vector[3]<<"d =  "<< w_vector[4];
	
	//Random chromosome
	int** chromosome = randomChromosome();

	for (int i = 0; i < 6; i++) {
		cout << endl << "Chromosome " << i << ": " << endl;
		for (int j = 0; j < 4; j++) {
			cout << chromosome[i][j] << " ";
		}
	}
	//Evaluation
	int* eval = evaluation(chromosome, w_vector);

	cout << endl << "Evaloation of Chromosomes  : " << endl;
	for (int j = 0; j < 6; j++) {
		cout <<"Chromosome "<<j<<": "<< eval[j] << " "<<endl;
	}
	
	//Fitness

	float* fitness = selection(eval);

	float total_fitness = 0.0;
	cout << endl << "Fitness of Chromosomes  : " << endl;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	for (int i = 0; i < 6; i++) {
		cout << "Chromosome " << i << ": " << fitness[i] << " " << endl;
		total_fitness += fitness[i];
	}
	cout << endl << "Total Fitness: " << total_fitness;

	//Probability
	
	float* probably = probability(fitness, total_fitness);
	cout << endl << "Probability of Chromosomes  : " << endl;
	for (int i = 0; i < 6; i++) {
		cout << "Chromosome " << i << ": " << probably[i] << " " << endl;
	}

	//Chance

	float* chanc = chance(probably);
	cout << endl << "Chance of Chromosomes  : " << endl;
	for (int i = 0; i < 6; i++) {
		cout << "Chromosome " << i << ": " << chanc[i] << " " << endl;
	}

	int** new_chromosome;

}


