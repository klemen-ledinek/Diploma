#include "stdafx.h"
#include "DE.h"



vector<double> DE::nov_agent(vector<double> p_a_agent, vector<double> p_b_agent, vector<double> p_c_agent)
{
	vector<double> w_vrni(p_a_agent.size());
	for (int i = 0; i < p_a_agent.size(); i++) {
		w_vrni[i] = p_a_agent[i] + this->getMutacija() * (p_b_agent[i] - p_c_agent[i]);
	}
	return w_vrni;
}

DE::DE(double* p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij, int p_cas_izvajanja,
		int p_min_meja, int p_max_meja, double p_crossover_rate)
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
	this->polni_populacijo(false);
}

double* DE::vrniRezultate()
{
	return this->vrni_uspesnost();
}

void DE::init()
{
	this->display();
	double* fitness = this->vrni_uspesnost();

	for (int i = 0; i < this->getSt_iteracij(); i++) {

		for (int j = 0; j < this->getSt_resitev(); j++) {
			int a = this->randomInteger(0, this->getSt_resitev() - 1);
			int b = this->randomInteger(0, this->getSt_resitev() - 1);
			int c = this->randomInteger(0, this->getSt_resitev() - 1);
			while (a == j || b == j || c == j || a == b || a == c || b == c) {
				a = this->randomInteger(0, this->getSt_resitev() - 1);
				b = this->randomInteger(0, this->getSt_resitev() - 1);
				c = this->randomInteger(0, this->getSt_resitev() - 1);
			}
			vector<double> a_agent = this->getItem(a);
			vector<double> b_agent = this->getItem(b);
			vector<double> c_agent = this->getItem(c);

			//double a_eval = get_single_fitness(a_agent);
			//double b_eval = get_single_fitness(b_agent);
			//double c_eval = get_single_fitness(c_agent);

			vector<double> r_agent = nov_agent(a_agent, b_agent, c_agent);
			double r_eval = this->vrni_uspesnot_populanta(r_agent);
			double chance = this->randomDouble(0, 1);
			if (chance < this->crossover_rate && abs(r_eval) < abs(fitness[i])) {
				fitness[i] = r_eval;
				this->dodaj_populanta(r_agent, i);
			}
		}
	}
		
	this->vrni_rezultate();
}


DE::~DE()
{
}
