#include "stdafx.h"
#include "GA.h"

vector<double> GA::new_chromosome(vector<double> p_chance) {
	
	double w_chance;
	w_chance = this->randomDouble(0, 1);
	for (int j = 0; j < p_chance.size();j++){
		if (w_chance < p_chance[j]) {
			return this->getItem(j);
			break;
		}
	}
		
	return this->parents[0];
}

string toBits(double number) {
	int converted = int(number);
	string w_vrni;
	while (converted != 0) {
		w_vrni = (converted % 2 == 0 ? "0" : "1") + w_vrni;
		converted /= 2;
	}

	return w_vrni;
}

double toDeci(string p_bits) {
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

vector<double> GA::mutate(vector<double> p_chromosome)
{
	vector<double> w_vrni (p_chromosome.size());
	for (int i = 0; i < p_chromosome.size(); i++) {
		string bits = toBits(p_chromosome[i]);
		for (int j = 0; j<bits.length(); j++)
		{
			if (this->randomDouble(0,1) < this->getMutacija())
			{
				if (bits.at(j) == '1')

					bits.at(j) = '0';

				else

					bits.at(j) = '1';
			}
		}
		w_vrni[i] = toDeci(bits);
	}
	return w_vrni;
}

void GA::crossover(vector<double>& p_first, vector<double>& p_second)
{
	if (this->randomDouble(0, 1) < this->crossover_rate) {
		for (int i = 0; i < this->getVelproblem(); i++) {
			
			string s_first = toBits((int)p_first[i]);
			string s_second = toBits((int)p_second[i]);
			
			int max_chromosom = toBits(int(this->getMax_meja())).length();
			int crossover = this->randomInteger(0, max_chromosom);

			for (int j = 0; j < max_chromosom; j++) {
				if (s_first.length() < max_chromosom) {
					s_first.insert(0, "0");
				}
				if (s_second.length() < max_chromosom) {
					s_second.insert(0, "0");
				}
			}

			
			string t1 = s_first.substr(0, crossover) + s_second.substr(crossover, s_first.length());
			string t2 = s_second.substr(0, crossover) + s_first.substr(crossover, s_second.length());

			p_first[i] = toDeci(t1);
			p_second[i] = toDeci(t2);

		}
	}
}

vector<double> GA::selection(double * p_evaluation)
{
	vector<double>  w_vrni(this->getSt_resitev());
	for (int i = 0; i < this->getSt_resitev(); i++) {
		w_vrni[i] = 1.0 / (1.0 + abs(p_evaluation[i]));
	}
	return w_vrni;
}

double GA::total_fitness(vector<double> p_selection)
{
	double w_vrni = 0.0;
	for (int i = 0; i < this->getSt_resitev(); i++) {
		w_vrni += p_selection[i];
	}
	return w_vrni;
}

vector<double> GA::probability(vector<double> p_fitness, float p_total_fitness)
{
	vector<double> w_vrni(this->getSt_resitev());

	for (int i = 0; i < this->getSt_resitev(); i++) {
		w_vrni[i] = p_fitness[i] / p_total_fitness;
	}
	return w_vrni;
}

vector<double> GA::chance(vector<double> probability)
{
	vector<double> w_vrni(this->getSt_resitev());
	w_vrni[0] = 0.0;
	for (int i = 0; i < this->getSt_resitev(); i++)
	{
		if (i == 0) {
			w_vrni[i] = w_vrni[i] + probability[i];
		}
		else {
			w_vrni[i] = w_vrni[i - 1] + probability[i];
		}
	}
	return w_vrni;
}


GA::GA(double * p_problem, int p_vel_problem, double p_mutacija, int p_st_resitev, int p_st_iteracij, int p_cas_izvajanja, int p_min_meja, int p_max_meja, double p_v_max, double p_crossover_rate)
{
	this->setProblem(p_problem);
	this->setVelproblem(p_vel_problem);
	this->setMutacija(p_mutacija);
	this->setSt_resitev(p_st_resitev);
	this->setSt_iteracij(p_st_iteracij);
	this->setCas_izvajanja(p_cas_izvajanja);
	this->setMin_meja(p_min_meja);
	this->setMax_meja(p_max_meja);
	this->polni_populacijo(true);
	this->crossover_rate = p_crossover_rate;
}

void GA::init()
{
	this->display();
	for (int i = 0; i < 1; i++) {
		double* evaluation = this->vrni_uspesnost();
		vector<double> fitness = this->selection(evaluation);
		double total_fitness = this->total_fitness(fitness);

		//Probability
		vector<double> probably = this->probability(fitness, total_fitness);
		//Chance
		vector<double> chanc = this->chance(probably);
		// New Chromosome
		this->parents = vector<vector<double>> (this->getSt_resitev());
		int parents_count = 0;
		while (parents_count < this->getSt_resitev()) {
			vector<double> first = this->new_chromosome(chanc);
			vector<double> second = this->new_chromosome(chanc);

			this->crossover(first, second);

			first = this->mutate(first);
			second = this->mutate(second);

			parents[parents_count++] = first;
			parents[parents_count++] = second;
		}

		cout << endl;
		this->setPopulacija(parents);

		//parents = new_chromosomes(chanc);

		//Crossover
		//double* parent_chance = randNums();
		//vector<int> parents = get_parents(parent_chance);
		//new_chromosome = crossover(parents, p_chromosome);
		//p_chromosome = new_chromosome;
		//Mutation
		//new_chromosome = mutation(p_chromosome);
		//p_chromosome = new_chromosome;
	}

	this->vrni_rezultate();
}

GA::~GA()
{
}
