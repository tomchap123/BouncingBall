//Project:	CIS023_F2018_Lab20b Tom Chaparas
//Module:	LinkedListClass.cpp
//Author:	Tom Chaparas	
//Date:		December 9, 2018
//Purpose:	Implementation File for LinkedListClass.h

#include "stdafx.h"
#include "LinkedListClass.h"


LinkedListClass::LinkedListClass()
{
	firstBall = nullptr;
	lastBall = nullptr;
	currentBall = nullptr;
}

LinkedListClass::~LinkedListClass()
{
	while (firstBall != nullptr)
	{
        BallClass* tempBall = new BallClass;
		tempBall = firstBall;
		firstBall = firstBall->GetNextBall();
		delete tempBall;
	}
}
// add a new ball to the end of the list
void LinkedListClass::Add(HWND hWnd)
{
    BallClass *node = new BallClass(hWnd);	// create new Ball

    if (firstBall == NULL)
    {
        firstBall = lastBall = node;
    }
    else
    {
        lastBall->SetNextBall(node);        //old ball point to new ball
        node->SetPrevBall(lastBall);
        lastBall = node;                    //append new ball to bottom of list
    }      
}

BallClass *LinkedListClass::Delete(BallClass *ball)
{
	BallClass* tempBall = ball;
	
   // if (ball == NULL)
   //     throw std::runtime_error("current ball cannot be null");

    if (ball == firstBall)
    {
        if (ball->GetNextBall() != NULL)
        {
            firstBall = ball->GetNextBall();
            firstBall->SetPrevBall(NULL);
            ball = firstBall;
            if (ball->GetNextBall() == NULL) {
                lastBall = firstBall;
            }
        }
        else
        {
            firstBall = NULL;
            lastBall = NULL;
            ball = NULL;
        }
    }
    else if(ball == lastBall)
    {
        lastBall = lastBall->GetPrevBall();
        lastBall->SetNextBall(NULL);
        ball = NULL;
    }
    else
    {
        ball->GetPrevBall()->SetNextBall(ball->GetNextBall());
        ball->GetNextBall()->SetPrevBall(ball->GetPrevBall());
        ball = ball->GetNextBall();
    }
    delete tempBall;

    return ball;
}

BallClass * LinkedListClass::GetFirstBall()
{
	return firstBall;
}



