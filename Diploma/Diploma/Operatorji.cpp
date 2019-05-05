#include "stdafx.h"
#include "Operatorji.h"


Operatorji::Operatorji()
{
	this->selekcija = true;
	this->mutacija = true;
	this->krizanje = true;
	this->vrstni_red = new int[3];
	this->vrstni_red[0] = 1;
	this->vrstni_red[1] = 2;
	this->vrstni_red[2] = 3;
}
Operatorji::Operatorji(bool p_selekcija, bool p_mutacija, bool p_krizanje, int p_vrstni_red[3]) {
	this->selekcija = p_selekcija;
	this->mutacija = p_mutacija;
	this->krizanje = p_krizanje;
	this->vrstni_red[0] = p_vrstni_red[0];
	this->vrstni_red[1] = p_vrstni_red[1];
	this->vrstni_red[2] = p_vrstni_red[2];
}

Operatorji::~Operatorji()
{
}

bool Operatorji::getSelekcija() {
	return this->selekcija;
}
bool Operatorji::getMutacija() {
	return this->mutacija;
}
bool Operatorji::getKrizanje() {
	return this->krizanje;
}
int* Operatorji::get_vrstni_red() {
	return this->vrstni_red;
}