/*
Jerome Hayes & Nyle Hawkinson
VirtualMachine.h
This program is the header file to my Virtual Machine
*/

#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Assembler.h"

using namespace std;

class VirtualMachine {
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
	int unused;      //UNUSED BIT
	int addr_const;  //ADDRESS OR CONSTANT
	int clock;
	int limit;
	int carry;
	int temp;

	void set_overflow(int result);
	void set_carry(int result);
	int two_compliment(int value);
public:
	VirtualMachine() : r(vector<int>(REG_FILE_SIZE)), mem(vector<int>(MEM_SIZE)), pc(0), ir(0), sr(0), limit(0), sp(256), clock(0), carry(0), temp(0) {};
	void run(fstream &input_file, fstream &output_file, ostream &result);

};
#endif
