#pragma once
#include"fl.h"
class flbox
{
public:
	flbox(void);
	~flbox(void);
public:
	list<fl*>m_fbox;
public:
	void Create_fl(HINSTANCE hi,int x1,int y1);
	void Allfl_show(HDC hdc);
};

