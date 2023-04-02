//-----------------------------------------------------------------------------
// save.h 한 학기 강의 저장하는 함수
//-----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include "save.h"

void save(const std::string& fileName)
{
	// 읽기 모드로 fileName을 연다
	std::ifstream in{ fileName };			// RAII개념 

	// 저장할 파일을 덧붙여 쓰기 모드로 연다
	std::ofstream out{ "2023 1학기 STL 월23화56 강의저장.txt", std::ios::app };

	out << '\n' << '\n' << '\n';

	// 저장한 시간을 파일에 기록하자								// epoch - 1970 1월 1일 시작
	auto now = std::chrono::system_clock::now();					// 현재 time_point를 얻는다
	auto utc = std::chrono::system_clock::to_time_t(now);			// UTC 시간으로 변경
	auto lt = std::localtime(&utc);									// 지역시간으로 변경

	auto old = out.imbue(std::locale("ko_KR"));						// 대한민국으로 지역변경 
	out << "=================================================" << '\n';
	out << fileName << std::put_time(lt, "%x %A %X") << '\n';					// 한국시간으로 파일에 출력
	out << "=================================================" << '\n';
	out.imbue(old);													// 원래 지역으로 변경

	// fileName을 읽어 저장할 파일에 쓴다
	// STL 자료구조와 알고리즘을 이용하여 작성
	std::vector<char> v{ std::istreambuf_iterator<char>{ in }, {} };			// istream_iterator - 공백 무시 // {} - 파일의 끝까지
	std::copy(v.begin(), v.end(), std::ostream_iterator<char>{ out });	// std::cout - 콘솔 입력, out - 메모장 입력
}