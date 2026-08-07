#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD p;

    p.X = x;
    p.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
int main()
{
    char move = _getch();

    gotoxy(0, 46);
    cout << "Code 1 = " << (int)move << "      ";

    if (move == 0 || move == 224)
    {
        move = _getch();

        gotoxy(0, 47);
        cout << "Code 2 = " << (int)move << "      ";
    }
}