#ifndef CHIP8_MEMORY_H_
#define CHIP8_MEMORY_H_

#include "global_typedefs.h"
#include <vector>
#include <tuple>
#include <stack>


struct Memory 
{
	u16 pc;
	std::vector<u8> mem;
	std::vector<u8> reg;
	std::stack<u16> stack;

	Memory();
	std::tuple<u8, u8> get_instruction();
};

#endif