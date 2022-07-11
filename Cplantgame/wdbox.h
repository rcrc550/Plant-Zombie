#pragma once
#include"wd.h"
class wdbox
{
public:
	wdbox(void);
	~wdbox(void);
public:
	list<wd*>m_wbox;
public:
	void Createwd(HINSTANCE hi,int x1,int y1);
	void Allwd_show(HDC hdc);
	void All_sendshot(HINSTANCE hinstance,shotbox &c_box);
	
};

