#include "wdbox.h"


wdbox::wdbox(void)
{
}


wdbox::~wdbox(void)
{
	list<wd*>::iterator ite=m_wbox.begin();
	while(ite!=m_wbox.end())
	{
		delete(*ite);
		++ite;
	}
}
void wdbox::Createwd(HINSTANCE hi,int x1,int y1)
{
	wd *c_wd=new wd;
	c_wd->Init_wd(hi,x1,y1);
	m_wbox.push_back(c_wd);


}
void wdbox::Allwd_show(HDC hdc)
{
	list<wd*>::iterator ite=m_wbox.begin();
	 while(ite!=m_wbox.end())
	 {
		 (*ite)->show_wd(hdc);
		 ++ite;
	 }


}
void wdbox::All_sendshot(HINSTANCE hinstance,shotbox &c_box)
{
	list<wd*>::iterator ite=m_wbox.begin();
	 while(ite!=m_wbox.end())
	 {
		 (*ite)->send_shot(hinstance,c_box);
		 ++ite;
	 }


}