#pragma once
#include "cgameapp.h"
#include "sys.h"
#include"Cback.h"
#include"Cor_box.h"
#include"msbox.h"
#include"shotbox.h"
#include"wdbox.h"
#include"flbox.h"
#include"die_box.h"
class CplantApp :
	public Cgameapp
{
public:
	CplantApp(void);
	~CplantApp(void);
public:
	Cback m_back;
	Cor_box c_box;
	flbox c_fl;
	msbox c_ms;
	wdbox c_wd;
	shotbox c_shot;
	die_box d_box;
	int myid;
	int itid;
	
public:
	virtual void  CreateGame();
	virtual void  GameRun(WPARAM ntimeid);    //��ʱ�����
	virtual void  ButtonDown(POINT point);  //��Ҫһ������� �������ͨ��LPARAM��ȡ�� 
	virtual void  ButtonUp(POINT point);    //��Ҫһ������� �������ͨ��LPARAM��ȡ��
	virtual void  GameDraw();           //��Ҫhwnd����
public:
	void shothitcor();
	void changeid();
};

