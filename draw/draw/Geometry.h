#pragma once

#include "stdafx.h"

class RECTANGLE
{
private:
	int X;
	int Y;
	int width;
	int height;
	Color kolor;
	BOOL changePoint( int &przesuniecieX, int &przesuniecieY );
public:
	RECTANGLE();
	RECTANGLE( int poczatekX, int poczatekY, int szerokosc, int wysokosc );
	int drawRectangle( HDC hdc, int przesuniecieX, int przesuniecieY );
	int SetPenColor( int r, int g, int b );
	int SetParameters( int poczatekX, int poczatekY, int szerokosc, int wysokosc );
	int GetStartPointX();
	int GetStartPointY();
	int GetWidth();
	int GetHeight();
};

class TRIANGLE
{
private:
	PointF Points[ 3 ];
	int size;
	Color kolor;
	BOOL transferTriangle( int &przesuniecieX, int &przesuniecieY );
public:
	TRIANGLE();
	TRIANGLE( int szczytX, int szczytY, int krawedz );
	int drawTriangle( HDC hdc, int przesuniecieX, int przesuniecieY );
	int SetPenColor( int r, int g, int b );
	PointF getPeakPoint();
	int GetSize();
	int SetParameters( int peakX, int peakY, int size );
	bool partOfATower;
	bool lastOnTower;
};

class CRANE_HOOK
{
private:
	int HookX;
	int HookY;
	int HookWidth;
	int HookHeight;
	PointF LinePointCrane;
	PointF LinePointHook;
	Color kolor;
public:
	CRANE_HOOK();
	void mooveHook( int przesuniecieX, int przesuniecieY );
	void drawHook( HDC hdc );
	int getBottomY();
	int getUpperY();
	int getLeftX();
	int getRightX();
	bool Active;
	int Attached;
};

class ELLIPSE
{
private:
	int X;
	int Y;
	int width;
	int height;
	Color kolor;
	BOOL changePoint( int &przesuniecieX, int &przesuniecieY );
public:
	ELLIPSE();
	ELLIPSE( int poczatekX, int poczatekY, int szerokosc, int wysokosc );
	int drawEllipse( HDC hdc, int przesuniecieX, int przesuniecieY );
	int SetPenColor( int r, int g, int b );
	int SetParameters( int poczatekX, int poczatekY, int szerokosc, int wysokosc );
	int GetStartPointX();
	int GetStartPointY();
	int GetWidth();
	int GetHeight();
};

class PENTAGON
{
private:	
	PointF Points[ 5 ];
	int size;
	Color kolor;
	BOOL transferPentagon( int &przesuniecieX, int &przesuniecieY );
public:
	PENTAGON();
	PENTAGON( int szczytX, int szczytY, int krawedz );
	int drawPentagon( HDC hdc, int przesuniecieX, int przesuniecieY );
	int SetPenColor( int r, int g, int b );
	PointF getPeakPoint();
	int GetWidth();
	int GetHeight();
	int SetParameters( int peakX, int peakY, int size );
};

/*class HEXAGON
{
private:	
	PointF Points[ 6 ];
	int size;
	Color kolor;
	BOOL transferHexagon( int &przesuniecieX, int &przesuniecieY );
public:
	HEXAGON();
	HEXAGON( int szczytX, int szczytY, int krawedz );
	int drawHexagon( HDC hdc, int przesuniecieX, int przesuniecieY );
	int SetPenColor( int r, int g, int b );
	PointF getPeakPoint();
	int SetParameters( int peakX, int peakY, int size );	
};*/


void InitTriangles( std::vector< TRIANGLE > tablicaTrojkatow );
void InitRectangles( std::vector< RECTANGLE > tablicaProstokatow );
