//-----------------------------------------------------------------------
// 2023 1학기 STL 3월 28일 	화56		월23화56				(4주 2)
//-----------------------------------------------------------------------
// C++ 클래스 복습 - String 클래스를 만든다
// 앞으로 String 클래스를 STL 컨테이너로 발전시킨다
//-----------------------------------------------------------------------
// 코딩환경 - VS Release/x64, C++표준 - lastest, SDL/아니요
//-----------------------------------------------------------------------
#include <iostream>

#include <array>
#include <algorithm>
#include <string>

#include "save.h"

using namespace std;

// [문제] String을 코딩하라
// 모든 special 함수에 관찰 메시지를 추가하라
// 생성시 객체에 고유번호를 부여하라.

bool 관찰;

class String {
	size_t len{};
	char* p{};			// unique_ptr<char> p 로 바꿔서 코딩해볼것 (고난이도)
	size_t id = ++sid;

	static size_t sid;

public:
	String() {
		print("디폴트 생성");
	};

	String(const char* s) : len{ strlen(s) } {
		p = new char[len];
		memcpy(p, s, len);		// DMA
		print("생성(char*)");
	}

	~String() {
		delete[] p;
		print("소멸자");
	}

	// 복사생성자 + 복사할당연산자  세트
	String(const String& other) : len{ other.len } {
		p = new char[len];
		memcpy(p, other.p, len);
		print("복사생성");
	}

	String& operator=(const String& other) {
		if (this == &other)
			return *this;
		delete[] p;

		len = other.len;
		p = new char[len];
		memcpy(p, other.p, len);
		
		print("복사할당연산자");
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
		if (관찰) {
			cout << "[" << id << "] - " << msg << ", 개수: " << len
				<< ", 주소: " << (void*)p << endl;
		}
	}
};

size_t String::sid{ 0 };

//--------
int main()
//--------
{
	array<String, 3> news{
	"목숨", "걸고", "만든"
	};

	관찰 = true;

	// [문제] news를 오름차순 정렬하라 - 데이터를 그림그려보며 확인하기
	sort(news.begin(), news.end(), [](String& a, String& b) {
		return a.getString() < b.getString();
		} );

	관찰 = false;
	for (String& s : news)
		cout << s << endl;
	
	save("소스.cpp");
}