#pragma once
#include"ms.h"
class msbox
{
public:
	msbox(void);
	~msbox(void);
public:
	list<ms*>c_mbox;
public:
	void Allms_show(HDC hdc);
	void Allms_create(HINSTANCE hi,int x1,int y1);
};

