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
std::vector < TRIANGLE > trojkaty;
std::vector < RECTANGLE > prostokaty;
std::vector < ELLIPSE > kola;
std::vector < PENTAGON > pieciokaty;
CRANE_HOOK Hak;
	
short int licznikWiezy = 0;
TRIANGLE trojkat;
RECTANGLE prostokat;
ELLIPSE kolo;
PENTAGON pieciokat;
HWND hwndButton;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);


void MyOnPaint(HDC hdc )
{
	/*Dzia�anie funkcji:
	1. Rysuje wszystkie obiekty
	*/
	Hak.drawHook( hdc );
	for ( int i = 0; i < trojkaty.size(); ++i )
		trojkaty[ i ].drawTriangle( hdc, 0, 0 );
	for ( int i = 0; i < prostokaty.size(); ++i )
		prostokaty[ i ].drawRectangle( hdc, 0, 0 );
	for ( int i = 0; i < kola.size(); ++i )
		kola[ i ].drawEllipse( hdc, 0, 0 );
	for ( int i = 0; i < pieciokaty.size(); ++i )
		pieciokaty[ i ].drawPentagon( hdc, 0, 0 );
}

void MessageBoxFormatted(HWND hWnd, LPCTSTR pCaption, LPCTSTR pFormatString, ...)
{
	/*Dzia�anie funkcji:
	1. Formatowanie i wy�wietlanie wiadomo�ci
	*/
    va_list vl;
    va_start(vl, pFormatString);
    
    TCHAR strFormat[1024];

    // Generic version of vsprintf, works for both MBCS and Unicode builds 
    _vstprintf(strFormat, pFormatString, vl);
	

    ::MessageBox(hWnd, strFormat, pCaption,MB_ICONINFORMATION);
}

bool NoFallCollision( int i, std::string typ )
{
	/*Dzia�anie funkcji:
	1. Wykrywa pionowe kolizje obiekt�w
	2. Gdy znajdzie kolizj� obiektu zwraca fa�sz 
	*/
	if ( typ == "triangle" )
	{
		for ( int j = 0; j < trojkaty.size(); ++j )
			if ( (i != j) && trojkaty[ i ].getPeakPoint().Y + trojkaty[ i ].GetSize()*1.71/2 > trojkaty[ j ].getPeakPoint().Y -5
					&& trojkaty[ i ].getPeakPoint().X - trojkaty[ i ].GetSize()/2 < trojkaty[ j ].getPeakPoint().X + trojkaty[ j ].GetSize()/2
					&& trojkaty[ i ].getPeakPoint().X + trojkaty[ i ].GetSize()/2 > trojkaty[ j ].getPeakPoint().X - trojkaty[ j ].GetSize()/2 
					&& (trojkaty[ i ].getPeakPoint().Y + trojkaty[ i ].GetSize()*1.71/2 - (trojkaty[ j ].getPeakPoint().Y -5)) < 20 )
			{
				return false;
			}
		for ( int j = 0; j < prostokaty.size(); ++j )
			if ( trojkaty[ i ].getPeakPoint().Y + trojkaty[ i ].GetSize()*1.71/2 > prostokaty[ j ].GetStartPointY()
					&& trojkaty[ i ].getPeakPoint().X - trojkaty[ i ].GetSize()/2 < prostokaty[ j ].GetStartPointX() + prostokaty[ j ].GetWidth()
					&& trojkaty[ i ].getPeakPoint().X + trojkaty[ i ].GetSize()/2 > prostokaty[ j ].GetStartPointX()
					&& (trojkaty[ i ].getPeakPoint().Y + trojkaty[ i ].GetSize()*1.71/2 - (prostokaty[ j ].GetStartPointY())) < 20 )
				return false;
		for ( int j = 0; j < kola.size(); ++j )
			if ( trojkaty[ i ].getPeakPoint().Y + trojkaty[ i ].GetSize()*1.71/2 > kola[ j ].GetStartPointY()
					&& trojkaty[ i ].getPeakPoint().X - trojkaty[ i ].GetSize()/2 < kola[ j ].GetStartPointX() + kola[ j ].GetWidth()
					&& trojkaty[ i ].getPeakPoint().X + trojkaty[ i ].GetSize()/2 > kola[ j ].GetStartPointX() 
					&& (trojkaty[ i ].getPeakPoint().Y + trojkaty[ i ].GetSize()*1.71/2 - (kola[ j ].GetStartPointY() -5)) < 20 )
				return false;
		for ( int j = 0; j < pieciokaty.size(); ++j )
			if ( trojkaty[ i ].getPeakPoint().Y + trojkaty[ i ].GetSize()*1.71/2 > pieciokaty[ j ].getPeakPoint().Y 
					&& trojkaty[ i ].getPeakPoint().X - trojkaty[ i ].GetSize()/2 < pieciokaty[ j ].getPeakPoint().X + pieciokaty[ j ].GetWidth()/2
					&& trojkaty[ i ].getPeakPoint().X + trojkaty[ i ].GetSize()/2 > pieciokaty[ j ].getPeakPoint().X - pieciokaty[ j ].GetWidth()/2 
					&& (trojkaty[ i ].getPeakPoint().Y + trojkaty[ i ].GetSize()*1.71/2 - (pieciokaty[ j ].getPeakPoint().Y -5)) < 20 )
				return false;
	}
	if ( typ == "rectangle" )
	{
		for ( int j = 0; j < trojkaty.size(); ++j )
			if ( prostokaty[ i ].GetStartPointY() + prostokaty[ i ].GetHeight() > trojkaty[ j ].getPeakPoint().Y 
					&& prostokaty[ i ].GetStartPointX() < trojkaty[ j ].getPeakPoint().X + trojkaty[ j ].GetSize()/2
					&& prostokaty[ i ].GetStartPointX() + prostokaty[ i ].GetWidth() > trojkaty[ j ].getPeakPoint().X - trojkaty[ j ].GetSize()/2
					&& (prostokaty[ i ].GetStartPointY() + prostokaty[ i ].GetHeight() - (trojkaty[ j ].getPeakPoint().Y)) < 20 )
				return false;
		for ( int j = 0; j < prostokaty.size(); ++j )
			if ( i != j && prostokaty[ i ].GetStartPointY() + prostokaty[ i ].GetHeight() > prostokaty[ j ].GetStartPointY()
					&& prostokaty[ i ].GetStartPointX() < prostokaty[ j ].GetStartPointX() + prostokaty[ j ].GetWidth()
					&& prostokaty[ i ].GetStartPointX() + prostokaty[ i ].GetWidth() > prostokaty[ j ].GetStartPointX() 
					&& (prostokaty[ i ].GetStartPointY() + prostokaty[ i ].GetHeight() - (prostokaty[ j ].GetStartPointY())) < 20)
				return false;
		for ( int j = 0; j < kola.size(); ++j )
			if ( prostokaty[ i ].GetStartPointY() + prostokaty[ i ].GetHeight() > kola[ j ].GetStartPointY()
					&& prostokaty[ i ].GetStartPointX() < kola[ j ].GetStartPointX() + kola[ j ].GetWidth()
					&& prostokaty[ i ].GetStartPointX() + prostokaty[ i ].GetWidth() > kola[ j ].GetStartPointX()
					&& (prostokaty[ i ].GetStartPointY() + prostokaty[ i ].GetHeight() - (kola[ j ].GetStartPointY())) < 20)
				return false;
		for ( int j = 0; j < pieciokaty.size(); ++j )
			if ( prostokaty[ i ].GetStartPointY() + prostokaty[ i ].GetHeight() > pieciokaty[ j ].getPeakPoint().Y 
					&& prostokaty[ i ].GetStartPointX() < pieciokaty[ j ].getPeakPoint().X + pieciokaty[ j ].GetWidth()/2
					&& prostokaty[ i ].GetStartPointX() + prostokaty[ i ].GetWidth() > pieciokaty[ j ].getPeakPoint().X - pieciokaty[ j ].GetWidth()/2 
					&& (prostokaty[ i ].GetStartPointY() + prostokaty[ i ].GetHeight() - (pieciokaty[ j ].getPeakPoint().Y)) < 20)
				return false;
	}
	if ( typ == "ellipse" )
	{
		for ( int j = 0; j < trojkaty.size(); ++j )
			if ( kola[ i ].GetStartPointY() + kola[ i ].GetHeight() > trojkaty[ j ].getPeakPoint().Y 
					&& kola[ i ].GetStartPointX() < trojkaty[ j ].getPeakPoint().X + trojkaty[ j ].GetSize()/2
					&& kola[ i ].GetStartPointX() + kola[ i ].GetWidth() > trojkaty[ j ].getPeakPoint().X - trojkaty[ j ].GetSize()/2 
					&& (kola[ i ].GetStartPointY() + kola[ i ].GetHeight() - (trojkaty[ j ].getPeakPoint().Y)) < 20)
				return false;
		for ( int j = 0; j < prostokaty.size(); ++j )
			if ( kola[ i ].GetStartPointY() + kola[ i ].GetHeight() > prostokaty[ j ].GetStartPointY()
					&& kola[ i ].GetStartPointX() < prostokaty[ j ].GetStartPointX() + prostokaty[ j ].GetWidth()
					&& kola[ i ].GetStartPointX() + kola[ i ].GetWidth() > prostokaty[ j ].GetStartPointX() 
					&& (kola[ i ].GetStartPointY() + kola[ i ].GetHeight() - (prostokaty[ j ].GetStartPointY())) < 20)
				return false;
		for ( int j = 0; j < kola.size(); ++j )
			if ( (i != j) && kola[ i ].GetStartPointY() + kola[ i ].GetHeight() > kola[ j ].GetStartPointY()
					&& kola[ i ].GetStartPointX() < kola[ j ].GetStartPointX() + kola[ j ].GetWidth()
					&& kola[ i ].GetStartPointX() + kola[ i ].GetWidth() > kola[ j ].GetStartPointX() 
					&& (kola[ i ].GetStartPointY() + kola[ i ].GetHeight() - (kola[ j ].GetStartPointY())) < 20)
				return false;
		for ( int j = 0; j < pieciokaty.size(); ++j )
			if ( kola[ i ].GetStartPointY() + kola[ i ].GetHeight() > pieciokaty[ j ].getPeakPoint().Y 
					&& kola[ i ].GetStartPointX() < pieciokaty[ j ].getPeakPoint().X + pieciokaty[ j ].GetWidth()/2
					&& kola[ i ].GetStartPointX() + kola[ i ].GetWidth() > pieciokaty[ j ].getPeakPoint().X - pieciokaty[ j ].GetWidth()/2 
					&& (kola[ i ].GetStartPointY() + kola[ i ].GetHeight() - (pieciokaty[ j ].getPeakPoint().Y)) < 20)
				return false;
	}
	if ( typ == "pentagon" )
	{
		for ( int j = 0; j < trojkaty.size(); ++j )
			if ( pieciokaty[ i ].getPeakPoint().Y + pieciokaty[ i ].GetHeight() > trojkaty[ j ].getPeakPoint().Y 
					&& pieciokaty[ i ].getPeakPoint().X - pieciokaty[ i ].GetWidth()/2 < trojkaty[ j ].getPeakPoint().X + trojkaty[ j ].GetSize()/2
					&& pieciokaty[ i ].getPeakPoint().X + pieciokaty[ i ].GetWidth()/2 > trojkaty[ j ].getPeakPoint().X - trojkaty[ j ].GetSize()/2 
					&& (pieciokaty[ i ].getPeakPoint().Y + trojkaty[ i ].GetSize()*1.71/2 - (trojkaty[ j ].getPeakPoint().Y -5)) < 20)
				return false;
		for ( int j = 0; j < prostokaty.size(); ++j )
			if ( pieciokaty[ i ].getPeakPoint().Y + pieciokaty[ i ].GetHeight() > prostokaty[ j ].GetStartPointY()
					&& pieciokaty[ i ].getPeakPoint().X - pieciokaty[ i ].GetWidth()/2 < prostokaty[ j ].GetStartPointX() + prostokaty[ j ].GetWidth()
					&& pieciokaty[ i ].getPeakPoint().X + pieciokaty[ i ].GetWidth()/2 > prostokaty[ j ].GetStartPointX() 
					&& (pieciokaty[ i ].getPeakPoint().Y + trojkaty[ i ].GetSize()*1.71/2 - (prostokaty[ j ].GetStartPointY())) < 20)
				return false;
		for ( int j = 0; j < kola.size(); ++j )
			if ( pieciokaty[ i ].getPeakPoint().Y + pieciokaty[ i ].GetHeight() > kola[ j ].GetStartPointY()
					&& pieciokaty[ i ].getPeakPoint().X - pieciokaty[ i ].GetWidth()/2 < kola[ j ].GetStartPointX() + kola[ j ].GetWidth()
					&& pieciokaty[ i ].getPeakPoint().X + pieciokaty[ i ].GetWidth()/2 > kola[ j ].GetStartPointX() 
					&& (pieciokaty[ i ].getPeakPoint().Y + trojkaty[ i ].GetSize()*1.71/2 - (kola[ j ].GetStartPointY())) < 20)
				return false;
		for ( int j = 0; j < pieciokaty.size(); ++j )
			if ( (i != j) && pieciokaty[ i ].getPeakPoint().Y + pieciokaty[ i ].GetHeight() > pieciokaty[ j ].getPeakPoint().Y 
					&& pieciokaty[ i ].getPeakPoint().X - pieciokaty[ i ].GetWidth()/2 < pieciokaty[ j ].getPeakPoint().X + pieciokaty[ j ].GetWidth()/2
					&& pieciokaty[ i ].getPeakPoint().X + pieciokaty[ i ].GetWidth()/2 > pieciokaty[ j ].getPeakPoint().X - pieciokaty[ j ].GetWidth()/2
					&& (pieciokaty[ i ].getPeakPoint().Y + trojkaty[ i ].GetSize()*1.71/2 - (pieciokaty[ j ].getPeakPoint().Y -5)) < 20)
				return false;
	}
	return true;
}

void ObjectFall( HWND hWnd, HDC hdc )
{
	/*Dzia�anie funkcji:
	1. Bada, czy wszystkie obiekty spad�y juz na ziemi�, b�d� na inne figury
	2. Je�eli nie, to dzia�a jak grawitacja i �ci�ga je w d�
	*/
	int controlCount = 0;
	for ( int i = 0; i < trojkaty.size(); ++i )
		if ( (i != (Hak.Attached - 1)) && (trojkaty[ i ].getPeakPoint().Y < 615) && NoFallCollision( i, "triangle" ) )
		{
			trojkaty[ i ].SetParameters( trojkaty[ i ].getPeakPoint().X, trojkaty[ i ].getPeakPoint().Y + 5, trojkaty[ i ].GetSize() );	
			controlCount = 0;
		}
		else
			++controlCount;
	for ( int i = 0; i < prostokaty.size(); ++i )
		if ( prostokaty[ i ].GetStartPointY() + prostokaty[ i ].GetHeight() < 680 && NoFallCollision( i, "rectangle" ) )
		{
			prostokaty[ i ].SetParameters( prostokaty[ i ].GetStartPointX(), prostokaty[ i ].GetStartPointY() + 5, 
											prostokaty[ i ].GetWidth(), prostokaty[ i ].GetHeight() );	
			controlCount = 0;
		}
		else
			++controlCount;
	for ( int i = 0; i < kola.size(); ++i )
		if ( kola[ i ].GetStartPointY() + kola[ i ].GetHeight() < 680 && NoFallCollision( i, "ellipse" ) )
		{
			kola[ i ].SetParameters( kola[ i ].GetStartPointX(), kola[ i ].GetStartPointY() + 5, 
											kola[ i ].GetWidth(), kola[ i ].GetHeight() );	
			controlCount = 0;
		}
		else
			++controlCount;
	for ( int i = 0; i < pieciokaty.size(); ++i )
		if ( pieciokaty[ i ].getPeakPoint().Y < 580 && NoFallCollision( i, "pentagon" ) )
		{
			pieciokaty[ i ].SetParameters( pieciokaty[ i ].getPeakPoint().X, pieciokaty[ i ].getPeakPoint().Y + 5, 60 );	
			controlCount = 0;
		}
		else
			++controlCount;
	MyOnPaint( hdc );
	
	if ( controlCount  == trojkaty.size() + prostokaty.size() + kola.size() + pieciokaty.size() )
		KillTimer( hWnd, TMR_1 );
}

void TowerControl( HWND hWnd, HDC hdc )
{
	/*Dzia�anie funkcji:
	1.Bada, czy gdzie� nie powsta�a wie�a z 3 tr�jk�t�w
	2.Je�li tak sie sta�o, to ostatni element przemieszcza w pocz�tek uk�adu
	*/
	for ( int i = 0; i < trojkaty.size(); ++i )
		for ( int j = 0; j < trojkaty.size(); ++j )
			if ( i !=j && ( trojkaty[ j ].getPeakPoint().X - trojkaty[ j ].GetSize()/2 < trojkaty[ i ].getPeakPoint().X + trojkaty[ i ].GetSize()/2
				&& trojkaty[ j ].getPeakPoint().X + trojkaty[ j ].GetSize()/2 > trojkaty[ i ].getPeakPoint().X - trojkaty[ i ].GetSize()/2 )
				&& trojkaty[ j ].getPeakPoint().Y < trojkaty[ i ].getPeakPoint().Y + trojkaty[ i ].GetSize()*1.71/2 +20
				&& trojkaty[ j ].getPeakPoint().Y > trojkaty[ i ].getPeakPoint().Y + trojkaty[ i ].GetSize()*1.71/2 -20 
				&& Hak.Attached == 0 )
				for ( int k = 0; k < trojkaty.size(); ++k )
					if ( k != j && k != i 
						&& ( trojkaty[ k ].getPeakPoint().X - trojkaty[ k ].GetSize()/2 < trojkaty[ j ].getPeakPoint().X + trojkaty[ j ].GetSize()/2
						&& trojkaty[ k ].getPeakPoint().X + trojkaty[ k ].GetSize()/2 > trojkaty[ j ].getPeakPoint().X - trojkaty[ j ].GetSize()/2 )
						&& trojkaty[ k ].getPeakPoint().Y < trojkaty[ j ].getPeakPoint().Y + trojkaty[ j ].GetSize()*1.71/2 +20
						&& trojkaty[ k ].getPeakPoint().Y > trojkaty[ j ].getPeakPoint().Y + trojkaty[ j ].GetSize()*1.71/2 -20 )
						for ( int m = 0; m < trojkaty.size(); ++m )
							if ( m != j && m != i && m != k 
								&& ( trojkaty[ m ].getPeakPoint().X - trojkaty[ m ].GetSize()/2 < trojkaty[ k ].getPeakPoint().X + trojkaty[ k ].GetSize()/2
								&& trojkaty[ m ].getPeakPoint().X + trojkaty[ m ].GetSize()/2 > trojkaty[ k ].getPeakPoint().X - trojkaty[ k ].GetSize()/2 )
								&& trojkaty[ m ].getPeakPoint().Y < trojkaty[ k ].getPeakPoint().Y + trojkaty[ k ].GetSize()*1.71/2 +20
								&& trojkaty[ m ].getPeakPoint().Y > trojkaty[ k ].getPeakPoint().Y + trojkaty[ k ].GetSize()*1.71/2 -20 )
							{
								trojkaty[ i ].SetParameters( 200, 100, trojkaty[ i ].GetSize() );
							}
	ObjectFall( hWnd, hdc );
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

   hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Add triangle"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		770, 10,                                  // the left and top co-ordinates
		100, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON1,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits

    hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Add rectangle"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		900, 10,                                  // the left and top co-ordinates
		100, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON2,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Add circle"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		1030, 10,                                  // the left and top co-ordinates
		100, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON3,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits

	hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
		TEXT("Add pentagon"),                  // the caption of the button
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
		1160, 10,                                  // the left and top co-ordinates
		100, 20,                              // width and height
		hWnd,                                 // parent window handle
		(HMENU)ID_BUTTON4,                   // the ID of your button
		hInstance,                            // the instance of your application
		NULL);                               // extra bits

   SetWindowText( hWnd, L"D�wig" ); //Set title

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
		case ID_BUTTON1:
			trojkat.SetParameters( 200 + ( 80*( trojkaty.size() + 1 ) )%800, 240, 80 );
			trojkaty.push_back( trojkat );
			InvalidateRect(hWnd, &drawArea, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			SetTimer( hWnd, TMR_1, 10, 0 );
			MyOnPaint( hdc );
			EndPaint(hWnd, &ps);
			SetFocus( hWnd );
			break;
		case ID_BUTTON2:
			prostokat.SetParameters( 400 + ( 100*( prostokaty.size() + 1 ) )%800, 240, 50, 75 );
			prostokaty.push_back( prostokat );
			InvalidateRect(hWnd, &drawArea, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			SetTimer( hWnd, TMR_1, 10, 0 );
			MyOnPaint( hdc );
			EndPaint(hWnd, &ps);
			SetFocus( hWnd );
			break;
		case ID_BUTTON3:
			kolo.SetParameters( 450 + ( 100*( kola.size() + 1 ) )%800, 240, 50, 75 );
			kola.push_back( kolo );
			InvalidateRect(hWnd, &drawArea, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			SetTimer( hWnd, TMR_1, 10, 0 );
			MyOnPaint( hdc );
			EndPaint(hWnd, &ps);
			SetFocus( hWnd );
			break;
		case ID_BUTTON4:
			pieciokat.SetParameters( 250 + ( 100*( pieciokaty.size() + 1 ) )%800, 240, 60 );
			pieciokaty.push_back( pieciokat );
			InvalidateRect(hWnd, &drawArea, TRUE);
			hdc = BeginPaint(hWnd, &ps);
			SetTimer( hWnd, TMR_1, 10, 0 );
			MyOnPaint( hdc );
			EndPaint(hWnd, &ps);
			SetFocus( hWnd );
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		/*Dzia�anie:
			1.Pocz�tkowe malowanie, w tym d�wigu
		*/
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
				/*Dzia�anie
					1. Uruchamia grawitacj�
					2. Uruchamia sprawdzanie wie�y
				*/
				InvalidateRect(hWnd, &drawArea, TRUE);
				hdc = BeginPaint(hWnd, &ps);
				ObjectFall( hWnd, hdc );
				TowerControl( hWnd, hdc );
				EndPaint(hWnd, &ps);
			break;
		}

	case WM_KEYDOWN:
		// TODO: Add any drawing code here...
			switch( (int)wParam )
			{
			case VK_DOWN:
				/*Dzia�anie:
				1. Przesuwa hak w d�
				2. Jak hak jest aktywny i natrafi na tr�jk�t, to przyczepia obiekt do haka
				3. Je�li co� jest przyczepione do haka, to przesuwa to razem z nim
				*/
				if ( Hak.Active && !Hak.Attached )
					for ( int i = 0; i < trojkaty.size(); ++i )
					{
						if ( trojkaty[ i ].getPeakPoint().Y > Hak.getUpperY() && trojkaty[ i ].getPeakPoint().Y < Hak.getBottomY()
							&& trojkaty[ i ].getPeakPoint().X > Hak.getLeftX() && trojkaty[ i ].getPeakPoint().X < Hak.getRightX() )
						{
							Hak.Attached = i+1;
						}
					}
				if ( Hak.Attached )
					{
						trojkaty[ Hak.Attached -1 ].SetParameters( trojkaty[ Hak.Attached -1 ].getPeakPoint().X, 
							trojkaty[ Hak.Attached -1 ].getPeakPoint().Y + 5, trojkaty[ Hak.Attached -1 ].GetSize() );
						Hak.mooveHook( 0, 5 );
						SetTimer( hWnd, TMR_1, 10, 0 );
					}
					else
						Hak.mooveHook( 0, 5 );
				break;
			case VK_UP:
				/*Dzia�anie:
				1. Przesuwa hak w g�r�
				2. Jak hak jest aktywny i natrafi na tr�jk�t, to przyczepia obiekt do haka
				3. Je�li co� jest przyczepione do haka, to przesuwa to razem z nim
				*/
				if ( Hak.Active && !Hak.Attached )
					for ( int i = 0; i < trojkaty.size(); ++i )
					{
						if ( trojkaty[ i ].getPeakPoint().Y > Hak.getUpperY() && trojkaty[ i ].getPeakPoint().Y < Hak.getBottomY()
							&& trojkaty[ i ].getPeakPoint().X > Hak.getLeftX() && trojkaty[ i ].getPeakPoint().X < Hak.getRightX() )
						{
							Hak.Attached = i+1;
						}
					}
				if ( Hak.Attached && Hak.getUpperY() > 63)
				{
					trojkaty[ Hak.Attached -1 ].SetParameters( trojkaty[ Hak.Attached -1 ].getPeakPoint().X, 
						trojkaty[ Hak.Attached -1 ].getPeakPoint().Y - 5, trojkaty[ Hak.Attached -1 ].GetSize() );
					Hak.mooveHook( 0, -5 );
					SetTimer( hWnd, TMR_1, 10, 0 );
				}
				else
					Hak.mooveHook( 0, -5 );
				break;
			case VK_LEFT:
				/*Dzia�anie:
				1. Przesuwa hak w lewo
				2. Jak hak jest aktywny i natrafi na tr�jk�t, to przyczepia obiekt do haka
				3. Je�li co� jest przyczepione do haka, to przesuwa to razem z nim
				*/
				if ( Hak.Active && !Hak.Attached )
					for ( int i = 0; i < trojkaty.size(); ++i )
					{
						if ( trojkaty[ i ].getPeakPoint().Y > Hak.getUpperY() && trojkaty[ i ].getPeakPoint().Y < Hak.getBottomY()
							&& trojkaty[ i ].getPeakPoint().X > Hak.getLeftX() && trojkaty[ i ].getPeakPoint().X < Hak.getRightX() )
						{
							Hak.Attached = i+1;
						}
					}
				if( Hak.Attached && Hak.getLeftX() > 149 )
				{
					trojkaty[ Hak.Attached -1 ].SetParameters( trojkaty[ Hak.Attached -1 ].getPeakPoint().X - 5,
						trojkaty[ Hak.Attached -1 ].getPeakPoint().Y, trojkaty[ Hak.Attached -1 ].GetSize() ); 
					Hak.mooveHook( -5, 0 );
					SetTimer( hWnd, TMR_1, 10, 0 );
				}
				else
					Hak.mooveHook( -5, 0 );
				break;
			case VK_RIGHT:
				/*Dzia�anie:
				1. Przesuwa hak w prawo
				2. Jak hak jest aktywny i natrafi na tr�jk�t, to przyczepia obiekt do haka
				3. Je�li co� jest przyczepione do haka, to przesuwa to razem z nim
				*/
				if ( Hak.Active && !Hak.Attached )
					for ( int i = 0; i < trojkaty.size(); ++i )
					{
						if ( trojkaty[ i ].getPeakPoint().Y > Hak.getUpperY() && trojkaty[ i ].getPeakPoint().Y < Hak.getBottomY()
							&& trojkaty[ i ].getPeakPoint().X > Hak.getLeftX() && trojkaty[ i ].getPeakPoint().X < Hak.getRightX() )
						{
							Hak.Attached = i+1;
						}
					}
				if ( Hak.Attached && Hak.getRightX() < 1329 )
				{
					trojkaty[ Hak.Attached -1 ].SetParameters( trojkaty[ Hak.Attached -1 ].getPeakPoint().X + 5,
						trojkaty[ Hak.Attached -1 ].getPeakPoint().Y, trojkaty[ Hak.Attached -1 ].GetSize() ); 
					Hak.mooveHook( 5, 0 );
					SetTimer( hWnd, TMR_1, 10, 0 );
				}
				else
					Hak.mooveHook( 5, 0 );
				break;
			case VK_RETURN: 
				/*Dzia�anie:
					1. Odczepia obiekt od haka
					2. Dezaktywuje hak
					3. Uruchamia timer
				*/
				Hak.Attached = 0;
				Hak.Active = false;
				SetTimer( hWnd, TMR_1, 10, 0 );
				break;
			case VK_SPACE:
				/*Dzia�anie: 
					1. Uaktywnia hak
				*/
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

