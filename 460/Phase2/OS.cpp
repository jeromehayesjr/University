#include "OS.h"

/*
Jerome Hayes & Nyle Hawkinson
os.cpp
This program makes the VirtualMachine and Assembler work together.
Creating a function operating system.
*/
void OS::start_up()
{
	Assembler as;
	string file_list, file_list_o;

    fstream progs, outputfile,inputfile;
	progs.open("\\progs\\Input\\",ios::in);
	if (!progs.is_open()) { cout << "Directory \\progs\\Input failed to open!" << endl; exit(20); }

	progs >> file_list;
	while (!progs.eof()) {
		//file_list stores the names of the files in progs
		file_list_o = file_list.substr(0, file_list.length() - 1); //Prep for changing the name of File_list to create a .o counterpart
		file_list_o += "o";  //Creation of .o counterpart

        outputfile.open("\\progs\\Object\\" + file_list_o, ios::out);
		if (!outputfile.is_open()) { cout << "A .o file failed to open. /n" << "File Name: " << file_list << endl; exit(21); }

        inputfile.open("\\progs\\In\\" + file_list, ios::in);  //The file file_list represents is opened
		if (!inputfile.is_open()) { cout << "An Assembler file in progs failed to open. /n File name: " << file_list << endl; exit(22); }

		if (!inputfile.eof() && outputfile.is_open()) { as.assemble(inputfile, outputfile); } //conversion of .s into .o

		inputfile.close();
		outputfile.close();

		progs >> file_list;
	}
	progs.close();
}

void OS::memory_allocation()
{
	//virtual machine run
	//opening files for program
    fstream vm_writefile, vm_readfile, vm_resultfile, progs, vm_stackfile;
	string file_list, file_list_o;

	//Opening and creation of various files based on names in the Object file
	progs.open("\\progs\\Object\\",ios::in);
	if (!progs.is_open()) { cout << "Directory \\progs\\Object failed to open!" << endl; exit(33); }

	progs >> file_list;
	//Inputs all programs into the memory in the Visual Machine
	while (!vm_writefile.eof() || !vm_readfile.eof() || !vm_resultfile.eof()) {

		//opens files of different types but with the same name
		file_list_o = file_list.substr(0, file_list.length() - 1);
        vm_writefile.open("\\progs\\Object\\" + file_list, ios::in);
        vm_readfile.open("\\progs\\In\\" + file_list_o + "in", ios::in);
        vm_resultfile.open("\\progs\\Result\\" + file_list_o + "out", ios::out);
        vm_stackfile.open("\\progs\\Stack\\" + file_list_o + "st", ios::out);

		//checks to see if files are open
		if (!vm_writefile.is_open()) { cout << "\\progs\\Object failed to open. /n"; exit(4); }
		if (!vm_readfile.is_open()) { cout << "\\progs\\In failed to open. /n"; exit(5); }
		if (!vm_resultfile.is_open()) { cout << "\\progs\\Out failed to open. /n"; exit(6); }
		if (!vm_stackfile.is_open()) { cout << "\\progs\\Stack failed to open. /n"; exit(7); }

		vm.load(vm_writefile);  //.o file is placed into memory

		//PCB is created and filled with relevant data
		PCB * p = new PCB;
		p->pc = vm.pc;
		p->base = vm.base;
		p->limit = vm.limit;
		p->in = vm_readfile;
		p->result = vm_resultfile;
		p->st = vm_stackfile;
		p->process_name = file_list_o;

		jobs.push_back(p);
		readyQ.push(p);

		//closing files
		vm_writefile.close();
		vm_readfile.close();
		vm_resultfile.close();
        vm_stackfile.close();

		progs >> file_list;
	}
}

void OS::program_run()
{
	PCB *running = readyQ.front();
	readyQ.pop();
	while (!readyQ.empty() && !waitQ.empty()) {

		fill_vm(running);

		int status = vm.run(running);
		int vm_return = (status >> 5) & 0b00000000111;

		//Checks process to see if it came across any errors. If so appropriate action is taken
		if (vm_return == 0) { readyQ.push(running); fill_pcb(running); }  //No errors, time slice up, program placed in back of readyQ and its values are stored
		else if (vm_return == 1) { 
            running->turn_around_time = time; 			
            running->result.open("\\progs\\Result\\" + file_list_o + "out", ios::out);
            if (!running->result.is_open()) { cout << "\\progs\\Result failed to open at OS::program_run(). /n"; exit(11); }
			running->result << endl; //////////////////////////////VM Utilization goes here as well as throughput
			running->result.close();
        }  //Program complete, no further action required besides outputting VM Utilization and Throughput.
		else if (vm_return == 2) { cout << "Out-of-Bound reference in program: " << running->process_name << endl;}  //Program encountered error, must be terminated
		else if (vm_return == 3) { cout << "Stack Overflow in program: " << running->process_name << endl; }  //Program encountered error, must be terminated
		else if (vm_return == 4) { cout << "Stack Underflow in program: " << running->process_name << endl; }  //Program encountered error, must be terminated
		else if (vm_return == 5) { cout << "Invalid Opcode in program: " << running->process_name << endl; }  //Program encountered error, must be terminated
		else if (vm_return == 6) {  //Read
			fill_pcb(running);
			running->in.open("\\progs\\In\\" + file_list_o + "in", ios::in);
			if (!running->in.is_open()) { cout << "\\progs\\In failed to open at OS::program_run(). /n"; exit(10); }
			waitQ.push(running);
            
			int io_register = (vm_return >> 3) & 0b00000011;
			running->in >> running->r[io_register]; //place values from in and place in r[]
			running->in.close();
            time += 28;
		}
		else if (vm_return == 7) { //Write
			fill_pcb(running);
			running->result.open("\\progs\\Result\\" + file_list_o + "out", ios::out);
			if (!running->result.is_open()) { cout << "\\progs\\Result failed to open at OS::program_run(). /n"; exit(11); }
			waitQ.push(running);

			int io_register = (vm_return >> 3) & 0b00000011;
			running->result << running->r[io_register] << endl;
			running->result.close();
            time += 28;
		}
		time += running->get_clock(); // fix!!!!!
		time += 5;
		system_time += 5;
        

        if (waitQ.front()->PCB::io_time(PCB::get_clock() - time >= 27))
            { readyQ.push(waitQ.front()); waitQ.pop(); }  //If the front of the waitQ has waited its 27 clicks it is placed in readyQ
		else if (readyQ.empty() == true)
            { readyQ.push(waitQ.front()); waitQ.pop(); }  //If readyQ is empty the front of waitQ is placed in readyQ.
		running = readyQ.front();
		readyQ.pop();

		running->waiting_time = (running->clock - time);

	}
    user_utilization = jobs.size() / time; //cpu user utilzation
}

void OS::system_information()
{
	int total_time;
	fstream system_info("\\progs\\Results\\",ios::in);
	system_info.open("system.txt");
	if (!system_info.is_open()) { cout << "\\progs\\Results\\ failed to open. /n"; exit(50); }
	system_info << "System Time: " << system_time << endl << "System CPU Utilization: " << ((time - system_time) / time) << endl;
	for (list<PCB *>::const_iterator iterator = jobs.begin(), end = jobs.end(); iterator != end; ++iterator) { total_time += (*iterator)->clock; }
    system_info << "User CPU Utilization: " << (total_time/time) << endl << "Throughput: " << (jobs.size()/(time/1000));


}

//Saves all values for later use. places virtual machine values in personal PCB
void fill_pcb(PCB *running)
{
    running->set_pc(vm.get_pc());
	running->set_sr(vm.sr);
	running->set_sp(vm.sp);
	running->set_st(vm.st);
	running->set_r(vm.r);
	running->set_clock(vm.clock);
	running->io_time;
	running->waiting_time;
	running->turn_around_time;
	running->stack_size = (vm.sp - 256) + 256;
}

//Loads all saved values
void fill_vm(PCB *running)
{
	vm.pc = running->pc;
	vm.sr = running->sr;
	vm.sp = running->sp;
	vm.st = running->st;
	vm.r = running->r;
	vm.clock = running->clock;
}
