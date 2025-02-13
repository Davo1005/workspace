#include "include.h"

int main()
{
	vector vec(10);
	vec.v_push_back(5);
	vec.v_push_back(5);
	vec.v_push_back(5);
	vec.v_push_back(6);

	int tmp=vec.v_fornt();
	cout << tmp;
	cout << vec.v_back();
}
