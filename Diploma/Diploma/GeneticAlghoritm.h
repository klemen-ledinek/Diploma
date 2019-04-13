#pragma once
class GeneticAlghoritm
{

public:
	GeneticAlghoritm();
	
	~GeneticAlghoritm();
	int** executeGeneticAlghortim(int** p_chromosome, vector<int> p_vector, int p_number_of_iterations);
	int randNum(int min, int max) {
		int range = (max - min) + 1;
		return min + (rand() % range);
	}
	int randNum() {
		int range = (30 - 0) + 1;
		return  0 + (rand() % range);
	}
	int randNum2() {
		int range = (2 - 0) + 1;
		return  0 + (rand() % range);
	}
	float randNumFloat() {
		float scale = RAND_MAX + 1.;
		float base = rand() / scale;
		float fine = rand() / scale;
		return base + fine / scale;
		//return 0.0+ (static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
	}
	float* randNums() {
		float* w_vrni = new float[6];
		for (int i = 0; i < 6; i++) {
			w_vrni[i] = randNumFloat();
		}
		return w_vrni;
	}
	int** randomChromosome() {
		int** p_chromosome = new int*[6];
		for (int i = 0; i < 6; i++) {
			p_chromosome[i] = new int[4];
			for (int j = 0; j < 4; j++) {
				p_chromosome[i][j] = randNum();
			}
		}
		return p_chromosome;
	}
	int getSumChromosome(int** p_chromosome, vector<int> p_vector, int p_chormosome_num) {
		int w_vrni = 0;
		for (int j = 0; j < 4; j++) {
			w_vrni += p_chromosome[p_chormosome_num][j] * p_vector[j];
		}

		return w_vrni;
	}
	vector<int> evaluation(int** p_chromosome, vector<int> p_vector) {
		vector<int> w_vrni(6);

		for (int i = 0; i < 6; i++) {
			w_vrni[i] = getSumChromosome(p_chromosome, p_vector, i);
		}

		return w_vrni;
	}
	vector<float> selection(vector<int> p_evaluation) {
		vector<float>  w_vrni(6);
		for (int i = 0; i < 6; i++) {
			w_vrni[i] = 1.0 / (1.0 + p_evaluation[i]);
		}
		return w_vrni;
	}
	float get_total_fitness(vector<float> p_selection) {
		float w_vrni = 0.0;
		for (int i = 0; i < 6; i++) {
			w_vrni += p_selection[i];
		}
		return w_vrni;
	}
	vector<float> probability(vector<float> p_fitness, float p_total_fitness) {
		vector<float> w_vrni(6);

		for (int i = 0; i < 6; i++) {
			w_vrni[i] = p_fitness[i] / p_total_fitness;
		}
		return w_vrni;
	}
	vector<float> chance(vector<float> probability) {
		vector<float> w_vrni(6);
		w_vrni[0] = 0.0;
		for (int i = 0; i < 6; i++)
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
	int** new_chromosomes(vector<float> p_chance, int** p_chromosome) {
		int** w_vrni = p_chromosome;
		float w_chance = randNumFloat();
		for (int i = 0; i < 6; i++)
		{
			w_chance = randNumFloat();
			if (w_chance < p_chance[0]) {
				w_vrni[i] = p_chromosome[0];
			}
			else if (w_chance > p_chance[0] && w_chance < p_chance[1]) {
				w_vrni[i] = p_chromosome[1];
			}
			else if (w_chance > p_chance[1] && w_chance < p_chance[2]) {
				w_vrni[i] = p_chromosome[2];
			}
			else if (w_chance > p_chance[2] && w_chance < p_chance[3]) {
				w_vrni[i] = p_chromosome[3];
			}
			else if (w_chance > p_chance[3] && w_chance < p_chance[4]) {
				w_vrni[i] = p_chromosome[4];
			}
			else if (w_chance > p_chance[4]) {
				w_vrni[i] = p_chromosome[5];
			}
		}
		return w_vrni;
	}
	vector<int> get_parents(float* p_chances) {
		int* parent = new int[6];
		int size = 0;
		float pc = 0.25;
		for (int i = 0; i < 6; i++) {
			if (p_chances[i] < pc) {
				parent[size] = i;
				size++;
			}
		}
		vector<int> parents(size);
		if (parent[0] < 0 || parent[0] > 5) {
			return parents;
		}

		for (int i = 0; i < size; i++) {
			parents[i] = parent[i];
		}

		return parents;
	}
	int** crossover(vector<int> p_parents, int** p_chromosomes) {
		int cut_points;
		int** w_vrni = p_chromosomes;
		if (p_parents.size() < 2) {
			return w_vrni;
		}
		for (int i = 0; i < p_parents.size(); i++) {


			cut_points = randNum2();
			if (i + 1 < p_parents.size()) {
				if (cut_points == 0) {
					w_vrni[p_parents[i]][1] = p_chromosomes[p_parents[i + 1]][1];
					w_vrni[p_parents[i]][2] = p_chromosomes[p_parents[i + 1]][2];
					w_vrni[p_parents[i]][3] = p_chromosomes[p_parents[i + 1]][3];
				}
				else if (cut_points == 1) {
					w_vrni[p_parents[i]][2] = p_chromosomes[p_parents[i + 1]][2];
					w_vrni[p_parents[i]][3] = p_chromosomes[p_parents[i + 1]][3];
				}
				else {
					w_vrni[p_parents[i]][3] = p_chromosomes[p_parents[i + 1]][3];
				}
			}
			else {
				if (cut_points == 0) {
					w_vrni[p_parents[i]][1] = p_chromosomes[p_parents[0]][1];
					w_vrni[p_parents[i]][2] = p_chromosomes[p_parents[0]][2];
					w_vrni[p_parents[i]][3] = p_chromosomes[p_parents[0]][3];
				}
				else if (cut_points == 1) {
					w_vrni[p_parents[i]][2] = p_chromosomes[p_parents[0]][2];
					w_vrni[p_parents[i]][3] = p_chromosomes[p_parents[0]][3];
				}
				else {
					w_vrni[p_parents[i]][3] = p_chromosomes[p_parents[0]][3];
				}
			}
		}
		return w_vrni;
	}
	int** mutation(int** p_chromosomes) {
		int** w_vrni = p_chromosomes;
		int total_chromosomes = 24;
		float chance_mutation = 0.05;
		int mutation_rate = chance_mutation * total_chromosomes;
		for (int i = 0; i < mutation_rate; i++) {
			int rand_mutated = randNum(0, 23);
			int arrayX = rand_mutated / 6;
			int arrayY = rand_mutated % 6;

			p_chromosomes[arrayX][arrayY] = randNum(0, 30);
		}
		return p_chromosomes;
	}
	int* get_fitest(int** p_chromosomes, vector<int> p_vector) {
		vector<int> w_evaluation = evaluation(p_chromosomes, p_vector);
		int* fitest = new int[4];
		fitest = p_chromosomes[0];
		for (int i = 1; i < 6; i++) {
			if (w_evaluation[i - 1] > w_evaluation[i]) {
				fitest = p_chromosomes[i];
			}
		}
		return fitest;

	}
};

