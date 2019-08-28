#include "stdafx.h"
#include "ParticleSwarmOptimization.h"

double gRandNum()
{
	return double(rand() / (RAND_MAX + 1.0));
}

void ParticleSwarmOptimization::getVelocitiy(int p_best_index)
{
	int testResults, bestResults;
	float vValue;

	bestResults = this->vrni_uspesnot_populanta(this->getItem(p_best_index));

	for (int i = 0; i < this->getSt_resitev(); i++)
	{
		testResults = this->vrni_uspesnot_populanta(this->getItem(i));
		double rand1 = this->randomDouble(0, 1);
		double rand2 = this->randomDouble(0, 1);
		vValue = this->mVelocitiy[i] +
				2 * rand1 * (this->mBest[i] - testResults) + 
				2 * rand2 * (bestResults - testResults);

		if (vValue > this->vMax) {
			this->mVelocitiy[i] = (this->vMax);
		}
		else if (vValue < -this->vMax) {
			this->mVelocitiy[i] = (-this->vMax);
		}
		else {
			this->mVelocitiy[i] = (vValue);
		}
	} 
}

void ParticleSwarmOptimization::updateParticle(int p_best_index)
{
	int total, tempData;

	for (int i = 0; i < this->getSt_resitev(); i++)
	{
		vector<double> temp = this->getItem(i);
		if (i == p_best_index) {
			continue;
		}
		for (int j = 0; j < this->getVelproblem(); j++)
		{
			temp[j] += ((this->mVelocitiy[i]) / this->getVelproblem());

		}
		this->dodaj_populanta(temp, i);


		total = this->vrni_uspesnot_populanta(this->getItem(i));
		if (total < this->mBest[i])
		{
			this->mBest[i] = total;
		}

	}
}

void ParticleSwarmOptimization::nastavi()
{
	for (int i = 0; i < this->getSt_resitev(); i++) {
		int total = 0;
		vector<double> temp = this->getItem(i);
		vector<vector<double>> test = this->vrni_populacijo();
		mBest[i] = this->vrni_uspesnot_populanta(temp);
		mVelocitiy[i] = 0.0;
	}
}

ParticleSwarmOptimization::ParticleSwarmOptimization(double * p_problem, int p_vel_problem, int p_st_resitev, 
		int p_st_iteracij, int p_cas_izvajanja, double p_min_meja, double p_max_meja, double p_v_max, double p_target)
{
	this->setProblem(p_problem);
	this->setVelproblem(p_vel_problem);
	this->setSt_resitev(p_st_resitev);
	this->setSt_iteracij(p_st_iteracij);
	this->setCas_izvajanja(p_cas_izvajanja);
	this->setMin_meja(p_min_meja);
	this->setMax_meja(p_max_meja);
	this->vMax = p_v_max;
	this->polni_populacijo(false);
	this->mBest = new int[p_st_resitev];
	this->mVelocitiy = new float[p_st_resitev];
	this->set_target(p_target);
	this->nastavi();
}

ParticleSwarmOptimization::ParticleSwarmOptimization(string * p_problem, int p_vel_problem, int p_st_resitev, 
		int p_st_iteracij, int p_cas_izvajanja, double p_min_meja, double p_max_meja, double p_v_max, double p_target)
{
	this->setVelproblem(p_vel_problem);
	this->setProblemBinary(p_problem);
	this->setSt_resitev(p_st_resitev);
	this->setSt_iteracij(p_st_iteracij);
	this->setCas_izvajanja(p_cas_izvajanja);
	this->setMin_meja(p_min_meja);
	this->setMax_meja(p_max_meja);
	this->vMax = p_v_max;
	this->polni_populacijo(false);
	this->mBest = new int[p_st_resitev];
	this->mVelocitiy = new float[p_st_resitev];
	this->set_target(p_target);
	this->nastavi();
}

double* ParticleSwarmOptimization::vrniRezultate()
{
	return this->vrni_uspesnost();
}

void ParticleSwarmOptimization::init()
{
	int gBest = 0;
	int gBestTest = 0;
	int st_iteracij = this->getSt_iteracij();
	if (this->getSt_iteracij() < 1 && this->getCas_izvajanja() > 0) {
		st_iteracij = INT_MAX;
	}

	time_t start;
	time_t end;
	double elapsed;

	start = time(NULL);

	for (int i = 0; i < st_iteracij; i++) {
		gBestTest = this->vrni_najboljsega();
		this->getVelocitiy(gBestTest);
		this->updateParticle(gBestTest);
		end = time(NULL);
		elapsed = difftime(end, start);
		if (elapsed > this->getCas_izvajanja() && this->getCas_izvajanja() > 0) {
			break;
		}
		if (this->get_best_fitnes() == this->get_target()) {
			break;
		}

	}
}

void ParticleSwarmOptimization::show_bestPopulant()
{
	vector<double> best = this->get_bestPopulant();
	for (int i = 0; i < best.size(); i++) {
		printf("%f ", best[i]);
	}
}

void ParticleSwarmOptimization::show_bestFitnes()
{
	double best_fintes = this->get_best_fitnes();
	printf("%f ", best_fintes);
}

double ParticleSwarmOptimization::get_bestFitnes()
{
	return this->get_best_fitnes();
}

void ParticleSwarmOptimization::refresh()
{
	this->polni_populacijo(false);
}

vector<double> ParticleSwarmOptimization::run()
{
	thread t1(&ParticleSwarmOptimization::init, this);
	current_Thread.addThread(move(t1));
	return this->get_bestPopulant();
}

void ParticleSwarmOptimization::wait()
{
	this->current_Thread.finish();
}



ParticleSwarmOptimization::~ParticleSwarmOptimization()
{
}
