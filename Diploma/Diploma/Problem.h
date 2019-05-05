#pragma once
class Problem
{
private:
	bool binarni = false;
	bool realni = false;
	vector<float> realni_problem;
	vector<int>	  binarni_problem;
public:
	Problem();
	Problem(bool p_binarni, bool p_realni, vector<float> p_realni_problem, vector<int> p_binarni_problem);
	int getSize();
	~Problem();
};

