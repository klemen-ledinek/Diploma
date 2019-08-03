#pragma once
class Wilcoxon_Element
{
private:
	double abs_value;
	double value;
	int sgn;
	double rank;
	double sgn_rank;
public:
	Wilcoxon_Element();
	Wilcoxon_Element(double result);
	~Wilcoxon_Element();

	double get_abs_value();
	double get_value();
	int get_sgn();

	void set_rank(double p_rank);
	double get_rank();
	double get_sgn_rank();

};

