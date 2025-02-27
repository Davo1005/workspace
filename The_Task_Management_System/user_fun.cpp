#include "TMS.h"






bool userexists(const string& fpath, const string& uname, const string& pass) 
{
	path filepath = fpath;
	ifstream file(filepath);
	if(!file.is_open())
	{
		cerr << "error: could not open file " << filepath << endl;
            	return false;	
	}
	string username, userpasswd;
	while(file >> username >> userpasswd)
	{
		if(username == uname && userpasswd == pass)
		{
			file.close();
			return true;
		}
	}
	file.close();
	return false;
}

void savetofile(const string& path) {
        ofstream file(path, ios::app);
        if (file.is_open()) {
            file << username << " " << password << endl;
            file.close();
        }
    }
