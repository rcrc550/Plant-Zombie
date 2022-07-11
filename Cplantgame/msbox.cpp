#include "msbox.h"


msbox::msbox(void)
{
}


msbox::~msbox(void)
{
	list<ms*>::iterator ite=c_mbox.begin();
	while(ite!=c_mbox.end())
	{
		delete(*ite);
		++ite;
	}
}

void msbox::Allms_show(HDC hdc)
{	 
	list<ms*>::iterator ite=c_mbox.begin();
	while(ite!=c_mbox.end())
	{
		(*ite)->show_ms(hdc);
		++ite;
	}


}	 
void msbox::Allms_create(HINSTANCE hi,int x1,int y1)
{
     
	ms *c_ms=new ms;
	c_ms->Init_ms(hi,x1,y1);
	c_mbox.push_back(c_ms);

}