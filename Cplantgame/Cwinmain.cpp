#include <windows.h>
#include"Cgameapp.h"
#include<time.h>
LRESULT CALLBACK WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
HINSTANCE hIns = 0;

int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR lpCmdLine,int nShowCmd)
{
	srand((unsigned int)time(0));
	//-----------------------------------------------------
	HWND hwnd = 0;
	MSG msg;       //  装消息的结构体
	WNDCLASSEX wndclass;
	//-----------------------------------------------------
	
	hIns = hInstance;

	//----------------------创建窗口过程-----------------------------------
	//  1. 设计
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wndclass.hCursor = LoadCursor(0,MAKEINTRESOURCE(IDC_ARROW));
	wndclass.hIcon = 0;
	wndclass.hIconSm = 0;
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WindowProc;
	wndclass.lpszClassName = "lele";
	wndclass.lpszMenuName = 0;
	wndclass.style = CS_HREDRAW|CS_VREDRAW;
	// 2.  注册
	if(RegisterClassEx(&wndclass) == FALSE)
	{
		MessageBox(0,"注册失败","提示",MB_OK);
		return 0;
	}
	//  3.  创建
	hwnd = CreateWindow("lele","龙少版植物大战僵尸",WS_OVERLAPPEDWINDOW,0,0,715,533,0,0,hInstance,0);
	if(hwnd == 0)
	{
		MessageBox(0,"创建失败","提示",MB_OK);
		return 0;	
	}
	//  4.  显示窗口
	ShowWindow(hwnd,SW_SHOW);
	//---------------------------创建窗口过程------------------------------------------------



	//----------------------------消息循环-------------------------------------------
	while(GetMessage(&msg,0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	//----------------------------消息循环-------------------------------------------

	return 0;
}

Cgameapp *tcs=0;
Cgameapp *Getojbectset();
//=================================处理消息========================================================
LRESULT CALLBACK WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	switch (uMsg)
	{
	
	case  WM_CREATE:
		tcs=Getojbectset();
		if(tcs!=0)
		{
		tcs->Sethandle(hwnd,hIns);   //设置句柄

		tcs->CreateGame();    //初始化游戏 加载资源
		}
		break;
	case WM_PAINT:
		if(tcs!=0)
		tcs->GameDraw();
		break;
	case WM_TIMER:
		if(tcs!=0)
			tcs->GameRun(wParam);
		break;
	case WM_KEYDOWN:
		if(tcs!=0)
		tcs->KeyDown(wParam);
		break;
	case WM_KEYUP:
		if(tcs!=0)
		tcs->KeyUp(wParam);
		break;
	case WM_LBUTTONUP:
		if(tcs!=0)
		{
         POINT point;
		 point.x=LOWORD(lParam);
		 point.y=HIWORD(lParam);
		tcs->ButtonUp(point);
		
		}break;
	case WM_LBUTTONDOWN:
		if(tcs!=0)
		{
         POINT point;
		 point.x=LOWORD(lParam);
		 point.y=HIWORD(lParam);
		 tcs->ButtonDown(point);	
		}
		break;
	case WM_MOUSEMOVE:
		if(tcs!=0)
	   {
		   POINT point;
		 point.x=LOWORD(lParam);
		 point.y=HIWORD(lParam);
	    tcs->MouseMove(point);
		}
		break;
    case WM_CLOSE:
		
		PostQuitMessage(0);
		if(tcs!=0)
		{
		delete tcs;
		tcs=0;
		}
		break;
	

	}

	return DefWindowProc( hwnd, uMsg, wParam, lParam);
}