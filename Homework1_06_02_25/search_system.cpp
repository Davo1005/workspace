#include "include.h"


void search_system()
{
	int toa=0;
	string strs;
	cout << "If you wont to surch by name of author press 1 if by title press 2: ";
	cin >> toa;
	
	if(toa == 1)
	{
		cout << "Print the correct keyword for searching: ";
		cin >> strs;
		for(int j=0;j<i;j++)
		{
			if(arr[j].author == strs)
			{
				print_books(j);
			}
		}
	}
	else if(toa == 2)
        {
                cout << "Print the correct keyword for searching: ";
                cin >> strs;
                for(int j=0;j<i;j++)
                {
                        if(arr[j].title == strs)
                        {
                                print_books(j);
                        }
                }
        }

}
