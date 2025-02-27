#ifndef TaskManager_H
#define TaskManager_H 
#include "TMS.h"

using namespace std;    



class TaskManager
{	
	private:
		vector<User*> users;
		User* loggedInUser;
	public:
		TaskManager();
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
		void registerUser(const string& username, const string& password);
		bool login(const string& username, const string& password);
		void logout();
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
					user->editTask(title, updatedTask);
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
        
        
};

#endif