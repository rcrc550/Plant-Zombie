#pragma once
#include"die_cor.h"
class die_box
{
public:
	die_box(void);
	~die_box(void);
public:
	list<die_cor*>m_fbox;
public:
	void Create_die(HINSTANCE hi,int x1,int y1);
	void Allfl_show(HDC hdc);
	void Change_showid();
};

