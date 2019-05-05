#pragma once
class Resitve
{
private:
	vector<double> parametri;
	int st_parametrov;
public:
	Resitve(int p_st_parametrov, int p_min, int p_max);
	double getParameter(int index);
	~Resitve();
};

