#ifndef TMS_H
#define TMS_H
#include "Task.h"
#include "TaskManeger.h"
#include <filesystem>
#include <fstream>	
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace std::filesystem;

int userid=0;

void savetofile(const string& pathstr, int user_id ,string usarname, string password);
bool userexists(const string& fpath, const string& uname, const string& pass);
string sha256(const std::string& input);

class User
{
	private:
		int user_id;
		string username;
		string password;
		vector<Task*> tasks;

	public:
	
		User(const string& username, const string& password) : user_id(userid++), username(username), password(sha256(password))
		{
			string path = "fsystem/userinfo.txt";
            
		
			if(!(userexists(path, username, password)))
			{
				savetofile(path, user_id ,username, password);
		
			}
			else
			{
				cout << "username has already used. choose another one or sign in";
			}
		}
		User(const string& usarname, const string& password, bool forloading) : user_id(userid++), username(usarname), password(password)
		{
			
		}
		

		User(const User& other);
		
		User(User&& other) noexcept;

		~User()
		{
			for (auto& task : tasks) {
					delete task;
				}
		}

		void addTask(Task* task)
		{
			tasks.push_back(task);
		}

		void deleteTask(int& task_id,const string& title)
		{	
			for( auto it = tasks.begin(); it!= tasks.end(); ++it)
			{
				if((*it)->gettitle() == title && (*it)->get_task_id() == task_id)
				{
					delete *it;
					tasks.erase(it);
					cout << "task has been deleted";
					return;		
				}
			}
			cout << "there is no taks with that title";
		}
		string getusername() const 
		{ 
			return username; 
		}

		string  getpassword() const 
		{ 
			return password; 
		}
		int getuser_id() const 
		{ 
			return user_id; 
		}
		void editTask( string& title,  Task& updatedtask)
		{
			for( auto& task : tasks)
				{
						if(task->gettitle() == title)
						{
							task->settitle(updatedtask, updatedtask.gettitle());
							task->setdescription(updatedtask, updatedtask.getdescription());
							task->setdeadline(updatedtask, updatedtask.getdeadline());
							task->setcategory(updatedtask, updatedtask.getcategory());
							task->setpriority(updatedtask, updatedtask.getpriority());
							cout << "task has been updated";
							return;
						}
				}
			cout << "there is no taks with that title";

		}	

		void listtasks() const
		{
			for (const auto& task : tasks) 
			{
				cout << "title: " << task->gettitle() << endl;
			}
		}

		Task* searchtask(const string& title)
		{
			for(const auto& task : tasks)
			{
				if(task->gettitle() == title) 
				{
					
						cout << "the task has found";
						return task;
				}

			}
			cout << "the task has not found";
		}
		

};

#endif	