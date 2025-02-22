#include <filesystem>
#include <fstream>	
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std::filesystem;

//class Taks;

class User
{
	prevate:
	 string username;
	 string password;
	 vector<Task*> tasks;

	public:
	 User(const string& usarname, const string& password);
	 User(const User& other);
	 User(User&& other) noexcept;
	 ~User();
	 void addTask(Task* task);
	 void deleteTask(const string& title);
	 void editTask(const string& title, const Task& updatedTask);
	 void listTasks() const;
	 Task* searchTask(const string& title);


};

class Task 
{
	prevate:
		string title;
		string description;
		string deadline;
		enum priority
		{
			Low=1,
			Medium,
			High
		};
		string category;
		bool completed;

	public:
		Task();
		Task(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, int priority);
		Task(const Task& other);
		Task(Task&& other) noexcept;
		~Task();
		string getTitle() const;
		string getDescription() const;
		string getDeadline() const;
		string getCategory() const;
		int getPriority() const;
		bool isCompleted() const;
		string getTitle() const;
	   
};

class TaskManager
{	
	preavte:
		vector<User*> users;
		User* loggedInUser;
	prevate:
		TaskManager();
		TaskManager(const TaskManager& other);
		askManager(TaskManager&& other) noexcept;
		~TaskManager(); → Destructor (deallocate users);
		void registerUser(const std::string& username, const std::string& password);
		bool login(const std::string& username, const std::string& password);
		void logout();
		void addTaskForUser(const Task& task);
		void deleteTaskForUser(const string& title);
		void editTaskForUser(const std::string& title, const Task& updatedTask); 
		void displayTasksForUser() const;
};
