#include "Token.h"

std::string Token::TokenTypeToString(TokenType type)
{
	switch (type)
	{
		case TokenType::Unknown:		return "Unknown";
		case TokenType::And:			return "And";
		case TokenType::Or:				return "Or";
		case TokenType::Not:			return "Not";
		case TokenType::Greater:		return "Greater";
		case TokenType::Greater_Equal:	return "Greater_Equal";
		case TokenType::Equal:			return "Equal";
		case TokenType::Equal_Equal:	return "Equal_Equal";
		case TokenType::Less:			return "Less";
		case TokenType::Less_Equal:		return "Less_Equal";
		case TokenType::Not_Equal:		return "Not_Equal";
		case TokenType::Dot:			return "Dot";
		case TokenType::Comma:			return "Comma";
		case TokenType::Colon:			return "Colon";
		case TokenType::Semicolon:		return "Semicolon";
		case TokenType::Slash:			return "Slash";
		case TokenType::Star:			return "Star";
		case TokenType::Plus:			return "Plus";
		case TokenType::Minus:			return "Minus";
		case TokenType::Left_Paren:		return "Left_Paren";
		case TokenType::Right_Paren:	return "Right_Paren";
		case TokenType::Left_Brace:		return "Left_Brace";
		case TokenType::Right_Brace:	return "Right_Brace";
		case TokenType::Class:			return "Class";
		case TokenType::Func:			return "Func";
		case TokenType::If:				return "If";
		case TokenType::Else:			return "Else";
		case TokenType::While:			return "While";
		case TokenType::For:			return "For";
		case TokenType::Nil:			return "Nil";
		case TokenType::Return:			return "Return";
		case TokenType::Print:			return "Print";
		case TokenType::This:			return "This";
		case TokenType::True:			return "True";
		case TokenType::False:			return "False";
		case TokenType::String:			return "String";
		case TokenType::Number:			return "Number";
		case TokenType::Identifier:		return "Identifier";
		case TokenType::Eof:			return "Eof";
	}
}