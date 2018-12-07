//Project:	CIS023_F2018_Lab20b Tom Chaparas
//Module:	LinkedListClass.h
//Author:	Tom Chaparas	
//Date:		December 3, 2018
//Purpose:	Header File for LinkedListClass.cpp

#pragma once
class LinkedListClass
{
public:
	LinkedListClass();
	~LinkedListClass();

	void Add(HWND);						// append a Ball to the list
	void Delete();						// delete the currentBall
	void First();						// make currentBall the 1st ball in the list
	void Next();						// advance currentBall to next ball in list

    BallClass* GetFirstBall();
	BallClass* GetCurrentBall();
	void SetCurrentBall(BallClass*);

private:
    BallClass* firstBall;				// first node in list
    BallClass* lastBall;				// last node in list
    BallClass* currentBall;				// current node

};

