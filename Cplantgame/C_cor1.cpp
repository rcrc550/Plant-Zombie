#include "C_cor1.h"


C_cor1::C_cor1(void)
{

	xl=4;
	id=0;
	x=715;
	z=(rand()%(404-72))%83;
	y=72+z*83;

}


C_cor1::~C_cor1(void)
{
}
void C_cor1::C_move()
{
	x-=0.7;


}
void C_cor1::Init_corse(HINSTANCE hi)
{
	m_corpse=::LoadBitmap(hi,MAKEINTRESOURCE(m_ys));
	if((this->y)>=(533-83))
	{
		(this->y)-=83;
	}

}
void C_cor1::show_cor(HDC hdc)
{
	HDC hmedc=::CreateCompatibleDC(hdc);
	::SelectObject(hmedc,m_corpse);
	::BitBlt(hdc,x,y,66,83,hmedc,0,0,SRCCOPY);
	::DeleteDC(hmedc);
}
void C_cor1::Hit_flower(flbox *m_fl)
 {

	 list<fl*>::iterator ite=m_fl->m_fbox.begin();
	 while(ite!=m_fl->m_fbox.end())
	 {
		 if((((*ite)->x+69)>=this->x)&&(((((*ite)->y-82)<=this->y)&&((*ite)->y>this->y))||((((*ite)->y+82)>=this->y)&&((*ite)->y<this->y))))
		 {
			 delete(*ite);
			 ite=m_fl->m_fbox.erase(ite);
		 }
		 if(ite!=m_fl->m_fbox.end())
			 ite++;
	 }

	
 }
 void C_cor1::Hit_wd(wdbox *wd1)
 {
	 list<wd*>::iterator ite=wd1->m_wbox.begin();
	 while(ite!=wd1->m_wbox.end())
	 {
		 if((((*ite)->x+71)>=this->x)&&(((((*ite)->y-78)<=this->y)&&((*ite)->y>this->y))||((((*ite)->y+78)>=this->y)&&((*ite)->y<this->y))))
		 {
			 delete(*ite);
			 ite=wd1->m_wbox.erase(ite);
		 }
		 if(ite!=wd1->m_wbox.end())
			 ite++;
	 }
	 
 }
 void  C_cor1::Hit_ms(msbox *ms1)
 {
	

	 list<ms*>::iterator ite=ms1->c_mbox.begin();
	 while(ite!=ms1->c_mbox.end())
	 {
		 if((((*ite)->x+72)>=this->x)&&(((((*ite)->y-77)<=this->y)&&((*ite)->y>this->y))||((((*ite)->y+77>=this->y)&&((*ite)->y<this->y)))))
		 {
			this->x=this->x+30;
		 }
		 if(ite!=ms1->c_mbox.end())
			 ite++;
	 }
 }
 
 bool C_cor1::Is_shot(shot *c_shot)
 {
	 if(((c_shot->x+66)>=this->x)&&((((c_shot->y-85)<=this->y)&&(c_shot->y>this->y))||(((c_shot->y+85)>=this->y)&&(c_shot->y<this->y))))
		 return true;
	 return false;
 }
