#include "include.h"

void print_books()
{
	for(int j=0;j<i;j++)
	{
		cout <<  " " << arr[j].title << " "
             << arr[j].author << " "
             << arr[j].isbn << " "
             << (arr[j].available ? "HASANELI E" : "ANHASANELI E")
             << endl;
	}
}

void print_books(int index)
{
	cout <<  " " << arr[index].title << " "
             << arr[index].author << " "
             << arr[index].isbn << " "
             << (arr[index].available ? "HASANELI E" : "ANHASANELI E")
             << endl;

}
