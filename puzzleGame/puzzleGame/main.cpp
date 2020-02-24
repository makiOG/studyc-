#include <iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include <algorithm>

enum num
{
	brock = 0,
	//player = 1,
	//target = 2,
	point = 3,
	space = 4,
};

struct Vector2
{
	int x;
	int y;

	

	/*
	int clamp(int min,int max,int target)
	{

	}
	*/
};



const char* _brockLetter = "#";
const char* _playerLetter = "p";
const char* _targetLetter = "o";
const char* _pointLetter = ".";
const char* _spaceLetter = " ";

const int _stageSizeX = 8;
const int _stageSizeY = 5;

Vector2 _playerPos{ 5,1 };
std::vector<Vector2> _targetPosList{
	{2,2},
{3,2}
};

const std::unordered_map<int, const char*> _letterConverter{
		{brock,_brockLetter},
		//{target,_targetLetter},
		{point,_pointLetter},
	{space,_spaceLetter},
};

int stage[_stageSizeY][_stageSizeX] = {
	{ 0,0,0,0,0,0,0,0 },
	{ 0,4,3,3,4,4,4,0 },
	{ 0,4,4,4,4,4,4,0 },
	{ 0,4,4,4,4,4,4,0 },
	{ 0,0,0,0,0,0,0,0 }
};

void Init()
{
}

void endl()
{
	std::cout << std::endl;
}

void Update()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			//プレイヤーの座標と一致したら
			if (_playerPos.x == j && _playerPos.y == i)
			{
				std::cout << _playerLetter;
				continue;
			}
			bool breakFlag = false;
			for (const auto& at : _targetPosList) {
				if (at.x == j && at.y == i)
				{
					std::cout << _targetLetter;
					breakFlag = true;
					break;
				}
			}
			if (breakFlag == true)
			{
				continue;
			}
			std::cout << _letterConverter.at(stage[i][j]);
		}
		std::cout << std::endl;
	}

	

	//char playerMove;

	std::string playerMove;
	std::cin >> playerMove;

	
	//範囲外参照対策
	//サボってるコード brockの数字(0)を参照して壁に入らない判定を入れてるわけじゃなくて、
	//壁の分を含めた領域の外に出ないようにしている。
	//壁の定義が変わればアウトなので、コード的にはよくないから適当コード

	if (!strcmp(playerMove.c_str(), "w") && _playerPos.y - 2 >= 0)
	{
		for (auto& at : _targetPosList) {
			if (_playerPos.x == at.x && _playerPos.y - 1 == at.y && stage[_playerPos.y - 2][_playerPos.x] == space)
			{
				at.y--;
			}
			else if (_playerPos.x == at.x && _playerPos.y - 1 == at.y && stage[_playerPos.y - 2][_playerPos.x] == point)
			{
				at.y--;
			}
		}

		

		//二次元配列上のfor文では左上からカウントを始めているため、y座標の正と負の方向が逆になっている。
		_playerPos.y--;
	}
	else if (!strcmp(playerMove.c_str(), "a") && _playerPos.x - 2 >= 0)
	{
		for (auto& at : _targetPosList) {
			if (_playerPos.x - 1 == at.x && _playerPos.y == at.y && stage[_playerPos.y][_playerPos.x - 2] == space)
			{
				at.x--;
			}
			else if (_playerPos.x - 1 == at.x && _playerPos.y == at.y && stage[_playerPos.y][_playerPos.x - 2] == space)
			{
				at.x--;
			}
		}
		_playerPos.x--;
	}
	else if (!strcmp(playerMove.c_str(), "s") && _playerPos.y + 2 < _stageSizeY)
	{
		for (auto& at : _targetPosList) {
			if (_playerPos.x == at.x && _playerPos.y + 1 == at.y && stage[_playerPos.y + 2][_playerPos.x] == space)
			{
				at.y++;
			}
			else if (_playerPos.x == at.x && _playerPos.y + 1 == at.y && stage[_playerPos.y + 2][_playerPos.x] == point)
			{
				at.y++;
			}
		}
		//二次元配列上のfor文では左上からカウントを始めているため、y座標の正と負の方向が逆になっている。
		_playerPos.y++;
	}
	else if (!strcmp(playerMove.c_str(), "d") && _playerPos.x + 2 < _stageSizeX)
	{
		for (auto& at : _targetPosList) {
			if (_playerPos.x + 1 == at.x && _playerPos.y == at.y && stage[_playerPos.y][_playerPos.x + 2] == space)
			{
				at.x++;
			}
			else if (_playerPos.x + 1 == at.x && _playerPos.y == at.y && stage[_playerPos.y][_playerPos.x + 2] == space)
			{
				at.x++;
			}
		}
		_playerPos.x++;
	}


	endl();
	
}

int main()
{
	//const int brock = 0;
	//const int player = 1;
	//const int circle = 2;
	//const int dot = 3;

	Init();

	while (true)
	{
		Update();
	}
	return 0;

}