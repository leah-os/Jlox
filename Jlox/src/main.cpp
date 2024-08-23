#include <stdlib.h>

#include "Lox.h"

int main(int argc, const char** argv)
{
	if (argc > 2) {
		LX_ERROR("Usage: ./jlox [script]");
		exit(64);
	}
	else if (argc == 2) {
		return Lox::RunScript(argv[1]);
	}
	else {
		return Lox::RunPrompt();
	}
}