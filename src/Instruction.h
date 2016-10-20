#ifndef CHIP8_INSTRUCTION_H_
#define CHIP8_INSTRUCTION_H_

#include "global_typedefs.h"
#include "Chip.h"
#include "Memory.h"


namespace Instruction
{
	#define ARGS (u8 n1, u8 n2, u8 n3, u8 n4)
	
	void ADD ARGS;
	void AND ARGS;
	void CALL ARGS;
	void CLS ARGS;
	void DRW ARGS;
	void JP ARGS;
	void LD ARGS;
	void OR ARGS;
	void RET ARGS;
	void RND ARGS;
	void SE ARGS;
	void SHL ARGS;
	void SHR ARGS;
	void SKP ARGS;
	void SKNP ARGS;
	void SNE ARGS;
	void SUB ARGS;
	void SUBN ARGS;
	void XOR ARGS;
}

#endif
