// Referenzen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void tausche(int, int);
void tauscheRef(int&, int&);
void ausgabe(string);
void ausgabeRef(string&);

int stringToInteger(bool&, const string&);

string& toString(const int);

int& absValue(int);

int main()
{
	locale::global(locale("German_germany"));

	int a = 5;
	int& r = a;

	cout << "&a: " << &a << ", &r: " << &r << endl;

	cout << "a: " << a << ", r: " << r << endl;

	r = -r;

	cout << "a: " << a << ", r: " << r << endl;

	int b = 7;

	cout << "a: " << a << ", b: " << b << endl;

	tausche(a, b);

	cout << "a: " << a << ", b: " << b << endl;

	tauscheRef(a, b);

	cout << "a: " << a << ", b: " << b << endl;

	string s = "alfatraining Bildungszentrum";

	cout << "s: " << s << ", &s: " << &s << endl;

	ausgabe(s);

	cout << "s: " << s << ", &s: " << &s << endl;

	ausgabeRef(s);

	cout << "s: " << s << ", &s: " << &s << endl;

	s = "1234";

	bool OK;

	a = stringToInteger(OK, s);

	if (OK)
		cout << "OK, s: '" << s << "', a: " << a << endl;
	else
		cout << "Fehler" << endl;

	s = "1234alfa";

	a = stringToInteger(OK, s);

	if (OK)
		cout << "OK, s: '" << s << "', a: " << a << endl;
	else
		cout << "Fehler" << endl;

	s = "alfa1234";

	a = stringToInteger(OK, s);

	if (OK)
		cout << "OK, s: '" << s << "', a: " << a << endl;
	else
		cout << "Fehler" << endl;

	s = "12 34";

	a = stringToInteger(OK, s);

	if (OK)
		cout << "OK, s: '" << s << "', a: " << a << endl;
	else
		cout << "Fehler" << endl;

	/*string str1 = toString(42);

	cout << "str1: " << str1 << endl;*/

	return EXIT_SUCCESS;
}

void tausche(int i, int j)
{
	int temp = i;
	i = j;
	j = temp;
}

void tauscheRef(int& i, int& j)
{
	int temp = i;
	i = j;
	j = temp;
}

void ausgabe(string s)
{
	cout << "s: " << s << ", &s: " << &s << endl;

	s.append(", Karlsruhe");
}

void ausgabeRef(string& s)
{
	cout << "s: " << s << ", &s: " << &s << endl;

	s.append(", Karlsruhe");
}

int stringToInteger(bool& OK, const string& s)
{
	int retValue;

	OK = true;

	size_t idx;

	try
	{
		retValue = stoi(s, &idx);

		if (idx != s.length())
		{
			retValue = 0;
			OK = false;
		}
	}
	catch (exception ex)
	{
		retValue = 0;
		OK = false;
	}

	return retValue;
}

string& toString(const int value)
{
	string str = to_string(value);

	return str;
}

//int& absValue(int a)
//{
//	return a > 0 ? a : -a;
//}
