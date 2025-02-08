#include "include.h"

void return_a_book()
{
	int index;
	cout << "Entern the index of the book that you wont to return: ";
	cin >> index;
	if(index < i && arr[index].available ==false)
	{
		 arr[index].available =true;
		 cout << "The book returned";
	}
	else
	{
		cout << "Invalid index";
	}
}
