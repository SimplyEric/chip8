#include "Memory.h"


Memory::Memory() 
{
	mem.reserve(0x1000);
	reg.reserve(0x10);
	pc = 0;
}

std::tuple<u8, u8> Memory::get_instruction()
{
	return std::make_tuple(mem[pc], mem[pc + 1]);
}
