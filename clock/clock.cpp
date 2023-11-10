#include <iostream>
#include <windows.h>

using namespace std;

main()
{
    int hour, minute, second, x, y;
    bool check = false;
    x = 0;
    y = 0;
    while (y == 0) //ASCII windows.h files for code
    {
        cout << "Enter Hour: ";
        cin >> hour;
        cout << "Enter Minutes: ";
        cin >> minute;
        cout << "Enter Second: ";
        cin >> second;
        if(hour=='0')

        if (check == true)
        {
            if (hour < 24 && minute <= 60 && second <= 60)
            {
                system("cls");
                cout << hour << ":" << minute << ":" << second << endl;
                ++y;
            }
        }
        while (x == 0)
        {
            system("cls");
            cout << "################################" << endl;
            cout << "##    " << hour << "   :   " << minute << "   :   " << second << "    ##" << endl;
            cout << "################################" << endl;
            Sleep(1000);
            second++;
            if (second > 59)
            {
                second = 0;
                ++minute;
            }
            if (minute > 59)
            {
                minute = 0;
                ++hour;
            }
            if (hour >= 24)
            {
                hour = 0;
            }
        }
    }
}