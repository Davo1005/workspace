#ifndef TaskManager_H
#define TaskManager_H 
#include "TMS.h"
#include <vector>

using namespace std;    
 


class TaskManager
{	
	private:
		vector<User*> users;
	public:
		User* loggedInUser;
		TaskManager()
		{
			loggedInUser = nullptr;
		}
		TaskManager(const TaskManager& other)
		{
			users = other.users;
			loggedInUser = other.loggedInUser;
		}
		TaskManager(TaskManager&& other) noexcept
		{
			users = move(other.users);
			loggedInUser = other.loggedInUser;
		}
		~TaskManager()
		{
			for(auto& user : users)
			{
				delete user;
			}
		}
		void registerUser(const string& username, const string& password)
		{
			users.push_back(new User(username, password));
		}
		bool login(const string& username, const string& password)
		{
			for(auto& user : users)
			{
				if(user->getusername() == username && user->getpassword() == password)
				{
					loggedInUser = user;
					return true;
				}
			}
			return false;
		}
		void logout()
		{
			loggedInUser = nullptr;
		}
		void addTaskForUser( int user_id, const Task& task)
		{
			for(const auto& user : users)
			{
				if(user->getuser_id() == user_id)
				{
					user->addTask(new Task(task));
					return;
				}
			}
		}
		void deleteTaskForUser(int user_id, int task_id,const string& title)
		{
			for(auto& user : users)
			{
				if(user->getuser_id() == user_id)
				{
					user->deleteTask(task_id, title);
					return;
				}
			}
		}
		void editTaskForUser(  string& title, Task& updatedTask)
		{
			for(auto& user : users)
			{
				if(user->getuser_id() == loggedInUser->getuser_id())
				{
					loggedInUser->editTask(title, updatedTask);
					return;
				}
			}
		}
		void listTasksForUser() 
		{
			for(auto& user : users)
			{
				if(user->getuser_id() == loggedInUser->getuser_id())
				{
					user->listtasks();
					return;
				}
			}
		}
		void searchTaskForUser(const string& title) 
		{
			for(auto& user : users)
			{
				if(user->getuser_id() == loggedInUser->getuser_id())
				{
					user->searchtask(title);
					return;
				}
			}
		}
		void displayTasksForUser(int user_id) 
		{
			for(auto& user : users)
			{
				if(user->getuser_id() == user_id)
				{
					user->listtasks();
					return;
				}
			}
		}
        
    void loadfromfile(const string pathstr)
	{
		ifstream file(pathstr);
		if(!file.is_open())
		{
			cerr << "error: could not open file " << pathstr << endl;
		}
		int user_id;
		string username, password;
		while(file >> user_id >> username >> password)
		{
			users.push_back(new User(username, password, true));
		}
		file.close();
	}
	
};
#endif