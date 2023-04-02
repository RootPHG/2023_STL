//-----------------------------------------------------------------------
// 2023 1학기 STL 3월 21일 	화23		월23화56				(3주 2)
//-----------------------------------------------------------------------
// 파일 읽고 쓰기 예제
//-----------------------------------------------------------------------
// 코딩환경 - VS RELEASE/X64, C++표준 - LASTEST, SDL/아니요
//-----------------------------------------------------------------------
#INCLUDE <IOSTREAM>

#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>

#INCLUDE "SAVE.H"

// [문제] "소스.CPP"를 읽어 소문자를 대문자로 변환하여
// "소스대문자.CPP"에 저장하라

//--------
INT MAIN()
//--------
{
	STD::IFSTREAM IN{ "소스.CPP" };

	STD::OFSTREAM OUT{ "소스대문자.CPP" };

	STD::TRANSFORM(STD::ISTREAMBUF_ITERATOR<CHAR>{IN}, {},
		STD::OSTREAMBUF_ITERATOR<CHAR>{OUT},
		[](CHAR C) {
			RETURN C = TOUPPER(C);
		} );

	SAVE("소스.CPP");
}
