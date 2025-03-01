#include "TaskManeger.h"
#include "TMS.h"
#include "Task.h"

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

int main() {
    TaskManager taskManager;
    const string pathstr1 = "fsystem/userinfo.txt";
    taskManager.loadfromfile(pathstr1);
    cout << "Welcome to Task Manager System" << endl;
    

    while(true)
    {
        string username, password, password2;
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
        cout << "Enter your password again: ";
        cin >> password2;
        if(samepassword(password, password2))
        {
            taskManager.registerUser(username, sha256(password));
            cout << "User has been registered" << endl;
            break;
        }
        else
        {
            cout << "Passwords are not the same" << endl;
        }
    }
    return 0;
}