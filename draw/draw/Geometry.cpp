#include "stdafx.h"

RECTANGLE::RECTANGLE()
{
	X = 100;
	Y = 100;
	width = 100;
	height = 100;
	kolor = Color( 255,123,0,255 );
}

RECTANGLE::RECTANGLE( int poczatekx, int poczateky, int szerokosc, int wysokosc )
{
	X = poczatekx;
	Y = poczateky;
	width = szerokosc;
	height = wysokosc;
	kolor = Color( 255,123,0,255 );
}

int RECTANGLE::drawRectangle( HDC hdc, int przesuniecieX, int przesuniecieY )
{
	Graphics graphics(hdc);
	Pen pen( kolor );
	changePoint( przesuniecieX, przesuniecieY );
	graphics.DrawRectangle( &pen, X, Y, width, height );
	return 0;
}

int RECTANGLE::SetPenColor( int r, int g, int b )
{
	kolor = Color( r, g, b );
	return 0;
}

int RECTANGLE::SetParameters( int poczatekX, int poczatekY, int szerokosc, int wysokosc )
{
	X = poczatekX;
	Y = poczatekY;
	width = szerokosc;
	height = wysokosc;
	return 0;
}

int RECTANGLE::GetStartPointX()
{
	return X;
}

int RECTANGLE::GetStartPointY()
{
	return Y;
}

int RECTANGLE::GetWidth()
{
	return width;
}

int RECTANGLE::GetHeight()
{
	return height;
}

BOOL RECTANGLE::changePoint( int &przesuniecieX, int &przesuniecieY )
{
	X += przesuniecieX;
	Y += przesuniecieY;
	return 0;
}

TRIANGLE::TRIANGLE()
{
	size = 80;
	Points[ 0 ].X = 100;
	Points[ 0 ].Y = 700;
	Points[ 1 ].X = 100 + 80/2;
	Points[ 1 ].Y = 700 + 1.71*80/2;
	Points[ 2 ].X = 100 - 80/2;
	Points[ 2 ].Y = 700 + 1.71*80/2;
	kolor = Color( 255,123,0,255 );
}

TRIANGLE::TRIANGLE( int szczytX, int szczytY, int krawedz )
{
	size = krawedz;
	Points[ 0 ].X = szczytX;
	Points[ 0 ].Y = szczytY;
	Points[ 1 ].X = szczytX + krawedz/2;
	Points[ 1 ].Y = szczytY + 1.71*krawedz/2;
	Points[ 2 ].X = szczytX - krawedz/2;
	Points[ 2 ].Y = szczytY + 1.71*krawedz/2;
	kolor = Color( 255,123,0,255 );
}


int TRIANGLE::drawTriangle( HDC hdc, int przesuniecieX, int przesuniecieY )
{
	Graphics graphics(hdc);
	Pen pen( kolor );
	transferTriangle( przesuniecieX, przesuniecieY );
	graphics.DrawPolygon( &pen, Points, 3 );
	return 0;
}

int TRIANGLE::SetPenColor( int r, int g, int b )
{
	kolor = Color( r, g, b );
	return 0;
}

PointF TRIANGLE::getPeakPoint()
{
	return Points[ 0 ];
}

int TRIANGLE::SetParameters( int szczytX, int szczytY, int krawedz )
{
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
	Graphics graphics(hdc);
	Pen pen( kolor );
	graphics.DrawLine( &pen, LinePointCrane, LinePointHook );
	graphics.DrawRectangle( &pen, HookX, HookY, HookWidth, HookHeight );
}

int CRANE_HOOK::getBottomY()
{
	return HookY + HookHeight;
}

int CRANE_HOOK::getUpperY()
{
	return HookY;
}

int CRANE_HOOK::getLeftX()
{
	return HookX;
}

int CRANE_HOOK::getRightX()
{
	return HookX + HookWidth;
}

void InitTriangles( std::vector < TRIANGLE > tablicaTrojkatow )
{
	for ( int i = 0; i < tablicaTrojkatow.size(); ++i )
		tablicaTrojkatow[ i ].SetParameters( 200 + 80*i, 610, 80 );
}

void InitRectangles( std::vector < RECTANGLE > tablicaProstokatow )
{
	for ( int i = 0; i < tablicaProstokatow.size(); ++i )
		tablicaProstokatow[ i ].SetParameters( 520 + 150*i, 580, 80, 100 );
}