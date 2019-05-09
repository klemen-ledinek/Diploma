#pragma once
#include "Resitve.h"
class Alghoritm
{
private:
	Problem problem;
	void pripravi_resitve();
	double moznost_mutacije;
	int populacija;
	int st_iteracij;
	vector<Resitve> resitve;
	int min_number;
	int max_number;
	
public:
	Alghoritm();
	void execute();
	~Alghoritm();
};

