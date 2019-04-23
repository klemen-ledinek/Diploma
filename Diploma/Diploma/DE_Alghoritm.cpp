#include "stdafx.h"
#include "DE_Alghoritm.h"


DE_Alghoritm::DE_Alghoritm(int p_pop_size, double p_cr, double p_f, int p_st_iteracij, int p_min, int p_max)
{
	this->pop_size = p_pop_size;
	this->CR = p_cr;
	this->F = p_f;
	this->st_iteracij = p_st_iteracij;
	this->population = new double[pop_size];
	this->min = p_min;
	this->max = p_max;
}

int randomInt(int p_min, int p_max) {
	int range = (p_min - p_max) + 1;
	return p_min + (rand() % range);
}
double randomDouble(int p_min, int p_max) {
	double w_vrni = (double)rand() / RAND_MAX;
	return p_min + w_vrni * (p_max - p_min);
}
double get_single_fitness(double p_agent) {
	double w_vrni = abs((p_agent - 15 + (p_agent * 3)) - 8);
	return w_vrni;
}
int DE_Alghoritm::get_best(double p_fitness[]) {
	int w_vrni = 0;
	for (int i = 1; i < this->pop_size - 1; i++) {
		if (p_fitness[i] < p_fitness[w_vrni]) {
			w_vrni = i;
		}
	}
	return w_vrni;
}
void DE_Alghoritm::initialize() {
	for (int i = 0; i < this->pop_size - 1; i++) {
		this->population[i] = randomDouble(this->min, this->max);
	}
}
double* DE_Alghoritm::get_fitness() {
	double* w_vrni = new double[this->pop_size];
	for (int i = 0; i < this->pop_size; i++) {
		w_vrni[i] = abs((this->population[i] - 15 + (this->population[i] * 3)) - 8);
	}
	return w_vrni;
}

void DE_Alghoritm::runIt() {
	double* fitness = get_fitness();
	initialize();

	for (int iter = 0; iter < this->st_iteracij - 1; iter++) {

		for (int i = 0; i < this->pop_size -1; i++) {
			int a = randomInt(0, this->pop_size - 1);
			int b = randomInt(0, this->pop_size - 1);
			int c = randomInt(0, this->pop_size - 1);
			while (a == i || b == i || c == i || a == b || a == c || b == c) {
				a = randomInt(0, this->pop_size - 1);
				b = randomInt(0, this->pop_size - 1);
				c = randomInt(0, this->pop_size - 1);
			}
			double a_agent = this->population[a];
			double b_agent = this->population[b];
			double c_agent = this->population[c];

			double a_eval = get_single_fitness(a_agent);
			double b_eval = get_single_fitness(b_agent);
			double c_eval = get_single_fitness(c_agent);

			double r_agent = a_agent + F * (b_agent - c_agent);
			double r_eval = get_single_fitness(r_agent);
			double chance = randomDouble(0, 1);
			if (chance < this->CR && r_eval < fitness[i]) {
				fitness[i] = r_eval;
				this->population[i] = r_agent;
			}
		}
	}

	printf("\nBest agent is %2.3f", this->population[get_best(fitness)]);
	printf("\nAfter iteration");
	for (int i = 0; i < this->pop_size - 1; i++) {
		printf("\n Populacija %d, %2.3f", i + 1, this->population[i]);
	}
}

DE_Alghoritm::~DE_Alghoritm()
{
}
