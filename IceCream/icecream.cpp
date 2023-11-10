#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
struct icecream
{
    string  icecream_company;
    string icecream_name;
    int price;
    int amount_present;
};

int main()
{
icecream check[100];
int i = 0;
int n= 0;
char character_to_check_enter,character_to_check_see;

while(1)
{
cout<<"Is You Want To Enter Data (Press any Y).......";
character_to_check_enter = getch();
cout<<endl;
cout<<"Is You Want To See Data (Press any Y).......";
character_to_check_see = getch();
cout<<endl;
system("cls");
while((character_to_check_enter == 'y' || character_to_check_enter == 'Y') && i != 100)
{   
    cout<<"Eneter Ice-cream Company Name: ";
    cin>>check[i].icecream_company;
    cout<<"Eneter Ice-cream Name: ";
    cin>>check[i].icecream_name;
    cout<<"Eneter Ice-cream Price: ";
    cin>>check[i].price;
    cout<<"Eneter Ice-cream Remain: ";
    cin>>check[i].amount_present;
    i = i + 1;
    n = n + 1;
    system("cls");
    cout<<"Is You Want To Enter Another Record (Press any Y otherwise N).......";
    character_to_check_enter = getch();
    cout<<endl;
    cout<<"Is You Want To See Data (Press any Y).......";
    character_to_check_see = getch();
    cout<<endl;
    system("cls");
}
while(character_to_check_see == 'y' || character_to_check_see == 'Y')
{
    for(int i = 0 ; i<n ; i++)
    {
        cout<<"Company Name                :   "<<check[i].icecream_company<<endl;
        cout<<"Ice-Cream Name              :   "<<check[i].icecream_name<<endl;
        cout<<"Ice-cream Price             :   "<<check[i].price<<endl;
        cout<<"Number Of Products Present  :   "<<check[i].amount_present<<endl;
        cout<<"_________________________________________________________________________"<<endl;
        
    }
    break;
}

if(character_to_check_enter != 'Y' || character_to_check_enter != 'y' || character_to_check_see != 'Y' || character_to_check_see != 'y' )
{   
    cout<<"Thanks For Visit";
    break;
}
}
return 0;
}