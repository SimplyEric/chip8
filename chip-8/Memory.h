#ifndef CHIP8_MEMORY_H_
#define CHIP8_MEMORY_H_

#include "global_typedefs.h"
#include <vector>
#include <tuple>


class Memory {
public:
	Memory();
	~Memory();
	void advance_pc();
	void jump_pc(u8 addr);
	std::tuple<u8, u8> get_instruction();
	u8 read(u8 addr);
	void write(u8 addr, u8 val);

private:
	std::vector<unsigned char> memory;
	u16 program_counter;
};

#endif