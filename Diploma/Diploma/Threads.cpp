#include "stdafx.h"
#include "Threads.h"


Threads::Threads()
{
	this->thread_list =  vector<thread>();
	this->size = 0;
}


Threads::~Threads()
{
	for (int i = 0; i < this->thread_list.size(); i++) {
		if (this->thread_list[i].joinable()) {
			this->thread_list[i].join();
		}
		
	}
}

void Threads::addThread(thread p_nit)
{
	this->thread_list.resize(this->size + 1);
	this->thread_list[this->size] = (move(p_nit));
	this->size += 1;
}


void Threads::finish()
{
	for (int i = 0; i < this->thread_list.size(); i++) {
		if (this->thread_list[i].joinable()) {
			this->thread_list[i].join();
		}
			
	}
}
