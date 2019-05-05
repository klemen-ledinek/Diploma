#pragma once
class Operatorji
{
private:
	bool selekcija = true;
	bool mutacija = true;
	bool krizanje = true;
	int* vrstni_red;
public:
	Operatorji();
	Operatorji(bool p_selekcija, bool p_mutacija, bool p_krizanje, int p_vrstni_red[3]);
	bool getSelekcija();
	bool getMutacija();
	bool getKrizanje();
	int* get_vrstni_red();
	~Operatorji();
};

