#include "stdafx.h"

#include "Problem.h"
#include "Alghoritm.h"



void Alghoritm::pripravi_resitve() {
	for (int i = 0; i < this->populacija; i++)
	{
		Resitve temp = Resitve(this->problem.getSize()-1, this->min_number, this->max_number);
		this->resitve.push_back(temp);
	}
}

Alghoritm::Alghoritm()
{
	this->problem = Problem();
	this->moznost_mutacije = 0.1;
	this->populacija = this->problem.getSize();
	this->st_iteracij = 10;
	this->populacija = 10;
	this->min_number = -50;
	this->max_number = 50;
	pripravi_resitve();
}


Alghoritm::~Alghoritm()
{
}

void Alghoritm::execute() {
	
}