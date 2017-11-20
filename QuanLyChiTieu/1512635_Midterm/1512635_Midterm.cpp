// 1512635_Midterm.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "1512635_Midterm.h"
#include<cmath>
#include<Windowsx.h>
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
      CW_USEDEFAULT, 0, 1220, 700, nullptr, nullptr, hInstance, nullptr);

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
		HWND cmbChoice = CreateWindow(L"combobox", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST
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
		HWND NoiDung = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | WS_BORDER, 200, 75, 200, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);

		//Group số tiền
		hwnd = CreateWindowEx(0, L"STATIC", L"Số tiền:", WS_CHILD | WS_VISIBLE | SS_LEFT, 425, 50, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		HWND SoTien = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 425, 75, 120, 20, hWnd, NULL, hInst, NULL);
		SendMessage(SoTien, WM_SETFONT, WPARAM(hFontBold), TRUE);
		
		hwnd = CreateWindowEx(0, L"STATIC", L"Thêm dữ liệu chi tiêu trong ngày", WS_CHILD | WS_VISIBLE | SS_LEFT, 180, 17, 220, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		
		hwnd = CreateWindowEx(0, L"STATIC", L"Ngày", WS_CHILD | WS_VISIBLE | SS_LEFT, 100, 115, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		HWND Ngay = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 150, 115, 23, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Tháng", WS_CHILD | WS_VISIBLE | SS_LEFT, 223, 115, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		HWND Thang = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 290, 115, 23, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Năm", WS_CHILD | WS_VISIBLE | SS_LEFT, 385, 115, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		HWND Nam = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 438, 115, 40, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);

		hwnd = CreateWindowEx(0, L"BUTTON", L"Thêm vào", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 150, 100, 35, hWnd, (HMENU)IDC_BUTTON_INPUT, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);

		/////////////////////////////////////Show data
		///////////////Tạo List view
		HWND hList = CreateWindow(WC_LISTVIEW, L"ListView", WS_CHILD | WS_VISIBLE |
			WS_BORDER | LVS_REPORT | LVS_REPORT | LVS_SINGLESEL | LVS_ICON | WS_VSCROLL
			, 650,50, 500, 230, hWnd, (HMENU)IDC_LISTSHOWDATA, hInst, NULL);
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
		col.cx = 150;
		ListView_InsertColumn(hList, 2, &col);

		hwnd = CreateWindowEx(0, L"STATIC", L"Tổng chi tiêu", WS_CHILD | WS_VISIBLE | SS_LEFT, 900, 290, 100, 20, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		HWND TongChiTieu = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER, 1000, 288, 150, 20, hWnd, NULL, hInst, NULL);
		SendMessage(TongChiTieu, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Tổng thu nhập", WS_CHILD | WS_VISIBLE | SS_LEFT, 650, 290, 150, 20, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		HWND TongThuNhap = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER, 750, 288, 150, 20, hWnd, NULL, hInst, NULL);
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
		hwnd = CreateWindowEx(0, L"STATIC", L"Di chuyển", WS_CHILD | WS_VISIBLE | SS_LEFT, 1020, 465, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Nhà cửa", WS_CHILD | WS_VISIBLE | SS_LEFT, 1020, 500, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Xe cộ", WS_CHILD | WS_VISIBLE | SS_LEFT, 1020, 535, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Nhu yếu phẩm", WS_CHILD | WS_VISIBLE | SS_LEFT, 1020, 570, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Dịch vụ", WS_CHILD | WS_VISIBLE | SS_LEFT, 1020, 605, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);

		//////////////////////////////////////////Ngày tháng năm
		hwnd = CreateWindowEx(0, L"STATIC", L"Xem danh sách chi tiêu", WS_CHILD | WS_VISIBLE | SS_LEFT, 220, 222, 160, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Ngày", WS_CHILD | WS_VISIBLE | SS_LEFT, 100, 257, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		HWND NgayA = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 150, 255, 23, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Tháng", WS_CHILD | WS_VISIBLE | SS_LEFT, 223, 257, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		HWND ThangA = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 290, 255, 23, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Năm", WS_CHILD | WS_VISIBLE | SS_LEFT, 385, 257, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		HWND NamA = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 438, 255, 40, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		HWND cmbChoice_Loai = CreateWindow(L"combobox", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST
			, 240, 298, 170, 15, hWnd, (HMENU)ID_CMBCHOICE_LOAI, hInst, NULL);
		hwnd = CreateWindowEx(0, L"STATIC", L"Xem theo", WS_CHILD | WS_VISIBLE | SS_LEFT, 170, 298, 70, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		SendMessage(cmbChoice_Loai, WM_SETFONT, WPARAM(hFontBold), TRUE);
		SendMessage(cmbChoice_Loai, CB_ADDSTRING, NULL, (LPARAM)L"Ngày - Tháng - Năm");
		SendMessage(cmbChoice_Loai, CB_ADDSTRING, NULL, (LPARAM)L"Tháng - Năm");
		SendMessage(cmbChoice_Loai, CB_ADDSTRING, NULL, (LPARAM)L"Năm");
		hwnd = CreateWindowEx(0, L"BUTTON", L"Xem", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 335, 100, 35, hWnd, (HMENU)IDC_BUTTON_INPUT, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);

		//Group Thu nhập
		hwnd = CreateWindowEx(0, L"STATIC", L"Thêm dữ liệu thu nhập trong ngày", WS_CHILD | WS_VISIBLE | SS_LEFT, 220, 412, 153, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Số tiền thu nhập", WS_CHILD | WS_VISIBLE | SS_LEFT, 50, 440, 150, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		HWND SoTienThu = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER, 178, 440, 120, 20, hWnd, NULL, hInst, NULL);
		SendMessage(SoTienThu, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Ngày", WS_CHILD | WS_VISIBLE | SS_LEFT, 100, 480, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		HWND NgayB = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 150, 480, 23, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Tháng", WS_CHILD | WS_VISIBLE | SS_LEFT, 223, 480, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		HWND ThangB = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 290, 480, 23, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"STATIC", L"Năm", WS_CHILD | WS_VISIBLE | SS_LEFT, 385, 480, 100, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		HWND NamB = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_BORDER | ES_NUMBER, 438, 480, 40, 20, hWnd, NULL, hInst, NULL);
		SendMessage(NoiDung, WM_SETFONT, WPARAM(hFontBold), TRUE);
		hwnd = CreateWindowEx(0, L"BUTTON", L"Thêm vào", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 510, 100, 35, hWnd, (HMENU)IDC_BUTTON_INPUT, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		////Group combobox
		//HWND cmb = CreateWindow(L"combobox", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST
		//	, 50, 75, 125, 15, hWnd, (HMENU)ID_CMBCHOICE, hInst, NULL);
		//hwnd = CreateWindowEx(0, L"STATIC", L"Loại chi tiêu", WS_CHILD | WS_VISIBLE | SS_LEFT, 50, 50, 100, 15, hWnd, NULL, hInst, NULL);
		//SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		//SendMessage(cmbChoice, WM_SETFONT, WPARAM(hFontBold), TRUE);
		//SendMessage(cmbChoice, CB_ADDSTRING, NULL, (LPARAM)L"Ăn uống");
		//SendMessage(cmbChoice, CB_ADDSTRING, NULL, (LPARAM)L"Di chuyển");
		//SendMessage(cmbChoice, CB_ADDSTRING, NULL, (LPARAM)L"Nhà cửa");
		//SendMessage(cmbChoice, CB_ADDSTRING, NULL, (LPARAM)L"Xe cộ");
		//SendMessage(cmbChoice, CB_ADDSTRING, NULL, (LPARAM)L"Nhu yếu phẩm");
		//SendMessage(cmbChoice, CB_ADDSTRING, NULL, (LPARAM)L"Dịch vụ");
		break;


	}
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
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
			Rectangle(hdc, 625, 25, 1175, 330);
			Rectangle(hdc, 625, 365, 1175, 650);
			Rectangle(hdc, 25, 230, 570, 390);
			Rectangle(hdc, 25, 420, 570, 562);
			//Biểu đồ tròn
			SetDCBrushColor(hdc, RGB(0, 0, 0));
			Pie(hdc, 653, 400,853, 600, 853, 500, 790, 450); SetDCBrushColor(hdc, RGB(0, 0, 0));
			SetDCBrushColor(hdc, RGB(100, 100, 100));
			Pie(hdc, 653, 400, 853, 600, 790, 550, 853, 500);
			//Cột 1
			SetDCBrushColor(hdc, RGB(223, 0, 41));
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
			SetDCBrushColor(hdc, RGB(162, 0, 124));
			Pie(hdc, 900, 575, 1000, 675, 950, 625, 993, 600);
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
