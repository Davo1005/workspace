#include "include.h"

int n,i=0;

Book * arr = NULL;

int main()
{
	cout<< "Size of array of books: ";
	cin >> n;
	arr = new Book[n];
	int tmp=1;
	while(tmp!=6)
	{
		cout << "Press 1 for adding a new book:" << endl;
		cout << "Press 2 for show all books:" << endl;
		cout << "Press 3 to search a book:" << endl;
		cout << "Press 4 to borrow a book:" << endl;
		cout << "Press 5 to return a book:" << endl;
		cout << "Press 6 to exit:" << endl;
		cout << "Select the command: ";
		cin >> tmp;


		switch(tmp)
		{
			case 1:
				add_book();
				break;
			case 2:
				print_books();
				break;
			case 3:
				search_system();
				break;
                        case 4:
				borrow_a_book();
				break;
			case 5:
				return_a_book();
				break;
			case 6: 
				cout << "Thank you for using our library system";
				delete[] arr;
				return 0;
			default :
				cout << "Invalid command" << endl;
		}
	}

}

