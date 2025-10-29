#include <iostream>
#define debug 0
using namespace std;

template <class T> class node;
template <class T>
class linked
{
	private:
		int count;
		node<T> * first;
	public:
		linked()
		{
			first=NULL;
			count=0;
		}
		linked(node<T> *nw)
		{
			first=nw;
			count=1;
		}
		
		T get(int index)
		{
			if (index>=count || index<0)		{throw "Ya çok büyük ya da negatif girmiþin kral";}
			node<T> *tmp=first;
			for(int i=0; i<index; i++)
			{
				tmp=tmp->next;
			}
			return tmp->stored;
		}
		
		void set(int index, T nw)
		{
			if (index>=count || index<0)		{throw "Ya çok büyük ya da negatif girmiþin kral";}
			node<T> *tmp=first;
			for(int i=0; i<index; i++)
			{
				tmp=tmp->next;
			}
			tmp->stored=nw;
		}
			
		node<T>* add(T nw)
		{
			count++;
			if (!first)
			{
				node<T> *nwptr=new node<T>;
				nwptr->next=NULL;
				nwptr->stored=nw;
				first=nwptr;
				return nwptr;
			}
			node<T> *tmp=first; 
			node<T> *nwptr=new node<T>;		nwptr->next=NULL;	nwptr->stored=nw; //Aslýnda bu üç satýr yerine node<T> * nwptr=new node<T>(nw,NULL); olurmuþ.
			for(;tmp->next ; tmp=tmp->next);
			tmp->next=nwptr;
			return nwptr;
		}
		
		node<T>* add(T nw,int index)
		{
			if (index>count || index<0)		{throw "Ya çok büyük ya da negatif girmiþin kral";}
			if (index==0)
			{
				node<T> * nwptr=new node<T>(nw,first);
				first=nwptr;
				count++;
				return nwptr;
			}
			node<T> *tmp=first;
			for(int i=0; i<index-1; i++,tmp=tmp->next); //tmp þu anda deðiþtirmek istediðimizin hemen öncesindeki
			node<T> * nwptr=new node<T>(nw,tmp->next);
			tmp->next=nwptr;
			count++;
			return nwptr;
		}
		
		void remove(int index)
		{
			if (index>=count || index<0)		{throw "Ya çok büyük ya da negatif girmiþin kral";}
			if(index==0)
			{
				node<T> *tmp=first->next;
				delete first;
				first=tmp;
				count--;
				return;
			}
			node<T> *rmv=first;
			node<T> *tmp;
			for(int i=0; i<index-1 ; i++, rmv=rmv->next); //rmv þu anda silinecek olandan bir öncekine point ediyor
			tmp=rmv->next;
			rmv->next=rmv->next->next;
			delete tmp;
			count--;
			return;
		}
		
		int get_size() {return count;}
		
		void print()
		{
			if(!first)
			{
				cout<<"Ýçim dýþým boþluk, uzay mýyým neyim?"<<endl;
				return;
			}
			node<T> *tmp=first;
			cout<<"Hacý sýrayla elemanlarý yazýyorum:"<<endl;
			for(; tmp; tmp=tmp->next)
			{
				cout<<tmp->stored<<endl;
			}
			cout<<"Bu hikaye de burada biter";
		}
};




template <class T>
class node
{
	private:
		T stored;
		node *next;
	public:
		template <class U> friend class linked;
		node(T new_val, node * nptr)
		{
			stored=new_val;
			next=nptr;
		}
		node()
		{
			next=NULL;
		}
		
		T get_val()		{return stored;}
		node * get_next()	{return next;}
		void set_val(T nw) {stored=nw;}
		void set_next(node * nw) {next=nw;}
};


int main()
{
	if (debug==1)
	{
		node<int> *m2=new node<int>;
		node<int> *m1=new node<int>;
		m2->set_val(2);
		m2->set_next(m1);
		m1->set_next(m2);
		m1->set_val(1);
		node<int> *ptr=m1;
		for (int i=0; i<4; i++)
		{
			cout<<"Þimdi sana ne vereceðim-> "<<ptr->get_val()<<endl;
			ptr=(ptr->get_next());
		}
		delete m1;
		delete m2;
	}
	if (debug==2)
	{
		node<int> m2;
		node<int> m1;
		m2.set_val(2);
		m2.set_next(&m1);
		m1.set_next(&m2);
		m1.set_val(1);
		node<int> *ptr=&m1;
		for (int i=0; i<4; i++)
		{
			cout<<"Þimdi sana ne vereceðim-> "<<ptr->get_val()<<endl;
			ptr=(ptr->get_next());
		}
	}
	
}
