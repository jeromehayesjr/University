#ifndef OS_H
#define OS_H

#include "Assembler.h"
#include "VirtualMachine.h"
#include "PCB.h"

#include <iostream>
#include <fstream>
#include <iostream>
#include <queue>
#include <list>

/*
Jerome Hayes & Nyle Hawkinson
os.cpp
This program makes the VirtualMachine and Assembler work together.
Creating a function operating system.
*/

using namespace std;
class OS
{
private:
	list<PCB *> jobs;
	queue<PCB *> readyQ, waitQ;
	VirtualMachine vm;
	string file_list, file_list_o;
	int time;
	int system_time;
	int throughput;
    int user_utilization;

public:
	OS() {};
	void start_up();
	void memory_allocation();
	void program_run();
	void system_information();
    void fill_vm(PCB *running);
    void fill_pcb(PCB *running);
    
    friend class VirtualMachine;
    friend class PCB;
};
#endif