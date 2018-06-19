#pragma once

#include <stdio.h>
#include <tchar.h>
#include <ws2spi.h>
#include <sporder.h>
#include <fstream>
#include <Windows.h>
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"sporder.lib")

using std::ifstream;

#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)

DLLEXPORT void Install();

DLLEXPORT void Remove();