#include "stdafx.h"
#include "DE.h"



DE::DE(double* p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij, int p_cas_izvajanja,
		int p_min_meja, int p_max_meja, int p_crossover_rate)
{
	this->setProblem(p_problem);
	this->setVelproblem(p_vel_problem);
	this->setMutacija(p_mutacija);
	this->setSt_resitev(p_st_resitev);
	this->setSt_iteracij(p_st_iteracij);
	this->setCas_izvajanja(p_cas_izvajanja);
	this->setMin_meja(p_min_meja);
	this->setMax_meja(p_max_meja);
	this->crossover_rate = p_crossover_rate;
	this->polni_populacijo();
}

void DE::init()
{
	double* ola = this->vrni_uspesnost();
}


DE::~DE()
{
}
