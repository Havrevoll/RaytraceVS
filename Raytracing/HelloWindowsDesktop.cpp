// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#ifndef UNICODE
#define UNICODE
#endif // !UNICODE


#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include "World.h"

// Global variables

   // The main window class name.
static TCHAR szWindowClass[] = _T("DesktopApp");

   // The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Raytracing av fine ting");

HINSTANCE hInst;

   // Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ PWSTR     pCmdLine,
	_In_ int       nCmdShow
)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;     // pointer to the window procedure (der mesteparten av oppf�rselen til vindauget)
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;  // handle to application instance.
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;  // string that identifies the window class.
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

	// Store instance handle in our global variable
	hInst = hInstance;

	
	HWND hWnd = CreateWindowEx(
		0, // optinal window styles. kunne vore WS_EX_COMPOSITED ? cannot be used if the window has a class style of either CS_OWNDC or CS_CLASSDC
		szWindowClass, // window class
		szTitle, // window text
		WS_OVERLAPPEDWINDOW, // window style
		CW_USEDEFAULT, CW_USEDEFAULT, //position
		512, 512, //size
		NULL, //parent window
		NULL,  // menu bar
		hInstance, // instance handle, the first parameter from WinMain
		NULL // additional application data
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

	// The parameters to ShowWindow explained:
	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	ShowWindow(hWnd, nCmdShow);

	UpdateWindow(hWnd);


	// Byrja p� raytracinga?

	World w;
	w.build();
	w.render_scene();


	// Main message loop:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;    // Kva er no igjen PAINTSTRUCT?
	HDC hdc;           // Kva er no igjen HDC? Det er Handle for Device Context
//	RECT rect;

	TCHAR greeting[] = _T("Ja, her skal biletet koma d�.");

	static int cxClient = 512;
	static int cyClient = 512;
	static int cxSource, cySource;

	static COLORREF* arr;
	HDC src;
	HBITMAP map;

	switch (message)
	{



	/*case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);

		break;*/

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		arr = new COLORREF[cxClient * cyClient]();

		for (int i = 0; i < cxClient; i++)
		{
			for (int j = 0; j < cyClient; j++)
			{

				arr[(cxClient * j) + i] = RGB(50, (int)(j * 255.0 / cyClient), (int)(i * 255.0 / cxClient));
			}
		}



		// Creating temp bitmap
		map = CreateBitmap(512, // width. 512 in my case
			512, // height
			1, // Color Planes, unfortanutelly don't know what is it actually. Let it be 1
			8 * 4, // Size of memory for one pixel in bits (in win32 4 bytes = 4*8 bits)
			(void*)arr); // pointer to array
// Temp HDC to copy picture
		src = CreateCompatibleDC(hdc); // hdc - Device context for window, I've got earlier with GetDC(hWnd) or GetDC(NULL);
		SelectObject(src, map); // Inserting picture into our temp HDC
		// Copy image from temp HDC to window
		BitBlt(hdc, // Destination
			0,  // x and
			0,  // y - upper-left corner of place, where we'd like to copy
			512, // width of the region
			512, // height
			src, // source
			0,   // x and
			0,   // y of upper left corner  of part of the source, from where we'd like to copy
			SRCCOPY); // Defined DWORD to juct copy pixels. Watch more on msdn;

		DeleteObject(map);

		DeleteDC(src); // Deleting temp HDC

	    delete arr;



	//	GetClientRect(hWnd, &rect);

//		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 8));

		// Here your application is laid out.
		// For this introduction, we just print out "Hello, Windows desktop!"
		// in the top left corner.
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
		// End application-specific layout section.


		EndPaint(hWnd, &ps);

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}