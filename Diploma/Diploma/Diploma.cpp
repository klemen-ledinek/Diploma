// Diploma.cpp : Programsko ogordje za razvoj stohastičnih algoritmov
// Avtor       : Klemen Ledinek
// Datum	   : 28.02.2019

#include "stdafx.h"
#include "DE_Alghoritm.h"
#include "PSO_Alghoritm.h"
#include "Problem.h"
#include "DE.h"
#include "Alghoritm.h"
#include "PSO.h"
#include "GA.h"
#include "GeneticAlghoritm.h"


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
	

	double* problem = new double[3];
	problem[0] = 1.0;
	problem[1] = 2.0;
	problem[2] = 3.0;

	//DE  #DONE
	DE novDe = DE(problem, 3, 0.1, 10, 10, 0, -50, 50, 0.5);
	novDe.init();

	//PSO #DONE
	PSO novPso = PSO(problem, 3, 0.1, 10, 10, 0, -50, 50, 20);
	novPso.init();
	//GA #DONE
	//GA novGa = GA(problem, 3, 0.1, 10, 10, 0, 0, 50, 20, 0.5);
	//novGa.init();



	//double *x = novDe.vrniRezultate();
	//double *y = novPso.vrniRezultate();
	//vector<int> abs_results(10);
	//vector<int> results(10);
	//for (int i = 0; i < 10; i++) {
		//abs_results[i] = x[i] - y[i];
		//results[i] = abs(abs_results[i]);
	//}
	//double assumed_median = 0.0;


}


