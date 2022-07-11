#pragma once
#include"shot.h"
class shotbox
{
public:
	shotbox(void);
	~shotbox(void);
public:
	list<shot*>c_shotbox;
public:
	void Allshot_move();
	void Allshot_show(HDC hdc);

};

