#pragma once
#include <thread>
class Threads
{
private:
	vector<thread> thread_list;
public:
	Threads();
	~Threads();

	void addThread(thread p_thread);
	void finish();
};

