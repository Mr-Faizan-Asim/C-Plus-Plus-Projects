#include<iostream>
#include<fstream>
using namespace std;
main()
{
int b = 20;
string m;
ifstream amsfile;
amsfile.open("s.txt");
for(int i = 0 ; i < b ; i++)
{
if(i >= b - 10)
{
amsfile >> m;
cout<<m<<endl;
}
else
{
amsfile >> m;
}
}
}