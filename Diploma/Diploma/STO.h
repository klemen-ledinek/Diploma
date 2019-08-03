#pragma once
#include "Threads.h"
class STO:
		public Threads
{
protected:
	Threads current_Thread = Threads();
private:
	double* problem;
	int vel_problem;
	vector<vector<double>> populacija;
	vector<vector<double>> best_populacija;
	vector<double> best_populant;
	double best_fitnes;
	double mutacija;
	int st_resitev;
	int st_iteracij;
	int cas_izvajanja;
	int min_meja;
	int max_meja;
	
	

	
public:
	STO();
	~STO();
protected:
	void setVelproblem(int p_vel_problem);
	int getVelproblem();
	void setProblem(double *p_problem);
	double* getProblem();
	void setMutacija(double p_mutacija);
	double getMutacija();
	void setSt_resitev(int p_st_resitev);
	int getSt_resitev();
	void setSt_iteracij(int p_st_iteracij);
	int getSt_iteracij();
	void setCas_izvajanja(int p_cas_izvajanja);
	int getCas_izvajanja();
	void setMin_meja(int p_min_meja);
	int getMin_meja();
	void setMax_meja(int p_max_meja);
	int getMax_meja();
	void setPopulacija(vector<vector<double>> p_populacija);
	vector<vector<double>> get_bestPopulation();
	vector<double> get_bestPopulant();
	double get_best_fitnes();
	//Funkcije
	vector<double> getItem(int p_lokacija);
	double randomDouble(int p_min, int p_max);
	int randomInteger(int p_min, int p_max);
	double* vrni_uspesnost();
	double vrni_uspesnot_populanta(vector<double> p_populant);
	void polni_populacijo(bool p_binary);
	void dodaj_populanta(vector<double> p_populant, int p_index);
	void vrni_rezultate();
	vector<vector<double>> vrni_populacijo();
	int vrni_najboljsega();
	void display();
	void setProblemBinary(string *p_problem);
};

