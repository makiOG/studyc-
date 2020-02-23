#include <iostream>
#include<unordered_map>
#include<string>

int main()
{
	//const int brock = 0;
	//const int player = 1;
	//const int circle = 2;
	//const int dot = 3;

	enum num
	{
		brock = 0,
		player = 1,
		circle = 2,
		dot = 3,
	};

	const char* _brockLetter = "#";
	const char* _playerLetter = "p";
	const char* _circleLetter = "o";
	const char* _dotLetter = ".";

	const std::unordered_map<int, const char*> _letterConverter{
		{brock,_brockLetter},
		{player,_playerLetter},
		{circle,_circleLetter},
		{dot,_dotLetter},
	};

	

	int stage[5][8] = { 
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,3,3,0,1,0,0 },
	{ 0,0,2,2,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 }
	};

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << _letterConverter.at(stage[i][j]);
		}
	}

	if (stage[1][1])
	{
		int i = 1;
	}

	auto a = "########";
	auto b = "# .. p #";
	auto c = "# oo   #";
	auto d = "#      #";
 	auto e = "########";
	//std::cout << a << std::endl << b << std::endl << c << std::endl << d << std::endl << e << std::endl;

	char aa;
	std::cin >> aa;
	return 0;

}