#include "stdafx.h"
#include "GeneticAlghoritm.h"
using namespace std;

GeneticAlghoritm::GeneticAlghoritm() {

}



GeneticAlghoritm::~GeneticAlghoritm()
{
}

int ** GeneticAlghoritm::executeGeneticAlghortim(int ** p_chromosome, vector<int> p_vector, int p_number_of_iterations)
{
	srand(time(NULL));
	for (int i = 0; i < p_number_of_iterations; i++) {
		//Evaluation
		vector<int> eval = evaluation(p_chromosome, p_vector);
		//Fitness
		vector<float> fitness = selection(eval);
		float total_fitness = get_total_fitness(fitness);
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(3);
		//Probability
		vector<float> probably = probability(fitness, total_fitness);
		//Chance
		vector<float> chanc = chance(probably);

		// New Chromosome
		int** new_chromosome = new_chromosomes(chanc, p_chromosome);
		p_chromosome = new_chromosome;
		//Crossover
		float* parent_chance = randNums();
		vector<int> parents = get_parents(parent_chance);
		new_chromosome = crossover(parents, p_chromosome);
		p_chromosome = new_chromosome;
		//Mutation
		new_chromosome = mutation(p_chromosome);
		p_chromosome = new_chromosome;
	}
	return p_chromosome;
}
