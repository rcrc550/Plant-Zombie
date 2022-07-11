#include "Cor_box.h"
#include"C_cor1.h"
#include"C_cor2.h"
#include"C_cor3.h"

Cor_box::Cor_box(void)
{
}


Cor_box::~Cor_box(void)
{
	list<Corse_all*>::iterator ite=m_cbox.begin();
	 while(ite!=m_cbox.end())
	 {
		 delete(*ite);
		 ++ite;
	 }
}
 void Cor_box::All_cormove()
 {
	 list<Corse_all*>::iterator ite=m_cbox.begin();
	 while(ite!=m_cbox.end())
	 {
		 if((*ite)->x<=0)
		 {
			 delete(*ite);
			 ite=m_cbox.erase(ite);
		 }
		 else
		 {
		  (*ite)->C_move();
		   ++ite;
		 }
	 }
	 

 }
 void Cor_box::All_corshow(HDC hdc)
 {
	 list<Corse_all*>::iterator ite=m_cbox.begin();
	 while(ite!=m_cbox.end())
	 {
		 (*ite)->show_cor(hdc);
		 ++ite;
	 }



 }
 void Cor_box::Create_cor(HINSTANCE hinstance)
 {
	 Corse_all *co=0;
	 int index=rand()%3;
	 if(index==1)
		 co=new C_cor1;
	 else if(index==0)
		 co=new C_cor3;
	 else 
		 co=new C_cor2;
	 co->Init_corse(hinstance);
	 m_cbox.push_back(co);

 }
 void Cor_box::Boxhit_ms(msbox *ms1)
{
	list<Corse_all*>::iterator ite=this->m_cbox.begin();
	while(ite!=this->m_cbox.end())
	{
		(*ite)->Hit_ms(ms1);
		++ite;
	}
}
void Cor_box::Boxhit_fl(flbox *ms1)
{
	list<Corse_all*>::iterator ite=this->m_cbox.begin();
	while(ite!=this->m_cbox.end())
	{
		(*ite)->Hit_flower(ms1);
		++ite;
	}
}
void Cor_box::Boxhit_wd(wdbox *ms1)
{
	list<Corse_all*>::iterator ite=this->m_cbox.begin();
	while(ite!=this->m_cbox.end())
	{
		(*ite)->Hit_wd(ms1);
		++ite;
	}
}