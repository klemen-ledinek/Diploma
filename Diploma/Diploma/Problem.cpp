#include "stdafx.h"
#include "Problem.h"


Problem::Problem()
{
	this->binarni = false;
	this->realni = true;
	this->binarni_problem = {  };
	this->realni_problem = { 1.0, 2.0, 3.0, 10.0};
}

Problem::Problem(bool p_binarni, bool p_realni, vector<float> p_realni_problem, vector<int> p_binarni_problem)
{
	this->binarni = p_binarni;
	this->realni = p_realni;
	this->binarni_problem = p_binarni_problem;
	this->realni_problem = p_realni_problem;
}
int Problem::getSize() {
	if (this->binarni) {
		return this->binarni_problem.size();
	}
	else if (this->realni)
	{
		return this->realni_problem.size();
	}
	return 0;
}
Problem::~Problem()
{
}
