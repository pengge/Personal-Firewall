#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include <WS2spi.h>
#include <WS2tcpip.h>
#include <tchar.h>
#include <vector>
#include <fstream>
#include <string>
#include <string>
#include <exception>

using std::vector;
using std::ifstream;
using std::exception;

struct FilterRule
{
	char IP[40];
	int PortTargetStart;
	int PortTargetEnd;
	int PortSelfStart;
	int PortSelfEnd;
	char Protocol[8];
	char Direction[8];
};

class FilterRules
{
public:
	FilterRules();
	~FilterRules();

	void ReadFromFile();

	bool FitFilterRules(char * ip, int portTarget, int portSelf, const char* protocol, const char * direction);
private:
	vector<FilterRule> _rules;
};