#pragma once
#include "STO.h"
class DE :
	public STO
{
private:
	int crossover_rate;
public:
	DE(double* p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij, 
		int p_cas_izvajanja, int p_min_meja, int p_max_meja, int p_crossover_rate);
	void init();
	~DE();
};

