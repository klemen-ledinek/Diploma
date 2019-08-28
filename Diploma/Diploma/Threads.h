#pragma once
#include <thread>
class Threads
{
private:
	vector<thread> thread_list;
	int size;
public:
	Threads();
	~Threads();

	void addThread(thread p_nit);
	void finish();
};

