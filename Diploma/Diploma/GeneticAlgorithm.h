#pragma once
#include "StochasticAlgorithm.h"
class GeneticAlgorithm :
	public StochasticAlgorithm
{
private:

	double crossover_rate;
	double mutacija;
	vector<double> selection(double* p_evaluation);
	double total_fitness(vector<double> p_selection);
	vector<double> probability(vector<double> p_fitness, float p_total_fitness);
	vector<double> chance(vector<double> probability);
	vector<vector<double>> parents;

	vector<double> new_chromosome(vector<double> p_chance);
	vector<double> mutate(vector<double> p_chromosome);
	void crossover(vector<double> &p_first, vector<double> &p_second);

	
public:
	GeneticAlgorithm(double* p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij,
		int p_cas_izvajanja, double p_min_meja, double p_max_meja, double p_v_max, double p_crossover_rate, double p_target);
	GeneticAlgorithm(string* p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij,
		int p_cas_izvajanja, double p_min_meja, double p_max_meja, double p_v_max, double p_crossover_rate, double p_target);
	void init();

	void show_bestPopulant();
	void show_bestFitnes();
	double get_bestFitnes();
	double run();
	void wait();
	void refresh();

	~GeneticAlgorithm();
};


