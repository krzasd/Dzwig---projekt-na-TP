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
	~TRIANGLE();
	int drawTriangle( HDC hdc, int przesuniecieX, int przesuniecieY );
	int SetPenColor( int r, int g, int b );
	PointF getPeakPoint();
	int SetParameters( int peakX, int peakY, int size );
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
public:
	CRANE_HOOK();
};

void InitTriangles( TRIANGLE* tablicaTrojkatow );
void InitRectangles( RECTANGLE* tablicaProstokatow );
