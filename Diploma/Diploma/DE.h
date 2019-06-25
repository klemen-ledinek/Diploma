#pragma once
#include "STO.h"
class DE :
	public STO
{
private:
	double crossover_rate;
	vector<double> nov_agent(vector<double> p_a, vector<double> p_b, vector<double> p_c);
public:
	DE(double* p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij, 
		int p_cas_izvajanja, int p_min_meja, int p_max_meja, double p_crossover_rate);
	void init();
	~DE();
};

