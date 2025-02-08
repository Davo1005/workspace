#include "include.h"

int n,i=0;

Book * arr = NULL;

int main()
{
	cout<< "Size of array of books: ";
	cin >> n;
	arr = new Book[n];
	add_book();
	add_book();
	search_system();
	print_books();	
	delete[] arr;
}

