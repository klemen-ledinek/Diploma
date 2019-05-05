// Diploma.cpp : Programsko ogordje za razvoj stohastičnih algoritmov
// Avtor       : Klemen Ledinek
// Datum	   : 28.02.2019

#include "stdafx.h"
#include "DE_Alghoritm.h"
#include "PSO_Alghoritm.h"
#include "Problem.h"
#include "Operatorji.h"
#include "Alghoritm.h"


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
	


	Alghoritm alg = Alghoritm();
	alg.execute();
	
	//DE
	//TODO Določi problem?? Class problem mogoče? Deluje
	//DE_Alghoritm de = DE_Alghoritm(100, 0.1,0.5, 10,-10,10);
	//de.runIt();

	//PSO
	//PSO_Alghoritm pso =  PSO_Alghoritm(50, 3, 99, 200, 10.0, -100, 100);
	//pso.runIt();
	
}


