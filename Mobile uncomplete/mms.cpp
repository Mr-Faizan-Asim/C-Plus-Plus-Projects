#include<iostream>
#include<windows.h>
using namespace std;
string user_name();
string password();
bool check(string user,string pass,string user_name[100],string password[100]);
int i = 0;

main()
{
string user[100],pass[100],checker,add,user_name,password_log;
cin>>add;
if(add == 1)
{
user[i] = user_name();
pass[i] = password();

}
if(add == 2)
{
user = user_name();
password_log = password();
checker = role(user_name,password_log,user[i],pass[i]);
}

}
bool check(string user,string pass,string user_name[100],string password[100])
{
    bool check = false;
    int j = 0;
    while(j < = 99)
    {
        if(name[j] == name )
        {
            check = true;
        }
    }
    return check;
}
string user_name()
{
    string user;
    cout<<"User-Name: ";
    cin>>user;

}

string password()
{
    string pass;
    cout<<"Password: ";
    cin>>pass;
}