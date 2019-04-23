#include "stdafx.h"
#include "PSO_Object.h"
#include "PSO_Alghoritm.h"


PSO_Object::PSO_Object()
{
	mpBest = 0;
	mVelocity = 0.0;
}

int PSO_Object::getData(int p_index) const {
	return this->mData[p_index];
}

void PSO_Object::setData(int p_index, int p_value) {
	this->mData[p_index] = p_value;
}

int PSO_Object::getpBest() const {
	return this->mpBest;
}

void PSO_Object::setpBest(int p_value) {
	this->mpBest = p_value;
}

float PSO_Object::getVelocity() const {
	return this->mVelocity;
}

void PSO_Object::setVelocity(float p_value) {
	this->mVelocity = p_value;
}

PSO_Object::~PSO_Object()
{
}
