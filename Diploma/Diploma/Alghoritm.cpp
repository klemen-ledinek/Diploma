#include "stdafx.h"

#include "Operatorji.h"
#include "Problem.h"
#include "Alghoritm.h"


void Alghoritm::selekcija() {
	if (this->operatorji.getSelekcija()) {
	}
}
void Alghoritm::mutacija() {
	if (this->operatorji.getMutacija()) {
	}
}
void Alghoritm::krizanje() {
	if (this->operatorji.getKrizanje()) {
	}
}

void Alghoritm::pripravi_resitve() {
	for (int i = 0; i < this->populacija; i++)
	{
		Resitve temp = Resitve(this->problem.getSize()-1, this->min_number, this->max_number);
		this->resitve.push_back(temp);
	}
}

Alghoritm::Alghoritm()
{
	this->operatorji =  Operatorji();
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
	int* vrstni_red = this->operatorji.get_vrstni_red();
	for (int i = 0; i < this->st_iteracij; i++) {
		switch (vrstni_red[0])
		{
		case 1:
			this->selekcija();
			break;
		case 2:
			this->krizanje();
			break;
		case 3:
			this->mutacija();
			break;
		default:
			break;
		}

		switch (vrstni_red[1])
		{
		case 1:
			this->selekcija();
			break;
		case 2:
			this->krizanje();
			break;
		case 3:
			this->mutacija();
			break;
		default:
			break;
		}

		switch (vrstni_red[2])
		{
		case 1:
			this->selekcija();
			break;
		case 2:
			this->krizanje();
			break;
		case 3:
			this->mutacija();
			break;
		default:
			break;
		}
	}
}