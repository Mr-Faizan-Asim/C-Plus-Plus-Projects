#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
main()
{
int n,i=0;
string name,father_name,v_name,v_father_name;
fstream namefile,fatherfile;
namefile.open("student.txt",  ios::app);
fatherfile.open("student_father.txt", ios::app);

cout<<"Is You Want To Enter Data(1/0): ";
cin>>n;
while(n == 1)
{
cout<<"Enter The Name: ";
cin>>name;
namefile << name<<endl;
cout<<"Enter Father Name: ";
cin>>father_name;
fatherfile << father_name<<endl;
i++;
cout<<"Is You Want To Enter Data(1/0): ";
cin>>n;
}
while(n == 0)
{

 for(int j = 0 ; j < i ; j++ )
 {
    namefile >> v_name;
    cout<<"Name: "<<v_name<<endl;
    fatherfile >> v_father_name;
    cout<<"Father Name: "<<v_father_name<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
 }

cout<<"Is You Want To Enter Data(1/0): ";
cin>>n;
}

    
}