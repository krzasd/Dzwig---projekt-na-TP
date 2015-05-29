#include "stdafx.h"

RECTANGLE::RECTANGLE()
{
	/*Dzia�anie funkcji:
	1. Konstruktor domy�lny
	*/
	X = 100;
	Y = 100;
	width = 100;
	height = 100;
	kolor = Color( 255,123,0,255 );
}

RECTANGLE::RECTANGLE( int poczatekx, int poczateky, int szerokosc, int wysokosc )
{
	/*Dzia�anie funkcji:
	1. Konstruktor
	*/
	X = poczatekx;
	Y = poczateky;
	width = szerokosc;
	height = wysokosc;
	kolor = Color( 255,123,0,255 );
}

int RECTANGLE::drawRectangle( HDC hdc, int przesuniecieX, int przesuniecieY )
{
	/*Dzia�anie funkcji:
	1. Rysuje prostok�t
	*/
	Graphics graphics(hdc);
	Pen pen( kolor );
	changePoint( przesuniecieX, przesuniecieY );
	graphics.DrawRectangle( &pen, X, Y, width, height );
	return 0;
}

int RECTANGLE::SetPenColor( int r, int g, int b )
{
	/*Dzia�anie funkcji:
	1. Ustawia kolor obiektu
	*/
	kolor = Color( r, g, b );
	return 0;
}

int RECTANGLE::SetParameters( int poczatekX, int poczatekY, int szerokosc, int wysokosc )
{
	/*Dzia�anie funkcji:
	1. Zmienia parametry obiektu
	*/
	X = poczatekX;
	Y = poczatekY;
	width = szerokosc;
	height = wysokosc;
	return 0;
}

int RECTANGLE::GetStartPointX()
{
	/*Dzia�anie funkcji:
	1. Zwraca startowy punkt X
	*/
	return X;
}

int RECTANGLE::GetStartPointY()
{
	/*Dzia�anie funkcji:
	1. Zwraca startowy punkt Y
	*/
	return Y;
}

int RECTANGLE::GetWidth()
{
	/*Dzia�anie funkcji:
	1. Zwraca szeroko��
	*/
	return width;
}

int RECTANGLE::GetHeight()
{
	/*Dzia�anie funkcji:
	1. Zwraca wysoko��
	*/
	return height;
}

BOOL RECTANGLE::changePoint( int &przesuniecieX, int &przesuniecieY )
{
	/*Dzia�anie funkcji:
	1. Zmiania punkt startowy
	*/
	X += przesuniecieX;
	Y += przesuniecieY;
	return 0;
}

TRIANGLE::TRIANGLE()
{
	/*Dzia�anie funkcji:
	1. Konstruktor domy�lny
	*/
	size = 80;
	Points[ 0 ].X = 100;
	Points[ 0 ].Y = 700;
	Points[ 1 ].X = 100 + 80/2;
	Points[ 1 ].Y = 700 + 1.71*80/2;
	Points[ 2 ].X = 100 - 80/2;
	Points[ 2 ].Y = 700 + 1.71*80/2;
	kolor = Color( 255,123,0,255 );
	partOfATower = false;
	lastOnTower = false;
}

TRIANGLE::TRIANGLE( int szczytX, int szczytY, int krawedz )
{
	/*Dzia�anie funkcji:
	1. Konstruktor
	*/
	size = krawedz;
	Points[ 0 ].X = szczytX;
	Points[ 0 ].Y = szczytY;
	Points[ 1 ].X = szczytX + krawedz/2;
	Points[ 1 ].Y = szczytY + 1.71*krawedz/2;
	Points[ 2 ].X = szczytX - krawedz/2;
	Points[ 2 ].Y = szczytY + 1.71*krawedz/2;
	kolor = Color( 255,123,0,255 );
	partOfATower = false;
	lastOnTower = false;
}


int TRIANGLE::drawTriangle( HDC hdc, int przesuniecieX, int przesuniecieY )
{
	/*Dzia�anie funkcji:
	1. Rysuje tr�jk�t
	*/
	Graphics graphics(hdc);
	Pen pen( kolor );
	transferTriangle( przesuniecieX, przesuniecieY );
	graphics.DrawPolygon( &pen, Points, 3 );
	return 0;
}

int TRIANGLE::SetPenColor( int r, int g, int b )
{
	/*Dzia�anie funkcji:
	1. Ustawia kolor
	*/
	kolor = Color( r, g, b );
	return 0;
}

PointF TRIANGLE::getPeakPoint()
{
	/*Dzia�anie funkcji:
	1. Zwraca szczyt
	*/
	return Points[ 0 ];
}

int TRIANGLE::GetSize()
{
	/*Dzia�anie funkcji:
	1. Zwraca rozmiar kraw�dzi
	*/
	return size;
}

int TRIANGLE::SetParameters( int szczytX, int szczytY, int krawedz )
{
	/*Dzia�anie funkcji:
	1. Ustawia parametry obiektu
	*/
	size = krawedz;
	Points[ 0 ].X = szczytX;
	Points[ 0 ].Y = szczytY;
	Points[ 1 ].X = szczytX + krawedz/2;
	Points[ 1 ].Y = szczytY + 1.71*krawedz/2;
	Points[ 2 ].X = szczytX - krawedz/2;
	Points[ 2 ].Y = szczytY + 1.71*krawedz/2;
	return 0;
}

BOOL TRIANGLE::transferTriangle( int &przesuniecieX, int &przesuniecieY )
{
	/*Dzia�anie funkcji:
	1. Zmienia po�o�enie punkt�w tr�jk�ta
	*/
	Points[ 0 ].X += przesuniecieX;
	Points[ 0 ].Y += przesuniecieY;
	Points[ 1 ].X += przesuniecieX;
	Points[ 1 ].Y += przesuniecieY;
	Points[ 2 ].X += przesuniecieX;
	Points[ 2 ].Y += przesuniecieY;
	return 0;
}

CRANE_HOOK::CRANE_HOOK()
{
	/*Dzia�anie funkcji:
	1. Konstruktor domy�lny
	*/
	HookX = 145;
	HookY = 59;
	HookWidth = 20;
	HookHeight = 50;
	LinePointCrane.X = 155;
	LinePointCrane.Y = 59;
	LinePointHook.X = 155;
	LinePointHook.Y = 59;
	kolor = Color( 0, 255, 0 );
	Active = false;
	Attached = false;
}

void CRANE_HOOK::mooveHook( int przesuniecieX, int przesuniecieY )
{
	/*Dzia�anie funkcji:
	1. Przemieszcza hak
	*/
	if ( HookX + przesuniecieX >= 145 && HookY + przesuniecieY >= 59 && HookX + przesuniecieX <= 1310 )
	{
		HookX += przesuniecieX;
		HookY += przesuniecieY;
		LinePointCrane.X += przesuniecieX;
		LinePointHook.X += przesuniecieX;
		LinePointHook.Y += przesuniecieY;
	}
}

void CRANE_HOOK::drawHook( HDC hdc )
{
	/*Dzia�anie funkcji:
	1. Rysuje hak
	*/
	Graphics graphics(hdc);
	Pen pen( kolor );
	graphics.DrawLine( &pen, LinePointCrane, LinePointHook );
	graphics.DrawRectangle( &pen, HookX, HookY, HookWidth, HookHeight );
}

int CRANE_HOOK::getBottomY()
{
	/*Dzia�anie funkcji:
	1. Zwraca doln� kraw�d� haku
	*/
	return HookY + HookHeight;
}

int CRANE_HOOK::getUpperY()
{
	/*Dzia�anie funkcji:
	1. Zwraca g�rna kraw�d� haku
	*/
	return HookY;
}

int CRANE_HOOK::getLeftX()
{
	/*Dzia�anie funkcji:
	1. Zwraca lew� kraw�d� haku
	*/
	return HookX;
}

int CRANE_HOOK::getRightX()
{
	/*Dzia�anie funkcji:
	1. Zwraca praw� kraw�d� haku
	*/
	return HookX + HookWidth;
}

ELLIPSE::ELLIPSE()
{
	/*Dzia�anie funkcji:
	1. Konstruktor domy�lny
	*/
	X = 100;
	Y = 100;
	width = 100;
	height = 100;
	kolor = Color( 255,123,0,255 );
}

ELLIPSE::ELLIPSE( int poczatekx, int poczateky, int szerokosc, int wysokosc )
{
	/*Dzia�anie funkcji:
	1. Konstruktor
	*/
	X = poczatekx;
	Y = poczateky;
	width = szerokosc;
	height = wysokosc;
	kolor = Color( 255,123,0,255 );
}

int ELLIPSE::drawEllipse( HDC hdc, int przesuniecieX, int przesuniecieY )
{
	/*Dzia�anie funkcji:
	1.Rysuje elips�
	*/
	Graphics graphics(hdc);
	Pen pen( kolor );
	changePoint( przesuniecieX, przesuniecieY );
	graphics.DrawEllipse( &pen, X, Y, width, height );
	return 0;
}

int ELLIPSE::SetPenColor( int r, int g, int b )
{
	/*Dzia�anie funkcji:
	1.Ustawia kolor obiektu
	*/
	kolor = Color( r, g, b );
	return 0;
}

int ELLIPSE::SetParameters( int poczatekX, int poczatekY, int szerokosc, int wysokosc )
{
	/*Dzia�anie funkcji:
	1. Zmienia parametry
	*/
	X = poczatekX;
	Y = poczatekY;
	width = szerokosc;
	height = wysokosc;
	return 0;
}

int ELLIPSE::GetStartPointX()
{
	/*Dzia�anie funkcji:
	1. Zwraca punktu startowego X
	*/
	return X;
}

int ELLIPSE::GetStartPointY()
{
	/*Dzia�anie funkcji:
	1. Zwraca punktu startowego Y
	*/
	return Y;
}

int ELLIPSE::GetWidth()
{
	/*Dzia�anie funkcji:
	1.Zwraca szeroko��
	*/
	return width;
}

int ELLIPSE::GetHeight()
{
	/*Dzia�anie funkcji:
	1. Zwraca wysoko��
	*/
	return height;
}

BOOL ELLIPSE::changePoint( int& przesuniecieX, int& przesuniecieY )
{
	/*Dzia�anie funkcji:
	1. Zmienia punkt startowy
	*/
	X += przesuniecieX;
	Y += przesuniecieY;
	return 0;
}

PENTAGON::PENTAGON()
{
	/*Dzia�anie funkcji:
	1. Konstruktor domy�lny
	*/
	size = 60;
	Points[ 0 ].X = 100;
	Points[ 0 ].Y = 700;
	Points[ 1 ].X = 100 + 1.41*60/2;
	Points[ 1 ].Y = 700 + 1.41*60/2;
	Points[ 2 ].X = 100 + 1.41*60/2;
	Points[ 2 ].Y = 760 + 1.41*60/2;
	Points[ 3 ].X = 100 - 1.41*60/2;
	Points[ 3 ].Y = 760 + 1.41*60/2;
	Points[ 4 ].X = 100 - 1.41*60/2;
	Points[ 4 ].Y = 700 + 1.41*60/2;
	kolor = Color( 255,123,0,255 );
}

PENTAGON::PENTAGON( int szczytX, int szczytY, int krawedz )
{
	/*Dzia�anie funkcji:
	1. Konstruktor
	*/
	size = krawedz;
	Points[ 0 ].X = szczytX;
	Points[ 0 ].Y = szczytY;
	Points[ 1 ].X = szczytX + 1.41*krawedz/2;
	Points[ 1 ].Y = szczytY + 1.41*krawedz/2;
	Points[ 2 ].X = szczytX + 1.41*krawedz/2;
	Points[ 2 ].Y = szczytY + 3.41*krawedz/2;
	Points[ 3 ].X = szczytX - 1.41*krawedz/2;
	Points[ 3 ].Y = szczytY + 3.41*krawedz/2;
	Points[ 4 ].X = szczytX - 1.41*krawedz/2;
	Points[ 4 ].Y = szczytY + 1.41*krawedz/2;
	kolor = Color( 255,123,0,255 );
}

int PENTAGON::drawPentagon( HDC hdc, int przesuniecieX, int przesuniecieY )
{
	/*Dzia�anie funkcji:
	1. Rysuje pi�ciok�t
	*/
	Graphics graphics(hdc);
	Pen pen( kolor );
	transferPentagon( przesuniecieX, przesuniecieY );
	graphics.DrawPolygon( &pen, Points, 5 );
	return 0;
}

int PENTAGON::SetPenColor( int r, int g, int b )
{
	/*Dzia�anie funkcji:
	1. Zmienia kolor
	*/
	kolor = Color( r, g, b );
	return 0;
}

PointF PENTAGON::getPeakPoint()
{
	/*Dzia�anie funkcji:
	1. Zwraca punkt szczytowy
	*/
	return Points[ 0 ];
}

int PENTAGON::SetParameters( int szczytX, int szczytY, int krawedz )
{
	/*Dzia�anie funkcji:
	1. Zmienia parametry
	*/
	size = krawedz;
	Points[ 0 ].X = szczytX;
	Points[ 0 ].Y = szczytY;
	Points[ 1 ].X = szczytX + 1.41*krawedz/2;
	Points[ 1 ].Y = szczytY + 1.41*krawedz/2;
	Points[ 2 ].X = szczytX + 1.41*krawedz/2;
	Points[ 2 ].Y = szczytY + 3.41*krawedz/2;
	Points[ 3 ].X = szczytX - 1.41*krawedz/2;
	Points[ 3 ].Y = szczytY + 3.41*krawedz/2;
	Points[ 4 ].X = szczytX - 1.41*krawedz/2;
	Points[ 4 ].Y = szczytY + 1.41*krawedz/2;
	return 0;
}

int PENTAGON::GetWidth()
{
	/*Dzia�anie funkcji:
	1. Zwraca szeroko��
	*/
	return Points[ 1 ].X - Points[ 4 ].X;
}

int PENTAGON::GetHeight()
{
	/*Dzia�anie funkcji:
	1. Zwraca wysoko��
	*/
	return Points[ 2 ].Y - Points[ 0 ].Y; 
}

BOOL PENTAGON::transferPentagon( int &przesuniecieX, int &przesuniecieY )
{
	/*Dzia�anie funkcji:
	1. Przemieszcza pi�ciok�t
	*/
	Points[ 0 ].X += przesuniecieX;
	Points[ 0 ].Y += przesuniecieY;
	Points[ 1 ].X += przesuniecieX;
	Points[ 1 ].Y += przesuniecieY;
	Points[ 2 ].X += przesuniecieX;
	Points[ 2 ].Y += przesuniecieY;
	Points[ 3 ].X += przesuniecieX;
	Points[ 3 ].Y += przesuniecieY;
	Points[ 4 ].X += przesuniecieX;
	Points[ 4 ].Y += przesuniecieY;
	return 0;
}
