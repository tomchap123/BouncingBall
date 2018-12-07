//Project:	CIS023_F2018_HW20 Tom Chaparas
//Module:	BallClass.cpp
//Author:	Tom Chaparas	
//Date:		December 9, 2018
//Purpose:	Header File for BallClass.h

#include "stdafx.h"
#include "BallClass.h"

BallClass::BallClass()
{
}

BallClass::BallClass(HWND hWnd)
{
    //get client window dimensions
    RECT rClient;							//client window
    GetClientRect(hWnd, &rClient);			//get window dimensions
    //POINT pCenter;
    POINT pStartLocation;

    pStartLocation.x = rClient.top;
    pStartLocation.y = rClient.left;
   // pCenter.x = rClient.right / 2;			//find horizontal center
    //pCenter.y = rClient.bottom / 2;			//find Vertical center
    int iSize = GetRandomInt(5, 10);


    rDim.left = pStartLocation.x - iSize;      
    //rDim.right = pStartLocation.x + iSize;     
    rDim.top = pStartLocation.y - iSize;         
    //rDim.bottom = pStartLocation.y + iSize;      

    //rDim.left = pCenter.x - iSize;			//place star in the middle of window
    //rDim.right = pCenter.x + iSize;
    //rDim.top = pCenter.y - iSize;
    //rDim.bottom = pCenter.y + iSize;

    r = GetRandomInt(0, 255);			//red
    b = GetRandomInt(0, 255);			//blue
    g = GetRandomInt(0, 255);			//green

    pSpeed.x = GetRandomInt(-10, 10);	//set speed and direction horizontal
    pSpeed.y = GetRandomInt(-10, 10);	//vertical

    iFrame = 0;							//initialize frame number
}

BallClass::~BallClass()
{
}

BallClass * BallClass::GetNextBall()
{
    return nextBall;
}

BallClass * BallClass::GetPrevBall()
{
    return prevBall;
}

void BallClass::SetNextBall(BallClass* ball)
{
    nextBall = ball;
}

void BallClass::SetPrevBall(BallClass * ball)
{

    prevBall = ball;
}

void BallClass::Draw(HDC hdc)
{

    //create brushes
    HBRUSH brush = CreateSolidBrush(RGB(r, g, b));
    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

    //draw various shapes
    //FillRect(hdc, &rDim, brush);
    Ellipse(hdc, rDim.left, rDim.top, rDim.right, rDim.bottom);  


    SelectObject(hdc, oldBrush);					//return to original brush
    DeleteObject(brush);							//throw away brush
}

bool BallClass::Move(HWND hWnd)
{
    int x_Direction = 1 * 1;
    int y_Direction = 1 * 1;

    //should we make the star bigger?
    if (iFrame++ % 1 == 0)
    {
        rDim.right++;
        rDim.bottom++;
    }

    rDim.left += pSpeed.x;				//move horizontal
    rDim.right += pSpeed.x;
    rDim.top += pSpeed.y;				//move vertical
    rDim.bottom += pSpeed.y;

    //get client rectangle
    RECT rClient;
    GetClientRect(hWnd, &rClient);

    //if ball hits the edge of the client rect, delete it
    if (rDim.left < 0 ||
        rDim.top < 0 ||
        rDim.right > rClient.right ||
        rDim.bottom > rClient.bottom)
        return false;

    return true;				//keep moving
}

RECT BallClass::GetInvalidateRect()
{
    rReturn = rDim;						//initially the shape of the ball

    if (pSpeed.x < 0)
        rReturn.right -= pSpeed.x;
    if (pSpeed.x > 0)
        rReturn.left -= pSpeed.x;
    if (pSpeed.y < 0)
        rReturn.bottom -= pSpeed.y;
    if (pSpeed.y > 0)
        rReturn.top -= pSpeed.y;

    return rReturn;
}

int BallClass::GetRandomInt(int iLow, int iHigh)
{
    random_device rd;			//non-deterministic generator
    mt19937 gen(rd());			//seed mersenne twister
    uniform_int_distribution<>    dist(iLow, iHigh);


    return dist(gen);			//return random #
}

