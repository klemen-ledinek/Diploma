#pragma once
#include "STO.h"
class GA :
	public STO
{
private:

	vector<float> selection(double* p_evaluation);
	float total_fitness(vector<float> p_selection);
	vector<float> probability(vector<float> p_fitness, float p_total_fitness);
	vector<float> chance(vector<float> probability);
	
public:
	GA(double* p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij,
		int p_cas_izvajanja, int p_min_meja, int p_max_meja, double p_v_max);
	void init();
	~GA();
};


