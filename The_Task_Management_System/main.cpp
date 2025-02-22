#include "TMS.h"

int main()
{
			
	path dirpath = "fsystem";
       	if(!exists(dirpath))
	{
		create_directory(dirpath);
	}	
	path filepath = dirpath / "userInfo";
	ofstream file(filepath);


}
