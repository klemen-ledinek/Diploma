#include "stdafx.h"
#include "Wilcoxon_Element.h"


Wilcoxon_Element::Wilcoxon_Element()
{
}

Wilcoxon_Element::Wilcoxon_Element(double result)
{
	this->value = result;
	this->abs_value = abs(result);
	if (result < 0) {
		this->sgn = -1;
	}
	else if (result > 0) {
		this->sgn = 1;
	}
	else {
		this->sgn = 0;
	}
}


Wilcoxon_Element::~Wilcoxon_Element()
{
}


double Wilcoxon_Element::get_abs_value()
{
	return this->abs_value;
}


double Wilcoxon_Element::get_value()
{
	return this->value;
}


int Wilcoxon_Element::get_sgn()
{
	return this->sgn;
}

void Wilcoxon_Element::set_rank(double p_rank)
{
	this->rank = p_rank;
	if (this->value < 0) {
		this->sgn_rank = -p_rank;
	}
	else {
		this->sgn_rank = p_rank;
	}
}

double Wilcoxon_Element::get_rank()
{
	return this->rank;
}


double Wilcoxon_Element::get_sgn_rank()
{
	return this->sgn_rank;
}
