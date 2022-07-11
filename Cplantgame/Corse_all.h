#pragma once
#include"sys.h"
#include"wdbox.h"
#include"flbox.h"
#include "shot.h"
#include"msbox.h"
class Corse_all
{
public:
	Corse_all(void);
	virtual ~Corse_all(void);
public:
	HBITMAP m_corpse;
	int id;
	int x;
	int y;
	int xl;
	int z;
public:
	virtual void Hit_flower(flbox &m_fl){};
	virtual void Hit_wd(wdbox &wd){};
	virtual void C_move(){};
    virtual void Init_corse(HINSTANCE hi){};
	virtual bool Is_shot(shot *c_shot){ return true;};
	virtual void show_cor(HDC hdc){};
	virtual void Hit_flower(flbox *m_fl){};
	virtual void  Hit_wd(wdbox *wd){};
	virtual void  Hit_ms(msbox *ms){};
public:
	void Down_xl();
	bool Cor_die();
	
	


};

