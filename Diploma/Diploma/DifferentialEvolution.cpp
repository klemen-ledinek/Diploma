#include "stdafx.h"
#include "DifferentialEvolution.h"



vector<double> DifferentialEvolution::nov_agent(vector<double> p_a_agent, vector<double> p_b_agent, vector<double> p_c_agent)
{
	vector<double> w_vrni(p_a_agent.size());
	for (int i = 0; i < p_a_agent.size(); i++) {
		w_vrni[i] = p_a_agent[i] + this->mutacija * (p_b_agent[i] - p_c_agent[i]);
	}
	return w_vrni;
}

DifferentialEvolution::DifferentialEvolution(double* p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, 
		int p_st_iteracij, int p_cas_izvajanja,	double p_min_meja, double p_max_meja, double p_crossover_rate, double p_target)
{
	
	
	this->setProblem(p_problem);
	this->setVelproblem(p_vel_problem);
	this->mutacija = p_mutacija;
	this->setSt_resitev(p_st_resitev);
	this->setSt_iteracij(p_st_iteracij);
	this->setCas_izvajanja(p_cas_izvajanja);
	this->setMin_meja(p_min_meja);
	this->setMax_meja(p_max_meja);
	this->crossover_rate = p_crossover_rate;
	this->set_target(p_target);
	this->polni_populacijo(false);

}

DifferentialEvolution::DifferentialEvolution(string * p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, 
		int p_st_iteracij, int p_cas_izvajanja, double p_min_meja, double p_max_meja, double p_crossover_rate, double p_target)
{
	this->setVelproblem(p_vel_problem);
	this->setProblemBinary(p_problem);
	this->mutacija = p_mutacija;
	this->setSt_resitev(p_st_resitev);
	this->setSt_iteracij(p_st_iteracij);
	this->setCas_izvajanja(p_cas_izvajanja);
	this->setMin_meja(p_min_meja);
	this->setMax_meja(p_max_meja);
	this->crossover_rate = p_crossover_rate;
	this->set_target(p_target);
	this->polni_populacijo(false);
}

void DifferentialEvolution::init()
{
	//this->display();
	double* fitness = this->vrni_uspesnost();
	int st_iteracij = this->getSt_iteracij();
	if (this->getSt_iteracij() < 1 && this->getCas_izvajanja() > 0) {
		st_iteracij = INT_MAX;
	}

	time_t start;
	time_t end;
	double elapsed;

	start = time(NULL);

	for (int i = 0; i < st_iteracij; i++) {
		
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

			vector<double> r_agent = nov_agent(a_agent, b_agent, c_agent);
			double r_eval = this->vrni_uspesnot_populanta(r_agent);
			double chance = this->randomDouble(0, 1);
			if (chance < this->crossover_rate && abs(r_eval) < abs(fitness[j])) {
				fitness[j] = r_eval;
				this->dodaj_populanta(r_agent, j);
			}
		}
		end = time(NULL);
		elapsed = difftime(end, start);
		if (elapsed > this->getCas_izvajanja()) {
			break;
		}
		if (abs(this->get_best_fitnes()) == this->get_target()) {
			break;
		}
		
	}
}

double DifferentialEvolution::run()
{
	thread t1(&DifferentialEvolution::init, this);
	current_Thread.addThread(move(t1));
	return this->get_best_fitnes();
	
}

void DifferentialEvolution::show_bestPopulant()
{
	vector<double> best = this->get_bestPopulant();
	for (int i = 0; i < best.size(); i++) {
		printf("%f ", best[i]);
	}
}



void DifferentialEvolution::show_bestFitnes()
{
	double best_fintes = this->get_best_fitnes();
	printf("%f ", best_fintes);
}

double DifferentialEvolution::get_bestFitnes()
{
	return this->get_best_fitnes();
}

void DifferentialEvolution::refresh()
{
	this->polni_populacijo(false);
}

void DifferentialEvolution::wait()
{
	this->current_Thread.finish();
}




DifferentialEvolution::~DifferentialEvolution()
{
}
