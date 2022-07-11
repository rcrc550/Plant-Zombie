#pragma once
#include"sys.h"
#include"Corse_all.h"
class Cor_box
{
public:
	Cor_box(void);
	~Cor_box(void);
public:
	list<Corse_all*>m_cbox;
public:
	 void All_cormove();
	 void All_corshow(HDC hdc);
	 void Create_cor(HINSTANCE hinstance);
	 void hit_flower();
	 void Boxhit_ms(msbox *ms1);
	 void Boxhit_fl(flbox *ms1);
	 void Boxhit_wd(wdbox *ms1);
};

