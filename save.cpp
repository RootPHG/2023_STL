//-----------------------------------------------------------------------------
// save.h �� �б� ���� �����ϴ� �Լ�
//-----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include "save.h"

void save(const std::string& fileName)
{
	// �б� ���� fileName�� ����
	std::ifstream in{ fileName };			// RAII���� 

	// ������ ������ ���ٿ� ���� ���� ����
	std::ofstream out{ "2023 1�б� STL ��23ȭ56 ��������.txt", std::ios::app };

	out << '\n' << '\n' << '\n';

	// ������ �ð��� ���Ͽ� �������								// epoch - 1970 1�� 1�� ����
	auto now = std::chrono::system_clock::now();					// ���� time_point�� ��´�
	auto utc = std::chrono::system_clock::to_time_t(now);			// UTC �ð����� ����
	auto lt = std::localtime(&utc);									// �����ð����� ����

	auto old = out.imbue(std::locale("ko_KR"));						// ���ѹα����� �������� 
	out << "=================================================" << '\n';
	out << fileName << std::put_time(lt, "%x %A %X") << '\n';					// �ѱ��ð����� ���Ͽ� ���
	out << "=================================================" << '\n';
	out.imbue(old);													// ���� �������� ����

	// fileName�� �о� ������ ���Ͽ� ����
	// STL �ڷᱸ���� �˰����� �̿��Ͽ� �ۼ�
	std::vector<char> v{ std::istreambuf_iterator<char>{ in }, {} };			// istream_iterator - ���� ���� // {} - ������ ������
	std::copy(v.begin(), v.end(), std::ostream_iterator<char>{ out });	// std::cout - �ܼ� �Է�, out - �޸��� �Է�
}