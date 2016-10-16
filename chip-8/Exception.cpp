#include "Exception.h"
#include <cstdlib>
#include <cstdio>


void handleException(Exception e)
{
	switch (e) 
	{
		case Exception::NONE:
			// do nothing
			break;
		case Exception::UNDEF_INSTR:
			fputs("undefined instruction called", stderr);
			std::exit(1);
			break;
	}
}
