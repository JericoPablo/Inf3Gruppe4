#include "stdafx.h"
#include "Parser.h"
#include <string>
#include <assert.h>




Parser::Parser()
{
}


Parser::~Parser()
{
}

bool Parser::parse(string input){
	//cout << "0" << endl;

	return parseEquation(input);
}

//parses Equation defined in EBNF
bool Parser::parseEquation(string equation){
	bool result;
	bool moreThanTwoEquals = false;
	bool equalsCounter = 0;
	if (equation.length() == 0){
		result = false;
	}
	else{
		bool equals = false;
		for (int counter = 0; counter < equation.length(); counter++){
			if (equation[counter] == '='){
				equalsCounter++;
			}
		}
		if (equalsCounter > 1){
			moreThanTwoEquals = true;
			result = false;
		}
		if (moreThanTwoEquals == false){
			for (int counter = 0; counter < equation.length(); counter++){
				if (equation[counter] == '='){
					equals = true;
					result = parseExpression(equation.substr(0, counter));
					if (result == true){
						result = parseExpression(equation.substr(counter + 1, equation.length() - counter - 1));
					}
					counter = equation.length();
				}
				if (equals == false & (counter == equation.length() - 1))
				{
					result = parseExpression(equation);
				}
			}
		}
	}
	//cout << "1" << endl;
	return result;
}

//parses Expression defined in EBNF
bool Parser::parseExpression(string input){
	bool result = true;
	bool nothingToDo = false;
	bool notIn = true;
	int charpos = 0;
	if (input.length() == 0){
		result = false;
	}
	else{
		for (int counter = 0; counter < input.length(); counter++){
			if (input[counter] == '('){
				nothingToDo = true;
				for (int counterback = input.length() - 1; counterback > counter - 1; counterback--){
					if ((notIn = true)&(counterback >= counter)){
						result = false;
					}
					if (input[counterback] == ')'){
						result = parseTerm(input.substr(counter, counterback - counter + 1));
						counter = counterback;
						notIn = false;
					}
				}
			}
			if (nothingToDo == false){
				if (input[counter] == '+' | (counter == input.length() - 1)){
					if (result != false){
						if (input[counter] == '+'){
							if (counter != input.length() - 1){
								result = parseTerm(input.substr(charpos, counter - charpos));
							}
							else{
								result = false;
							}
						}
						else{
							result = parseTerm(input.substr(charpos, counter + 1 - charpos));
						}
						charpos = counter + 1;
					}
				}
			}
			nothingToDo = false;
		}
	}

	return result;
}

//parses Term defined in EBNF
bool Parser::parseTerm(string input){
	bool result = true;
	bool nothingToDo = false;
	bool notIn = true;
	int charpos = 0;
	if (input.length() == 0){
		result = false;
	}
	else{
		for (int counter = 0; counter < input.length(); counter++){
			if (input[counter] == '('){
				nothingToDo = true;
				for (int counterback = input.length() - 1; counterback > counter - 1; counterback--){
					if ((notIn = true)&(counterback >= counter)){
						result = false;
					}
					if (input[counterback] == ')'){
						result = parseFactor(input.substr(counter, counterback - counter + 1));
						counter = counterback;
						notIn = false;
					}
				}

			}
			if (nothingToDo == false){
				if (input[counter] == '*' | (counter == input.length() - 1)){
					if (result != false){
						if (input[counter] == '*'){
							if (counter != input.length() - 1){
								result = parseFactor(input.substr(charpos, counter - charpos));
							}
							else{
								result = false;
							}
						}
						else{
							result = parseFactor(input.substr(charpos, counter + 1 - charpos));
						}
						charpos = counter + 1;
					}
				}
			}
			nothingToDo = false;
		}
	}

	return result;
}

//parses Factor defined in EBNF
bool Parser::parseFactor(string input){
	bool result;
	result = parseConstant(input);
	if ((result == false)&(input[0] == '(')&(input[input.length() - 1] == ')')){
		/*bool  noway = true;
		bool charcounter = 0;
		int end;
		for (int counter = 0; counter < input.length(); counter++){
		if (input[counter] == '('){
		charcounter++;
		}
		}*/
		result = parseExpression(input.substr(1, input.length() - 2));
	}
	return result;
}

//parses Constant defined in EBNF
bool Parser::parseConstant(string input){
	bool result;
	if (input.length() == 0){
		result = false;
	}
	else{
		bool plus = true;
		for (int counter = 0; counter < input.length(); counter++){
			if (counter == 0){
				result = isDigitWithoutZero(input[counter]);
			}
			else{
				if (result == true){
					result = isDigit(input[counter]);
				}
			}
		}
	}
	return result;
	//cout << "5" << endl;
}

//compares char -> returns true when input is 0-9
bool Parser::isDigit(char input){
	bool result = true;
	if (!((input == 48) | (isdigit(input)))){
		result = false;
	}
	return result;
	//cout << "6" << endl;
}

//compares char -> returns true when input is 1-9
bool Parser::isDigitWithoutZero(char input){
	bool result = true;
	if (!((input == 49) | (input == 50) | (input == 51) |
		(input == 52) | (input == 53) | (input == 54) |
		(input == 55) | (input == 56) | (input == 57))){
		result = false;
	}
	return result;
	//cout << "7" << endl;
}

int Parser::calc(string input){
	int result = 0;
	int charpos = 0;
	bool firstTime = true;
	string nextOperator = "";
	for (int counter = 0; counter < input.length(); counter++){
		if ((input[counter] == '+') | (input[counter] == '*') | (counter == input.length()-1)){
			if (input[counter] == '+'){
				if (firstTime){
					result = atoi(input.substr(charpos, input.length() - counter).c_str());
				}
				else{
					if (nextOperator == "+"){
						result += atoi(input.substr(charpos, input.length() - counter).c_str());
					}
					if (nextOperator == "*"){
						result *= atoi(input.substr(charpos, input.length() - counter).c_str());
					}
				}
				charpos = counter + 1;
				nextOperator = "+";
				firstTime = false;
			}
			if (input[counter] == '*'){
				if (firstTime){
					result = atoi(input.substr(charpos, input.length() - counter).c_str());
				}
				else{
					if (nextOperator == "+"){
						result += atoi(input.substr(charpos, input.length() - counter).c_str());
					}
					if (nextOperator == "*"){
						result *= atoi(input.substr(charpos, input.length() - counter).c_str());
					}
				}
				charpos = counter + 1;
				nextOperator = "*";
				firstTime = false;
			}
			if (counter == input.length() - 1){
				if (firstTime){
					result = atoi(input.substr(charpos, input.length() - counter).c_str());
				}
			}
			else{
				if (nextOperator == "+"){
					result += atoi(input.substr(charpos, input.length() - counter).c_str());
				}
				if (nextOperator == "*"){
					result *= atoi(input.substr(charpos, input.length() - counter).c_str());
				}
			}
		}
	}
	return result;
}
