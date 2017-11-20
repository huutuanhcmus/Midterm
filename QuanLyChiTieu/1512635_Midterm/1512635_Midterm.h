#pragma once

#include "resource.h"

#include <commctrl.h>
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma comment(lib, "ComCtl32.lib")

bool isTrueDay(WCHAR* ngay, WCHAR* thang, WCHAR* nam);
bool OutputData(HWND &hWnd, WCHAR* ngay, WCHAR* thang, WCHAR* nam, int &pos);
int lengthDay(int thang, int nam);
bool isHave(WCHAR *ngay, WCHAR *thang, WCHAR *nam);