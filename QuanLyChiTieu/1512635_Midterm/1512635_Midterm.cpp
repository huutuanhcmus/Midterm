// 1512635_Midterm.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "1512635_Midterm.h"
#include<cmath>
#include<Windowsx.h>
#include<string>
#include<fstream>
#include <codecvt>

#pragma comment (lib,"User32.lib")

using namespace std;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY1512635_MIDTERM, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY1512635_MIDTERM));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY1512635_MIDTERM));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY1512635_MIDTERM);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      0, 0, 1270, 730, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
HWND cmbChoice;
HWND NoiDung;
HWND SoTien;
HWND Ngay;
HWND Thang;
HWND Nam;

HWND SoTienThu;
HWND NgayB;
HWND ThangB;
HWND NamB;

HWND cmbChoice_Loai;
HWND NgayA;
HWND ThangA;
HWND NamA;

HWND hList;

HWND TongChiTieu;
HWND TongThuNhap;

double Thu, Chi;
double arrayData[6];

bool flag = false;

HWND box[6];

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
	{
		INITCOMMONCONTROLSEX icc;
		icc.dwSize = sizeof(icc);
		icc.dwICC = ICC_WIN95_CLASSES;
		InitCommonControlsEx(&icc);

		// Lấy font hệ thống
		LOGFONT lf;
		GetObject(GetStockObject(DEFAULT_GUI_FONT), sizeof(LOGFONT), &lf);
		HFONT hFont = CreateFont(lf.lfHeight, lf.lfWidth,
			lf.lfEscapement, lf.lfOrientation, lf.lfWeight,
			lf.lfItalic, lf.lfUnderline, lf.lfStrikeOut, lf.lfCharSet,
			lf.lfOutPrecision, lf.lfClipPrecision, lf.lfQuality,
			lf.lfPitchAndFamily, lf.lfFaceName);

		HFONT hFontBoldUnderLine = CreateFont(16, lf.lfWidth,
			lf.lfEscapement, lf.lfOrientation, 700,
			lf.lfItalic, TRUE, lf.lfStrikeOut, lf.lfCharSet,
			lf.lfOutPrecision, lf.lfClipPrecision, lf.lfQuality,
			lf.lfPitchAndFamily, lf.lfFaceName);

		HFONT hFontBold = CreateFont(16, lf.lfWidth,
			lf.lfEscapement, lf.lfOrientation, 700,
			lf.lfItalic, FALSE, lf.lfStrikeOut, lf.lfCharSet,
			lf.lfOutPrecision, lf.lfClipPrecision, lf.lfQuality,
			lf.lfPitchAndFamily, lf.lfFaceName);
		//Set màu
		HBRUSH brush = CreateSolidBrush(RGB(240, 240, 240));
		SetClassLongPtr(hWnd, GCLP_HBRBACKGROUND, (LONG)brush);


		//////////////////////////////////////////Input data
		//Group combobox
		cmbChoice = CreateWindow(L"combobox", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST
			, 50, 75, 125, 15, hWnd, (HMENU)ID_CMBCHOICE, hInst, NULL);
		HWND hwnd = CreateWindowEx(0, L"STATIC", L"Loại chi tiêu", WS_CHILD | WS_VISIBLE | SS_LEFT, 50, 50, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		SendMessage(cmbChoice, WM_SETFONT, WPARAM(hFontBold), TRUE);
		SendMessage(cmbChoice, CB_ADDSTRING, NULL, (LPARAM)L"Ăn uống");
		SendMessage(cmbChoice, CB_ADDSTRING, NULL, (LPARAM)L"Di chuyển");
		SendMessage(cmbChoice, CB_ADDSTRING, NULL, (LPARAM)L"Nhà cửa");
		SendMessage(cmbChoice, CB_ADDSTRING, NULL, (LPARAM)L"Xe cộ");
		SendMessage(cmbChoice, CB_ADDSTRING, NULL, (LPARAM)L"Nhu yếu phẩm");
		SendMessage(cmbChoice, CB_ADDSTRING, NULL, (LPARAM)L"Dịch vụ");

		//Group nội dung
		hwnd = CreateWindowEx(0, L"STATIC", L"Nội dung:", WS_CHILD | WS_VISIBLE | SS_LEFT, 200, 50, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		NoiDung = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | WS_BORDER, 200, 75, 200, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);

		//Group số tiền
		hwnd = CreateWindowEx(0, L"STATIC", L"Số tiền:", WS_CHILD | WS_VISIBLE | SS_LEFT, 425, 50, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		SoTien = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 425, 75, 120, 20, hWnd, NULL, hInst, NULL);
		SendMessage(SoTien, WM_SETFONT, WPARAM(hFontBold), TRUE);
		
		hwnd = CreateWindowEx(0, L"STATIC", L"Thêm dữ liệu chi tiêu trong ngày", WS_CHILD | WS_VISIBLE | SS_LEFT, 180, 17, 220, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		
		hwnd = CreateWindowEx(0, L"STATIC", L"Ngày", WS_CHILD | WS_VISIBLE | SS_LEFT, 100, 115, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		Ngay = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 150, 115, 23, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Tháng", WS_CHILD | WS_VISIBLE | SS_LEFT, 223, 115, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		Thang = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 290, 115, 23, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Năm", WS_CHILD | WS_VISIBLE | SS_LEFT, 385, 115, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		Nam = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 438, 115, 40, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);

		hwnd = CreateWindowEx(0, L"BUTTON", L"Thêm vào", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 150, 100, 35, hWnd, (HMENU)IDC_BUTTON_INPUT, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);

		/////////////////////////////////////Show data
		///////////////Tạo List view
		hList = CreateWindow(WC_LISTVIEW, L"ListView", WS_CHILD | WS_VISIBLE |
			WS_BORDER | LVS_REPORT | LVS_REPORT | LVS_SINGLESEL | LVS_ICON | WS_VSCROLL
			, 650,50, 550, 230, hWnd, (HMENU)IDC_LISTSHOWDATA, hInst, NULL);
		SendMessage(hList, WM_SETFONT, WPARAM(hFontBold), TRUE);
		LVCOLUMN col;
		col.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
		col.fmt = LVCFMT_LEFT;
		col.pszText = L"Loại chi tiêu";
		col.cx = 150;
		ListView_InsertColumn(hList, 0, &col);
		col.pszText = L"Nội dung";
		col.cx = 200;
		ListView_InsertColumn(hList, 1, &col);
		col.pszText = L"Số tiền";
		col.cx = 200;
		ListView_InsertColumn(hList, 2, &col);

		hwnd = CreateWindowEx(0, L"STATIC", L"Tổng chi tiêu", WS_CHILD | WS_VISIBLE | SS_LEFT, 950, 290, 100, 20, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		TongChiTieu = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER, 1050, 288, 150, 20, hWnd, NULL, hInst, NULL);
		SendMessage(TongChiTieu, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Tổng thu nhập", WS_CHILD | WS_VISIBLE | SS_LEFT, 650, 290, 150, 20, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		TongThuNhap = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER, 758, 288, 150, 20, hWnd, NULL, hInst, NULL);
		SendMessage(TongThuNhap, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Danh sách đã chi tiêu", WS_CHILD | WS_VISIBLE | SS_LEFT, 832, 17, 150, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);

		//Biểu đồ tròn
		hwnd = CreateWindowEx(0, L"STATIC", L"Biểu đồ", WS_CHILD | WS_VISIBLE | SS_LEFT, 880, 357, 54, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Biểu đồ thể hiện tỉ lệ chi tiêu", WS_CHILD | WS_VISIBLE | SS_LEFT, 655, 610, 200, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Chú thích:", WS_CHILD | WS_VISIBLE | SS_LEFT, 950, 390, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Ăn uống", WS_CHILD | WS_VISIBLE | SS_LEFT, 1020, 430, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		box[0] = CreateWindowEx(0, L"STATIC", L"0%", WS_CHILD | WS_VISIBLE | SS_LEFT, 1080, 430, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(box[0], WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Di chuyển", WS_CHILD | WS_VISIBLE | SS_LEFT, 1020, 465, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		box[1] = CreateWindowEx(0, L"STATIC", L"0%", WS_CHILD | WS_VISIBLE | SS_LEFT, 1093, 465, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(box[1], WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Nhà cửa", WS_CHILD | WS_VISIBLE | SS_LEFT, 1020, 500, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		box[2] = CreateWindowEx(0, L"STATIC", L"0%", WS_CHILD | WS_VISIBLE | SS_LEFT, 1083, 500, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(box[2], WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Xe cộ", WS_CHILD | WS_VISIBLE | SS_LEFT, 1020, 535, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		box[3] = CreateWindowEx(0, L"STATIC", L"0%", WS_CHILD | WS_VISIBLE | SS_LEFT, 1063, 535, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(box[3], WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Nhu yếu phẩm", WS_CHILD | WS_VISIBLE | SS_LEFT, 1020, 570, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		box[4] = CreateWindowEx(0, L"STATIC", L"0%", WS_CHILD | WS_VISIBLE | SS_LEFT, 1123, 570, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(box[4], WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Dịch vụ", WS_CHILD | WS_VISIBLE | SS_LEFT, 1020, 605, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		box[5] = CreateWindowEx(0, L"STATIC", L"0%", WS_CHILD | WS_VISIBLE | SS_LEFT, 1073, 605, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(box[5], WM_SETFONT, WPARAM(hFontBold), TRUE);

		//////////////////////////////////////////Ngày tháng năm
		hwnd = CreateWindowEx(0, L"STATIC", L"Xem danh sách chi tiêu", WS_CHILD | WS_VISIBLE | SS_LEFT, 220, 222, 160, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Ngày", WS_CHILD | WS_VISIBLE | SS_LEFT, 100, 257, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		NgayA = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 150, 255, 23, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Tháng", WS_CHILD | WS_VISIBLE | SS_LEFT, 223, 257, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		ThangA = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 290, 255, 23, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Năm", WS_CHILD | WS_VISIBLE | SS_LEFT, 385, 257, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		NamA = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 438, 255, 40, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		cmbChoice_Loai = CreateWindow(L"combobox", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST
			, 240, 298, 170, 15, hWnd, (HMENU)ID_CMBCHOICE_LOAI, hInst, NULL);
		hwnd = CreateWindowEx(0, L"STATIC", L"Xem theo", WS_CHILD | WS_VISIBLE | SS_LEFT, 170, 298, 70, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		SendMessage(cmbChoice_Loai, WM_SETFONT, WPARAM(hFontBold), TRUE);
		SendMessage(cmbChoice_Loai, CB_ADDSTRING, NULL, (LPARAM)L"Ngày - Tháng - Năm");
		SendMessage(cmbChoice_Loai, CB_ADDSTRING, NULL, (LPARAM)L"Tháng - Năm");
		SendMessage(cmbChoice_Loai, CB_ADDSTRING, NULL, (LPARAM)L"Năm");
		hwnd = CreateWindowEx(0, L"BUTTON", L"Xem", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 335, 100, 35, hWnd, (HMENU)IDC_BUTTON_INPUT_XEM, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);

		//Group Thu nhập
		hwnd = CreateWindowEx(0, L"STATIC", L"Thêm dữ liệu thu nhập trong ngày", WS_CHILD | WS_VISIBLE | SS_LEFT, 220, 412, 153, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Số tiền thu nhập", WS_CHILD | WS_VISIBLE | SS_LEFT, 50, 440, 150, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		SoTienThu = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER, 178, 440, 120, 20, hWnd, NULL, hInst, NULL);
		SendMessage(SoTienThu, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Ngày", WS_CHILD | WS_VISIBLE | SS_LEFT, 100, 480, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		NgayB = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 150, 480, 23, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Tháng", WS_CHILD | WS_VISIBLE | SS_LEFT, 223, 480, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		ThangB = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 290, 480, 23, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Năm", WS_CHILD | WS_VISIBLE | SS_LEFT, 385, 480, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		NamB = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 438, 480, 40, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"BUTTON", L"Thêm vào", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 510, 100, 35, hWnd, (HMENU)IDC_BUTTON_INPUT_THU, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		
		wfstream fileA;
		fileA.open("History.txt", ios::in);
		WCHAR ngay[3];
		WCHAR thang[3];
		WCHAR nam[5];
		fileA >> ngay >> thang >> nam;
		int index;
		fileA >> index;
		SendMessage(NgayA, WM_SETTEXT, NULL, (LPARAM)ngay);
		SendMessage(ThangA, WM_SETTEXT, NULL, (LPARAM)thang);
		SendMessage(NamA, WM_SETTEXT, NULL, (LPARAM)nam);
		SendMessage(cmbChoice_Loai, (UINT)CB_SETCURSEL, (WPARAM)index, (LPARAM)0);
		SendMessage(hWnd, WM_COMMAND, (WPARAM)IDC_BUTTON_INPUT_XEM, 0);
		flag = true;
		InvalidateRect(hWnd, NULL, TRUE);
		break;


	}
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case IDC_BUTTON_INPUT:
			{
				int length_cmbChoice = GetWindowTextLength(cmbChoice);
				int length_NoiDung = GetWindowTextLength(NoiDung);
				int length_SoTien = GetWindowTextLength(SoTien);
				int length_Ngay = GetWindowTextLength(Ngay);
				int length_Thang = GetWindowTextLength(Thang);
				int length_Nam = GetWindowTextLength(Nam);
				if (length_cmbChoice == 0 || length_NoiDung == 0 || length_SoTien == 0 ||
					length_Ngay == 0 || length_Thang == 0 || length_Nam == 0) {
					MessageBox(0, L"Vui lòng nhập đầy đủ thông tin chi tiêu!", L"Thông báo", 0);
					break;
				}
				WCHAR* ngay = new WCHAR[length_Ngay + 1];
				WCHAR* thang = new WCHAR[length_Thang + 1];
				WCHAR* nam = new WCHAR[length_Nam + 1];
				GetWindowText(Ngay, ngay, length_Ngay + 1);
				GetWindowText(Thang, thang, length_Thang + 1);
				GetWindowText(Nam, nam, length_Nam + 1);
				if (!isTrueDay(ngay, thang, nam)) {
					MessageBox(0, L"Vui lòng nhập chính xác ngày - tháng - năm!", L"Thông báo", 0);
					break;
				}
				wstring ws_nam(nam);
				wstring ws_thang(thang);
				wstring ws_ngay(ngay);
				string str_nam(ws_nam.begin(), ws_nam.end());
				string str_thang(ws_thang.begin(), ws_thang.end());
				string str_ngay(ws_ngay.begin(), ws_ngay.end());
				int ItemIndex = SendMessage(cmbChoice, (UINT)CB_GETCURSEL,(WPARAM)0, (LPARAM)0);
				WCHAR* content_NoiDung = new WCHAR[length_NoiDung + 1];
				GetWindowText(NoiDung, content_NoiDung, length_NoiDung + 1);
				wstring ws_NoiDung(content_NoiDung);
				string str_NoiDung(ws_NoiDung.begin(), ws_NoiDung.end());
				WCHAR* content_SoTien = new WCHAR[length_SoTien + 1];
				GetWindowText(SoTien, content_SoTien, length_SoTien + 1);
				wstring ws_SoTien(content_SoTien);
				string str_SoTien(ws_SoTien.begin(), ws_SoTien.end());
				wfstream file;
				string temp = "data/" + str_nam + "/" + str_thang + "/" + "CHI_" + str_ngay + ".txt";
				file.open(temp , ios::app);
				if (!file.good()) {
					string address = "data/" + str_nam + "/" + str_thang;
					string str = "mkdir \"" + address + "\"";
					system(str.c_str());
					address += "/CHI_"  + str_ngay + ".txt";
					file.open(address, ios::app);
					if (!file.good()) {
						MessageBox(0, L"Không thể thêm dữ liệu!", L"Thông báo", 0);
						break;
					}
				}
				file.imbue(std::locale(std::locale(), new std::codecvt_utf8_utf16<wchar_t,
					0x10ffff, std::codecvt_mode(std::consume_header | std::generate_header)>));
				file << ItemIndex << " " << ws_NoiDung << " " << ws_SoTien << '\n';
				file.close();
				SendMessage(NgayA, WM_SETTEXT, NULL, (LPARAM)ngay);
				SendMessage(ThangA, WM_SETTEXT, NULL, (LPARAM)thang);
				SendMessage(NamA, WM_SETTEXT, NULL, (LPARAM)nam);
				SendMessage(cmbChoice_Loai, (UINT)CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
				SendMessage(hWnd, WM_COMMAND, (WPARAM)IDC_BUTTON_INPUT_XEM, 0);
				MessageBox(0, L"Thêm dữ liệu thành công!", L"Thông báo", 0);
					//int ItemIndex = SendMessage(cmbChoice, (UINT)CB_GETCURSEL,
					//	(WPARAM)0, (LPARAM)0);//?? HWND của combo box đâu
					//int length = GetWindowTextLength(cmbChoice);
					//WCHAR*  cbItem = new WCHAR[length + 1];
					//cbItem = L"";

					//(WCHAR)SendMessage(cmbChoice, (UINT)CB_GETLBTEXT,
					//	(WPARAM)ItemIndex, (LPARAM)cbItem);

					//if (cbItem == L"")
					//	MessageBox(0, &cbItem[0], 0, 0);
				//NoiDung

				/*WCHAR *content = NULL;
				int szcontent;
				szcontent = GetWindowTextLength(NoiDung);
				content = new WCHAR[szcontent + 1];
				content = L"";
				GetWindowText(NoiDung, content, szcontent + 1);
				if (content == L"")
					MessageBox(0, content, 0, 0);*/
				break;
			}
			case IDC_BUTTON_INPUT_XEM:
			{
				for (int i = 0; i < 6; i++)
					arrayData[i] = 0;
				Thu = Chi = 0;
				ListView_DeleteAllItems(hList);
				WCHAR* ngayA;
				WCHAR* thangA;
				WCHAR* namA;
				int length_cmbChoice_Loai = GetWindowTextLength(cmbChoice_Loai);
				int length_NgayA = GetWindowTextLength(NgayA);
				int length_ThangA = GetWindowTextLength(ThangA);
				int length_NamA = GetWindowTextLength(NamA);
				if (length_cmbChoice_Loai == 0) {
					MessageBox(0, L"Vui lòng nhập đầy đủ thông tin chi tiêu!", L"Thông báo", 0);
					break;
				}
				int ItemIndex = SendMessage(cmbChoice_Loai, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (ItemIndex == 0) {
					if (length_NgayA == 0 || length_ThangA == 0 || length_NamA == 0) {
						MessageBox(0, L"Vui lòng nhập đầy đủ thông tin chi tiêu!", L"Thông báo", 0);
						break;
					}
					ngayA = new WCHAR[length_NgayA + 1];
					thangA = new WCHAR[length_ThangA + 1];
					namA = new WCHAR[length_NamA + 1];
					GetWindowText(NgayA, ngayA, length_NgayA + 1);
					GetWindowText(ThangA, thangA, length_ThangA + 1);
					GetWindowText(NamA, namA, length_NamA + 1);
					if (!isTrueDay(ngayA, thangA, namA)) {
						MessageBox(0, L"Vui lòng nhập chính xác ngày - tháng - năm!", L"Thông báo", 0);
						break;
					}
					int pos = 0;
					Thu = Chi = 0;
					OutputData(hList, ngayA, thangA, namA, pos, Thu, Chi);
					WCHAR str1[20];
					swprintf_s(str1, L"%f", Thu);
					WCHAR str2[20];
					swprintf_s(str2, L"%f", Chi);
					SendMessage(TongThuNhap, WM_SETTEXT, NULL, (LPARAM)str1);
					SendMessage(TongChiTieu, WM_SETTEXT, NULL, (LPARAM)str2);
					InvalidateRect(hWnd, NULL, TRUE);
				}
				else if (ItemIndex == 1) {
					if (length_ThangA == 0 || length_NamA == 0) {
						MessageBox(0, L"Vui lòng nhập đầy đủ thông tin chi tiêu!", L"Thông báo", 0);
						break;
					}
					thangA = new WCHAR[length_ThangA + 1];
					namA = new WCHAR[length_NamA + 1];
					GetWindowText(ThangA, thangA, length_ThangA + 1);
					GetWindowText(NamA, namA, length_NamA + 1);
					if (!isTrueDay(L"1", thangA, namA)) {
						MessageBox(0, L"Vui lòng nhập chính xác tháng - năm!", L"Thông báo", 0);
						break;
					}
					int pos = 0;
					Thu = Chi = 0;
					for (int i = 1; i <= lengthDay(_wtoi(thangA), _wtoi(namA)); i++) {
						wstring value = to_wstring(i);
					const WCHAR* ngayTemp = value.c_str();
						if (!isHave((WCHAR*)ngayTemp, thangA, namA))
							continue;
						LVITEM m;
						m.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
						m.iSubItem = 0;
						m.pszText = L"";
						m.iImage = 0;
						m.lParam = (LPARAM)L"Test";
						m.cchTextMax = 2;
						m.iItem = pos;
						ListView_InsertItem(hList, &m);
						WCHAR* folder = new WCHAR[20];
						wsprintf(folder, L"Ngày %s", ngayTemp);
						ListView_SetItemText(hList, pos, 0, L"****************");
						ListView_SetItemText(hList, pos, 2, L"****************");
						ListView_SetItemText(hList, pos, 1, folder);
						pos++;
						double ThuTemp, ChiTemp;
						OutputData(hList, (WCHAR*)ngayTemp, thangA, namA, pos, ThuTemp, ChiTemp);
						Thu += ThuTemp;
						Chi += ChiTemp;
					}
					WCHAR str1[20];
					swprintf_s(str1, L"%f", Thu);
					WCHAR str2[20];
					swprintf_s(str2, L"%f", Chi);
					SendMessage(TongThuNhap, WM_SETTEXT, NULL, (LPARAM)str1);
					SendMessage(TongChiTieu, WM_SETTEXT, NULL, (LPARAM)str2);
					InvalidateRect(hWnd, NULL, TRUE);
				}
				else {
					if (length_NamA == 0) {
						MessageBox(0, L"Vui lòng nhập đầy đủ thông tin chi tiêu!", L"Thông báo", 0);
						break;
					}
					namA = new WCHAR[length_NamA + 1];
					GetWindowText(NamA, namA, length_NamA + 1);
					int pos = 0;
					Thu = Chi = 0;
					for (int i = 1; i <= 12; i++) {
						wstring value = to_wstring(i);
						const WCHAR* thangTemp = value.c_str();
						LVITEM m;
						m.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
						m.iSubItem = 0;
						m.pszText = L"";
						m.iImage = 0;
						m.lParam = (LPARAM)L"Test";
						m.cchTextMax = 2;
						m.iItem = pos;
						ListView_InsertItem(hList, &m);
						WCHAR* folder = new WCHAR[20];
						wsprintf(folder, L"Tháng %s", thangTemp);
						ListView_SetItemText(hList, pos, 0, L"OOOOOOOOOOOO");
						ListView_SetItemText(hList, pos, 2, L"OOOOOOOOOOOO");
						ListView_SetItemText(hList, pos, 1, folder);
						pos++;
						for (int j = 1; j < lengthDay(i, _wtoi(namA)); j++) {
							wstring value1 = to_wstring(j);
							const WCHAR* ngayTemp = value1.c_str();
							if (!isHave((WCHAR*)ngayTemp, (WCHAR*)thangTemp, namA))
								continue;
							m.iItem = pos;
							ListView_InsertItem(hList, &m);
							WCHAR* folder1 = new WCHAR[20];
							wsprintf(folder1, L"Ngày %s", ngayTemp);
							ListView_SetItemText(hList, pos, 0, L"****************");
							ListView_SetItemText(hList, pos, 2, L"****************");
							ListView_SetItemText(hList, pos, 1, folder1);
							pos++;
							double ThuTemp, ChiTemp;
							OutputData(hList, (WCHAR*)ngayTemp, (WCHAR*)thangTemp, namA, pos, ThuTemp, ChiTemp);
							Thu += ThuTemp;
							Chi += ChiTemp;
						}
					}
					WCHAR str1[20];
					swprintf_s(str1, L"%f", Thu);
					WCHAR str2[20];
					swprintf_s(str2, L"%f", Chi);
					SendMessage(TongThuNhap, WM_SETTEXT, NULL, (LPARAM)str1);
					SendMessage(TongChiTieu, WM_SETTEXT, NULL, (LPARAM)str2);
					InvalidateRect(hWnd, NULL, TRUE);
				}
				wfstream fileA;
				fileA.open("History.txt", ios::out);
				switch (ItemIndex) {
					case 0:
						fileA << ngayA << L" " << thangA << L" " << namA << L" " << ItemIndex;
						break;
					case 1:
						fileA  << L"1 " << thangA << L" " << namA << L" " << ItemIndex;
						break;
					case 2:
						fileA << L"1 1 " << namA << L" " << ItemIndex;
						break;
				}
				fileA.close();
				break;
			}
			case IDC_BUTTON_INPUT_THU:
			{
				int length_SoTienThu = GetWindowTextLength(SoTienThu);
				int length_NgayB = GetWindowTextLength(NgayB);
				int length_ThangB = GetWindowTextLength(ThangB);
				int length_NamB = GetWindowTextLength(NamB);
				if (length_SoTienThu == 0 || length_NgayB == 0 || length_ThangB == 0 || length_NamB == 0) {
					MessageBox(0, L"Vui lòng nhập đầy đủ thông tin chi tiêu!", L"Thông báo", 0);
					break;
				}
				WCHAR* ngayB = new WCHAR[length_NgayB + 1];
				WCHAR* thangB = new WCHAR[length_ThangB + 1];
				WCHAR* namB = new WCHAR[length_NamB + 1];
				GetWindowText(NgayB, ngayB, length_NgayB + 1);
				GetWindowText(ThangB, thangB, length_ThangB + 1);
				GetWindowText(NamB, namB, length_NamB + 1);
				if (!isTrueDay(ngayB, thangB, namB)) {
					MessageBox(0, L"Vui lòng nhập chính xác ngày - tháng - năm!", L"Thông báo", 0);
					break;
				}
				wstring ws_namB(namB);
				wstring ws_thangB(thangB);
				wstring ws_ngayB(ngayB);
				string str_namB(ws_namB.begin(), ws_namB.end());
				string str_thangB(ws_thangB.begin(), ws_thangB.end());
				string str_ngayB(ws_ngayB.begin(), ws_ngayB.end());
				WCHAR* content_SoTienThu = new WCHAR[length_SoTienThu + 1];
				GetWindowText(SoTienThu, content_SoTienThu, length_SoTienThu + 1);
				wstring ws_SoTienThu(content_SoTienThu);
				string str_SoTienThu(ws_SoTienThu.begin(), ws_SoTienThu.end());
				fstream file;

				string temp = "data/" + str_namB + "/" + str_thangB + "/" + "THU_" + str_ngayB + ".txt";
				file.open(temp, ios::app);
				if (!file.good()) {
					string address = "data/" + str_namB + "/" + str_thangB;
					string str = "mkdir \"" + address + "\"";
					system(str.c_str());
					address += "/THU_" + str_ngayB + ".txt";
					file.open(address, ios::app);
					if (!file.good()) {
						MessageBox(0, L"Không thể thêm dữ liệu!", L"Thông báo", 0);
						break;
					}
				}
				file << str_SoTienThu << '\n';
				file.close();
				SendMessage(NgayA, WM_SETTEXT, NULL, (LPARAM)ngayB);
				SendMessage(ThangA, WM_SETTEXT, NULL, (LPARAM)thangB);
				SendMessage(NamA, WM_SETTEXT, NULL, (LPARAM)namB);
				SendMessage(cmbChoice_Loai, (UINT)CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
				SendMessage(hWnd, WM_COMMAND, (WPARAM)IDC_BUTTON_INPUT_XEM, 0);
				MessageBox(0, L"Thêm dữ liệu thành công!", L"Thông báo", 0);
				break;
			}
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
	case WM_MOUSEMOVE:
	{
		int x = GET_X_LPARAM(lParam);
		int y = GET_Y_LPARAM(lParam);
		WCHAR buffer[200];
		wsprintf(buffer, L"%d, %d", x, y);
		SetWindowText(hWnd, buffer);
		break;
	}
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			SetDCBrushColor(hdc, RGB(240, 240, 240));
			SelectObject(hdc, GetStockObject(DC_BRUSH));
			Rectangle(hdc, 25, 25, 570, 200);
			Rectangle(hdc, 625, 25, 1225, 330);
			Rectangle(hdc, 625, 365, 1225, 650);
			Rectangle(hdc, 25, 230, 570, 390);
			Rectangle(hdc, 25, 420, 570, 562);

			for (int i = 0; i < 6; i++) {
				SendMessage(box[i], WM_SETTEXT, NULL, (LPARAM)L"0%");
			}
			if (flag == true) {

				int Do[6] = { 0 };
				if (Chi == 0)
					break;
				Do[0]= (arrayData[0] / Chi) * 360;
				for (int i = 1; i < 6; i++) {
					Do[i] = Do[i - 1] + (arrayData[i] / Chi) * 360;
				}
				bool subFlag[6];
				//Biểu đồ tròn
				POINT start, end, cent, temp;
				int TongDo[6] = { 0 };
				for (int i = 0; i < 6; i++) {
					TongDo[i] = (arrayData[i] / Chi) * 360;
					WCHAR str[80];
					swprintf_s(str, L"%f%%", (arrayData[i] / Chi)*100);
					SendMessage(box[i], WM_SETTEXT, NULL, (LPARAM)str);
					if (TongDo[i] == 0)
						subFlag[i] = false;
					else
						subFlag[i] = true;
				}
				for (int i = 5; i >= 0; i--) {
					if (subFlag[i] == true) {
						Do[i] = 360;
						break;
					}
				}
				cent.x = 753;
				cent.y = 500;
				temp.x = 753;
				temp.y = 400;
				if (subFlag[0]) {
					SetDCBrushColor(hdc, RGB(162, 0, 124));
					start = temp;
					end = FindPointCircle(cent, 100, Do[0]);
					temp = end;
					Pie(hdc, 653, 400, 853, 600, end.x, end.y, start.x, start.y);
				}
				if (subFlag[1]) {
					SetDCBrushColor(hdc, RGB(91, 189, 43));
					start = temp;
					end = FindPointCircle(cent, 100, Do[1]);
					temp = end;
					Pie(hdc, 653, 400, 853, 600, end.x, end.y, start.x, start.y);
				}
				if (subFlag[2]) {
					SetDCBrushColor(hdc, RGB(0, 178, 191));
					start = temp;
					end = FindPointCircle(cent, 100, Do[2]);
					temp = end;
					Pie(hdc, 653, 400, 853, 600, end.x, end.y, start.x, start.y);
				}
				if (subFlag[3]) {
					SetDCBrushColor(hdc, RGB(252, 245, 76));
					start = temp;
					end = FindPointCircle(cent, 100, Do[3]);
					temp = end;
					Pie(hdc, 653, 400, 853, 600, end.x, end.y, start.x, start.y);
				}
				if (subFlag[4]) {
					SetDCBrushColor(hdc, RGB(121, 55, 139));
					start = temp;
					end = FindPointCircle(cent, 100, Do[4]);
					temp = end;
					Pie(hdc, 653, 400, 853, 600, end.x, end.y, start.x, start.y);
				}
				if (subFlag[5]) {
					SetDCBrushColor(hdc, RGB(0, 103, 107));
					start = temp;
					end.x = 753;
					end.y = 400;
					temp = end;
					Pie(hdc, 653, 400, 853, 600, end.x, end.y, start.x, start.y);
				}

				//Cột 1
				SetDCBrushColor(hdc, RGB(162, 0, 124));
				Pie(hdc, 900, 400, 1000, 500, 950, 450, 993, 425);
				//Cột 2
				SetDCBrushColor(hdc, RGB(91, 189, 43));
				Pie(hdc, 900, 435, 1000, 535, 950, 485, 993, 460);
				//Cột 3
				SetDCBrushColor(hdc, RGB(0, 178, 191));
				Pie(hdc, 900, 470, 1000, 570, 950, 520, 993, 495);
				//Cột 4
				SetDCBrushColor(hdc, RGB(252, 245, 76));
				Pie(hdc, 900, 505, 1000, 605, 950, 555, 993, 530);
				//Cột 5
				SetDCBrushColor(hdc, RGB(121, 55, 139));
				Pie(hdc, 900, 540, 1000, 640, 950, 590, 993, 565);
				//Cột 6
				SetDCBrushColor(hdc, RGB(0, 103, 107));
				Pie(hdc, 900, 575, 1000, 675, 950, 625, 993, 600);
				EndPaint(hWnd, &ps);

				if (Thu > Chi) {
					SetDCBrushColor(hdc, RGB(223, 0, 41));
					Rectangle(hdc, 25, 600, 600, 650);
				}
				else if (Thu < Chi) {
					SetDCBrushColor(hdc, RGB(223, 0, 41));
					Rectangle(hdc, 0, 0, 1000, 1000);
				}
			}

			SetDCBrushColor(hdc, RGB(223, 0, 41));
			SelectObject(hdc, GetStockObject(DC_BRUSH));
			SetDCBrushColor(hdc, RGB(223, 0, 41));
			Rectangle(hdc, 25, 100, 600, 650);
			flag = true;
			EndPaint(hWnd, &ps);
        }

        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

bool isTrueDay(WCHAR* ngay, WCHAR* thang, WCHAR* nam) {
	int Ngay, Thang, Nam;
	Ngay = _wtof(ngay);
	Thang = _wtof(thang);
	Nam = _wtof(nam);
	switch (Thang) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (Ngay >= 1 && Ngay <= 31)
				return true;
			else
				return false;
		case 4:
		case 6:
		case 9:
		case 11:
			if (Ngay >= 1 && Ngay <= 30)
				return true;
			else
				return false;
		case 2:
			if (Nam % 4 == 0 && Nam % 100 != 0 || Nam % 400 == 0) {
				if (Ngay >= 1 && Ngay <= 29)
					return true;
			}
			else {
				if (Ngay >= 1 && Ngay <= 28)
					return true;
			}
			return false;
		default:
			return false;
	}
	return false;
}

bool OutputData(HWND &hWnd1, WCHAR* ngay, WCHAR* thang, WCHAR* nam, int &pos, double &Thu, double &Chi){
	Thu = Chi = 0;
	wstring ws_nam(nam);
	wstring ws_thang(thang);
	wstring ws_ngay(ngay);
	string str_nam(ws_nam.begin(), ws_nam.end());
	string str_thang(ws_thang.begin(), ws_thang.end());
	string str_ngay(ws_ngay.begin(), ws_ngay.end());
	fstream fileThu;
	wfstream fileChi;
	fileThu.open("data/" + str_nam + "/" + str_thang + "/" + "THU_" + str_ngay + ".txt", ios::in);
	fileChi.open("data/" + str_nam + "/" + str_thang + "/" + "CHI_" + str_ngay + ".txt", ios::in);
	if (!(fileThu.good() || fileChi.good())) {
		return false;
	}
	if (fileThu.good()) {
		while (!fileThu.eof()) {
			string Tien;
			getline(fileThu, Tien);
			if (Tien == "")
				break;
			Thu = Thu + stod(Tien);
			string narrow_string(Tien);
			wstring wide_string = wstring(narrow_string.begin(), narrow_string.end());
			const WCHAR* result = wide_string.c_str();
			LVITEM m;
			m.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
			m.iSubItem = 0;
			m.pszText = L"";
			m.iImage = 0;
			m.lParam = (LPARAM)L"Test";
			m.cchTextMax = 2;
			m.iItem = pos;
			ListView_InsertItem(hList, &m);
			ListView_SetItemText(hWnd1, pos, 0, L"Thu nhập");
			ListView_SetItemText(hWnd1, pos, 1, L"-----------------------------------");
			ListView_SetItemText(hWnd1, pos, 2, (WCHAR*)result);
			pos++;
		}
		fileThu.close();
	}
	if (fileChi.good()) {
		while (!fileChi.eof()) {
			fileChi.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
			wstring loai;
			fileChi >> loai;
			if (loai == L"")
				break;
			wstring ND;
			getline(fileChi, ND);
			int vitri = ND.find_last_of(' ');
			wstring phi(ND.begin() + vitri, ND.end());
			ND.erase(ND.begin() + vitri, ND.end());
			const WCHAR* result2 = ND.c_str();
			const WCHAR* result3 = phi.c_str();
			double db_phi = stod(phi);;
			Chi = Chi + db_phi;
			LVITEM m;
			m.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
			m.iSubItem = 0;
			m.pszText = L"";
			m.iImage = 0;
			m.lParam = (LPARAM)L"Test";
			m.cchTextMax = 2;
			m.iItem = pos;
			ListView_InsertItem(hList, &m);
			if (loai == L"0") {
				arrayData[0] = arrayData[0] + db_phi;
				ListView_SetItemText(hWnd1, pos, 0, L"Ăn uống");
			}
			else if (loai == L"1") {
				arrayData[1] = arrayData[1] + db_phi;
				ListView_SetItemText(hWnd1, pos, 0, L"Di chuyển");
			}
			else if (loai == L"2") {
				arrayData[2] = arrayData[2] + db_phi;
				ListView_SetItemText(hWnd1, pos, 0, L"Nhà cửa");
			}
			else if (loai == L"3") {
				arrayData[3] = arrayData[3] + db_phi;
				ListView_SetItemText(hWnd1, pos, 0, L"Xe cộ");
			}
			else if (loai == L"4") {
				arrayData[4] = arrayData[4] + db_phi;
				ListView_SetItemText(hWnd1, pos, 0, L"Nhu yếu phẩm");
			}
			else if (loai == L"5") {
				arrayData[5] = arrayData[5] + db_phi;
				ListView_SetItemText(hWnd1, pos, 0, L"Dịch vụ");
			}
			ListView_SetItemText(hWnd1, pos, 1, (WCHAR*)result2);
			ListView_SetItemText(hWnd1, pos, 2, (WCHAR*)result3);
			pos++;
		}
		fileChi.close();
	}
	return true;
}

int lengthDay(int thang, int nam) {
	switch (thang) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0)
				return 29;
			else 
				return 28;
	default:
		return 0;
	}
}

bool isHave(WCHAR *ngay, WCHAR *thang, WCHAR *nam){
	wstring ws_nam(nam);
	wstring ws_thang(thang);
	wstring ws_ngay(ngay);
	string str_nam(ws_nam.begin(), ws_nam.end());
	string str_thang(ws_thang.begin(), ws_thang.end());
	string str_ngay(ws_ngay.begin(), ws_ngay.end());
	fstream fileThu, fileChi;
	fileThu.open("data/" + str_nam + "/" + str_thang + "/" + "THU_" + str_ngay + ".txt", ios::in);
	fileChi.open("data/" + str_nam + "/" + str_thang + "/" + "CHI_" + str_ngay + ".txt", ios::in);
	if (!(fileThu.good() || fileChi.good())) {
		return false;
	}
	if (fileThu.good())
		fileThu.close();
	if (fileChi.good())
		fileChi.close();
	return true;
}

POINT FindPointCircle(POINT cent, int R, int Goc) {
	POINT kq;
	kq.x = cent.x + R*sin((Goc*3.14) / 180 * 1.0);
	kq.y = cent.y - R*cos((Goc*3.14) / 180 * 1.0);
	return kq;
}