#pragma once

#include "Token.h"

#include <vector>
#include <unordered_map>

class Scanner
{
public:
	Scanner(const std::string& source)
		: m_Source(source), m_Current(0), m_Line(1)
	{
	}

	std::vector<Token> ScanTokens();
	void AddToken(TokenType type);
	void AddToken(TokenType type, int literal);
	void AddToken(TokenType type, const std::string& literal);

private:
	void NumberToken();
	void StringToken();
	void IdentifierToken();
	char Seek();
	char GetNextChar();
	bool IsMatches(char c);
	bool IsIdentifierChar(char c);
	bool IsNotEnd();

private:
	std::string m_Source;
	int m_Current, m_Line;
	std::vector<Token> m_Tokens;
	std::unordered_map<std::string, TokenType> m_Keywords = {
		{"or", TokenType::Or},
		{"and", TokenType::And},
		{"not", TokenType::Not},
		{"for", TokenType::For},
		{"while", TokenType::While},
		{"if", TokenType::If},
		{"else", TokenType::Else},
		{"true", TokenType::True},
		{"false", TokenType::False},
		{"func", TokenType::Func},
		{"class", TokenType::Class},
		{"nil", TokenType::Nil},
		{"return", TokenType::Return},
		{"print", TokenType::Print},
		{"this", TokenType::This}
	};;
};