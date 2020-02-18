#include <iostream>
using namespace std;

int main()
{
	const int brock = 0;
	const int player = 1;
	const int maru = 2;
	const int ten = 3;

	int stage[5][8] = { 
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,3,3,0,1,0,0 },
	{ 0,0,2,2,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 }
	};

	if (stage[1][1])
	{
		int i = 1;
	}

	auto a = "########";
	auto b = "# .. p #";
	auto c = "# oo   #";
	auto d = "#      #";
 	auto e = "########";
	cout << a << endl << b << endl << c << endl << d << endl << e << endl;

	char aa;
	cin >> aa;
	return 0;

}