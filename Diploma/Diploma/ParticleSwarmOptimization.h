#pragma once
#include "StochasticAlgorithm.h"
class ParticleSwarmOptimization :
	public StochasticAlgorithm
{
private:
	int *mBest;
	float *mVelocitiy;
	float vMax;

	void getVelocitiy(int p_best_index);
	void updateParticle(int p_best_index);
	void nastavi();
public:
	ParticleSwarmOptimization(double* p_problem, int p_vel_problem, int p_st_resitev, int p_st_iteracij,
		int p_cas_izvajanja, double p_min_meja, double p_max_meja, double p_v_max, double p_target);
	ParticleSwarmOptimization(string* p_problem, int p_vel_problem, int p_st_resitev, int p_st_iteracij,
		int p_cas_izvajanja, double p_min_meja, double p_max_meja, double p_v_max, double p_target);

	double* vrniRezultate();
	void init();
	void show_bestPopulant();
	void show_bestFitnes();
	double get_bestFitnes();
	void refresh();
	vector<double> run();
	void wait();
	~ParticleSwarmOptimization();
};

