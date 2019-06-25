#include "stdafx.h"
#include "GA.h"



vector<float> GA::selection(double * p_evaluation)
{
	vector<float>  w_vrni(this->getSt_resitev());
	for (int i = 0; i < this->getSt_resitev(); i++) {
		w_vrni[i] = 1.0 / (1.0 + abs(p_evaluation[i]));
	}
	return w_vrni;
}

float GA::total_fitness(vector<float> p_selection)
{
	float w_vrni = 0.0;
	for (int i = 0; i < this->getSt_resitev(); i++) {
		w_vrni += p_selection[i];
	}
	return w_vrni;
}

vector<float> GA::probability(vector<float> p_fitness, float p_total_fitness)
{
	vector<float> w_vrni(this->getSt_resitev());

	for (int i = 0; i < this->getSt_resitev(); i++) {
		w_vrni[i] = p_fitness[i] / p_total_fitness;
	}
	return w_vrni;
}

vector<float> GA::chance(vector<float> probability)
{
	vector<float> w_vrni(this->getSt_resitev());
	w_vrni[0] = 0.0;
	for (int i = 0; i < this->getSt_resitev(); i++)
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


GA::GA(double * p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij, int p_cas_izvajanja, int p_min_meja, int p_max_meja, double p_v_max)
{
	this->setProblem(p_problem);
	this->setVelproblem(p_vel_problem);
	this->setMutacija(p_mutacija);
	this->setSt_resitev(p_st_resitev);
	this->setSt_iteracij(p_st_iteracij);
	this->setCas_izvajanja(p_cas_izvajanja);
	this->setMin_meja(p_min_meja);
	this->setMax_meja(p_max_meja);
	this->polni_populacijo();
}

void GA::init()
{
	this->display();

	for (int i = 0; i < this->getSt_iteracij(); i++) {
		double* evaluation = this->vrni_uspesnost();
		vector<float> fitness = this->selection(evaluation);
		float total_fitness = this->total_fitness(fitness);

		//Probability
		vector<float> probably = this->probability(fitness, total_fitness);
		//Chance
		vector<float> chanc = this->chance(probably);
		// New Chromosome
		//int** new_chromosome = new_chromosomes(chanc, p_chromosome);
		//p_chromosome = new_chromosome;

		//Crossover
		/*float* parent_chance = randNums();
		vector<int> parents = get_parents(parent_chance);
		new_chromosome = crossover(parents, p_chromosome);
		p_chromosome = new_chromosome;
		//Mutation
		new_chromosome = mutation(p_chromosome);
		p_chromosome = new_chromosome;*/
	}

	this->vrni_rezultate();
}

GA::~GA()
{
}
