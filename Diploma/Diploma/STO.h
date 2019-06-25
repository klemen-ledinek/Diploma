#pragma once
class STO
{
private:
	double* problem;
	int vel_problem;
	vector<vector<double>> populacija;
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
	


	//Funkcije
	vector<double> getItem(int p_lokacija);
	double randomDouble(int p_min, int p_max);
	int randomInteger(int p_min, int p_max);
	double* vrni_uspesnost();
	double vrni_uspesnot_populanta(vector<double> p_populant);
	void polni_populacijo();
	void dodaj_populanta(vector<double> p_populant, int p_index);
	void vrni_rezultate();
	int vrni_najboljsega();
	void display();
};

