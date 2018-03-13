// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif						

#include <stdio.h>
#include <tchar.h>
#include<fstream>
#include<iostream>
#include <time.h>
using namespace std;

struct SInfo {
	char first[11];
	char second[11];
	char third[11];
	char fourth[11];
	char fifth[11];
};



// TODO: reference additional headers your program requires here
