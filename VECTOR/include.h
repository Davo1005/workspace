#include <iostream>
using namespace std;

class vector
{
	private:
		int* data;
		int size;
		int cap;
	void v_raelloc(int new_cap)
	{
		int* new_data = new int[new_cap];
		for(int i=0;i<size;i++)
		{
			new_data[i] = data[i];
		}
		delete[] data;
		data=new_data;		
		new_data=nullptr;
	}
	public:
		vector():size(),cap(0),data(nullptr){}
		vector(int tmp_size):size(0), cap(tmp_size)
		{
			data = new int[size];
		}
		~vector()
		{
			delete[] data;
		}
		int v_at(int index) const 
		{
			if(index>=0 && index<size)
			{
				return data[index];	
			}
			cout << "INVALID INDEX ERROR";
			return -1;
		}
		void v_push_back(int value)
		{
			if(size == cap)
			{
				v_raelloc(cap*2);
			}
			data[size++]=value;
		}
		void v_pop_back()
		{
			if(size == 0)
			{
				return;
			}
			--size;
		}
		int v_getsize()const
		{
			return size;
		}
		int v_getcap()const
		{
			return cap;
		}
		void v_resize(int tmp_size)
		{
			if(tmp_size>=0)
			{
				size=tmp_size;
			}
		}
		void v_reserve(int tmp_cap)
		{
			if(tmp_cap>=0)
			{
				cap=tmp_cap;
			}
		}
		int v_fornt()const
		{
			return data[0];
		}
		int v_back() const 
		{
			return data[size-1];
		}
		bool v_isEmpty()const
		{
			return size;
		}
		void v_shrink_to_fit()
		{
			 v_raelloc(size);
		}
		void v_insert( int index, int value)
		{
			if(index < 0 || index>size)
			{
				cout<< "INVALID INDEX";
				return;
			}
			if(size == cap)
			{
				 v_raelloc(2*cap);
			}
			for(int i=size-1;i>=index;i++)
			{
				 data[i+1]=data[i];
			}
			data[index]=value;
			size++;		

		}
		void v_erase(int index)
		{
			if(index<size&& index >=0)
			{
				for(int i=index;i<size;i++)
				{
					data[i]=data[i+1];
				}
				size--;
			}
			else
			{
				cout<< "INVALID INDEX";
				return;
			}
		}
		void clear()
		{
			size=0;
		}



};
