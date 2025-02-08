#include "include.h"


using namespace std;

int main()
{
	int ar=0;
	int id=0;
	cout << "Select a shape: "<< endl;
	cout << "1. Circle" << endl;
	cout << "2. Rectangle" << endl;
	cout << "3. Triangle" << endl	;
	cout << "4. Square" << endl;
	cout << "Enter choice: ";
	cin >> id;
	if(id == 1)
	{
		double rad;                
                cout << "Enter ridus: ";
                cin  >> rad;
                ar = area(rad);

	}
	else if(id == 2)
	{

		char ch ='r';
                double width;
                cout << "Enter width: ";
                cin  >> width;
                double height;
                cout << "Enter height: ";
                cin  >> height;
                ar = area(width, height, ch);

	}
	else if(id == 3)
	{
		double base, height;
                cout << "Enter base: ";
                cin  >> base;
                cout << "Enter height: ";
                cin  >> height;
                ar = area(base, height);

	}
	else if(id == 4)
	{
		int side;
                cout << "Enter side: ";
                cin  >> side;
                ar = area(side);


	}
	else
	{
		cout << "ERROR" << endl;
		return 0;
	}

	cout << "area == " <<  ar;
	return 0;
}
