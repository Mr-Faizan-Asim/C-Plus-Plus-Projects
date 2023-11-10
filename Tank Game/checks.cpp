#include<iostream>
#include<windows.h>
using namespace std;
int screen_size();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void print_box(int rows , int columns,int start_rows,int start_columns);
main()
{

print_box(20,140,10,20);    

}




























void print_box(int rows , int columns,int start_rows,int start_columns)
{
    
    system("cls");
    
    for(int i = start_rows ; i <= rows ; i ++)
    {   
        for(int j = start_columns ; j <= columns ; j++)
        {
            gotoxy(j,i);
            if(i == start_rows || i == rows || j == columns || j == start_columns)
            {
                cout<<"#";
            }
            else if(i  )
            {
                cout<<" ";
            }
        }
        cout<<endl;

    }
    

}
// GOTOXY
void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
// GETCHAR
char getCharAtxy(short int x, short int y)
{
	CHAR_INFO ci;
	COORD xy = {0, 0};
	SMALL_RECT rect = {x, y, x, y};
	COORD coordBufsize;
	coordBufsize.X = 1;
	coordBufsize.Y = 1;
	return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufsize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}