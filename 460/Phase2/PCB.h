#ifndef PCB_H
#define PCB_H

#include <fstream>
#include <vector>
#include "VirtualMachine.h"

using namespace std;

class PCB
{

private:
	string process_name;
	int pc;          //PROGRAM COUNTER
	int sr;          //STATUS REGISTER
	int sp;          //STACK POINTER
	vector<int> r;
    fstream result;
    fstream in;
    fstream st;
	int temp;
	int limit;
	int base;
    int clock;
	int time;
    int io_time;
    int waiting_time;
    int turn_around_time;
    int stack_size;
public:
	PCB() { }

	///vector not declared

	int get_sr() { return sr; }
	int get_pc() { return pc; }
	int get_sp() { return sp; }
	int get_limit() { return limit; }
	int get_base() { return base; }
    int get_clock() {return clock;}
    int get_io_time(){return io_time;}
    int get_waitng_time() {return waiting_time;}
    int get_turn_around_time() {return turn_around_time;}
    int get_stack_size() {return stack_size;}

    void add_clock(int time) {clock += time;}
    void add_io_time(int time) {io_time += time;}
    void add_waiting_time(int time) {waiting_time += time;}
    void add_turn_around_time(int time) {turn_around_time += time;}
    
    friend class VirtualMachine;
    friend class OS;
    
    void set_io_time(int r) { io_time = r;}
    void set_sr(int r) {sr=r;}
    void set_pc(int r) {pc = r;}
    void set_sp(int r) {sp = r;}
    void set_clock(int r) {clock = r;}
    void set_st(fstream & f) {st = f;}
    void set_r(vector<int> v) { r[0] = v[0]; r[1] = v[1]; r[2] = v[2]; r[3] = v[3];}
};


#endif
