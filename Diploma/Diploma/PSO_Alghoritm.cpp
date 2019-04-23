#include "stdafx.h"
#include "PSO_Object.h"
#include "PSO_Alghoritm.h"


PSO_Alghoritm::PSO_Alghoritm(int p_max_particles, int p_max_inputs, int p_target, int p_max_epochs, float p_vMax, int p_range_min, int p_range_max)
{
	this->max_particles = p_max_particles;
	this->max_inputs = p_max_inputs;
	this->target = p_target;
	this->max_epochs = p_max_epochs;
	this->vMax = p_vMax;
	this->pso_objects = new PSO_Object[p_max_particles];
	this->range_min = p_range_min;
	this->range_max = p_range_max;
}

void PSO_Alghoritm::runIt()
{
	int gBest = 0;
	int gBestTest = 0;
	int epoch = 0;
	bool done = false;
	initialize(this->max_particles, this->max_inputs);

	do {
		if (epoch < this->max_epochs) {
			for (int i = 0; i <= this->max_particles - 1; i++) {

				for (int j = 0; j <= max_inputs - 1; j++) {
					if (j < max_inputs - 1) {
						cout << this->pso_objects[i].getData(j) << " + ";
					}
					else {
						cout << this->pso_objects[i].getData(j) << " = ";
					}
				}
				cout << testProblem(i) << endl;
				if (testProblem(i) == this->target)
				{
					done = true;
				}
			}
			gBestTest = minimum();

			if (abs(this->target - testProblem(gBestTest)) < abs(this->target - testProblem(gBest)))
			{
				gBest = gBestTest;
			}

			getVelocity(gBest);

			updateParticles(gBest);

			epoch += 1;

		}
		else {
			done = true;
		}

	} while (!done);

	cout << epoch << " epochs completed." << endl;
}



float gRand()
{
	return float(rand() / (RAND_MAX + 1.0));
}
int getRandomNumber(int low, int high)
{
	return low + int(((high - low) + 1) * rand() / (RAND_MAX + 1.0));
}
void PSO_Alghoritm::initialize(int p_particles, int p_inputs)
{
	int total;

	for (int i = 0; i <= p_particles - 1; i++)
	{
		total = 0;
		for (int j = 0; j <= p_inputs - 1; j++)
		{
			this->pso_objects[i].setData(j, getRandomNumber(this->range_min, this->range_max));
			total += this->pso_objects[i].getData(j);
		} // j
		this->pso_objects[i].setpBest(total);
	} // i

	return;
}
int PSO_Alghoritm::testProblem(int p_index)
{
	int total = 0;

	for (int i = 0; i <= this->max_inputs - 1; i++)
	{
		total += this->pso_objects[p_index].getData(i);
	}

	return total;
}
int PSO_Alghoritm::minimum()
{
	int winner = 0;
	bool foundNewWinner;
	bool done = false;

	do
	{
		foundNewWinner = false;
		for (int i = 0; i <= this->max_particles - 1; i++)
		{
			if (i != winner) {
				if (abs(this->target - testProblem(i)) < abs(this->target - testProblem(winner)))
				{
					winner = i;
					foundNewWinner = true;
				}
			}
		} // i

		if (foundNewWinner == false)
		{
			done = true;
		}

	} while (!done);

	return winner;
}
void PSO_Alghoritm::getVelocity(int gBestIndex)
{
	int testResults, bestResults;
	float vValue;

	bestResults = testProblem(gBestIndex);

	for (int i = 0; i <= this->max_particles - 1; i++)
	{
		testResults = testProblem(i);
		vValue = this->pso_objects[i].getVelocity() +
			2 * gRand() * (this->pso_objects[i].getpBest() - testResults) + 2 * gRand() *
			(bestResults - testResults);

		if (vValue > this->vMax) {
			this->pso_objects[i].setVelocity(this->vMax);
		}
		else if (vValue < -this->vMax) {
			this->pso_objects[i].setVelocity(-this->vMax);
		}
		else {
			this->pso_objects[i].setVelocity(vValue);
		}
	} // i
}
void PSO_Alghoritm::updateParticles(int gBestIndex)
{
	int total, tempData;

	for (int i = 0; i <= this->max_particles - 1; i++)
	{
		for (int j = 0; j <= this->max_inputs - 1; j++)
		{
			if (this->pso_objects[i].getData(j) != this->pso_objects[gBestIndex].getData(j))
			{
				tempData = this->pso_objects[i].getData(j);
				this->pso_objects[i].setData(j, tempData + static_cast<int>(this->pso_objects[i].getVelocity()));
			}
		} // j

		  //Check pBest value.
		total = testProblem(i);
		if (abs(this->target - total) < this->pso_objects[i].getpBest())
		{
			this->pso_objects[i].setpBest(total);
		}

	} // i

}

PSO_Alghoritm::~PSO_Alghoritm()
{
}
