#include "include.h"

using namespace std;


void add_book()
{
    Book new_book; 
    if(i==n)
    {
	    arr = (Book * )realloc(arr, n*2*sizeof(Book));
	    n*=2;
	    
    }
    cout << "Enter title: ";
    cin.ignore();
    cin >> new_book.title;
    cout << "Enter author: ";
    cin >> new_book.author;
    cout << "Enter ISBN: ";
    cin >> new_book.isbn;
    cout << "If it is accessible, print 1, otherwise print 0: ";
    cin >> new_book.available;
    arr[i++]= new_book;
}
