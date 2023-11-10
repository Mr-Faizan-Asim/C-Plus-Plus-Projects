#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class bank
{
    char name[100],address[100],account_type[100];
    int balance;
    public:
        void open_account();
        void deposite_money();
        void withdraw_money();
        void display_account();
};
void bank :: open_account()
{
cout<<"Enter Your Full Name: ";
cin.ignore();//to stop buffering
cin.getline(name,100);
cout<<"Enter Your Address: ";
cin.ignore();//to stop buffering
cin.getline(address,100);
cout<<"Which Thing You want to do Saving (s) or Current (c) : ";
cin>> account_type;
cout<<"Enter Amount of Deposite: ";
cin>> balance;
cout<<"Your Account is Created! ";

}
void bank :: deposite_money()
{
        int a;
        cout<<"Enter How Much You Deposite: ";
        cin>>a;
        balance = balance + a;
        cout<<"Total Amount: "<<balance;

}
void bank :: display_account()
{
 cout<<"Your Full Name: \t"<<name<<endl;
 cout<<"Your Address: \t"<<address<<endl;
 cout<<"Type of Account: \t"<<account_type<<endl;
 cout<<"Amount You Deposite:  \t"<<balance<<endl;


}
void bank :: withdraw_money()
{
    float with;
    bank obj;
    cout<<"Withdraw: \t"<<endl;
    cout<<"Enter Amount to Withdraw: \t";
    cin>> with;
    balance = balance - with;
    cout<<"Now Total Amount Left is: \t"<<balance;
}

int main()
{
int n;//number select
bank obj;
char x;
do
{
cout<<"1) Open Account \n";
cout<<"2) Deposite Money \n";
cout<<"3) WithDraw Money \n";
cout<<"4) Display Account \n";
cout<<"5) Exit \n";
cout<<"Select the Option From Above\n";
cin>>n;
switch(n)
{
    case 1:
    obj.open_account();
    break;
    case 2:
    obj.deposite_money();
    break;
    case 3:
    obj.withdraw_money();
    break;
    case 4:
    obj.display_account();
    break;
    case 5:
        if(n == 5)
        {
            exit(1);//to terminate a C++ Program
        }
    default:
    cout<<"You Entered Wrong Number ";
}
cout<<"\n Do You Want to Select Next Option Y/n: ";
cout<<"If you want to exit Press N .....";
x = getch();
if(x == 'n' || x=='N')
{
exit;
}
}
while(x=='y' || x=='Y');

return 0;
}