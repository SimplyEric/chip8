#include "Instruction.h"
#include "Exception.h"

void Instruction::ADD(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
	switch (n1)
	{
	case 0x7:
		mem.reg[n2] += n3 << 4 | n4;
		break;
	case 0x8:
		mem.reg[n2] += mem.reg[n3];
		if (mem.reg[n3] > mem.reg[n2])
			mem.reg[0xF] = 0x1;
		else
			mem.reg[0xF] = 0x0;
		break;
	case 0xF:
		mem.pc += mem.reg[n2];
		break;
	default:
		throw Exception::UNDEF_INSTR;
		break;
	}
}

void Instruction::AND(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
	mem.reg[n2] &= mem.reg[n3];
}

void Instruction::CALL(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
	mem.stack.push(mem.pc);
	mem.pc = (u16)n2 << 8 | (u16)n3 << 4 | (u16)n4;
}

void Instruction::CLS(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::DRW(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::JP(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::LD(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::OR(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::RET(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::RND(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::SE(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::SHL(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::SHR(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::SKP(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::SKNP(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::SNE(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::SUB(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::SUBN(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}

void Instruction::XOR(Memory mem, u8 n1, u8 n2, u8 n3, u8 n4)
{
}
