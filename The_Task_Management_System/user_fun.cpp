#include "TMS.h"


User ::User(const string& usarname, const string& password) : username(usarname),password(password)
{
	string path = "fsystem/userInfo.txt";

	if(!(userExists(path, usarname, password)))
	{
		saveTofile(path);

	}
	else
	{
		cout << "Username has already used. Choose another one or sign in";
	}
}

/*User :: User(const User& other)
{
	//animast a;
}

User ::  User(User&& other) noexcept
{
  // animast a ;
}*/

~User()
{
	for (auto& task : tasks) {
            delete task;
        }
}

void User :: addTask(Task* task)
{
	tasks.push_back(task);
}
void User :: deleteTask(const string& title)
{
	for( auto it = tasks.begin(); it!= tasks.end(); ++it)
	{
		if(*it->gettitle() == title)
		{
			delete *it;
                	tasks.erase(it);
			cout << "Task has been deleted";
			return;		
		}
	}
	cout << "There is no Taks with that title";
}
string User:: getUsername() const 
{ 
	return username; 
}

string User :: getPassword() const 
{ 
	return password; 
}
void User :: editTask(const std::string& title, const Task& updatedTask)
{
	for( auto it = tasks.begin(); it!= tasks.end(); ++it)
        {
                if(*it->gettitle() == title)
                {
                        *it = updatetask;
                        tasks.erase(it);
			cout << "Task has been updated";
			return;
                }
        }
	cout << "There is no Taks with that title";

}	

void User :: listTasks() const
{
	for (const auto& task : tasks) 
	{
     	   cout << "Title: " << task.title << endl;
	}
}

Task* User ::  searchTask(const string& title)
{
	for(const auto& task : tasks)
	{
	    if(task->getTitle() == title) 
	    {
                cout << "The task has found";
       	   	return;
	    }

	}
	cout << "The task has not found";
}

bool userExists(const string& fpath, const string& uname, const string& pass) 
{
	path filePath = fpath;
	ifstream file(filePath);
	if(!file.is_open())
	{
		cerr << "Error: Could not open file " << filePath << endl;
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

string Taks :: getTitle() const 
{ 
	return title; 
}
string Taks :: getDescription() const 
{ 
	return description; 
}
string Taks :: getDeadline() const 
{ 
	return deadline; 
}
string Taks :: getCategory() const 
{ 
	return category; 
}
int Taks:: getPriority() const 
{ 
	return priority; 
}
bool Taks:: isCompleted() const 
{ 
	return completed; 
}
