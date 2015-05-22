// Blatt2.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "stdafx.h"
#include "iostream"
#include <assert.h>
#include "Parser.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int zahl = -1;
	string input = "1=1";
	cout << input << endl;
	//cout << pns[0] << endl;
	//assert(zahl > 0);
	cout << "hallo" << endl;

	//cout << input.substr(2, 1).length() << endl;


	Parser * parser = new Parser();
	cout << "ist der input parsebar?" << endl;
	cout << parser->parse(input) << endl;



	/*string myString = "23";
	int x = atoi(myString.c_str());
	cout << x << endl;*/

	cout << parser->calc("3*100+12") << endl;

	
	cin >> zahl;
	return 0;
}

