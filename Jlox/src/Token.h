#pragma once

#include "Lox.h"

#include <string>

enum class TokenType
{
	Unknown = 0,

	/* logical operators */
	And, Or, Not,

	/* Operators */
	Greater, Greater_Equal, Equal, Equal_Equal,
	Less, Less_Equal, Not_Equal,

	/* One character token */
	Dot, Comma, Colon, Semicolon, Slash, Star, 
	Plus, Minus, Left_Paren, Right_Paren, Left_Brace, Right_Brace,

	/* keywords */
	Class, Func, If, Else, While, For, Nil, Return,
	Print, This, True, False,

	/* Literals */
	String, Number, Identifier,

	Eof
};

enum class LiteralType {
	None,
	Number, String
};

struct Object {
public:
	std::string string;
	double number;

	Object()
	{
	}
	Object(const std::string& str)
	{
		m_Type = LiteralType::String;
		string = str;
	}
	Object(double num)
	{
		m_Type = LiteralType::Number;
		number = num;
	}
	Object(const Object& obj)
	{
		m_Type = obj.m_Type;
		switch (m_Type) {
			case LiteralType::Number:
				number = obj.number;
				break;
			case LiteralType::String:
				string = obj.string;
				break;
			default:
				LX_ASSERT(false && "Unknown literal type");
		}
	}
	~Object()
	{
	}
public:
	LiteralType m_Type;
};

class Token
{
public:
	TokenType m_Type;
	std::string m_Lexeme;
	Object *m_Literal;
	int m_Line;

public:
	Token(TokenType type, std::string lexeme, Object *literal, int line)
		: m_Type(type), m_Lexeme(lexeme), m_Literal(literal), m_Line(line)
	{ }

	std::string ToString()
	{
		return "Token: " + TokenTypeToString(m_Type);
	}

private:
	std::string TokenTypeToString(TokenType type);
};

