// 1512635_Midterm.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "1512635_Midterm.h"

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
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

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
		
		hwnd = CreateWindowEx(0, L"STATIC", L"Thêm dữ liệu chi tiêu trong ngày", WS_CHILD | WS_VISIBLE | SS_LEFT, 185, 17, 220, 15, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFontBold), TRUE);
		
		
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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			SetDCBrushColor(hdc, RGB(240, 240, 240));
			SelectObject(hdc, GetStockObject(DC_BRUSH));
			Rectangle(hdc, 25, 25, 570, 145);
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
