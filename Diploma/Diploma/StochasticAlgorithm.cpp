#include "stdafx.h"
#include "StochasticAlgorithm.h"
#include "Problemi.h"


void StochasticAlgorithm::polni_populacijo(bool p_binary)
{
	vector<vector<double>> populacija(this->st_resitev);
	for (int i = 0; i < this->st_resitev; i++) {
		for (int j = 0; j < this->vel_problem; j++) {
			populacija[i].resize(vel_problem);
			//this->populacija[i] = new double[this->vel_problem -1];
			if (!p_binary) {
				populacija[i][j] = this->randomDouble(this->min_meja, this->max_meja);
			}
			else {
				populacija[i][j] = this->randomInteger(this->min_meja, this->max_meja);
			}
		}
	}
	this->populacija = populacija;
}

void StochasticAlgorithm::dodaj_populanta(vector<double> p_populant, int p_index)
{
	this->populacija[p_index] = p_populant;
}

void StochasticAlgorithm::vrni_rezultate()
{

	int best = this->vrni_najboljsega();
	printf("\nBest agent is ");
	for (int i = 0; i < this->vel_problem; i++) {
		printf("%f ",this->populacija[best][i]);
	}
	
	printf("\nAfter iteration");
	this->display();
}

vector<vector<double>> StochasticAlgorithm::vrni_populacijo()
{
	return this->populacija;
}

int StochasticAlgorithm::vrni_najboljsega()
{
	double* fitness = this->vrni_uspesnost();
	int w_vrni = 0;
	for (int i = 1; i < this->st_resitev; i++) {
		double fit = abs(fitness[i]);
		double fit2 = abs(fitness[w_vrni]);
		if (fit < fit2) {
			w_vrni = i;
		}
	}
	return w_vrni;
}

StochasticAlgorithm::StochasticAlgorithm()
{
	this->best_fitnes = DBL_MAX;
}


StochasticAlgorithm::~StochasticAlgorithm()
{
}

void StochasticAlgorithm::setVelproblem(int p_vel_problem)
{
	this->vel_problem = p_vel_problem;
}

int StochasticAlgorithm::getVelproblem()
{
	return this->vel_problem;
}



void StochasticAlgorithm::setProblem(double * p_problem)
{
	this->problem = p_problem;
}

double * StochasticAlgorithm::getProblem()
{
	return this->problem;
}

void StochasticAlgorithm::setSt_resitev(int p_st_resitev)
{
	this->st_resitev = p_st_resitev;
}

int StochasticAlgorithm::getSt_resitev()
{
	return this->st_resitev;
}

void StochasticAlgorithm::setSt_iteracij(int p_st_iteracij)
{
	this->st_iteracij = p_st_iteracij;
}

int StochasticAlgorithm::getSt_iteracij()
{
	return this->st_iteracij;
}

void StochasticAlgorithm::setCas_izvajanja(int p_cas_izvajanja)
{
	this->cas_izvajanja = p_cas_izvajanja;
}

int StochasticAlgorithm::getCas_izvajanja()
{
	return this->cas_izvajanja;
}

void StochasticAlgorithm::setMin_meja(double p_min_meja)
{
	this->min_meja = p_min_meja;
}

double StochasticAlgorithm::getMin_meja()
{
	return this->min_meja;
}

void StochasticAlgorithm::setMax_meja(double p_max_meja)
{
	this->max_meja = p_max_meja;
}

double StochasticAlgorithm::getMax_meja()
{
	return this->max_meja;
}

void StochasticAlgorithm::set_target(double p_target)
{
	this->target = p_target;
}

double StochasticAlgorithm::get_target()
{
	return this->target;
}

void StochasticAlgorithm::setPopulacija(vector<vector<double>> p_populacija)
{
	this->populacija = p_populacija;
}

vector<double> StochasticAlgorithm::get_bestPopulant()
{
	return this->best_populant;
}

double StochasticAlgorithm::get_best_fitnes()
{
	return this->best_fitnes;
}


vector<double> StochasticAlgorithm::getItem(int p_lokacija)
{
	vector<double> w_vrni(this->vel_problem);
	w_vrni = this->populacija[p_lokacija];
	return w_vrni;
}

double StochasticAlgorithm::randomDouble(double p_min, double p_max)
{
	double w_vrni = (double)rand() / RAND_MAX;
	return p_min + w_vrni * (p_max - p_min);
}

int StochasticAlgorithm::randomInteger(int p_min, int p_max)
{
	int range = (p_min - p_max) + 1;
	return p_min + (rand() % range);
}

double * StochasticAlgorithm::vrni_uspesnost()
{
	double* w_vrni = new double[this->st_resitev];
	Problemi func = Problemi();
	for (int i = 0; i < this->st_resitev; i++) {
		//w_vrni[i] = DBL_MAX;
		double* result = new double[1];
		func.cec19_test_func(this->populacija[i].data(), result, this->vel_problem, 1, this->problem[0]);
		w_vrni[i] = result[0];
		if (abs(w_vrni[i]) < abs(this->best_fitnes)) {
			this->best_fitnes = w_vrni[i];
			this->best_populant = this->populacija[i];
		}
	}

	return w_vrni;
}



double StochasticAlgorithm::vrni_uspesnot_populanta(vector<double> p_populant)
{
	double* w_vrni = new double[1]; 
	w_vrni[0] = 0.0;
	Problemi func = Problemi();
	func.cec19_test_func(p_populant.data(), w_vrni, this->vel_problem, 1, this->problem[0]);
	return w_vrni[0];
}


void StochasticAlgorithm::display() {
	cout << endl;
	for (int i = 0; i < this->st_resitev; i++) {
		for (int j = 0; j < this->vel_problem; j++) {
			printf("%f " ,this->populacija[i][j]);
		}
		printf("Uspesnost: %f \n", this->vrni_uspesnot_populanta(this->populacija[i]));
	}
	cout << endl;
}
double toDecimal(string p_bits) {
	double w_vrni = 0.0;
	int value_to_add = 1;

	for (int i = p_bits.length(); i > 0; i--)
	{


		if (p_bits.at(i - 1) == '1')

			w_vrni += value_to_add;

		value_to_add *= 2;

	}//next bit
	return w_vrni;
}
void StochasticAlgorithm::setProblemBinary(string * p_problem)
{
	this->problem = new double[this->vel_problem];
	for (int i = 0; i < this->vel_problem; i++) {
		this->problem[i] = toDecimal(p_problem[i]);
	}
}




