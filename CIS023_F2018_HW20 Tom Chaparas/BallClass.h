//Project:	CIS023_F2018_HW20 Tom Chaparas
//Module:	BallClass.h
//Author:	Tom Chaparas	
//Date:		December 9, 2018
//Purpose:	Header File for BallClass.cpp

#pragma once
class BallClass
{
public:
    BallClass();
    BallClass(HWND);				// override constructor
    ~BallClass();

    BallClass* GetNextBall();		// movement along linked list
    BallClass* GetPrevBall();
    void SetNextBall(BallClass*);
    void SetPrevBall(BallClass*);

    void Draw(HDC);					//answer WM_PAINT message
    bool Move(HWND);
    RECT GetInvalidateRect();		//for more accurate InvalidateRect()

private:
    RECT rDim;						//dimensions of ball
    RECT rReturn;
    POINT pSpeed;					//speed and direction
    int r, g, b;					//red, green ,blue values 0-255
    int iFrame;						//number of movements

    BallClass* nextBall;			// pointer to next node in list
    BallClass* prevBall;			// pointer to previous node in list

    int GetRandomInt(int, int);		//generate random # in range
};


