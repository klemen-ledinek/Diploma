#pragma once
#include "STO.h"
class GA :
	public STO
{
private:

	double crossover_rate;
	vector<double> selection(double* p_evaluation);
	double total_fitness(vector<double> p_selection);
	vector<double> probability(vector<double> p_fitness, float p_total_fitness);
	vector<double> chance(vector<double> probability);
	vector<vector<double>> parents;

	vector<double> new_chromosome(vector<double> p_chance);
	vector<double> mutate(vector<double> p_chromosome);
	void crossover(vector<double> &p_first, vector<double> &p_second);

	
public:
	GA(double* p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij,
		int p_cas_izvajanja, int p_min_meja, int p_max_meja, double p_v_max, double p_crossover_rate);
	GA(string* p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij,
		int p_cas_izvajanja, int p_min_meja, int p_max_meja, double p_v_max, double p_crossover_rate);
	void init();
	~GA();
};


