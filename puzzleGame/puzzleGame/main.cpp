#include <iostream>
#include <fstream>
#include <algorithm>
enum Object {
	OBJ_SPACE,
	OBJ_WALL,
	OBJ_BLOCK,
	OBJ_MAN,

	OBJ_UNKNOWN,
};

//関数プロトタイプ
void readFile(char** buffer, int* size, const char* filename);

//二次元配列クラス
//テンプレートになじみはあるだろうか？なければ基礎だけでも勉強しておこう。
//このクラス宣言の中ではTというクラスがあるかのように扱われ、
//これを使う時にはTのところにintとかboolとか入れて使う。
template< class T > class Array2D {
public:
	Array2D() : mArray(0) {}
	~Array2D() {
		delete[] mArray;
		mArray = 0;  //ポインタに0を入れるのはクセにしよう。
	}
	void setSize(int size0, int size1) {
		mSize0 = size0;
		mSize1 = size1;
		mArray = new T[size0 * size1];
	}
	T& operator()(int index0, int index1) {
		return mArray[index1 * mSize0 + index0];
	}
	const T& operator()(int index0, int index1) const {
		return mArray[index1 * mSize0 + index0];
	}
private:
	T* mArray;
	int mSize0;
	int mSize1;
};

//状態クラス
class State {
public:
	State(const char* stageData, int size);
	void update(char input);
	void draw() const;
	bool hasCleared() const;
private:
	enum Object {
		OBJ_SPACE,
		OBJ_WALL,
		OBJ_BLOCK,
		OBJ_MAN,

		OBJ_UNKNOWN,
	};
	void setSize(const char* stageData, int size);

	int mWidth;
	int mHeight;
	Array2D< Object > mObjects;
	Array2D< bool > mGoalFlags;
};

//グローバル変数
State* gState = 0;

void readFile(char** buffer, int* size, const char* filename) {
	std::ifstream in(filename);
	if (!in) {
		*buffer = 0;
		*size = 0;
	}
	else {
		in.seekg(0, std::ifstream::end);
		*size = static_cast<int>(in.tellg());
		in.seekg(0, std::ifstream::beg);
		*buffer = new char[*size];
		in.read(*buffer, *size);
	}

	
}

int main()
{
	//最初のフレームは初期化。最初の状態を描画して終わり。
	if (!gState) {
		const char* filename = "stageData.txt";
		char* stageData;
		int fileSize;
		readFile(&stageData, &fileSize, filename);
		if (!stageData) {
			std::cout << "stage file could not be read." << std::endl;
			return;
		}
		gState = new State(stageData, fileSize);
		//後始末
		delete[] stageData;
		stageData = 0;
		//初回描画
		gState->draw();
		return; //そのまま終わる
	}
	bool cleared = false;
	//メインループ
	//クリアチェック
	if (gState->hasCleared()) {
		cleared = true;
	}
	//入力取得
	std::cout << "a:left s:right w:up z:down. command?" << std::endl; //操作説明
	char input;
	std::cin >> input;
	//更新
	gState->update(input);
	//描画
	gState->draw();

	if (cleared) {
		//祝いのメッセージ
		std::cout << "Congratulation! you win." << std::endl;
		delete gState;
		gState = 0;
	}
}

State::State(const char * stageData, int size)
{
}

void State::update(char input)
{
}

void State::draw() const
{
}

bool State::hasCleared() const
{
	return false;
}

void State::setSize(const char * stageData, int size)
{
}
