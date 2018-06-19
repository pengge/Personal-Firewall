#include "stdafx.h"
#include "FilterRules.h"
#include <ShlObj.h>

std::wstring GetLocalAppDataPath()
{
	wchar_t m_lpszDefaultDir[MAX_PATH];
	wchar_t szDocument[MAX_PATH] = { 0 };
	memset(m_lpszDefaultDir, 0, _MAX_PATH);

	LPITEMIDLIST pidl = NULL;
	SHGetSpecialFolderLocation(NULL, CSIDL_LOCAL_APPDATA, &pidl);
	if (pidl && SHGetPathFromIDList(pidl, szDocument))
	{
		GetShortPathName(szDocument, m_lpszDefaultDir, _MAX_PATH);
	}

	std::wstring wsR = m_lpszDefaultDir;

	return wsR;
}

std::wstring GetLocalAppDataPath(std::wstring appName)
{
	std::wstring path = GetLocalAppDataPath();
	path.append(L"\\");
	path.append(appName);

	if (_waccess(path.c_str(), 0) == -1)
	{
		_wmkdir(path.c_str());
	}

	return path;
}

FilterRules::FilterRules()
{
}


FilterRules::~FilterRules()
{
}

void FilterRules::ReadFromFile()
{
	OutputDebugString(_T("Read from file."));
	ifstream ifs(GetLocalAppDataPath().append(L"\\PersonalFirewall\\v1_1\\Filter.Rules"));
	FilterRule temp;
	while (ifs >> temp.IP >> temp.PortTargetStart >> temp.PortTargetEnd >> temp.PortSelfStart >> temp.PortSelfEnd >> temp.Protocol >> temp.Direction) {
		_rules.push_back(temp);
	}
	ifs.close();
}

bool FilterRules::FitFilterRules(char * ip, int portTarget, int portSelf, const char* protocol, const char * direction)
{
	for (auto fr : _rules) {
		OutputDebugStringA(fr.IP);
		char tmp[8];
		sprintf(tmp, "%d", fr.PortTargetStart);
		OutputDebugStringA(tmp);
		sprintf(tmp, "%d", fr.PortTargetEnd);
		OutputDebugStringA(tmp);
		sprintf(tmp, "%d", fr.PortSelfStart);
		OutputDebugStringA(tmp);
		sprintf(tmp, "%d", fr.PortSelfEnd);
		OutputDebugStringA(tmp);

		OutputDebugStringA(fr.Protocol);
		OutputDebugStringA(fr.Direction);

		if (strcmp(ip, fr.IP) != 0) {
			continue;
		}
		if (portTarget < fr.PortTargetStart || portTarget > fr.PortTargetEnd) {
			continue;
		}
		if (portSelf < fr.PortSelfStart || portSelf > fr.PortSelfEnd) {
			continue;
		}
		if (strcmp(fr.Protocol, "ALL") != 0 && strcmp(protocol, fr.Protocol) != 0) {
			continue;
		}
		if (strcmp(fr.Direction, "ALL") != 0 && strcmp(direction, fr.Direction) != 0) {
			continue;
		}
		return true;
	}
	return false;
}
