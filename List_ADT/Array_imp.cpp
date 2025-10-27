#include <iostream>
using namespace std;

template <class T>
class list
{
	private:
		T *arr;
		int count;
		int size;
	public:
		list()
		{
			size=1;
			count=0;
			arr=new T[1];
		}
		list(T * dif, int tane)
		{
			size=tane;
			count=tane;
			arr=new T[size];
			for (int i=0; i<tane; i++)
			{
				arr[i]=dif[i];
			}
		}
		~list()
		{
			delete [] arr;
		}
		list(const list<T> &oth)
		{
			size=oth.size;
			count=oth.count;
			arr=new T [size];
                        for (int i=0; i<count; i++)
			{
				arr[i]=(oth.arr)[i];
                        }
		}
		list<T>& operator=(const list<T> &oth)
		{
			if (this!=&oth)
			{
				delete [] arr;
				this->size=oth.size;
				this->count=oth.count;
				arr=new T [size];
				for (int i=0; i<count; i++)
                                {
                                        arr[i]=(oth.arr)[i];
                                }
			}
			return *this;
		}

		T get(int index) // İndex'teki elemanı verir
		{
			if (index>=count)
			{
				cout<<"İndex dışı get isteği"<<endl;
			}
			return arr[index];
		}

		void set(T item,int index) // İndex'teki elemana item değeri atanır.
		{
			if (index==size)
			{
				cout<<"Kral bu set fonksiyonu"<<endl;
				cout<<"Add fonksiyonu hemen aşağıda"<<endl;
			}
			arr[index]=item;
		}

		void add(T item) // Listenin sonuna item eklenir.
		{
			if (count==size)
			{
				T *tmp=new T[size+1];
                                for (int i=0; i<count; i++)
                                {
                                        tmp[i]=arr[i];
                                }
                                delete [] arr;
                                arr=tmp;
				size++;
			}
			arr[count]=item;
			count++;
		}

                                

		void remove(int index) // index'teki elemanı siler.
		{
			int i;
                        T *tmp=new T[size];
                        for ( i=0; i<count; i++)
			{
				if(i==index)    {break;}
                                tmp[i]=arr[i];
			}
                        for ( i=index; i<size-1; i++)
			{
				tmp[i]=arr[i+1];
                        }
                        delete [] arr;
                        arr=tmp;
			count--;
		}

		int get_size()	{return size;}
		int get_count()	{return count;}

		void print() // Listenin elemanlarını sırayla ekrana basar
		{
			for(int i=0; i<count; i++)
			{
				cout<<i<<". Eleman-> "<<arr[i]<<endl;
			}
			cout<<"Listenin sonu"<<endl;
		}
};


