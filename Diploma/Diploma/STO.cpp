#include "stdafx.h"
#include "STO.h"


void STO::polni_populacijo()
{
	this->populacija = new double*[this->st_resitev];
	for (int i = 0; i < this->st_resitev - 1; i++) {
		for (int j = 0; j < this->vel_problem - 1; j++) {
			this->populacija[i] = new double[this->vel_problem];
			this->populacija[i][j] = this->randomDouble(this->min_meja, this->max_meja);
		}
	}
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

double STO::randomDouble(int p_min, int p_max)
{
	double w_vrni = (double)rand() / RAND_MAX;
	return p_min + w_vrni * (p_max - p_min);
}

double * STO::vrni_uspesnost()
{
	double* w_vrni = new double[this->st_resitev];
	for (int i = 0; i < this->st_resitev - 1; i++) {
		w_vrni[i] = 0.0;
		for (int j = 0; j < this->vel_problem - 1; j++) {
			w_vrni[i] += this->populacija[i][j] * this->problem[j];
			
		}
		printf("\n%f", w_vrni[i]);
	}
	return w_vrni;
}




