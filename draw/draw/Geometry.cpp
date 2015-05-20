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

TRIANGLE::~TRIANGLE()
{
	delete this;
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
	LinePointHook.Y = 109;
}


/*
PENTAGON::PENTAGON()
{
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

PENTAGON::~PENTAGON()
{
	delete this;
}

int PENTAGON::drawPentagon( HDC hdc, int przesuniecieX, int przesuniecieY )
{
	Graphics graphics(hdc);
	Pen pen( kolor );
	transferPentagon( przesuniecieX, przesuniecieY );
	graphics.DrawPolygon( &pen, Points, 5 );
	return 0;
}

int PENTAGON::SetPenColor( int r, int g, int b )
{
	kolor = Color( r, g, b );
	return 0;
}

PointF PENTAGON::getPeakPoint()
{
	return Points[ 0 ];
}

int PENTAGON::SetParameters( int szczytX, int szczytY, int krawedz )
{
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

BOOL PENTAGON::transferPentagon( int &przesuniecieX, int &przesuniecieY )
{
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
} */

void InitTriangles( TRIANGLE* tablicaTrojkatow )
{
	for ( int i = 0; i < ILOSC_TROJKATOW; ++i )
	{
		tablicaTrojkatow[ i ].SetParameters( 200 + 80*i, 610, 80 );
	}
}



void InitRectangles( RECTANGLE* tablicaProstokatow )
{
	for ( int i = 0; i < ILOSC_PROSTOKATOW; ++i )
	{
		tablicaProstokatow[ i ].SetParameters( 440 + 150*i, 580, 80, 100 );
	}
}


void InitPentagons( PENTAGON* tablicaPieciakatow )
{
	for ( int i = 0; i < ILOSC_PIECIAKOTOW; ++i )
	{
		tablicaPieciokatow[ i ].SetParameters( 200 + 80*i, 610, 80 );
	}
}
