#include "TaskManeger.h"
#include "TMS.h"
#include "Task.h"
#include <chrono>
#include <thread>


using namespace std;

string sha256(const std::string& input);
string getusername();
void savetofile(const string& pathstr, int user_id ,string username, string password);
bool userexists(const string& fpath, const string& uname, const string& pass); 

int samepassword(string psw, string psw2)
{
    if(psw == psw2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printSlow(const string &text) {
    int delay = 5;
    for (char c : text) {
        cout << c << flush;  
        this_thread::sleep_for(std::chrono::milliseconds(delay)); 
    }
    cout << endl;
}


int main() {
    char command;
    TaskManager taskManager;
    const string pathstr1 = "fsystem/userinfo.txt";
    taskManager.loadfromfile(pathstr1);
    printSlow("Welcome to Task Manager System");
    
    while(true)
    {
        string username, password, password2;
        printSlow("Please select an option");
        printSlow("1. Register");
        printSlow("2. Login");
        printSlow("3. Logout");
        printSlow("4. Exit");
        printSlow("Enter your command: ");
        command = getchar();
        cin.ignore(1000, '\n');
        switch(command)
        {   
            case '1':
                while(true)
                {   
                    printSlow("Enter your username: ");
                    cin >> username;
                    printSlow("Enter your password: ");
                    cin >> password;
                    printSlow("Enter your password again: ");
                    cin >> password2;
                    
                    if( (!(userexists(pathstr1, username, sha256(password)))) && samepassword(sha256(password), sha256(password2)))
                    {
                        taskManager.registerUser(username, sha256(password));
                        printSlow("User has been registered");
                        break;
                    }
                    else if(samepassword(password, password2))
                    {
                        printSlow("User already exists");
                    }
                    else
                    {
                        printSlow("Passwords are not the same");
                    }
                }
                break;
            case '2':
                printSlow("Enter your username: ");
                cin >> username;
                printSlow("Enter your password: ");
                cin >> password;
                if(taskManager.login(username, sha256(password)))
                {
                    printSlow("You have been logged in");
                }
                else
                {
                    printSlow("Username or password is wrong");
                }
                break;
            case '3':
                loggedout:
                {
                    taskManager.logout();
                    printSlow("You have been logged out");
                }
                break;
            case '4':
                printSlow("Goodbye");
                return 0;
            default:
                printSlow("Invalid command");
                break;
        }
    }

    loggedin:
            while(true)
            {
                printSlow("Hello " + taskManager.loggedInUser->getusername());
                printSlow("Please select an option");
                printSlow("1. Edit Task");
                printSlow("2. Tasks list");
                printSlow("3. Search Task");
                printSlow("4. Display Tasks");
                printSlow("5. Logout");
                printSlow("6. Exit");
                printSlow("Enter your command: ");
                command = getchar();
                cin.ignore(1000, '\n');
                switch(command)
                {
                    case '1':
                        {
                            string title,titlenew;
                            printSlow("Enter the title of the task you want to edit: ");
                            cin >> title;

                            Task updatedTask;
                            printSlow("Enter the new title of the task: ");
                            cin >> titlenew;
                            updatedTask.settitle(updatedTask,titlenew);
                            

                            printSlow("Enter the description of the task: ");
                            string description;
                            cin >> description;
                            updatedTask.setdescription(updatedTask, description);
                            
                            printSlow("Enter the deadline of the task: ");
                            string deadline;
                            cin >> deadline;
                            updatedTask.setdeadline(updatedTask, deadline);
                            printSlow("Enter the category of the task: ");
                            
                            string category;
                            cin >> category;
                            updatedTask.setcategory(updatedTask,category);
                            printSlow("Enter the priority of the task: ");
                            
                            int priority;
                            cin >> priority;
                            updatedTask.setpriority(updatedTask,priority);
                            
                            taskManager.editTaskForUser(title, updatedTask);
                        }
                        break;
                    case '2':
                        taskManager.listTasksForUser();
                        break;
                    case '3':
                        {
                            string title;
                            printSlow("Enter the title of the task you want to search: ");
                            cin >> title;
                            taskManager.searchTaskForUser(title);
                        }
                        break;
                        
                    case '4':
                        taskManager.displayTasksForUser(taskManager.loggedInUser->getuser_id());
                        break;
                    case '5':
                        taskManager.logout();
                        printSlow("You have been logged out");

                        break;
                    case '6':
                        printSlow("Goodbye");
                        return 0;
                    default:
                        printSlow("Invalid command");
                        break;
                }
            }   

    return 0;
}
