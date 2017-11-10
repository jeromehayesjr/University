/*
Jerome Hayes & Nyle Hawkinson
Assembler.cpp
This is the Assembler of the Operating System. The Assembler reads an assembly program and outputs
its corresponding object program.
*/

#include "Assembler.h"
#include <bitset>

using namespace std;


Assembler::Assembler()
{
	m["LOAD"] = &Assembler::LOAD;
	m["LOADI"] = &Assembler::LOADI;
	m["STORE"] = &Assembler::STORE;
	m["ADD"] = &Assembler::ADD;
	m["ADDI"] = &Assembler::ADDI;
	m["ADDC"] = &Assembler::ADDC;
	m["ADDCI"] = &Assembler::ADDCI;
	m["SUB"] = &Assembler::SUB;
	m["SUBI"] = &Assembler::SUBI;
	m["SUBC"] = &Assembler::SUBC;
	m["SUBCI"] = &Assembler::SUBCI;
	m["AND"] = &Assembler::AND;
	m["ANDI"] = &Assembler::ANDI;
	m["XOR"] = &Assembler::XOR;
	m["XORI"] = &Assembler::XORI;
	m["COMPL"] = &Assembler::COMPL;
	m["SHL"] = &Assembler::SHL;
	m["SHLA"] = &Assembler::SHLA;
	m["SHR"] = &Assembler::SHR;
	m["SHRA"] = &Assembler::SHRA;
	m["COMPR"] = &Assembler::COMPR;
	m["COMPRI"] = &Assembler::COMPRI;
	m["GETSTAT"] = &Assembler::GETSTAT;
	m["PUTSTAT"] = &Assembler::PUTSTAT;
	m["JUMP"] = &Assembler::JUMP;
	m["JUMPL"] = &Assembler::JUMPL;
	m["JUMPE"] = &Assembler::JUMPE;
	m["JUMPG"] = &Assembler::JUMPG;
	m["CALL"] = &Assembler::CALL;
	m["RETURN"] = &Assembler::RETURN;
	m["READ"] = &Assembler::READ;
	m["WRITE"] = &Assembler::WRITE;
	m["HALT"] = &Assembler::HALT;
	m["NOOP"] = &Assembler::NOOP;
	val1 = -1;
	val2 = -1;
	form = 0;

}
void Assembler::assemble(fstream &assemblyProg, fstream &outfile)
{
	string line, opcode;

	getline(assemblyProg, line);
	while (!assemblyProg.eof()) {

			if (line[0] == '!') { while (line[0] == '!') { getline(assemblyProg, line); } }
			val1 = -1, val2 = -1; //init to invalid values

		istringstream str(line.c_str());
		str >> opcode >> val1 >> val2;

		//File values are pushed onto corresponding variables based on the opcode given
		try {
			if (!m[opcode])
				NullPointerException();     //If opcode does not exist error message is opened
			else (this->*m[opcode])();   //If opcode exists and map key is used to call a function
		}
		catch (NullPointerException e) {
			cerr << e.what() << endl;
			exit(8);
		}

		outfile << form << endl;  //writes code in .o file
		form = 0;

		getline(assemblyProg, line);
	}
}

// Functions that map keys point to.
// "form" is filled with a different binary value depending on the map key. The bits are shifted 2 times to accomodate for the bits for the registry.
// The registry destination is then added to the front of "form" if it passes the check_registry test, which checks to see if the register to be used is valid.
// "form" is then bit shifted once to accomodate for the immediate bit. The immediate bit is based off the map key. Depending on the key, "form" is either shifted
// 2(1) or 8(2) times.
// (1) If shifted twice check_registry is called again and is appened to the back of form if val2 passes the test. then to fill the remaining bits (16 in total), "form"
// is bit shifted 6 times. "form" is then returned.
// (2) If shifted 8 times, the "constant" is appended to the end of "form". "form" is then returned.

void Assembler::LOAD()
{
	form = 0;
	form = (form << 2) | check_registry(val1);
	form = (form << 9) | check_address(val2);
}
void Assembler::LOADI()
{
	form = 0;
	form = (form << 2) | check_registry(val1);
	form = (form << 1) | 1;
        form = (form << 8) | check_constant(val2);
}
void Assembler::STORE()
{
	form = 1;
	form = (form << 2) | check_registry(val1);
	form = (form << 1) | 1;
	form = (form << 8) | check_address(val2);
}
void Assembler::ADD()
{
	form = 2;
	form = (form << 2) | check_registry(val1);
	form = (form << 3) | check_registry(val2);
	form = form << 6;
}
void Assembler::ADDI()
{
	form = 2;
	form = (form << 2) | check_registry(val1);
	form = (form << 1) | 1;
	form = (form << 8) | check_constant(val2); 
}
void Assembler::ADDC()
{
	form = 0b00011;
	form = (form << 2) | check_registry(val1);
	form = (form << 3) | check_registry(val2);
	form = form << 6;
}
void Assembler::ADDCI()
{
	form = 3;
	form = (form << 2) | check_registry(val1);
	form = (form << 1) | 1;
	form = (form << 8) | check_constant(val2);
}
void Assembler::SUB()
{

	form = 4;
	form = (form << 2) | check_registry(val1);
	form = (form << 3) | check_registry(val2);
	form = form << 6;
}
void Assembler::SUBI()
{

	form = 4;
	form = (form << 2) | check_registry(val1);
	form = (form << 1) | 1;
	form = (form << 8) | check_constant(val2);
}
void Assembler::SUBC()
{

	form = 5;
	form = (form << 2) | check_registry(val1);
	form = (form << 3) | check_registry(val2);
	form = form << 6;
}
void Assembler::SUBCI()
{

	form = 5;
	form = (form << 2) | check_registry(val1);
	form = (form << 1) | 1;
	form = (form << 8) | check_constant(val2);
}
void Assembler::AND()
{

	form = 6;
	form = (form << 2) | check_registry(val1);
	form = (form << 3) | check_registry(val2);
	form = form << 6;
}
void Assembler::ANDI()
{

	form = 6;
	form = (form << 2) | check_registry(val1);
	form = (form << 1) | 1;
	form = (form << 8) | check_constant(val2);
}
void Assembler::XOR()
{

	form = 7;
	form = (form << 2) | check_registry(val1);
	form = (form << 3) | check_registry(val2);
	form = form << 6;
}
void Assembler::XORI()
{

	form = 7;
	form = (form << 2) | check_registry(val1);
	form = (form << 1) | 1;
	form = (form << 8) | check_constant(val2);
}
void Assembler::COMPL()
{

	form = 8;
	form = (form << 2) | check_registry(val1);
	form = form << 9;
}
void Assembler::SHL()
{

	form = 9;
	form = (form << 2) | check_registry(val1);
	form = form << 9;
}
void Assembler::SHLA()
{

	form = 10;
	form = (form << 2) | check_registry(val1);
	form = form << 9;
}
void Assembler::SHR()
{

	form = 11;
	form = (form << 2) | check_registry(val1);
	form = form << 9;
}
void Assembler::SHRA()
{

	form = 12;
	form = (form << 2) | check_registry(val1);
	form = form << 9;
}
void Assembler::COMPR()
{

	form = 13;
	form = (form << 2) | check_registry(val1);
	form = (form << 3) | check_registry(val2);
	form = form << 6;
}
void Assembler::COMPRI()
{

	form = 13;
	form = (form << 2) | check_registry(val1);
	form = (form << 1) | 1;
	form = (form << 8) | check_constant(val2);
}
void Assembler::GETSTAT()
{

	form = 14;
	form = (form << 2) | check_registry(val1);
	form = form << 9;
}
void Assembler::PUTSTAT()
{

	form = 15;
	form = (form << 2) | check_registry(val1);
	form = form << 9;
}
void Assembler::JUMP()
{

	form = 16;
	form = (form << 3) | 1;
	form = (form << 8) | check_address(val1);
}
void Assembler::JUMPL()
{

	form = 17;
	form = (form << 3) | 1;
	form = (form << 8) | check_address(val1);
}
void Assembler::JUMPE()
{

	form = 18;
	form = (form << 3) | 1;
	form = (form << 8) | check_address(val1);
}
void Assembler::JUMPG()
{

	form = 19;
	form = (form << 3) | 1;
	form = (form << 8) | check_address(val1);
}
void Assembler::CALL()
{

	form = 20;
	form = (form << 3) | 1;
	form = (form << 8) | check_address(val1);
}
void Assembler::RETURN()
{
	form = 21;
	form = form << 11;
}
void Assembler::READ()
{

	form = 22;
	form = (form << 2) | check_registry(val1);
	form = form << 9;
}
void Assembler::WRITE()
{

	form = 23;
	form = (form << 2) | check_registry(val1);
	form = form << 9;
}
void Assembler::HALT()
{
	form = 24;
	form = form << 11;
}
void Assembler::NOOP()
{
	form = 25;
	form = form << 11;
}


int Assembler::check_registry(int value)        // check to see if val1 and val2 value are not out of range
{
	if (value > 3 && value < 0) {
		cout << "Invalid Registry! " << endl;
		exit(9);
	}
	else 
		return value;
}

int Assembler::check_address(int value)
{
        if (value > 256) {
                cout << "Address too high!" << endl;
                exit(10);
        }
        else if (value < 0 ) {
                cout << "Address too low!" << endl;
                exit(11);
        }
        return value;
}

int Assembler::check_constant(int value)    // check to see if constant is not out of range
{
	if (value > 0b11111111) {
		cout << "Constant too high!" << endl;
		exit(12);
        }
        else 
                if(value > 0b1111111110000000 && value < 0b10000000)  //checks sign of value
                    value |= 0b10000000;  //if sign is present add it to value
        value &= 0b11111111;  //gets rid of ones before 8 bit
        return value;
        
}


