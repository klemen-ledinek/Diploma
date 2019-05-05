#pragma once
#include "Resitve.h"
class Alghoritm
{
private:
	Operatorji operatorji;
	Problem problem;
	void selekcija();
	void mutacija();
	void krizanje();
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

