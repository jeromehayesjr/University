#include <iostream>
#include "Assembler.h"
#include "VirtualMachine.h"

	/*
	Jerome Hayes & Nyle Hawkinson
	os.cpp
	This program makes the VirtualMachine and Assembler work together.
	Creating a function operating system.
	*/


#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	//assembler
	//opening files for program
	fstream inputfile;
	inputfile.open("fact.s", ios::in);
	Assembler as;

	if (!inputfile.is_open()) {
		cout << "prog.s failed to open. /n";
		exit(1);
	}
	fstream outputfile;
	outputfile.open("prog.o", ios::out);

	if (!outputfile.is_open()) {
		cout << "prog.o failed to open. /n";
		exit(2);
	}
	if (!inputfile.eof() && outputfile.is_open())
		as.assemble(inputfile, outputfile);

	//closing files
	inputfile.close();
	outputfile.close();

	//virtual machine run
	//opening files for program
	VirtualMachine vm;

	fstream vm_writefile;
	vm_writefile.open("prog.o", ios::in);

	if (!vm_writefile.is_open()) {
		cout << "prog.o failed to open. /n";
		exit(4);
	}

	fstream vm_readfile;
	vm_readfile.open("prog.in", ios::out);

	if (!vm_readfile.is_open()) {
		cout << "prog.out failed to open. /n";
		exit(5);
	}

	fstream vm_resultfile;
	vm_resultfile.open("prog.out", ios::out);

	if (!vm_resultfile.is_open()) {
		cout << "prog.out failed to open. /n";
		exit(7);
	}
	if (!vm_writefile.eof() && vm_resultfile.is_open())
		vm.run(vm_writefile, vm_readfile, vm_resultfile);
	exit(6);

	//closing files
	vm_writefile.close();
	vm_readfile.close();
	vm_resultfile.close();
}

