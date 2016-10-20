#include "Memory.h"


Memory::Memory() 
{
	memory.reserve(0x1000);
	program_counter = 0;
}

Memory::~Memory()
{
}

void Memory::advance_pc()
{
	program_counter += 2;
}

void Memory::jump_pc(u8 addr)
{
	program_counter = addr;
}

std::tuple<u8, u8> Memory::get_instruction()
{
	return std::make_tuple(read(program_counter), read(program_counter + 1));
}

u8 Memory::read(u8 addr)
{
	return memory[addr];
}

void Memory::write(u8 addr, u8 val)
{
	memory[addr] = val;
}
