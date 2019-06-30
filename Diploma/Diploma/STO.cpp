#include "stdafx.h"
#include "STO.h"


void STO::polni_populacijo(bool p_binary)
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

void STO::dodaj_populanta(vector<double> p_populant, int p_index)
{
	this->populacija[p_index] = p_populant;
}

void STO::vrni_rezultate()
{

	int best = this->vrni_najboljsega();
	printf("\nBest agent is ");
	for (int i = 0; i < this->vel_problem; i++) {
		printf("%f ",this->populacija[best][i]);
	}
	 
	printf("\nAfter iteration");
	this->display();
}

vector<vector<double>> STO::vrni_populacijo()
{
	return this->populacija;
}

int STO::vrni_najboljsega()
{
	double* fitness = this->vrni_uspesnost();
	int w_vrni = 0;
	for (int i = 1; i < this->st_resitev; i++) {
		if (abs(fitness[i]) < abs(fitness[w_vrni])) {
			w_vrni = i;
		}
	}
	return w_vrni;
}

STO::STO()
{
	
}


STO::~STO()
{
}

void STO::setVelproblem(int p_vel_problem)
{
	this->vel_problem = p_vel_problem;
}

int STO::getVelproblem()
{
	return this->vel_problem;
}



void STO::setProblem(double * p_problem)
{
	this->problem = p_problem;
}

double * STO::getProblem()
{
	return this->problem;
}

void STO::setMutacija(double p_mutacija)
{
	this->mutacija = p_mutacija;
}

double STO::getMutacija()
{
	return this->mutacija;
}

void STO::setSt_resitev(int p_st_resitev)
{
	this->st_resitev = p_st_resitev;
}

int STO::getSt_resitev()
{
	return this->st_resitev;
}

void STO::setSt_iteracij(int p_st_iteracij)
{
	this->st_iteracij = p_st_iteracij;
}

int STO::getSt_iteracij()
{
	return this->st_iteracij;
}

void STO::setCas_izvajanja(int p_cas_izvajanja)
{
	this->cas_izvajanja = p_cas_izvajanja;
}

int STO::getCas_izvajanja()
{
	return this->cas_izvajanja;
}

void STO::setMin_meja(int p_min_meja)
{
	this->min_meja = p_min_meja;
}

int STO::getMin_meja()
{
	return this->min_meja;
}

void STO::setMax_meja(int p_max_meja)
{
	this->max_meja = p_max_meja;
}

int STO::getMax_meja()
{
	return this->max_meja;
}

void STO::setPopulacija(vector<vector<double>> p_populacija)
{
	this->populacija = p_populacija;
}

vector<double> STO::getItem(int p_lokacija)
{
	vector<double> w_vrni(this->vel_problem);
	w_vrni = this->populacija[p_lokacija];
	return w_vrni;
}

double STO::randomDouble(int p_min, int p_max)
{
	double w_vrni = (double)rand() / RAND_MAX;
	return p_min + w_vrni * (p_max - p_min);
}

int STO::randomInteger(int p_min, int p_max)
{
	int range = (p_min - p_max) + 1;
	return p_min + (rand() % range);
}

double * STO::vrni_uspesnost()
{
	double* w_vrni = new double[this->st_resitev];
	for (int i = 0; i < this->st_resitev; i++) {
		w_vrni[i] = 0.0;
		cout << endl;
		for (int j = 0; j < this->vel_problem; j++) {
			w_vrni[i] += this->populacija[i][j] * this->problem[j];
			
		}
	}
	return w_vrni;
}

double STO::vrni_uspesnot_populanta(vector<double> p_populant)
{
	double w_vrni = 0.0;
	for (int i = 0; i < this->vel_problem; i++) {
		w_vrni += p_populant[i] * this->problem[i];
	}
	return w_vrni;
}


void STO::display() {
	cout << endl;
	for (int i = 0; i < this->st_resitev; i++) {
		for (int j = 0; j < this->vel_problem; j++) {
			printf("%f " ,this->populacija[i][j]);
		}
		printf("Uspesnost: %f \n", this->vrni_uspesnot_populanta(this->populacija[i]));
	}
	cout << endl;
}

