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

//�֐��v���g�^�C�v
void readFile(char** buffer, int* size, const char* filename);

//�񎟌��z��N���X
//�e���v���[�g�ɂȂ��݂͂��邾�낤���H�Ȃ���Ί�b�����ł��׋����Ă������B
//���̃N���X�錾�̒��ł�T�Ƃ����N���X�����邩�̂悤�Ɉ����A
//������g�����ɂ�T�̂Ƃ����int�Ƃ�bool�Ƃ�����Ďg���B
template< class T > class Array2D {
public:
	Array2D() : mArray(0) {}
	~Array2D() {
		delete[] mArray;
		mArray = 0;  //�|�C���^��0������̂̓N�Z�ɂ��悤�B
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

//��ԃN���X
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

//�O���[�o���ϐ�
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
	//�ŏ��̃t���[���͏������B�ŏ��̏�Ԃ�`�悵�ďI���B
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
		//��n��
		delete[] stageData;
		stageData = 0;
		//����`��
		gState->draw();
		return; //���̂܂܏I���
	}
	bool cleared = false;
	//���C�����[�v
	//�N���A�`�F�b�N
	if (gState->hasCleared()) {
		cleared = true;
	}
	//���͎擾
	std::cout << "a:left s:right w:up z:down. command?" << std::endl; //�������
	char input;
	std::cin >> input;
	//�X�V
	gState->update(input);
	//�`��
	gState->draw();

	if (cleared) {
		//�j���̃��b�Z�[�W
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
