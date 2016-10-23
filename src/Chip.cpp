#include "Chip.h"
#include "Exception.h"
#include "Instruction.h"

Chip::Chip(Memory mem)
{
	memory = mem;
}

Chip::~Chip()
{
}

void Chip::exec_instr_and_advance_pc()
{
	std::tuple<u8, u8> instruction = memory.get_instruction();

	// split the instruction into four parts, each padded with 4 zeros
	u8 n1 = (std::get<0>(instruction) & ((u8) ~0x0 << 4)) >> 4,
	   n2 = std::get<0>(instruction) & ((u8) ~0x0 >> 4),
	   n3 = (std::get<1>(instruction) & ((u8) ~0x0 << 4)) >> 4,
	   n4 = std::get<1>(instruction) & ((u8) ~0x0 >> 4);

	#define ARGS (this->memory,n1,n2,n3,n4)

	try 
	{
		switch (n1)
		{
		case 0x0:
			if (n2 == 0x0 && n3 == 0xE && n4 == 0x0)
				Instruction::CLS ARGS;
			else if (n2 == 0x0 && n3 == 0xE && n4 == 0xE)
				Instruction::RET ARGS;
			else
				throw Exception::UNDEF_INSTR;
			break;
		
		case 0x1:
			Instruction::JP ARGS;
			break;
		
		case 0x2:
			Instruction::CALL ARGS;
			break;
		
		case 0x3:
			Instruction::SE ARGS;
			break;
		
		case 0x4:
			Instruction::SNE ARGS;
			break;
		
		case 0x5:
			if (n4 == 0)
				Instruction::SE ARGS;
			else
				throw Exception::UNDEF_INSTR;
			break;
		
		case 0x6:
			Instruction::LD ARGS;
			break;

		case 0x7:
			Instruction::ADD ARGS;
			break;
			
		case 0x8:
			switch (n4)
			{
			case 0x0: Instruction::LD ARGS; break;
			case 0x1: Instruction::OR ARGS; break;
			case 0x2: Instruction::AND ARGS; break;
			case 0x3: Instruction::XOR ARGS; break;
			case 0x4: Instruction::ADD ARGS; break;
			case 0x5: Instruction::SUB ARGS; break;
			case 0x6: Instruction::SHR ARGS; break;
			case 0x7: Instruction::SUBN ARGS; break;
			case 0xE: Instruction::SHL ARGS; break;
			default: throw Exception::UNDEF_INSTR; break;
			}
			break;
			
		case 0x9:
			if (n4 == 0)
				Instruction::SNE ARGS;
			else
				throw Exception::UNDEF_INSTR;
			break;
			
		case 0xA:
			Instruction::LD ARGS;
			break;
			
		case 0xB:
			Instruction::JP ARGS;
			break;
			
		case 0xC:
			Instruction::RND ARGS;
			break;
			
		case 0xD:
			Instruction::DRW ARGS;
			break;
			
		case 0xE:
			if (n3 == 0x9 && n4 == 0xE)
				Instruction::SKP ARGS;
			else if (n3 == 0xA && n4 == 0x1)
				Instruction::SKNP ARGS;
			else
				throw Exception::UNDEF_INSTR;
			break;
			
		case 0xF:
			switch (std::get<1>(instruction))
			{
			case 0x1E:
				Instruction::ADD ARGS;
				break;
			case 0x07:
			case 0x0A:
			case 0x15:
			case 0x18:
			case 0x29:
			case 0x33:
			case 0x55:
			case 0x66:
				Instruction::LD ARGS;
				break;
			default:
				throw Exception::UNDEF_INSTR;
			}
			break;
			
		default:
			throw Exception::UNDEF_INSTR;
			break;
		}
	}
	catch (Exception e)
	{
		handleException(e);
	}
	
}
