#include "Chip.h"
#include "Exception.h"


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
	   n2 = std::get<1>(instruction) & ((u8) ~0x0 >> 4),
	   n3 = (std::get<0>(instruction) & ((u8) ~0x0 << 4)) >> 4,
	   n4 = std::get<1>(instruction) & ((u8) ~0x0 >> 4);

	try 
	{
		switch (n1)
		{
		case 0x0:
			if (n2 == 0x0 && n3 == 0xE)
			{
				if (n4 == 0x0)
					; // CLS
				else if (n4 == 0xE)
					; // RET
				else
					throw Exception::UNDEF_INSTR;
			}
			else
				throw Exception::UNDEF_INSTR;
			break;
		case 0x1:
			break;
		case 0x2:
			break;
		case 0x3:
			break;
		case 0x4:
			break;
		case 0x5:
			break;
		case 0x6:
			break;
		case 0x7:
			break;
		case 0x8:
			break;
		case 0x9:
			break;
		case 0xA:
			break;
		case 0xB:
			break;
		case 0xC:
			break;
		case 0xD:
			break;
		case 0xE:
			break;
		case 0xF:
			break;
		default:
			break;
		}
	}
	catch (Exception e)
	{
		handleException(e);
	}
	
	
}
