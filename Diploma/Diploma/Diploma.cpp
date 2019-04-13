// Diploma.cpp : Programsko ogordje za razvoj stohastičnih algoritmov
// Avtor       : Klemen Ledinek
// Datum	   : 28.02.2019

#include "stdafx.h"
#include "GeneticAlghoritm.h"

int randomInt(int p_min, int p_max) {
	int range = (p_min - p_max) + 1;
	return p_min + (rand() % range);
}
double randomDouble(int p_min, int p_max) {
	double w_vrni = (double)rand() / RAND_MAX;
	return p_min + w_vrni * (p_max - p_min);
}
double* get_fitness(double p_population[],int p_size) {
	double* w_vrni = new double[p_size];
	for (int i = 0; i < p_size; i++) {
		w_vrni[i] = abs((p_population[i] - 15 + (p_population[i] * 3)) - 8);
	}
	return w_vrni;
}
double get_single_fitness(double p_agent) {
	double w_vrni = abs((p_agent - 15 +  (p_agent * 3) )- 8 );
	return w_vrni;
}
int get_best(double p_fitness[], int p_size) {
	int w_vrni = 0;
	for (int i = 1; i < p_size; i++) {
		if (p_fitness[i] < p_fitness[w_vrni]) {
			w_vrni = i;
		}
	}
	return w_vrni;
}
int main()
{
	srand(time(NULL)); //seed of random numbers
	/*vector<int> w_vector = { 1,2 ,3 ,4, 30 };
	cout << "\n Izpis vrednosti vektorja ";
	cout <<endl<< w_vector[0]<<"a + "<< w_vector[1]<< "b + "<< w_vector[2]<< "c + "<< w_vector[3]<<"d =  "<< w_vector[4];
	
	//Random chromosome
	int** chromosome = GeneticAlghoritm().randomChromosome();
	for (int i = 0; i < 6; i++) {
		cout << endl << "Chromosome " << i << ": " << endl;
		for (int j = 0; j < 4; j++) {
			cout << chromosome[i][j] << " ";
		}
	}
	chromosome = GeneticAlghoritm().executeGeneticAlghortim(chromosome, w_vector, 2);
	cout << endl << endl << "Zadnja iteracija "<< endl;
	for (int x = 0; x < 6; x++) {
		cout << endl << "Chromosome " << x << endl;
		for (int y = 0; y < 4; y++) {
			cout << chromosome[x][y] << " ";
		}
	}
	int* bestChromosome = GeneticAlghoritm().get_fitest(chromosome, w_vector);
	cout <<endl<< endl << "Best chromosome"<<endl<<endl;
	for (int y = 0; y < 4; y++) {
		cout << bestChromosome[y] << " ";
	}
	*/

	int number = 10;
	double F = 0.5;
	double cr = 0.1;
	double population[10];
	printf("\nFunction is:  x - 15 + x*3 = 8");
	for (int i = 0; i < 10; i++) {
		population[i] = randomDouble(-10,50);
		printf("\n Populacija %d, %2.3f",i+1,population[i]);
	} 
	double* fitness = get_fitness(population, 10);


	// Foor Loop here
	for (int iter = 0; iter < 100; iter++) {
		
		for (int i = 0; i < 10; i++) {
			int a = randomInt(0, 9);
			int b = randomInt(0, 9);
			int c = randomInt(0, 9);
			while (a == i || b == i || c == i || a == b || a == c || b == c) {
				a = randomInt(0, 9);
				b = randomInt(0, 9);
				c = randomInt(0, 9);
			}
			double a_agent = population[a];
			double b_agent = population[b];
			double c_agent = population[c];

			double a_eval = get_single_fitness(a_agent);
			double b_eval = get_single_fitness(b_agent);
			double c_eval = get_single_fitness(c_agent);

			double r_agent = a_agent + F * (b_agent - c_agent);
			double r_eval = get_single_fitness(r_agent);
			double chance = randomDouble(0, 1);
			if (chance < cr && r_eval < fitness[i]) {
				fitness[i] = r_eval;
				population[i] = r_agent;
			}
		}
	}
	
	printf("\nBest agent is %2.3f", population[get_best(fitness, 10)]);
	printf("\nAfter iteration");
	for (int i = 0; i < 10; i++) {
		printf("\n Populacija %d, %2.3f", i + 1, population[i]);
	} 
	
}


