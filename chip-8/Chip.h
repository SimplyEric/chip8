#ifndef CHIP8_CHIP_H_
#define CHIP8_CHIP_H_

#include "global_typedefs.h"
#include "Memory.h"

class Chip {
public:
	Chip(Memory mem);
	~Chip();
	void exec_instr_and_advance_pc();
private:
	Memory memory;
};

#endif
