#include "Lox.h"

#include <fstream>
#include <sstream>

#include "Scanner.h"

bool Lox::m_HadError = true;

int Lox::Run(const char *buffer)
{
	return 0;
}

int Lox::RunPrompt()
{
	while (true) {
		LX_INFO("jlox> ");
		char string[256];
		scanf("%s", string);
		LX_INFO("\t%s\n", string);
	}
}

int Lox::RunScript(const char* filepath)
{
	std::ifstream script(filepath, std::ios_base::in);
	
	if (!script.fail()) {
		LX_INFO("Script opened succesfully: %s\n", filepath);

		std::stringstream buffer;
		buffer << script.rdbuf();

		Scanner scanner(buffer.str());
		scanner.ScanTokens();

		LX_INFO("%s\n", buffer.str().c_str());

		return Run(buffer.str().c_str());
	}
	else {
		LX_ERROR("Couldn`t open file: %s\n", filepath);
		return -1;
	}

	return 0;
}

void Lox::ReportError(int line, const char* message)
{
	m_HadError = true;
	LX_ERROR("Error at line %d: %s\n", line, message);
}
