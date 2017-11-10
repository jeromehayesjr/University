/*
Jerome Hayes & Nyle Hawkinson
Assembler.h
This program is the header file to our Assembler.
*/

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

class NullPointerException : public runtime_error {
public:
	NullPointerException() : runtime_error("Null Pointer!") {}
};

class Assembler {


private:
	typedef void (Assembler::*FP)();  //Function pointer type
	map<string, FP> m;
	int val1;
	int val2;
	int form;


	void LOAD();
	void LOADI();
	void STORE();
	void ADD();
	void ADDI();
	void ADDC();
	void ADDCI();
	void SUB();
	void SUBI();
	void SUBC();
	void SUBCI();
	void AND();
	void ANDI();
	void XOR();
	void XORI();
	void COMPL();
	void SHL();
	void SHLA();
	void SHR();
	void SHRA();
	void COMPR();
	void COMPRI();
	void GETSTAT();
	void PUTSTAT();
	void JUMP();
	void JUMPL();
	void JUMPE();
	void JUMPG();
	void CALL();
	void RETURN();
	void READ();
	void WRITE();
	void HALT();
	void NOOP();
	int check_constant(int value);
	int check_registry(int value);
        int check_address(int value);

public:
	Assembler();
	void assemble(fstream &assemblyProg, fstream &outfile);

};

#endif
