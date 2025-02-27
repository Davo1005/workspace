#ifndef TASK_H
#define TASK_H
#include "TMS.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;



int  task_id=0;
enum Priority
		{
			Low=1,
			Medium,
			High
		};

class Task 
{
	private:
		int uid;
		int id;
		string title;
		string description;
		string deadline;
		Priority priority;
		string category;
		bool completed;

	public:
		Task();
		Task(const string& title, const string& description, const string& deadline, const string& category, int priority, int uid): id(task_id++), uid(uid), title(title), description(description), deadline(deadline), category(category), priority(static_cast<Priority>(priority)),  completed(false) {}
		Task(const Task& other);
		Task(Task&& other) noexcept
        {   
            title = other.title;
            description = other.description;
            deadline = other.deadline;
            category = other.category;
            priority = other.priority;
            completed = other.completed;
        }
		~Task()
        {
            cout << "task has been deleted";
        }
		string gettitle() const
        {
                return title;
        }

        int get_task_id() const
        {
            return id;
        }
        int getuid() const
        {
            return uid;
        }


        string getdescription() const 
        { 
            return description; 
        }
        string getdeadline() const 
        { 
            return deadline; 
        }
        string getcategory() const 
        { 
            return category; 
        }
        bool iscompleted() const 
        { 
            return completed; 
        }
		
		int getpriority() const 
        {
            return static_cast<int>(priority); 
        }

        void settitle(Task* task,string str)
        {
            task->title = str;
        }
        void setdescription(Task* task,string str)
        {
            task->description = str;
        }
        void setdeadline(Task* task,string str)
        {
            task->deadline = str;
        }   
        void setcategory(Task* task,string str)
        {
            task->category = str;
        }
        void setpriority(Task* task,int pr)
        {
            if (task != nullptr) { 
                if (pr >= 1 && pr <= 3) { 
                    task->priority = static_cast<Priority>(pr); 
                    return;
                } 
            }
            cout << "invalid priority";
        }
        void setcompleted(Task* task,bool b)
        {
            task->completed = b;
        }
    
    };
#endif