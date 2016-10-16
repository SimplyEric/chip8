#ifndef CHIP8_INSTRUCTION_H_
#define CHIP8_INSTRUCTION_H_

#include "global_typedefs.h"
#include "Chip.h"
#include "Memory.h"

#define nnn  u8 n1, u8 n2, u8 n3
#define xkk  u8 x, u8 k1, u8 k2
#define xyn  u8 x, u8 y, u8 n
#define xy   u8 x, u8 y


namespace Instruction
{
	void CLS();
	void RET();
	void JP(u8 flag, nnn);
	void CALL(nnn);
	void SE(xkk);
	void SE(xy);
	void SNE(xkk);
	void SNE(xy);
	void LD(nnn);
	void LD(xkk);
	void LD(xy);
	void LD(u8 x, u8 flag1, u8 flag2);
	void AND(xkk);
	void OR(xy);
	void ADD(xy);
	void XOR(xy);
	void SUB(xy);
	void SHR(xy);
	void SHL(xy);
	void SUBN(xy);
	void RND(xkk);
	void DRW(xyn);
	void SKP(u8 x);
}

#endif
