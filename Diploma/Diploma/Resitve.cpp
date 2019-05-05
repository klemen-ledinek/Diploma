#include "stdafx.h"
#include "Resitve.h"

double getRandomNumber(int p_min, int p_max) {
	double w_vrni = (double)rand() / RAND_MAX;
	return p_min + w_vrni * (p_max - p_min);
}

Resitve::Resitve(int p_st_parametrov, int p_min, int p_max)
{
	this->st_parametrov = p_st_parametrov;
	for (int i = 0; i < p_st_parametrov; i++)
	{
		this->parametri.push_back(getRandomNumber(p_min, p_max));
	}
}

double Resitve::getParameter(int index) {
	return this->parametri[index];
}

Resitve::~Resitve()
{
}
