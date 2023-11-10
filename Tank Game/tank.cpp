#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
int x = 14,y=15;
int enemy_1 = 0;
int enemy_2 = 0;
int enemy_3 = 0;
int khalid_health = 10;
int columns_of_screen,rows_of_screen;
int screen_size();
void print_khalid_tank(int x ,int y);
void erase_tank(int x , int y);
void print_box(int rows , int columns);
int  khalid_tank_fire_right();
void print_enemy_tank(int x1,int y1);
void erase_enemy_tank(int x1,int y1);
void move_tank_left();
void move_tank_right();
void move_tank_down();
void move_tank_up();
void enemy_damage();
string level_one();
int  enemy_tank_fire(int x1, int y1);
int  khalid_tank_fire_up();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
main()
{
string option_level;
cout<<"LEVEL OPTION: ";
cin>>option_level;
if(option_level == "1")
{
    option_level = level_one();
}
if(option_level == "2")
{
    
}

}
string level_two()
{
bool health_enemy_1,health_enemy_2,health_enemy_3;
health_enemy_1 = health_enemy_2 = health_enemy_3 = false; 
enemy_1 = enemy_2 = enemy_3 = 0;
khalid_health = 10;
print_box(rows_of_screen,columns_of_screen - 1);
while (health_enemy_1 == false || health_enemy_2 == false || health_enemy_3 == false)
{
enemy_damage();
if(enemy_1 < 6)
{
    print_enemy_tank(columns_of_screen - 20,5);
    enemy_tank_fire(columns_of_screen - 20, 5);
}
else if(enemy_1 >= 6)
{
    erase_enemy_tank(columns_of_screen - 20,5);
    health_enemy_1 = true;
}

if(enemy_2 < 6)
{
    print_enemy_tank(columns_of_screen - 20,15);
    enemy_tank_fire(columns_of_screen - 20, 15);
}
else if(enemy_2 >= 6)
{
    erase_enemy_tank(columns_of_screen - 20,15);
    health_enemy_2 = true;
}

if(enemy_3 < 6)
{
    print_enemy_tank(columns_of_screen - 20,25);
    enemy_tank_fire(columns_of_screen - 20, 25);
}
else if(enemy_3 >= 6)
    {
    erase_enemy_tank(columns_of_screen - 20,25);
    health_enemy_3 = true;
    }


if(GetAsyncKeyState(VK_LEFT))
{
   move_tank_left();
   
}
if (GetAsyncKeyState(VK_RIGHT))
{
    move_tank_right();
}
if (GetAsyncKeyState(VK_UP))
{
    move_tank_up();
}
if (GetAsyncKeyState(VK_DOWN))
{
    move_tank_down();
}
if (GetAsyncKeyState(VK_SPACE))
{
    khalid_tank_fire_right();
}
if (GetAsyncKeyState(VK_TAB))
{
    khalid_tank_fire_up();
}

}
}
string level_one()
{
screen_size();
bool health_enemy_1,health_enemy_2,health_enemy_3;
health_enemy_1 = health_enemy_2 = health_enemy_3 = false; 
print_box(rows_of_screen,columns_of_screen - 1);
while (health_enemy_1 == false || health_enemy_2 == false || health_enemy_3 == false)
{
enemy_damage();
if(enemy_1 < 6)
{
    print_enemy_tank(columns_of_screen - 20,5);
    enemy_tank_fire(columns_of_screen - 20, 5);
}
else if(enemy_1 >= 6)
{
    erase_enemy_tank(columns_of_screen - 20,5);
    health_enemy_1 = true;
}

if(enemy_2 < 6)
{
    print_enemy_tank(columns_of_screen - 20,15);
    enemy_tank_fire(columns_of_screen - 20, 15);
}
else if(enemy_2 >= 6)
{
    erase_enemy_tank(columns_of_screen - 20,15);
    health_enemy_2 = true;
}

if(enemy_3 < 6)
{
    print_enemy_tank(columns_of_screen - 20,25);
    enemy_tank_fire(columns_of_screen - 20, 25);
}
else if(enemy_3 >= 6)
    {
    erase_enemy_tank(columns_of_screen - 20,25);
    health_enemy_3 = true;
    }


if(GetAsyncKeyState(VK_LEFT))
{
   move_tank_left();
   
}
if (GetAsyncKeyState(VK_RIGHT))
{
    move_tank_right();
}
if (GetAsyncKeyState(VK_UP))
{
    move_tank_up();
}
if (GetAsyncKeyState(VK_DOWN))
{
    move_tank_down();
}
if (GetAsyncKeyState(VK_SPACE))
{
    khalid_tank_fire_right();
}
if (GetAsyncKeyState(VK_TAB))
{
    khalid_tank_fire_up();
}

}
system("cls");
print_box(5,columns_of_screen);
gotoxy(columns_of_screen/2 - 10,3);
cout<<"LeveL One Completed";
Sleep(3000);
return "2";
}

void print_khalid_tank(int tank_place_x ,int tank_place_y)
{
char tank_parts[6][22] = {{char(201),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(187),' ',' ',' ',' ',' ',' ',' '},
                        {char(204),'|',' ','|',' ',' ',char(178),char(178),char(178),' ','|',' ','|',' ',char(93),' ',' ',' ',' ',' ',' ',' '},
                        {char(204),'\\','\\',' ',' ',' ',' ',char(178),' ',' ',' ','\\','\\',' ',char(204),'#','#','#','#','#','#',']'},
                        {char(204),'/','/',' ',' ',' ','P','A','K',' ',' ','/','/',' ',char(204),'#','#','#','#','#','#',']'},
                        {char(204),'|',' ','|',' ',' ',' ',char(178),' ',' ','|',' ','|',' ',char(93),' ',' ',' ',' ',' ',' ',' '},
                        {char(200),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(188),' ',' ',' ',' ',' ',' ',' '}};
for(int i = 0 ; i < 6 ; i++)
{
    gotoxy(tank_place_x,tank_place_y);
    for(int j = 0 ; j < 22 ; j++ )
    {
        cout<<tank_parts[i][j];
    }
    tank_place_y++;
}
}

void erase_tank(int x , int y)
{
 int eraser_x = x , eraser_y = y ; 
 for(int i = 0 ; i < 6 ; i++)
 {
    eraser_x = x;
    gotoxy(eraser_x,eraser_y);
    for(int j = 0 ; j < 22 ; j++ )
    {
        cout<<" ";
        eraser_x++;
    }
    eraser_y++;
 }

}
//FIRE Right
int khalid_tank_fire_right()
{ 
    int dot_x = x + 22;
    int dot_y = y + 3;
    while(dot_x < columns_of_screen)
    {
        char nextlocation = getCharAtxy(dot_x,dot_y);
        Sleep(0.5);
        gotoxy(dot_x,dot_y);
        cout<<"*";
        gotoxy(dot_x,dot_y + 1);
        cout<<"*";    
        gotoxy(dot_x,dot_y);
        cout<<" ";
        gotoxy(dot_x,dot_y + 1);
        cout<<" ";
        dot_x++;
        if( nextlocation == char(204)|| nextlocation == char(201) || nextlocation  == char(200) ||  nextlocation == '<' )
        {
            for (int i = 5; i <= 9; i++)
            {
                if(y == i)
                {
                enemy_1++;
                }
            }
            for (int i = 15; i <= 19; i++)
            {
                if(y == i)
                {
                enemy_2++;
                }
            }
            for (int i = 25; i <= 29; i++)
            {
                if(y == i)
                {
                enemy_3++;
                }
            }
        }
    }
}
//FIRE UP
int khalid_tank_fire_up()
{ 
    int dot_x = x + 7;
    int dot_y = y ;
    while(dot_y > 0 )
    {   
        Sleep(0.2);
        gotoxy(dot_x,dot_y);
        cout<<"*";
        gotoxy(dot_x,dot_y + 1);
        cout<<"*";    
        gotoxy(dot_x,dot_y);
        cout<<" ";
        gotoxy(dot_x,dot_y + 1);
        cout<<" ";
        dot_y--;
    }
}
// Move Left
void move_tank_left()
{
    char nextlocation = getCharAtxy(x - 1,y);
    if(nextlocation != '#')
    {
        erase_tank(x,y);
        x = x - 1;
        print_khalid_tank(x,y);
        Sleep(100);
    }
    
}
// Move Right
void move_tank_right()
{
    char nextlocation = getCharAtxy(x + 22,y);
    if(nextlocation != '#')
    {
        erase_tank(x,y);
        x = x + 1;
        print_khalid_tank(x,y);
        Sleep(100);
    }
}
// Move Down
void move_tank_down()
{
    char nextlocation = getCharAtxy(x,y+8);
    if(nextlocation != '#')
    {
        erase_tank(x,y);
        y = y + 1;
        print_khalid_tank(x,y);
        Sleep(100);
    }
}
// Move Up
void move_tank_up()
{
    char nextlocation = getCharAtxy(x, y - 1);
    if(nextlocation != '#')
    {
        erase_tank(x,y);
        y = y - 1;
        print_khalid_tank(x,y);
        Sleep(100);
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
void print_box(int rows , int columns)
{
    system("cls");
    for(int i = 1 ; i <= rows ; i ++)
    {
        for(int j = 0 ; j <= columns ; j++)
        {
            if(i == 1 || i == rows || j == columns || j == 0)
            {
                cout<<"#";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
        
    }

}
// Enemy Tank
void print_enemy_tank(int x1,int y1)
    {
    int enemy_x = x1;
    int enemy_y = y1;
    Sleep(0.2);
    char enemies_tank[5][10] = {{' ',' ',' ',' ',char(201),'=','=','=','=',char(187)},
                                {' ',' ',' ',' ',char(204),' ','I','N',' ',char(204)},
                                {'<','|','|','|',char(204),' ','D','I',' ',char(204)},
                                {' ',' ',' ',' ',char(204),' ','A','N',' ',char(204)},
                                {' ',' ',' ',' ',char(200),'=','=','=','=',char(188)}};
    
    for (int i = 0; i < 5; i++)
    {
        gotoxy(enemy_x,enemy_y);
        for (int j = 0; j < 10; j++)
        {
            cout<<"\33[33m"<<enemies_tank[i][j];
        }
        enemy_y++;
    }
    }
//
 void erase_enemy_tank(int x1,int y1)
    {
    int enemy_x = x1;
    int enemy_y = y1;
    for (int i = 0; i < 5; i++)
    {
        gotoxy(enemy_x,enemy_y);
        for (int j = 0; j < 10; j++)
        {
            cout<<" ";
        }
        enemy_y++;
    }
    }
// Screen Size
int screen_size()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns_of_screen = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows_of_screen = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return 0;
}
// BULLET FIRE
int enemy_tank_fire(int x1, int y1)
{ 
    int dot_x = x1;
    int dot_y = y1 ;
    while(dot_x > 0 )
    {   
        char nextlocation = getCharAtxy(x - 1,y);
        Sleep(0.1);
        gotoxy(dot_x,dot_y);
        cout<<"\33[32m"<<"o";   
        gotoxy(dot_x,dot_y);
        cout<<" ";
        dot_x--;
        Sleep(0.1);
        if( nextlocation == char(188)|| nextlocation == char(93) || nextlocation  == '#' || nextlocation  == char(187) ||  nextlocation == ']' )
        {
            for (int i = 0; i <= rows_of_screen; i++)
            {
                if(y == i)
                {
                khalid_health--;
                }
            }

    }
}
}
void enemy_damage()
{
    gotoxy(columns_of_screen/2 +  10,2);
    cout<<" E1: "<<enemy_1;
    gotoxy(columns_of_screen/2 + 20 ,2);
    cout<<" E2: "<<enemy_2;
    gotoxy(columns_of_screen/2 + 30 ,2);
    cout<<" E3: "<<enemy_3;
    gotoxy(columns_of_screen/2 - 10 ,2);
    cout<<" HEALTH: "<<khalid_health;

}