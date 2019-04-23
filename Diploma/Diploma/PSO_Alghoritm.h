#pragma once
class PSO_Alghoritm
{
private:
	//Atributi
	int max_particles;
	int max_inputs;
	int target;
	int max_epochs;
	float vMax;
	PSO_Object* pso_objects;
	int range_min;
	int range_max;
	//Funkcije in procedure
	void initialize(int p_particles, int p_inputs);
	int testProblem(int p_index);
	int minimum();
	void getVelocity(int gBestIndex);
	void updateParticles(int gBestIndex);
public:
	PSO_Alghoritm(int p_max_particles, int p_max_inputs, int p_target, int p_max_epochs, float p_vMax, int p_range_min, int p_range_max);
	void runIt();
	~PSO_Alghoritm();
};

