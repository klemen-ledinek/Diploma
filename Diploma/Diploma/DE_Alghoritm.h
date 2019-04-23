#pragma once
class DE_Alghoritm
{
private:
	int pop_size;
	double CR;
	double F;
	double* population;
	int st_iteracij;
	int min;
	int max;

	//Funkcije
	double* get_fitness();
	void initialize();
	int get_best(double p_fitness[]);
public:
	DE_Alghoritm(int p_pop_size, double p_cr, double p_f, int p_st_iteracij, int p_min, int p_max);
	void runIt();
	~DE_Alghoritm();
};

