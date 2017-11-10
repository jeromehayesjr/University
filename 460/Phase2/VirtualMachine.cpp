/*
Jerome Hayes & Nyle Hawkinson
VirtualMachine.cpp
This program reads from a .o file and excuite specific instructions.
*/

#include "VirtualMachine.h"

using namespace std;

int VirtualMachine::run(PCB *running)
{
	//If values are in the stack file the values are placed in the stack.
	running->st.open(ios::in);
	if (!running->st.is_open()) { cout << "\\progs\\Stack failed to open at VirtualMachine::run(). /n"; exit(30); }
    if (running->st.gcount() != 0) { //If the stack file has nothing in it do nothing
		if ((running->st.gcount() % 6) != 0) { cout << "File .st has missing or has too many values! /n"; exit(31); }  //st should always be divisible by 6, if not something went wrong.
        sp = 256;
        running->st >> mem[sp];
        while (!running->st.eof()) {
			if ((sp--) <= pc) { sr &= 0b1111111100011111; sr |= 0b0000000001100000; /*stack overflow*/  break; }
			sp--;
			running->st >> mem[sp];
        } 
    }
	running->st.close();

	int call_return = 0;
	int time_splice = clock + 15;
	while (pc <= limit && clock => time_splice) {

		ir = mem[pc];
		pc++;

		//Breaks up opcode into sections.
		op = rd = i = rs = addr_const = ir;
		op = (op >> 11);
		rd = (rd >> 9) & 0b0000011 ;
		i = (i >> 8) & 0b00000001;
		rs = (rs >> 6) & 0b0000000011;
	    addr_const = addr_const & 0b0000000011111111;
        cout << op << "  " << rd  << " " << i  << " " << rs << " " << addr_const  << endl;

		//If the first bit in addr_const is 1 the twos compliment is given
		addr_const = two_compliment(addr_const);

		//Compares opcode and immediate as to find the right algorithims to perform
		if (op == 0b00000 && i != 1) {//LOAD
			if (addr_const > limit || addr_const < base) { sr &= 0b1111111100011111; sr |= 0b0000000001000000; /*Out-of-bounds*/  return sr; }
			r[rd] = mem[addr_const];

			clock += 4;
		}
		else if (op == 0b00000 && i == 1) {//LOADI
            if (addr_const > limit || addr_const < base) { sr &= 0b1111111100011111; sr |= 0b0000000001000000; /*Out-of-bounds*/  return sr; }
			r[rd] = addr_const;

			clock += 1;
		}
		else if (op == 0b00001 && i == 1) {//STORE
			if (addr_const > limit || addr_const < base) { sr &= 0b1111111100011111; sr |= 0b0000000001000000; /*Out-of-bounds*/  return sr; }
			mem[addr_const] = r[rd];

			clock += 4;
		}
		else if (op == 0b00010 && i != 1) {//ADD
			temp = r[rd];
			r[rd] = r[rd] + r[rs];

			set_carry(r[rd]);
			set_overflow(temp, r[rs], r[rd]);
			clock += 1;
		}
		else if (op == 0b00010 && i == 1) {//ADDI
			temp = r[rd];
			r[rd] = r[rd] + addr_const;

			set_carry(r[rd]);
			set_overflow(temp, addr_const, r[rd]);
			clock += 1;
		}
		else if (op == 0b00011 && i != 1) {//ADDC
			temp = r[rd];
			r[rd] = r[rd] + r[rs] + carry;

			set_carry(r[rd]);
			set_overflow(temp, r[rs] + 1, r[rd]);
			clock += 1;
		}
		else if (op == 0b00011 && i == 1) {//ADDCI
			temp = r[rd];
			r[rd] = r[rd] + addr_const + carry;

			set_carry(r[rd]);
			set_overflow(temp, addr_const + 1, r[rd]);
			clock += 1;
		}
		else if (op == 0b00100 && i != 1) {//SUB
			r[rd] = r[rd] - r[rs];

			set_carry(r[rd]);
			clock += 1;
		}
		else if (op == 0b00100 && i == 1) {//SUBI
			r[rd] = r[rd] - addr_const;

			set_carry(r[rd]);
			clock += 1;
		}
		else if (op == 0b00101 && i != 1) {//SUBC
			r[rd] = r[rd] - r[rs] - carry;

			set_carry(r[rd]);
			clock += 1;
		}
		else if (op == 0b00101 && i == 1) {//SUBCI
			r[rd] = r[rd] - addr_const - carry;

			set_carry(r[rd]);
			clock += 1;
		}
		else if (op == 0b00110 && i != 1) {//AND
			r[rd] = r[rd] & r[rs];

			clock += 1;
		}
		else if (op == 0b00110 && i == 1) {//ANDI
			r[rd] = r[rd] & addr_const;

			clock += 1;
		}
		else if (op == 0b00111 && i != 1) {//XOR
			r[rd] = r[rd] ^ r[rs];

			clock += 1;
		}
		else if (op == 0b00111 && i == 1) {//XORI
			r[rd] = r[rd] ^ addr_const;

			clock += 1;
		}
		else if (op == 0b01000) {//COMPL
			r[rd] = ~r[rd];

			clock += 1;
		}
		else if (op == 0b01001) {//SHL
			r[rd] = r[rd] << 1;

			set_carry(r[rd]);
			clock += 1;
		}
		else if (op == 0b01010) {//SHLA
			set_carry(r[rd] >> 1);
			if (r[rd] > 32767) {
				r[rd] = r[rd] << 1;
				r[rd] = r[rd] | 32767;
			}
			else { r[rd] = r[rd] << 1; }


			clock += 1;
		}
		else if (op == 0b01011) {//SHR
			r[rd] = r[rd] >> 1;

			set_carry(r[rd]);
			clock += 1;
		}
		else if (op == 0b01100) {//SHRA
			set_carry(r[rd] >> 1);
			if (r[rd] > 32767) {
				r[rd] = r[rd] >> 1;
				r[rd] = r[rd] | 32767;
			}
			else { r[rd] = r[rd] >> 1; }

			clock += 1;
		}
		else if (op == 0b01101 && i != 1) {//COMPR
			if (r[rd] < r[rs]) { sr = 8; }
			else if (r[rd] > r[rs]) { sr = 4; }
			else if (r[rd] == r[rs]) { sr = 2; }

			clock += 1;
		}
		else if (op == 0b01101 && i == 1) {//COMPRI
			if (r[rd] < addr_const) { sr = 8; }
			else if (r[rd] > addr_const) { sr = 4; }
			else if (r[rd] == addr_const) { sr = 2; }

			clock += 1;
		}
		else if (op == 0b01110) {//GETSTAT
			r[rd] = sr;
			clock += 1;
		}
		else if (op == 0b01111) {//PUTSTAT
			sr = r[rd];

			clock += 1;
		}
		else if (op == 0b10000 && i == 1) {//JUMP
			if (addr_const > limit || addr_const < base) { sr &= 0b1111111100011111; sr |= 0b0000000001000000; /*Out-of-bounds*/  return sr; }
			pc = addr_const;

			clock += 1;
		}
		else if (op == 0b10001 && i == 1) {//JUMPL
			if (addr_const > limit || addr_const < base) { sr &= 0b1111111100011111; sr |= 0b0000000001000000; /*Out-of-bounds*/  return sr; }
			bitset<16> check(sr);
			if (check.test(4) == true) { pc = addr_const; }

			clock += 1;
		}
		else if (op == 0b10010 && i == 1) {//JUMPE
			if (addr_const > limit || addr_const < base) { sr &= 0b1111111100011111; sr |= 0b0000000001000000; /*Out-of-bounds*/  return sr; }
			bitset<16> check(sr);
			if (check.test(1) == true) { pc = addr_const; }

			clock += 1;
		}
		else if (op == 0b10011 && i == 1) {//JUMPG
			if (addr_const > limit || addr_const < base) { sr &= 0b1111111100011111; sr |= 0b0000000001000000; /*Out-of-bounds*/  return sr; }
			bitset<16> check(sr);
			if (check.test(2) == true) { pc = addr_const; }

			clock += 1;
		}
		else if (op == 0b10100 && i == 1) {//CALL
			if (addr_const > limit || addr_const < base) { sr &= 0b1111111100011111; sr |= 0b0000000001000000; /*Out-of-bounds*/  return sr; }
			if ((sp - 6) <= pc) { sr &= 0b1111111100011111; sr |= 0b0000000001100000; /*stack overflow*/  break; }
			sp--;
			mem[sp] = pc;
			sp--;
			mem[sp] = sr;
			sp--;
			mem[sp] = r[0];
			sp--;
			mem[sp] = r[1];
			sp--;
			mem[sp] = r[2];
			sp--;
			mem[sp] = r[3];
                   
            call_return = pc;
            pc = addr_const;
			clock += 4;
		}
		else if (op == 0b10101) {//RETURN
			if ((sp + 6) >= 256) { sr &= 0b1111111100011111; sr |= 0b0000000010000000; /*stack underflow*/  break; }
			r[3] = mem[sp];
			sp++;
			r[2] = mem[sp];
			sp++;
			r[1] = mem[sp];
			sp++;
			r[0] = mem[sp];
			sp++;
			sr = mem[sp];
			sp++;
			pc = mem[sp];
			sp++;

            pc = call_return;
			clock += 4;           
		}
		else if (op == 0b10110) {//READ

			clock += 1;
			sr &= 0b1111110000011111; sr |= 0b0000000011000000; /*read operation*/
			int shift = (rd << 8); /*Set I/O register*/
			sr |= shift;
			return sr;
		}
		else if (op == 0b10111) {//WRITE
			if (r[rd] > 32767) { r[rd] = r[rd] + 0b111111111111111100000000; } //Sign Extension

			clock += 1;
			sr &= 0b1111110000011111; sr |= 0b0000000011100000; /*write operation*/
			int shift = (rd << 8); /*Set I/O register*/
			sr |= shift;
			return sr;
		}
		else if (op == 0b11000) {//HALT
			sr &= 0b1111111100011111; sr |= 0b0000000000100000; /*Halt Operation*/

			clock += 1;
			return sr;
		}
		else if (op == 0b11001) {//NOOP
			clock += 1;
		}
		else { sr &= 0b1111111100011111; sr |= 0b0000000010100000; /*Invalid Opcode*/ }
	}
    
    running->st.open(ios::out);
    running->st.close();
	//Places the stack into a file
	if (sp != 256) {  //If stack is empty do nothing
		running->st.open(ios::out);
		running->st << mem[sp];
		while (sp != 256) {
			sp--;
			running->st << mem[sp];
		}
		running->st.close();

	}

	if ((clock >= time_splice) || (pc > limit)) { sr &= 0b1111111100011111; } /*Time slice*/
	return sr;
}


int VirtualMachine::two_compliment(int value)
{
	bitset<8> check(value);
	if (check.test(7) == true) {  //Sign bit is present
		value = ~value + 1;  //Aquire 2's compliment, making - into positive
		return value * -1;  //Return original negative number
	}
	return value;  //No sign bit present so return original value.
}

void VirtualMachine::set_carry(int result) 
{
	bitset<16> check(result);  //If 16 bit == 1 set place carry bit
	if (check.test(15) == true) { sr = 1; carry = 1; }
	else { sr = 0; carry = 0; }  //Else carry bit set to 0
}

void VirtualMachine::set_overflow(int val1, int val2, int result) {
	//Checks to see if values are over 16 bits. If so set overflow bit
	bitset<16> check1(val1);	
	bitset<16> check2(val2);	
	bitset<16> check3(result);
	if ((check1.test(15) == 0 && check2.test(15) == 0 && check3.test(15) == 1) || (check1.test(15) == 1 && check2.test(15) == 1 && check3.test(15) == 0)) {
		sr = 0b10000;
		if (carry == 1) { sr += 1; }
	}
	else { sr = 0; if (carry == 1) { sr += 1; } }
}

void VirtualMachine::load(fstream &write_memory)
{
	//Loads .o file contents into the virtual machine memory
	pc = base;
	write_memory >> mem[pc];
	while (!write_memory.eof()) {
		if ((pc++) > 256) { cout << "Programs are too big for OS /n"; exit(40); }
		pc++;
		limit++;
		write_memory >> mem[pc];
	}	
	pc++;
}