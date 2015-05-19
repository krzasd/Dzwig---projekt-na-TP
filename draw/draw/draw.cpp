// draw.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#define MAX_LOADSTRING 100
#define TMR_1 1

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
RECT drawArea = { 145, 59, 1420, 720 };			// non crane rectangle
TRIANGLE* trojkaty = new TRIANGLE[ ILOSC_TROJKATOW ];
RECTANGLE* prostokaty = new RECTANGLE[ ILOSC_PROSTOKATOW ];
CRANE_HOOK Hak;
	

HWND hwndButton;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);


void MyOnPaint(HDC hdc )
{
	Hak.drawHook( hdc );
	for ( int i = 0; i < ILOSC_TROJKATOW; ++i )
		trojkaty[ i ].drawTriangle( hdc, 0, 0 );
	for ( int i = 0; i < ILOSC_PROSTOKATOW; ++i )
		prostokaty[ i ].drawRectangle( hdc, 0, 0 );
}

int OnCreate(HWND window)
{
   InitTriangles( trojkaty );
   InitRectangles( prostokaty );
   return 0;
}



int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

//	value= 10;

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);
	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+3); //black color
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
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
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   /*hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Start"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		900, 10,                                  // the left and top co-ordinates
		80, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON1,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits

    hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Stop"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		1000, 10,                                  // the left and top co-ordinates
		80, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON2,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits*/

   SetWindowText( hWnd, L"D¿wig" ); //Set title
   
   OnCreate(hWnd);

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
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	//OnCreate(hWnd,wParam,lParam);
	//OnTimer(hWnd,wParam,lParam);

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu & button selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		/*case ID_BUTTON1:
			SetTimer(hWnd, TMR_1, 10, 0);
			break;
		case ID_BUTTON2:
			KillTimer( hWnd, TMR_1 );
			break;*/
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		MyOnPaint( hdc );
		PaintCrane( hdc );
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
		switch (wParam)
		{
			case TMR_1:
				//force window to repaint
				InvalidateRect(hWnd, &drawArea, TRUE);
				hdc = BeginPaint(hWnd, &ps);
				MyOnPaint( hdc );
				EndPaint(hWnd, &ps);
			break;
		}

	case WM_KEYDOWN:
		// TODO: Add any drawing code here...
			switch( (int)wParam )
			{
			case VK_DOWN:
				if ( Hak.Active && !Hak.Attached )
					for ( int i = 0; i < ILOSC_TROJKATOW; ++i )
					{
						if ( trojkaty[ i ].getPeakPoint().Y > Hak.getUpperY() && trojkaty[ i ].getPeakPoint().Y < Hak.getBottomY()
							&& trojkaty[ i ].getPeakPoint().X > Hak.getLeftX() && trojkaty[ i ].getPeakPoint().X < Hak.getRightX() )
							Hak.Attached = i+1;
					}
				if ( Hak.Attached )
					{
						trojkaty[ Hak.Attached -1 ].SetParameters( trojkaty[ Hak.Attached -1 ].getPeakPoint().X, 
							trojkaty[ Hak.Attached -1 ].getPeakPoint().Y + 5, 80 );
						Hak.mooveHook( 0, 5 );
					}
					else
						Hak.mooveHook( 0, 5 );
				break;
			case VK_UP:
				if ( Hak.Active && !Hak.Attached )
					for ( int i = 0; i < ILOSC_TROJKATOW; ++i )
					{
						if ( trojkaty[ i ].getPeakPoint().Y > Hak.getUpperY() && trojkaty[ i ].getPeakPoint().Y < Hak.getBottomY()
							&& trojkaty[ i ].getPeakPoint().X > Hak.getLeftX() && trojkaty[ i ].getPeakPoint().X < Hak.getRightX() )
							Hak.Attached = i+1;
					}
				if ( Hak.Attached && Hak.getUpperY() > 63)
				{
					trojkaty[ Hak.Attached -1 ].SetParameters( trojkaty[ Hak.Attached -1 ].getPeakPoint().X, 
						trojkaty[ Hak.Attached -1 ].getPeakPoint().Y - 5, 80 );
					Hak.mooveHook( 0, -5 );
				}
				else
					Hak.mooveHook( 0, -5 );
				break;
			case VK_LEFT:
				if ( Hak.Active && !Hak.Attached )
					for ( int i = 0; i < ILOSC_TROJKATOW; ++i )
					{
						if ( trojkaty[ i ].getPeakPoint().Y > Hak.getUpperY() && trojkaty[ i ].getPeakPoint().Y < Hak.getBottomY()
							&& trojkaty[ i ].getPeakPoint().X > Hak.getLeftX() && trojkaty[ i ].getPeakPoint().X < Hak.getRightX() )
							Hak.Attached = i+1;
					}
				if( Hak.Attached && Hak.getLeftX() > 149 )
				{
					trojkaty[ Hak.Attached -1 ].SetParameters( trojkaty[ Hak.Attached -1 ].getPeakPoint().X - 5,
						trojkaty[ Hak.Attached -1 ].getPeakPoint().Y, 80 ); 
					Hak.mooveHook( -5, 0 );
				}
				else
					Hak.mooveHook( -5, 0 );
				break;
			case VK_RIGHT:
				if ( Hak.Active && !Hak.Attached )
					for ( int i = 0; i < ILOSC_TROJKATOW; ++i )
					{
						if ( trojkaty[ i ].getPeakPoint().Y > Hak.getUpperY() && trojkaty[ i ].getPeakPoint().Y < Hak.getBottomY()
							&& trojkaty[ i ].getPeakPoint().X > Hak.getLeftX() && trojkaty[ i ].getPeakPoint().X < Hak.getRightX() )
							Hak.Attached = i+1;
					}
				if ( Hak.Attached && Hak.getRightX() < 1329 )
				{
					trojkaty[ Hak.Attached -1 ].SetParameters( trojkaty[ Hak.Attached -1 ].getPeakPoint().X + 5,
						trojkaty[ Hak.Attached -1 ].getPeakPoint().Y, 80 ); 
					Hak.mooveHook( 5, 0 );
				}
				else
					Hak.mooveHook( 5, 0 );
				break;
			case VK_RETURN:
				Hak.Attached = 0;
				Hak.Active = false;
				break;
			case VK_SPACE:
				Hak.Active = true;
				break;
			}
		InvalidateRect(hWnd, &drawArea, TRUE);
		hdc = BeginPaint(hWnd, &ps);
		MyOnPaint( hdc );
		EndPaint(hWnd, &ps);
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

