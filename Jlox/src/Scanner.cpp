#include "Scanner.h"

std::vector<Token> Scanner::ScanTokens()
{
	std::vector<Token> tokens;

	while (m_Current < m_Source.size()) {
		char c = GetNextChar();
		switch (c) {
			case '(':
				AddToken(TokenType::Left_Paren);
				break;
			case ')':
				AddToken(TokenType::Right_Paren);
				break;
			case '*':
				AddToken(TokenType::Star);
				break;
			case ';':
				AddToken(TokenType::Semicolon);
				break;
			case ':':
				AddToken(TokenType::Colon);
				break;
			case '.':
				AddToken(TokenType::Dot);
				break;
			case ',':
				AddToken(TokenType::Comma);
				break;
			case '/':
				if (IsMatches('/')) {
					while (IsNotEnd() && !IsMatches('\n'))
						GetNextChar();
					m_Line++;
					break;
				}
				AddToken(TokenType::Slash);
				break;
			case '=':
				if (IsMatches('=')) {
					GetNextChar();
					AddToken(TokenType::Equal_Equal);
					break;
				}
				AddToken(TokenType::Equal);
				break;
			case '>':
				if (IsMatches('=')) {
					GetNextChar();
					AddToken(TokenType::Greater_Equal);
					break;
				}
				AddToken(TokenType::Greater);
				break;
			case '<':
				if (IsMatches('=')) {
					GetNextChar();
					AddToken(TokenType::Less_Equal);
					break;
				}
				AddToken(TokenType::Less);
				break;
			case '"':
				StringToken();
				break;
			case '\n':
				m_Line++;
				break;
			case ' ':
			case '\r':
			case '\t':
				break;
			default:
				if (std::isdigit(c))
					NumberToken();
				else if (std::isalpha)
					IdentifierToken();
				else
					Lox::ReportError(m_Line, std::string("Unexpected symbol: " + c).c_str());
				break;
		}
	}
	for (int i = 0; i < m_Tokens.size(); i++) {
		LX_INFO("%s %s\n", m_Tokens[i].ToString().c_str(), m_Tokens[i].m_Lexeme.c_str());
	}
	return m_Tokens;
}

void Scanner::AddToken(TokenType type)
{
	m_Tokens.push_back(Token(type, "", nullptr, m_Line));
}

void Scanner::AddToken(TokenType type, const std::string& literal)
{
	m_Tokens.push_back(Token(type, literal, new Object(literal), m_Line));
}

void Scanner::AddToken(TokenType type, int literal)
{
	m_Tokens.push_back(Token(type, "", new Object(literal), m_Line));
}

void Scanner::StringToken()
{
	std::string liter;
	while (IsNotEnd() && !IsMatches('"'))
		liter.push_back(GetNextChar());
	if (!IsNotEnd())
		Lox::ReportError(m_Line, "Undetermined string literal");
	GetNextChar();
	AddToken(TokenType::String, liter);
}

void Scanner::NumberToken()
{
	char c = m_Source[m_Current - 1];
	int res = 0;
	while (IsNotEnd() && std::isdigit(c)) {
		res = res * 10 + (c - '0');
		c = Seek();
		m_Current++;
	}
	AddToken(TokenType::Number, res);
}

void Scanner::IdentifierToken()
{
	std::string ident;
	char c = m_Source[m_Current - 1];
	
	while (IsNotEnd() && IsIdentifierChar(c)) {
		ident.push_back(c);
		c = Seek();
		m_Current++;
	}
	m_Current--;

	if(m_Keywords[ident] != TokenType::Unknown)
		AddToken(m_Keywords[ident], ident);
	else
		AddToken(TokenType::Identifier, ident);
}

char Scanner::Seek()
{
	return m_Source[m_Current];
}

char Scanner::GetNextChar()
{
	return m_Source[m_Current++];
}

bool Scanner::IsMatches(char c)
{
	return c == m_Source[m_Current];
}

bool Scanner::IsIdentifierChar(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '_');
}

bool Scanner::IsNotEnd()
{
	return m_Current <= m_Source.size();
}