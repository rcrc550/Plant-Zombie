#pragma once
#include "corse_all.h"

class C_cor3 :
	public Corse_all
{
public:
	C_cor3(void);
	~C_cor3(void);
public:
	virtual void Hit_flower(flbox *m_fl);
	virtual void  Hit_wd(wdbox *wd);
	virtual bool Is_shot(shot *c_shot);
	virtual void C_move();
	virtual void Init_corse(HINSTANCE hi);
	virtual void  Hit_ms(msbox *ms);
	virtual void show_cor(HDC hdc);
};

