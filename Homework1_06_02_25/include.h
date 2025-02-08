using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
struct Book
{
	string title;
	string author;
	string isbn;
        bool available;

};
extern Book* arr;
extern int n, i;
void search_system();
void print_books();
void print_books(int);
void add_book();


