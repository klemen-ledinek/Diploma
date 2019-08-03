#include "stdafx.h"
#include "PSO.h"

float gRandNum()
{
	return float(rand() / (RAND_MAX + 1.0));
}

void PSO::getVelocitiy(int p_best_index)
{
	int testResults, bestResults;
	float vValue;

	bestResults = this->vrni_uspesnot_populanta(this->getItem(p_best_index));

	for (int i = 0; i < this->getSt_resitev(); i++)
	{
		testResults = this->vrni_uspesnot_populanta(this->getItem(i));
		vValue = this->mVelocitiy[i] +
			2 * gRandNum() * (this->mBest[i] - testResults) + 2 * gRandNum() *
			(bestResults - testResults);

		if (vValue > this->vMax) {
			this->mVelocitiy[i] = (this->vMax);
		}
		else if (vValue < -this->vMax) {
			this->mVelocitiy[i] = (-this->vMax);
		}
		else {
			this->mVelocitiy[i] = (vValue);
		}
	} // i
}

void PSO::updateParticle(int p_best_index)
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
				temp[j] += this->mVelocitiy[i];
			
		} // j
		this->dodaj_populanta(temp, i);

		  //Check pBest value.
		total = this->vrni_uspesnot_populanta(this->getItem(i));
		if (abs(0 - total) < this->mBest[i])
		{
			this->mBest[i] = total;
		}

	} // i
}

void PSO::nastavi()
{
	for (int i = 0; i < this->getSt_resitev(); i++) {
		mBest[i] = 0;
		mVelocitiy[i] = 0.0;
	}
}

PSO::PSO(double * p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij, int p_cas_izvajanja, int p_min_meja, int p_max_meja, double p_v_max)
{
	this->setProblem(p_problem);
	this->setVelproblem(p_vel_problem);
	this->setMutacija(p_mutacija);
	this->setSt_resitev(p_st_resitev);
	this->setSt_iteracij(p_st_iteracij);
	this->setCas_izvajanja(p_cas_izvajanja);
	this->setMin_meja(p_min_meja);
	this->setMax_meja(p_max_meja);
	this->vMax = p_v_max;
	this->polni_populacijo(false);
	this->mBest = new int[p_st_resitev];
	this->mVelocitiy = new float[p_st_resitev];
	this->nastavi();
	//thread t([] {&PSO::init; });
	//current_Thread.addThread(move(t));
}

PSO::PSO(string * p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij, int p_cas_izvajanja, int p_min_meja, int p_max_meja, double p_v_max)
{
	this->setVelproblem(p_vel_problem);
	this->setProblemBinary(p_problem);
	this->setMutacija(p_mutacija);
	this->setSt_resitev(p_st_resitev);
	this->setSt_iteracij(p_st_iteracij);
	this->setCas_izvajanja(p_cas_izvajanja);
	this->setMin_meja(p_min_meja);
	this->setMax_meja(p_max_meja);
	this->vMax = p_v_max;
	this->polni_populacijo(false);
	this->mBest = new int[p_st_resitev];
	this->mVelocitiy = new float[p_st_resitev];
	this->nastavi();
	//thread t([] {&PSO::init; });
	//current_Thread.addThread(move(t));
}

double* PSO::vrniRezultate()
{
	return this->vrni_uspesnost();
}

void PSO::init()
{
	//this->display();
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
		if (elapsed > this->getCas_izvajanja()) {
			break;
		}
	}
	//this->vrni_rezultate();
}

void PSO::show_bestPopulant()
{
	vector<double> best = this->get_bestPopulant();
	for (int i = 0; i < best.size(); i++) {
		printf("%f ", best[i]);
	}
}

void PSO::show_bestPopultaion()
{
	vector<vector<double>> best_pop = this->get_bestPopulation();
	for (int i = 0; i < best_pop.size(); i++) {
		for (int j = 0; j < best_pop[i].size(); j++) {
			printf("%f ", best_pop[i][j]);
		}
		printf("\n");
	}
}

void PSO::show_bestFitnes()
{
	double best_fintes = this->get_best_fitnes();
	printf("%f ", best_fintes);
}

vector<vector<double>> PSO::get_best_Population()
{
	return this->get_bestPopulation();
}

PSO::~PSO()
{
}
