/*
Jerome Hayes & Nyle Hawkinson
VirtualMachine.cpp
This program reads from a .o file and excuite specific instructions.
*/

#include "VirtualMachine.h"
#include <bitset>
#include <string>

using namespace std;

void VirtualMachine::run(fstream &input_file, fstream &output_file, ostream &results)
{
        int call_return = 0;

	input_file >> mem[pc];
	while (!input_file.eof() || pc < MEM_SIZE) {
		pc++;
		limit++;
		input_file >> mem[pc];
	}
	input_file.close();
	pc = 0;

	while (pc <= limit) {

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
			r[rd] = mem[addr_const];

			clock += 4;
		}
		else if (op == 0b00000 && i == 1) {//LOADI
			r[rd] = addr_const;

			clock += 1;
		}
		else if (op == 0b00001 && i == 1) {//STORE
			mem[addr_const] = r[rd];

			clock += 4;
		}
		else if (op == 0b00010 && i != 1) {//ADD
			r[rd] = r[rd] + r[rs];

			set_carry(r[rd]);
			set_overflow(r[rd]);
            set_overflow(r[rs]);
			clock += 1;
		}
		else if (op == 0b00010 && i == 1) {//ADDI
			r[rd] = r[rd] + addr_const;
            
			set_carry(r[rd]);
            set_overflow(r[rd]);
			clock += 1;
		}
		else if (op == 0b00011 && i != 1) {//ADDC
			r[rd] = r[rd] + r[rs] + carry;

			set_carry(r[rd]);
			set_overflow(r[rd]);
			clock += 1;
		}
		else if (op == 0b00011 && i == 1) {//ADDCI
			temp = r[rd];
			r[rd] = r[rd] + addr_const + carry;

			set_carry(r[rd]);
            set_overflow(r[rd]);
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
			pc = addr_const;

			clock += 1;
		}
		else if (op == 0b10001 && i == 1) {//JUMPL
			bitset<16> check(sr);
			if (check.test(4) == true) { pc = addr_const; }

			clock += 1;
		}
		else if (op == 0b10010 && i == 1) {//JUMPE
			bitset<16> check(sr);
			if (check.test(1) == true) { pc = addr_const; }

			clock += 1;
		}
		else if (op == 0b10011 && i == 1) {//JUMPG
			bitset<16> check(sr);
			if (check.test(2) == true) { pc = addr_const; }

			clock += 1;
		}
		else if (op == 0b10100 && i == 1) {//CALL
            
            call_return = pc;
            
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
            clock += 4;
            pc = addr_const;

		}
		else if (op == 0b10101) {//RETURN
            pc = call_return;
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
			clock += 4;
		}
		else if (op == 0b10110) {//READ
			output_file >> r[rd];

			clock += 28;
		}
		else if (op == 0b10111) {//WRITE
			if (r[rd] > 32767) { r[rd] = r[rd] + 0b111111111111111100000000; } //Sign Extension
			results << r[rd] << " ";

			clock += 28;
		}
		else if (op == 0b11000) {//HALT
			break;

			clock += 1;
		}
		else if (op == 0b11001) {//NOOP
			clock += 1;
		}
	}

	results << endl << "clock: " << clock << endl;
}


int VirtualMachine::two_compliment(int value)
{
	bitset<16> check(value);
	if (check.test(15) == true) {  //Sign bit is present
		value = ~value + 1;  //Aquire 2's compliment, making - into positive
		return value * -1;  //Return original negative number
	}
	return value;  //No sign bit present so return original value.
}

void VirtualMachine::set_carry(int result) // works!!
{
    string binary = bitset<16>(result).to_string(); //to binary
    
    if (binary[0] == '1') { sr = 1; carry = 1; } // checking 16 bit
    else { sr = 0; carry = 0; }  //Else carry bit set to 0
}

void VirtualMachine::set_overflow(int result)   //works!!
{
    string binary = bitset<16>(result).to_string();     //to binary
    unsigned long decimal = std::bitset<16>(binary).to_ulong(); // to decimal
    if(decimal > 32767) {                   //If value bigger than 0b111111111111111
        sr = 0b10000;                               //set overflow bit
        cout << "Error 10: Overflow!!" << endl;     //disply error and stop program
        exit(10);
    }
}
