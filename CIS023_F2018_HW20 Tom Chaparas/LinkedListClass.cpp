//Project:	CIS023_F2018_Lab20b Tom Chaparas
//Module:	LinkedListClass.cpp
//Author:	Tom Chaparas	
//Date:		December 3, 2018
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
    BallClass* newBall = new BallClass(hWnd);	// create new Ball of type BallClass

	newBall->SetNextBall(nullptr);
	newBall->SetPrevBall(lastBall);

	if (firstBall == nullptr)
		firstBall = newBall;
	else
		lastBall->SetNextBall(newBall);		// old bottom Ball points to new Ball

	lastBall = newBall;						// append new Ball to bottom of list
}

void LinkedListClass::Delete()
{
	BallClass* tempBall = new BallClass;
	tempBall = currentBall;

	if (currentBall == firstBall)			// special consideration for 1st node
	{
		firstBall = currentBall->GetNextBall();
		firstBall->SetPrevBall(nullptr);
        currentBall = firstBall;

	}
	else if (currentBall == lastBall)		// special consideration for last node
	{
		lastBall = currentBall->GetPrevBall();
		lastBall->SetNextBall(nullptr);
		currentBall = lastBall;
	}
	else									// node in the middle of the list
	{
		currentBall->GetPrevBall()->SetNextBall(currentBall->GetNextBall());
		currentBall->GetNextBall()->SetPrevBall(currentBall->GetPrevBall());

		currentBall = currentBall->GetNextBall();
	}
	delete tempBall;
}

void LinkedListClass::First()
{
	currentBall = firstBall;
}

void LinkedListClass::Next()
{
	currentBall = currentBall->GetNextBall();
}

BallClass * LinkedListClass::GetFirstBall()
{
	return firstBall;
}

BallClass * LinkedListClass::GetCurrentBall()
{
	return currentBall;
}

void LinkedListClass::SetCurrentBall(BallClass * inBall)
{
	currentBall = inBall;
}
