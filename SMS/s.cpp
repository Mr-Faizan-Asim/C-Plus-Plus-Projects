#include<iostream>
#include<windows.h>
using namespace std;
string username[100];
string password[100];
bool sign_up();
string sign_in();
main()
{

}

bool sign_in()
{
string user_name,pass;
sign_in:
cout<<"USERNAME: ";
cin>>user_name;
cout<<"PASSWORD: ";
cin>>pass;
for(int i = 0 ; i < 100 ; i++ )
{
    if(username[i] == user_name && password[i] == pass)
    {
        return true;
    }
}
cout<<"INVALID! "
goto sign_in;
}
bool print_box()
{

}