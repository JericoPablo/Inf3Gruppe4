#pragma once
#ifndef PARSER_HEADER
#define PARSER_HEADER

#include <assert.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;


class Parser
{
public:
	Parser();
	~Parser();

	bool parse(string input);
	bool parseEquation(string equation);
	bool parseExpression(string input);
	bool parseTerm(string input);
	bool parseFactor(string input);
	bool parseConstant(string input);
	bool isDigit(char input);
	bool isDigitWithoutZero(char input);
	
	int calc(string input);
	int calcBracket(string input);
	

};
#endif
