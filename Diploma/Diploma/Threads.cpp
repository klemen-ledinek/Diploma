#include "stdafx.h"
#include "Threads.h"


Threads::Threads()
{
	this->thread_list =  vector<thread>();
}


Threads::~Threads()
{
	for (int i = 0; i < this->thread_list.size(); i++) {
		if (this->thread_list[i].joinable()) {
			this->thread_list[i].join();
		}
		
	}
}

void Threads::addThread(thread p_thread)
{
	this->thread_list.push_back(move(p_thread));
}


void Threads::finish()
{
	for (int i = 0; i < this->thread_list.size(); i++) {
		if (this->thread_list[i].joinable()) {
			this->thread_list[i].join();
		}
		
		//}
			
	}
}
