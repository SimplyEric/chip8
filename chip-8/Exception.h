#ifndef CHIP8_EXCEPTION_H_
#define CHIP8_EXCEPTION_H_

enum class Exception : unsigned char {
	NONE = 0x00,
	UNDEF_INSTR = 0x01
};


void handleException(Exception e);



#endif