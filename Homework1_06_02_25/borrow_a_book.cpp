#include "include.h"

void borrow_a_book()
{
	int index;
	cout << "Enter an index of the book: ";
	cin >> index;
	if(index < i)
	{
		if(arr[index].available == true )
		{
			arr[index].available = false;
			cout << "The book rezerved for you ";
			return;
		}
		cout << "The book borrowed";
		return;
	}
	else
	{
		cout << "The index is not valid";
	}
		
	

}
