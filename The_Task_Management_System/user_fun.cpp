#include<vector>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;






bool userexists(const string& path, const string& uname, const string& pass) 
{

	ifstream file(path);
	if(!file.is_open())
	{
		cerr << "error: could not open file " << path << endl;
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

void savetofile(const string& pathstr, int user_id ,string username, string password){
        
		ofstream file(pathstr, ios::app);
        if (file.is_open()) {
			
            file << user_id << username << " " << password << endl;
            file.close();
        }
    }

	
