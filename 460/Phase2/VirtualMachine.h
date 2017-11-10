/*
Jerome Hayes & Nyle Hawkinson
VirtualMachine.h
This program is the header file to my Virtual Machine
*/

#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H


#include "PCB.h"

#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

class VirtualMachine 
{


private:
	static const int REG_FILE_SIZE = 4;
	static const int MEM_SIZE = 256;
	vector<int> r;   //REGISTERS SIZE 4
	vector<int> mem; //MEMORY SIZE 256
	int pc;          //PROGRAM COUNTER
	int ir;	         //INSTRUCTION REGISTER
	int sr;          //STATUS REGISTER
	int sp;          //STACK POINTER
	int op;          //OPERAND
	int rd;          //DESTINATION
	int i;           //IMMEDIATE
	int rs;          //SOURCE
	int addr_const;  //ADDRESS OR CONSTANT
	int clock;
	int limit;
	int base;
	int carry;
	int temp;
	fstream st;

	void set_overflow(int val1, int val2, int result);
	void set_carry(int result);
	int two_compliment(int value);
public:
	VirtualMachine() : r(vector<int>(REG_FILE_SIZE)), mem(vector<int>(MEM_SIZE)), pc(0), ir(0), sr(0), limit(0), sp(256), clock(0), carry(0), temp(0) {};
	int run(PCB *running);
	void load(fstream &write_memory);
    int get_sr() {return sr;}
    int get_pc() {return pc;}
    
    friend class OS;
};
#endif
