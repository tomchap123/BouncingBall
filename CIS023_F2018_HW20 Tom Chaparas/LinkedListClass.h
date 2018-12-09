//Project:	CIS023_F2018_Lab20b Tom Chaparas
//Module:	LinkedListClass.h
//Author:	Tom Chaparas	
//Date:		December 9, 2018
//Purpose:	Header File for LinkedListClass.cpp

#pragma once
class LinkedListClass
{
public:
	LinkedListClass();
	~LinkedListClass();

	void Add(HWND);						// append a Ball to the list
	BallClass *Delete(BallClass*);		// delete the currentBall
    BallClass* GetFirstBall();
	

private:
    BallClass* firstBall;				// first node in list
    BallClass* lastBall;				// last node in list
    BallClass* currentBall;				// current node

};

