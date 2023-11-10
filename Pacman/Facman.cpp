#include<iostream>
#include<stdio.h>
#include<windows.h>
using namespace std;
string pac_character;
string ghost_character;
int columns_of_screen;
int rows_of_screen;
void front();
void start();
void gotoxy(int x,int y);
char getCharAtxy(short int x, short int y);
void print_pacman(int x, int y);
void erase(int x, int y);
void stage();
int screen_size();
void print_box(int rows , int columns);
void ghost(int gx,int gy);
void move(bool run);
void clear(int x,int y,char previos);
void ghost_move(int gx,int gy,char previosChar);
int x =28,y=10,z=0;
main()
{
screen_size();
system("Color 09");
char previosChar =  ' ';
char previosChar1 = ' ';
char previosChar2 = ' ';
char previosChar3 = ' ';
int gx = 80,gy =22 ;
int g2x = 81, g2y = 23;
int g3x = 87, g3y = 30;
int g4x = 83, g4y = 23;
bool run = true;
string direction = "up";
string direction1 = "left";
string direction2 = "right";
string direction3 = "down";

start();
print_box(6,columns_of_screen);
gotoxy(columns_of_screen / 2 - 10 ,2);
cout<<"Enter Pacman Character: ";
gotoxy(columns_of_screen / 2  + 20,2);
cin>>pac_character;
gotoxy(columns_of_screen / 2 - 10,4);
cout<<"Enter Ghost Character: ";
gotoxy(columns_of_screen / 2 + 20,4);
cin>>ghost_character;
stage();
print_pacman(x,y);
ghost(gx,gy);
ghost(g2x,g2y);
while(z<902)
{
move(run);
  //first
 if(direction == "right")
 {
    char nextLocation = getCharAtxy(gx+1,gy);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|' )
    {
        direction = "down";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(gx,gy,previosChar);
        gx = gx + 1;
        previosChar = nextLocation;
        ghost(gx,gy);
    }
	else if (nextLocation == ghost_character[0])
		{
			direction = "up";
		}
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 }
 if(direction == "left")
 {
    char nextLocation = getCharAtxy(gx-1,gy);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|' )
    {
        direction = "up";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(gx,gy,previosChar);
        gx = gx - 1;
        previosChar = nextLocation;
        ghost(gx,gy);
    }
	else if (nextLocation == ghost_character[0])
		{
			direction = "down";
		}
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 }
if(direction == "down")
 {
    char nextLocation = getCharAtxy(gx,gy+1);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|') 
    {
        direction = "left";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(gx,gy,previosChar);
        gy = gy + 1;
        previosChar = nextLocation;
        ghost(gx,gy);
    }
	else if (nextLocation == ghost_character[0])
		{
			direction = "left";
		}
	
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 }
 
 
if(direction == "up")
 {
    char nextLocation = getCharAtxy(gx,gy-1);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|' || nextLocation == ghost_character[0])
    {
        direction = "right";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(gx,gy,previosChar);
        gy = gy - 1;
        previosChar = nextLocation;
        ghost(gx,gy);
    
	}
	else if (nextLocation == ghost_character[0])
		{
			direction = "left";
		}
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 
	}
	// second
	if(direction1 == "right") //right
 {
    char nextLocation = getCharAtxy(g2x+1,g2y);
    if(nextLocation == '#' || nextLocation == '|' || nextLocation == ghost_character[0])
    {
        direction1 = "up";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(g2x,g2y,previosChar1);
        g2x = g2x + 1;
        previosChar1 = nextLocation;
        ghost(g2x,g2y);
    }
	else if( nextLocation == '%' )
	{
		direction1 = "left";
	}
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 }
 if(direction1 == "left") //left
 {
    char nextLocation = getCharAtxy(g2x-1,g2y);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|' || nextLocation == ghost_character[0])
    {
        direction1 = "down";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(g2x,g2y,previosChar1);
        g2x = g2x - 1;
        previosChar1 = nextLocation;
        ghost(g2x,g2y);
    }
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 }
if(direction1 == "down") //Down
 {
    char nextLocation = getCharAtxy(g2x,g2y+1);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|' || nextLocation == ghost_character[0] )
    {
        direction1 = "right";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(g2x,g2y,previosChar1);
        g2y = g2y + 1;
        previosChar1 = nextLocation;
        ghost(g2x,g2y);
    }
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 }
 
 
if(direction1 == "up") // up
 {
    char nextLocation = getCharAtxy(g2x,g2y-1);
    if(  nextLocation == '%' || nextLocation == '|' || nextLocation == ghost_character[0] || nextLocation == '#' )
    {
        direction1 = "left";
    }
	else if(nextLocation == '#')
	{
		direction1 = "right";
	}
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(g2x,g2y,previosChar1);
        g2y = g2y - 1;
        previosChar1 = nextLocation;
        ghost(g2x,g2y);
    
	}
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 
	}
	// third
		if(direction2 == "right") //right
 	{
    char nextLocation = getCharAtxy(g3x+1,g3y);
    if( nextLocation == '%' || nextLocation == '|' || nextLocation == ghost_character[0] || nextLocation == '#' )
    {
        direction2 = "up";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(g3x,g3y,previosChar2);
        g3x = g3x + 1;
        previosChar2 = nextLocation;
        ghost(g3x,g3y);
    }
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 }
 if(direction2 == "left") //left
 {
    char nextLocation = getCharAtxy(g3x-1,g3y);
    if(nextLocation == '#' || nextLocation == '%'  || nextLocation == ghost_character[0] || nextLocation == '|')
    {
        direction2 = "down";
    }
	else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(g3x,g3y,previosChar2);
        g3x = g3x - 1;
        previosChar2 = nextLocation;
        ghost(g3x,g3y);
    }
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 }
if(direction2 == "down") //Down
 {
    char nextLocation = getCharAtxy(g3x,g3y+1);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|' || nextLocation == ghost_character[0] )
    {
        direction2 = "right";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(g3x,g3y,previosChar2);
        g3y = g3y + 1;
        previosChar2 = nextLocation;
        ghost(g3x,g3y);
    }
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 }
 
 
	if(direction2 == "up") // up
	{
    char nextLocation = getCharAtxy(g3x,g3y-1);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|' || nextLocation == ghost_character[0])
    {
        direction2 = "left";
    }
    
	else if( nextLocation == '%' )
	{
		direction2 = "right";
	}
	else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(g3x,g3y,previosChar2);
        g3y = g3y - 1;
        previosChar2 = nextLocation;
        ghost(g3x,g3y);
    
	}
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 
	}
	// fourth
	if(direction3 == "right") //right
 {
    char nextLocation = getCharAtxy(g4x+1,g4y);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|')
    {
        direction3 = "down";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(g4x,g4y,previosChar3);
        g4x = g4x + 1;
        previosChar3 = nextLocation;
        ghost(g4x,g4y);
    }
	else if(nextLocation == ghost_character[0])
	{
		direction = "left";
	}
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 }
 if(direction3 == "left") //left
 {
    char nextLocation = getCharAtxy(g4x-1,g4y);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|' || nextLocation == ghost_character[0])
    {
        direction3 = "up";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(g4x,g4y,previosChar3);
        g4x = g4x - 1;
        previosChar3 = nextLocation;
        ghost(g4x,g4y);
    }
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 }
if(direction3 == "down") //Down
 {
    char nextLocation = getCharAtxy(g4x,g4y+1);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|' || nextLocation == ghost_character[0] )
    {
        direction3 = "left";
    }
    
	else if( nextLocation == '#' )
	{
		direction1 = "left";
	}
	else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(g4x,g4y,previosChar3);
        g4y = g4y + 1;
        previosChar3 = nextLocation;
        ghost(g4x,g4y);
    }
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 }
 
 
if(direction3 == "up") // up
 {
    char nextLocation = getCharAtxy(g4x,g4y-1);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|' || nextLocation == ghost_character[0])
    {
        direction3 = "right";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        clear(g4x,g4y,previosChar3);
        g4y = g4y - 1;
        previosChar3 = nextLocation;
        ghost(g4x,g4y);
    
	}
	else if(nextLocation == pac_character[0])
	{	system("cls");
		gotoxy(68,24);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;
		gotoxy(68,25);
		cout<<"@   Game Over   @"<<endl;
		gotoxy(68,26);
		cout<<"@@@@@@@@@@@@@@@@@"<<endl;

	}
 
	}
}
}





void start()
{
char a;
system("cls");
front();

gotoxy(98,25);
cin.get();

system("cls");

}

void front()
{
system("cls");

cout<<endl<<endl<<endl;
cout<<"\t           .. .........................................................................................................................  "<<endl;
cout<<"\t          ..|%|    |%|      |%|..     %%%%%%%%%%%%%|%|                            |%%|....        |%|  ..  |%%|....      |%|.       "<<endl;
cout<<"\t           ..|%|    %%%%%%%%%%%%%%     |%|                                            |%%|....     |%|  ....   |%%|....   |%|.       "<<endl;
cout<<"\t           ..|%|    %%%%%%%%%%%%%%     |%|                    |%%|....                 |%%|....            |%|  ....     |%|. .      "<<endl;
cout<<"\t          .. %%%%%%%%%%%%%%%%%%%%            ....           %%%%%%%%%%%%%%%%%%%%%%%%%%%%     |%|....     %%%%% .   |%%|....%%%|....."<<endl;
cout<<"\t         ..        |%|%%%%%%%|%|      "<<"\033[33m"<<"|%%|....           |%|                      |%|     |%|....       |%| .  ................... "<<endl;
cout<<"\t        ..        |%|%%%%%%%|%|      |%%|....           |%|         |%%|....        |%%|....       |%|     |%|....       |%| .  "<<endl;
cout<<"\t        ..        %%%%%%%%%%%%%      |%%|....           %%%%%%%%%%%%%%%%%%%%%%%%%%%%        ....     %%%%% . %%%%%%%%%%%%%%%%%%%    "<<endl;
cout<<"\t      ..        |%|                |%%|....           |%%|.... "<<"\033[34m"<<"............................      |%%|....   ....     ..... .  "<<endl;
cout<<"\t        ..        %%%%%%%%%%%%%%%    |%%|....         %%%%%%%%%%%%%%%%%%%%%%%%%%%%     |%|  ....     %%%%% .  %%%%%%%%%%%%%%%%%%%   "<<endl;
cout<<"\t      ..                    |%|          ....         |%| ........... |%%|.............         |%|  ....    |%%|....    |%| .  "<<endl;
cout<<"\t        ..                    |%|     |%%|....      ....         |%| ................ |%%|........|%|      |%|  ....       |%| .  "<<endl;
cout<<"\t      ..       ...........  |%|                                                                              |%|  ....       |%| .  "<<endl;
cout<<"\t        ..|%|     |%%|....|%|%%%%%%|%|   "<<"\033[33m"<<"***********************************************************"<<"\033[34m"<<"   |%%|.... ....   |%|......  "<<endl;
cout<<"\t        .    .|%|     |%%|....|%|        "<<"\033[33m"<<"| ######     #      ####### #        #      #     #     # |"<<"\033[34m"<<"   ....    |%%|....|%|.       "<<endl;
cout<<"\t        ..|%|    |%%|.... |%|      |%|   "<<"\033[33m"<<"| #     #   # #    #        # #    # #     # #    # #   # |"<<"\033[34m"<<"    |%%|....  ..   |%|......  "<<endl;
cout<<"\t        ..|%|                  |%%|...   "<<"\033[33m"<<"| ######   #   #   #        #  #  #  #    #   #   #  #  # |"<<"\033[34m"<<"          |%%% |%%|....%%%|.  "<<endl;
cout<<"\t        ..|%|    |%|%%%%%%|%|. |%%|...   "<<"\033[33m"<<"| #       #=====#  #        #    #   #   #=====#  #   # # |"<<"\033[34m"<<"         |%%|....  .........  "<<endl; 
cout<<"\t        .......................  |%%|..  "<<"\033[33m"<<"| #      #       #  ####### #        #  #       # #    ## |"<<"\033[34m"<<"    |%|  .  ....... |%%|....  "<<endl;
cout<<"\t             ............... |%%|......  "<<"\033[33m"<<"***********************************************************         |%%|....    .......  "<<endl;
cout<<"\t"<<"\033[34m"<<"        ..|%|    |%|      |%|..            |%|%%%%%%|%|                                                  .     |%%|.... |%%|....   "<<endl;
cout<<"\t          ..|%|    |%|      |%|..            |%|                                                   |%|  ..    |%%|.... |%%|....   "<<endl;
cout<<"\t          ..|%|    %%%%%%%%%%%%%%            |%|           "<<"\033[31m"<<"CLICK ANY KEY TO START ......       "<<"\033[36m"<<"    |%|  ....   |%%|.... |%%|....  "<<endl;
cout<<"\t          ..|%|    %%%%%%%%%%%%%%            |%|                                                   |%|  ....     |                    "<<endl;
cout<<"\t          ..|%|                              |%|                                       |%|%%%%%%%%%%%|%|  ....     |%|...... |%%|     "<<endl;
cout<<"\t       ............................................................................ |%%|.... |%%|..............     .......  "<<endl;
cout<<"\t         .. %%%%%%%%%%%%%%%%%%%%    "<<"\033[31m"<<"%%%%%%%%%%%%%%%%%%% ..        ....           %%%%%%%%%%%%%%%%%%%%%%%%%%%%     |%|....     %%%%% .  "<<endl;
cout<<"\t         ..        |%|%%%%%%%|%|      |%%|....           |%|                  >>>>>>>>>>>>>>>>>>>>>>    |%|     |%|....       |%| .  "<<endl;
cout<<"\t        ..        |%|%%%%%%%|%|      |%%|....           |%|                      |%|     |%|....       |%| .  %%%%%%%%%%%%%%%%%%%..."<<endl;
cout<<"\t        ..        %%%%%%%%%%%%%      |%%|....           %%%%%%%%%%%%%%%%%%%%%%%%%%%%      %%%%%%%%%%%%%%%%%%%%%%  ....     .......  "<<endl;
cout<<"\t      ......................................................................................     .......%%%%%%%%%%%%%%%%%%%     ||"<<endl;

}
void gotoxy(int x,int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);	
}

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
void erase(int x, int y)
{
	gotoxy(x,y);
	
	cout<<" ";

}

void print_pacman(int x, int y)
{
	gotoxy(x,y);
	cout<<"\033[33m"<<pac_character;

}
void stage()
{
	
cout<<endl;
cout<<"\033[33m"<<"\t\t\t\t\t\t#######     #      "<<"\033[31m"<<"######"<<"\033[33m"<<" #       #     #      #     #         " <<endl;
cout<<"\033[33m"<<"\t\t\t\t\t\t#      #   # #    "<<"\033[31m"<<"#       "<<"\033[33m"<<"# #   # #    # #     # #   #    "<<endl;
cout<<"\033[33m"<<"\t\t\t\t\t\t#######   #   #   "<<"\033[31m"<<"#       "<<"\033[33m"<<"#  # #  #   #   #    #  #  #     "<<endl;
cout<<"\033[33m"<<"\t\t\t\t\t\t#        #=====#  "<<"\033[31m"<<"#       "<<"\033[33m"<<"#   #   #  #=====#   #   # #   "<<endl;
cout<<"\033[33m"<<"\t\t\t\t\t\t#       #       #  "<<"\033[31m"<<"###### "<<"\033[33m"<<"#       # #       #  #     #        "<<endl;
cout<<endl;
cout<<"\033[34m"<<"\t\t\t############################################################################################################\t\t####################"<<endl;
cout<<"\033[33m"<<"\t\t\t||.. ................................... |%|      ...................................................... ||\t\t#                  #"<<endl;
cout<<"\t\t\t||.. %%%%%%%%%%%%%%%%%%%%            ....           %%%%%%%%%%%%%%%%%%%%%%%%%%%%     |%|....     %%%%% . ||\t\t#                  #"<<endl;
cout<<"\t\t\t||..        |%|%%%%%%%|%|      |%||%|....           |%|                      |%|     |%|....       |%| . ||\t\t#                  #"<<endl;
cout<<"\t\t\t||..        |%|%%%%%%%|%|      |%||%|....           |%|                      |%|     |%|....       |%| . ||\t\t#                  #"<<endl;
cout<<"\t\t\t||..        %%%%%%%%%%%%%      |%||%|....           %%%%%%%%%%%%%%%%%%%%%%%%%%%%        ....     %%%%% . ||\t\t#                  #"<<endl;
cout<<"\t\t\t||..        |%|                |%||%|....           ............................   |%|   ....     ...... ||\t\t#                  #"<<endl;
cout<<"\t\t\t||..        %%%%%%%%%%%%%%%    |%||%|....           %%%%%%%%%%%%%%%%%%%%%%%%%%%    |%|  ....     %%%%% . ||\t\t#                  #"<<endl;
cout<<"\t\t\t||..                    |%|          ....            ....................         |%|  ....       |%|  . ||\t\t#                  #"<<endl;
cout<<"\t\t\t||..                         ....         |%| ....................|%|      |%|  ....       |%|         . ||\t\t#                  #"<<endl;
cout<<"\t\t\t||..       ...........  |%|          ....             ....................|%|      |%|  ....       |%| . ||\t\t#                  #"<<endl;
cout<<"\t\t\t||..|%|    |%|%%%%%%|%|.      |%||%| ....                                          |%|  ....   |%|...... ||\t\t####################"<<endl;
cout<<"\t\t\t||..|%|    |%|      |%|.|&|          ................................................................    ||\t\t"<<endl;
cout<<"\t\t\t||..|%|    |%|      |%|%|              .......                 .............................       |%|   ||\t\t"<<endl;
cout<<"\t\t\t||..       |%|%%%%%%|%|      |%||%|....  %%%                            %%%          |%|....       |%| . ||\t\t"<<endl;
cout<<"\t\t\t||..       |%|%%%%%%|%|      |%||%|....   |%|                           |%|          |%|....       |%| . ||\t\t"<<endl;
cout<<"\t\t\t||..|%|     ...........               ....|%|                           |%|               ..   ......... ||\t\t"<<endl;
cout<<"\t\t\t||..|%|    |%|%%%%%%|%|..              ...|%|    %%%%%%%%%%%%%%%%%%%%%%%%%%|         |%|  ..     ...|%%%%||\t\t"<<endl; 
cout<<"\t\t\t||......................|%|......................................................         ..     ....... ||\t\t"<<endl;
cout<<"\t\t\t||    ..................  ...............................................................     .......    ||\t\t"<<endl;
cout<<"\t\t\t||..|%|    |%|      |%|..     |%||%|..                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%  ....     |%|.      ||\t\t"<<endl;
cout<<"\t\t\t||..|%|    |%|      |%|..           ....  |%|                                    |%|  ..       |%|.      ||\t\t"<<endl;
cout<<"\t\t\t||..|%|    %%%%%%%%%%%%%%     |%||%| ....                                        |%|  ....     |%|.      ||"<<endl;
cout<<"\t\t\t||..       ...........  |%|          ....             ....................|%|      |%|  ....       |%| . ||"<<endl;
cout<<"\t\t\t||..|%|    |%|%%%%%%|%|.      |%||%| ....                         %%%%%%%%%%%      |%|  ....   |%|...... ||"<<endl;
cout<<"\t\t\t||..|%|    |%|      |%|..     |%||%| ....        %%%%%%%%%%%%%%%%%%%%%%%%%%%%           ....   |%|.      ||"<<endl;
cout<<"\t\t\t||..|%|    |%|      |%|..              ....|%|                                       |%|  ..   |%|...... ||"<<endl;
cout<<"\t\t\t||                                     ....|%|                                       |%|  ..   |%|...... ||"<<endl;
cout<<"\t\t\t||..|%|                       |%||%| ................              |%|%%%%%%%%%%%|%|  ....     |%|...... ||"<<endl;
cout<<"\t\t\t||    ............  ....... ................................................................     ....... ||"<<endl;
cout<<"\033[34m"<<"\t\t\t############################################################################################################"<<endl;
}
void ghost(int gx,int gy)
{
gotoxy(gx,gy);
cout<<"\033[31m"<<ghost_character[0];
}
void clear(int x, int y, char previos)
{
    gotoxy(x,y);
    cout<<"\033[33m"<<previos;
}

void ghost_move(int gx,int gy,char previosChar)
{

	
string direction = "up";

 Sleep(100);
 if(direction == "right")
 {
    char nextLocation = getCharAtxy(gx+1,gy);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|')
    {
        direction = "down";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        erase(gx,gy);
        gx = gx + 1;
        previosChar = nextLocation;
        ghost(gx,gy);
    }
 }
 if(direction == "left")
 {
    char nextLocation = getCharAtxy(gx-1,gy);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|')
    {
        direction = "up";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        erase(gx,gy);
        gx = gx - 1;
        previosChar = nextLocation;
        ghost(gx,gy);
    }
 }
if(direction == "down")
 {
    char nextLocation = getCharAtxy(gx,gy+1);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|')
    {
        direction = "left";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        erase(gx,gy);
        gy = gy + 1;
        previosChar = nextLocation;
        ghost(gx,gy);
    }
 }
 
if(direction == "up")
 {
    char nextLocation = getCharAtxy(gx,gy-1);
    if(nextLocation == '#' || nextLocation == '%' || nextLocation == '|')
    {
        direction = "right";
    }
    else if(nextLocation == ' ' || nextLocation == '.')
    {
        erase(gx,gy);
        gy = gy - 1;
        previosChar = nextLocation;
        ghost(gx,gy);
    }
 }
 





}


void move(bool run)
{

		if(GetAsyncKeyState(VK_LEFT))
		{
				char nextLocation = getCharAtxy(x - 1, y);
				if(nextLocation == ' ' || nextLocation == '.')
				{
				
				erase(x,y);
				x = x -1;
				print_pacman(x,y);
				}
				if(nextLocation == '.')
				{
					z = z + 1;
					gotoxy(149,10);
					cout<<"\033[93m"<<"Points= "<<"\033[97m"<<z;
					gotoxy(158,10);
					
				}
		}
		if(GetAsyncKeyState(VK_RIGHT))
	    {
			char nextLocation = getCharAtxy(x + 1, y);
			if(nextLocation == ' ' || nextLocation == '.')
			
			{
				erase(x,y);
				x = x + 1;
				print_pacman(x,y);
			}
			if(nextLocation == '.')
				{
					z = z + 1;
					gotoxy(149,10);
					cout<<"\033[93m"<<"Points= "<<"\033[97m"<<z;
					gotoxy(158,10);
					
				}
		}
		if(GetAsyncKeyState(VK_UP))
	    {
			char nextLocation = getCharAtxy(x,y - 1);
			if(nextLocation == ' ' || nextLocation == '.')
			
			{
				erase(x,y);
				y =	y - 1;
				print_pacman(x,y);
			}
			if(nextLocation == '.')
				{
					z = z + 1;
					gotoxy(149,10);
					cout<<"\033[93m"<<"Points= "<<"\033[97m"<<z;
					gotoxy(158,10);
					
				}
		}
			if(GetAsyncKeyState(VK_DOWN))
	    {
			char nextLocation = getCharAtxy(x,y + 1);
			if(nextLocation == ' ' || nextLocation == '.')
			
			{
				erase(x,y);
				y =	y + 1;
				print_pacman(x,y);
			}
			if(nextLocation == '.')
				{
					z = z + 1;
					gotoxy(149,10);/*row,column*/
					cout<<"\033[93m"<<"Points= "<<"\033[97m"<<z;
					gotoxy(158,10);
					
				}
		}
		if(GetAsyncKeyState(VK_ESCAPE))
		{
					run = false;
		}
		Sleep(100);	
    
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
int screen_size()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns_of_screen = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows_of_screen = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return 0;
}