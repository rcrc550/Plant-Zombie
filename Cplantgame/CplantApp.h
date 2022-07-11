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
	virtual void  GameRun(WPARAM ntimeid);    //定时器编号
	virtual void  ButtonDown(POINT point);  //需要一个坐标点 坐标点是通过LPARAM获取的 
	virtual void  ButtonUp(POINT point);    //需要一个坐标点 坐标点是通过LPARAM获取的
	virtual void  GameDraw();           //需要hwnd窗口
public:
	void shothitcor();
	void changeid();
};

