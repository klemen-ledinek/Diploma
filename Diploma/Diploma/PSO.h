#pragma once
#include "STO.h"
class PSO :
	public STO
{
private:
	int *mBest;
	float *mVelocitiy;
	float vMax;

	void getVelocitiy(int p_best_index);
	void updateParticle(int p_best_index);
	void nastavi();
public:
	PSO(double* p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij,
		int p_cas_izvajanja, int p_min_meja, int p_max_meja, double p_v_max);

	double* vrniRezultate();
	void init();
	~PSO();
};

