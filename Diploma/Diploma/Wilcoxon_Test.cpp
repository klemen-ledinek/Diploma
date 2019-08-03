#include "stdafx.h"
#include "Wilcoxon_Test.h"


void Wilcoxon_Test::sort_elements()
{
	int min_location = 0;
	for (int i = 0; i < this->elementi.size(); i++) {
		min_location = i;
		for (int j = min_location +1; j < this->elementi.size();j++) {
			if (this->elementi[min_location].get_abs_value() > this->elementi[j].get_abs_value()) {
				min_location = j;
			}
		}
		if (min_location != i) {
			iter_swap(this->elementi.begin() + i, this->elementi.begin() + min_location);
		}
		
	}
}



void Wilcoxon_Test::rank_elements()
{
	bool multiple_same = false;
	for (int i = 0; i < this->elementi.size(); i++) {
		if (this->elementi[i].get_abs_value() == 0) {
			continue;
		}
		if (i + 1 >= this->elementi.size()) {
			this->elementi[i].set_rank(i+1);
		}
		for (int j = i + 1; j < this->elementi.size(); j++) {

			if (this->elementi[i].get_abs_value() != this->elementi[j].get_abs_value()) {

				if (!multiple_same) {
					this->elementi[i].set_rank(i+1);
					break;
				}
				else {
					multiple_same = false;
					rank_elements_between(i, j);
					i = j;
				}
			}
			else {
				multiple_same = true;
			}
		}
	}
}

void Wilcoxon_Test::rank_elements_between(int p_start, int p_end)
{
	double rank = p_start+1 / p_end+1;
	for (int i = p_start; i <= p_end; i++) {
		this->elementi[i].set_rank(rank);
	}
}

void Wilcoxon_Test::set_result()
{
	for (int i = 0; i < this->elementi.size(); i++) {
		this->test_statistic += this->elementi[i].get_sgn_rank();
	}
}

void Wilcoxon_Test::calculate()
{
	int n = this->elementi.size();
	double wcrit = sqrt((n*(n + 1)*(2 * n + 1)) / 6);

	if (abs(this->test_statistic) < abs(wcrit)) {
		cout << "Skupek podatkov je podoben!";
	}
	else {
		cout << "Skupek podatkov ni podoben!";
	}
}

void Wilcoxon_Test::dodaj_Element(double x, double y)
{
	Wilcoxon_Element element = Wilcoxon_Element(x - y);
	//this->elementi.resize(this->elementi.size() + 1);
	this->elementi.push_back(element);

}

void Wilcoxon_Test::init()
{
	this->sort_elements();
	this->rank_elements();
	this->set_result();
	this->calculate();
}

Wilcoxon_Test::Wilcoxon_Test(vector<vector<double>> pop_x, vector<vector<double>> pop_y)
{
	if (pop_x.size() != pop_y.size()) {
		printf("Neenakomerne populacije!");
		return;
	}
	for (int i = 0; i < pop_x.size(); i++) {
		double fit_x = this->vrni_uspesnot_populanta(pop_x[i]);
		double fit_y = this->vrni_uspesnot_populanta(pop_y[i]);
		dodaj_Element(fit_x, fit_y);
	}
}


Wilcoxon_Test::~Wilcoxon_Test()
{
}
