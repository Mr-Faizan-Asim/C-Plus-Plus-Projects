#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
main()
{
int n,i=0;
string name,father_name;
 fstream namefile;
 
 namefile.open("student.txt", ios::in | ios::out );
 for(int i = 0 ; i < 20 ; i++)
 {
 namefile >> name ;
 if(name == "120-119")
 {
 father_name = "R";
 namefile << endl;
 namefile >> name;
 }
 cout<<name<<endl;  
}

}