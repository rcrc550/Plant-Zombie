#pragma once
#include<windows.h>
#define DELARE(THISCLASS)\
Cgameapp *Getojbectset()\
{\
	return new THISCLASS;\
}
class Cgameapp
{
protected:
	HWND m_hwnd;
	HINSTANCE m_hinstance;
public:
	Cgameapp()
    {
		m_hwnd=0;
	
		m_hinstance=0;

	}
	virtual ~Cgameapp()
	{

	}
public:
	void Sethandle(HWND hwnd,HINSTANCE hinstance)
	{
		m_hwnd=hwnd;
		m_hinstance=hinstance;
	}
public:
	
	virtual void  CreateGame(){}
	virtual void  GameRun(WPARAM ntimeid){}     //定时器编号
	virtual void  ButtonDown(POINT point){}     //需要一个坐标点 坐标点是通过LPARAM获取的 
	virtual void  ButtonUp(POINT point){}       //需要一个坐标点 坐标点是通过LPARAM获取的
	virtual void  GameDraw(){}                  //需要hwnd窗口
	virtual void  KeyDown(WPARAM nkey){}        //具体按键 
	virtual void  KeyUp(WPARAM nkey ){}         //具体按键
	virtual void  MouseMove(POINT point){}      //需要一个坐标点 坐标点是通过LPARAM获取的



};