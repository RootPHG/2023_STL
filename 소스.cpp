//-----------------------------------------------------------------------
// 2023 1�б� STL 3�� 28�� 	ȭ56		��23ȭ56				(4�� 2)
//-----------------------------------------------------------------------
// C++ Ŭ���� ���� - String Ŭ������ �����
// ������ String Ŭ������ STL �����̳ʷ� ������Ų��
//-----------------------------------------------------------------------
// �ڵ�ȯ�� - VS Release/x64, C++ǥ�� - lastest, SDL/�ƴϿ�
//-----------------------------------------------------------------------
#include <iostream>

#include <array>
#include <algorithm>
#include <string>

#include "save.h"

using namespace std;

// [����] String�� �ڵ��϶�
// ��� special �Լ��� ���� �޽����� �߰��϶�
// ������ ��ü�� ������ȣ�� �ο��϶�.

bool ����;

class String {
	size_t len{};
	char* p{};			// unique_ptr<char> p �� �ٲ㼭 �ڵ��غ��� (���̵�)
	size_t id = ++sid;

	static size_t sid;

public:
	String() {
		print("����Ʈ ����");
	};

	String(const char* s) : len{ strlen(s) } {
		p = new char[len];
		memcpy(p, s, len);		// DMA
		print("����(char*)");
	}

	~String() {
		delete[] p;
		print("�Ҹ���");
	}

	// ��������� + �����Ҵ翬����  ��Ʈ
	String(const String& other) : len{ other.len } {
		p = new char[len];
		memcpy(p, other.p, len);
		print("�������");
	}

	String& operator=(const String& other) {
		if (this == &other)
			return *this;
		delete[] p;

		len = other.len;
		p = new char[len];
		memcpy(p, other.p, len);
		
		print("�����Ҵ翬����");
		return *this;
	}



	String operator+(const String& rhs) const {
		String temp;
		temp.len = len + rhs.len;
		temp.p = new char[temp.len];
		memcpy(temp.p, p, len);
		memcpy(temp.p + len, rhs.p, rhs.len);
		return temp;
	}

	friend ostream& operator<<(ostream& os, const String& s) {
		for (int i = 0; i < s.len; ++i)
			os << s.p[i];
		return os;
	}

	string getString() const {
		return string (p, len);
	}


	void print(const char* msg) const {
		if (����) {
			cout << "[" << id << "] - " << msg << ", ����: " << len
				<< ", �ּ�: " << (void*)p << endl;
		}
	}
};

size_t String::sid{ 0 };

//--------
int main()
//--------
{
	array<String, 3> news{
	"���", "�ɰ�", "����"
	};

	���� = true;

	// [����] news�� �������� �����϶� - �����͸� �׸��׷����� Ȯ���ϱ�
	sort(news.begin(), news.end(), [](String& a, String& b) {
		return a.getString() < b.getString();
		} );

	���� = false;
	for (String& s : news)
		cout << s << endl;
	
	save("�ҽ�.cpp");
}