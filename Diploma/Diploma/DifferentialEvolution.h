#pragma once
#include "StochasticAlgorithm.h"
class DifferentialEvolution :
	public StochasticAlgorithm
{
private:
	double crossover_rate;
	double mutacija;
	vector<double> nov_agent(vector<double> p_a, vector<double> p_b, vector<double> p_c);
public:
	DifferentialEvolution(double* p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij, 
		int p_cas_izvajanja, double p_min_meja, double p_max_meja, double p_crossover_rate, double p_target);
	DifferentialEvolution(string* p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij,
		int p_cas_izvajanja, double p_min_meja, double p_max_meja, double p_crossover_rate, double p_target);
	void init();
	double run();
	void show_bestPopulant();
	void show_bestFitnes();
	double get_bestFitnes();
	void refresh();
	void wait();
	~DifferentialEvolution();
};

