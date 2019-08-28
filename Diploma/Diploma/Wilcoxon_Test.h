#pragma once
#include "Wilcoxon_Element.h"
#include "StochasticAlgorithm.h"
class Wilcoxon_Test
{
private:
	vector<Wilcoxon_Element> elementi;
	double test_statistic = 0.0;


	void sort_elements();
	void rank_elements();
	void rank_elements_between(int p_start, int p_end);
	void set_result();
	void calculate();
public:
	void dodaj_Element(double x, double y);

	void init();

	Wilcoxon_Test(vector<double> pop_x, vector<double> pop_y);
	~Wilcoxon_Test();
};

