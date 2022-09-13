#include <iostream>
using namespace std;

class MyString {
private:
	char* str;
	int lenght;

public:
	MyString();
	 
	MyString(int answer);     

	MyString(const char* ch);

	~MyString();

	void MyStrcpy(MyString& obj);

	bool MyStrStr(char* str);

	int  MyChr(char c);

	int MyStrLen(const char* str);

	void MyStrCat(MyString& b);

	void MyDelChr(char c);

	int MyStrCmp(MyString& b);

	int GetString() const;

	char* GetrString() const;

	void Enter();
	void Print() const;
};

MyString::MyString() {
	str = new char[80];
	str = nullptr;
	lenght = 0;
}

MyString::MyString(int answer) {
	this->lenght = answer;
	str = new char[lenght + 1];
	//cout << "Answer: " << answer << endl;
}

MyString::MyString(const char* ch) {
	str = new char[strlen(ch) + 1];
	strcpy_s(str, strlen(ch) + 1, ch);

	lenght = 0;
}

void MyString::Enter() {
	
}

void MyString::Print() const {
	cout << str << endl;
}

MyString::~MyString() {
	delete[]str;
}

void MyString::MyStrcpy(MyString& obj) {
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
}

bool MyString::MyStrStr(char* str) {
	bool ans = 0;
	if (MyStrLen(str) > lenght) {
		return ans;
	}

	cout << "Enter part of string: ";
	cin.getline(str, 100);
	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);

	for (int i = 0; i < lenght; i++) {
		ans = 1;
		for (int j = 0; j < MyStrLen(str); j++) {
			if (this->str[j + i] != str[j])
				ans = 0;
		}
		break;
	}
}

int MyString::MyChr(char c) {
	for (int i = 0; i < lenght; i++) {
		if (str[i] == c) {
			cout << "Index: " << i << endl;
		}
	}
	return 0;
}

int MyString::MyStrLen(const char* str) {
	lenght = 0;
	while (str[lenght] != '\0') {
		lenght++;
	}
	return lenght;
}

void MyString::MyStrCat(MyString& b) {
	char* ob = new char[lenght + b.lenght + 1];
	for (int i = 0; i < lenght; i++) {
		ob[i] = str[i];
	}
	for (int i = 0; i < b.lenght; i++) {
		ob[i + lenght] = b.str[i];
	}
	lenght += b.lenght;
	ob[lenght] = '\0';
	delete[] str;
	str = ob;
}

void MyString::MyDelChr(char c) {
	bool check = 0;
	for (int i = 0; i < lenght; i++)
	{
		if (str[i] == c)
		{
			check = 1;
			for (int j = i; j < lenght - 1; j++)
				str[j] = str[j + 1];
			str[lenght] = '\0';
			i--;
			lenght--;
		}
	}
	if (check)
	{
		char* temp = new char[lenght + 1];
		for (int i = 0; i < lenght; i++)
			temp[i] = str[i];
		temp[lenght] = '\0';
		delete[] str;
		str = temp;
	}
}

int MyString::MyStrCmp(MyString& b) {
	char* ob = new char[lenght + b.lenght + 1];
	for (int i = 0; i < lenght; i++)
	{
		ob[i] = str[i];
	}
	for (int i = 0; i < b.lenght; i++)
	{
		ob[i + lenght] = b.str[i];
	}
	lenght += b.lenght;
	ob[lenght] = '\0';
	delete[] str;
	str = ob;

	return 0;
}

int MyString::GetString() const {
	return lenght;
}

char* MyString::GetrString() const {
	return str;
}


int main() {

	MyString mstr2("Hello!");
	mstr2.Print();

	cout << endl;

	MyString mstr3(7);
	cout << mstr3.GetString() << endl;

	cout << endl;

	MyString mstr4("Good Bye!");
	cout << mstr4.GetrString() << endl;

}

