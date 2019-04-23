#pragma once
class PSO_Object
{
private:
	int mData[50];
	int mpBest;
	float mVelocity;
public:
	PSO_Object();
	int getData(int p_index) const;
	void setData(int p_index, int p_value);
	int getpBest() const;
	void setpBest(int p_value);
	float getVelocity() const;
	void setVelocity(float p_value);
	~PSO_Object();
};

