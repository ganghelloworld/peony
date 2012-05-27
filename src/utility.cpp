#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int require(bool b, string msg)
{
	if(!b)
	{
		cout << msg << endl;
		exit(1);
	}
	return 1;
}

string int2string(int a)
{
	stringstream ss;
	ss << a;
	return ss.str();
}
