#pragma once

#include <stdio.h>
#include <assert.h>

#define LX_INFO(fmt, ...) printf(fmt, __VA_ARGS__)
#define LX_WARN(fmt, ...) printf(stderr, fmt, __VA_ARGS__)
#define LX_ERROR(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)

#define LX_ASSERT(...) assert(__VA_ARGS__)

class Lox
{
public:
	static int Run(const char* buffer);

	static int RunPrompt();
	static int RunScript(const char* filepath);

	static void ReportError(int line, const char* message);

private:
	static bool m_HadError;
};

