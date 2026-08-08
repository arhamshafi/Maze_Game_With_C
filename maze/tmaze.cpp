#include <conio.h>
#include <ctime>
#include <iostream>
#include <limits>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y)
{
    COORD p;
    p.X = x;
    p.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
void line(HANDLE h)
{
    SetConsoleTextAttribute(h, 14);
    cout << "===================================================================="
            "======================================"
            "=============="
         << endl;
}
int getValidChoice(HANDLE h)
{
    int choice;
    SetConsoleTextAttribute(h, 15);
    cout << "      Enter Your Choice : ";
    cin >> choice;
    while (cin.fail() || (choice != 0 && choice != 1))
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            SetConsoleTextAttribute(h, 12);
            cout << "\n      Invalid Input! Please enter numbers only\n";
        }
        else
        {
            SetConsoleTextAttribute(h, 12);
            cout << "\n      Invalid Choice! Please Enter 0 or 1\n";
        }
        SetConsoleTextAttribute(h, 15);
        cout << "\n      Enter Your Choice : ";
        cin >> choice;
    }
    return choice;
}
int menu(HANDLE h, int option)
{
    SetConsoleTextAttribute(h, 10);
    cout << "\n                                           MAZE ESCAPE" << endl;
    SetConsoleTextAttribute(h, 11);
    cout << "                                         THE LOST TEMPLE\n" << endl;
    line(h);
    SetConsoleTextAttribute(h, 15);
    cout << "\n                                 Programming Fundamentals Project\n" << endl;
    SetConsoleTextAttribute(h, 11);
    cout << "      STORY\n" << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "      Deep inside the Lost Temple lies a legendary treasure that "
            "has\n"
         << "      remained hidden for centuries. Many explorers entered but "
            "none\n"
         << "      ever returned. Now it is your turn: complete every challenge,\n"
         << "      survive every danger, and escape with the legendary "
            "treasure.\n\n"
         << "      Your Mission :\n"
         << endl;
    SetConsoleTextAttribute(h, 13);
    cout << "         [K] Find the Hidden Key" << endl;
    SetConsoleTextAttribute(h, 14);
    cout << "         [$] Collect All Coins" << endl;
    SetConsoleTextAttribute(h, 12);
    cout << "         [E] Avoid Dangerous Enemies" << endl;
    SetConsoleTextAttribute(h, 9);
    cout << "         [D] Unlock the Exit Door" << endl;
    SetConsoleTextAttribute(h, 10);
    cout << "         [L] Escape the Temple Alive\n" << endl;
    line(h);
    SetConsoleTextAttribute(h, 11);
    cout << "\n      GAME SYMBOLS\n" << endl;
    SetConsoleTextAttribute(h, 9);
    cout << "      # = Wall" << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "      . = Empty Path" << endl;
    SetConsoleTextAttribute(h, 10);
    cout << "      P = Player" << endl;
    SetConsoleTextAttribute(h, 13);
    cout << "      K = Key" << endl;
    SetConsoleTextAttribute(h, 14);
    cout << "      $ = Coin" << endl;
    SetConsoleTextAttribute(h, 12);
    cout << "      E = Enemy" << endl;
    SetConsoleTextAttribute(h, 11);
    cout << "      D = Exit Door\n" << endl;
    line(h);
    SetConsoleTextAttribute(h, 11);
    cout << "\n      Project Team :\n" << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "      Muhammad Arham Shafi Butt\n      Yashfa Arfan Butt\n      "
            "Seerat Fatima Butt\n"
         << endl;
    cout << "      Department    : BS / ADP ITM\n"
         << "      Course        : Programming Fundamentals\n"
         << "      Instructor    : Ms. Malaika Pasha\n"
         << "      Semester      : Spring 2026\n"
         << endl;
    line(h);
    SetConsoleTextAttribute(h, 10);
    cout << "\n                        [1] Start Game\n" << endl;
    SetConsoleTextAttribute(h, 12);
    cout << "                        [0] Exit\n" << endl;
    line(h);
    cout << endl;
    return getValidChoice(h);
}
void loading(HANDLE h)
{
    system("cls");
    line(h);
    SetConsoleTextAttribute(h, 15);
    cout << "\nLoading : [ ";
    SetConsoleTextAttribute(h, 8);
    for (int i = 1; i <= 30; i++)
    {
        cout << "=";
        if (i < 10)
            Sleep(60);
        else if (i < 20)
            Sleep(180);
        else
            Sleep(70);
    }
    SetConsoleTextAttribute(h, 15);
    cout << " ] 100%\n";
    Sleep(500);
}
int hWalls[7][3] = {{3, 5, 110}, {6, 10, 80}, {10, 30, 115}, {15, 5, 95}, {20, 40, 118}, {25, 5, 70}, {30, 15, 118}};
int vWalls[7][3] = {{12, 2, 25}, {25, 5, 34}, {45, 1, 20}, {60, 8, 32}, {78, 2, 27}, {95, 10, 35}, {108, 5, 30}};
int gates[14][2] = {{3, 25}, {6, 40},  {10, 65}, {15, 30}, {20, 88}, {25, 55}, {30, 90},
                    {8, 12}, {18, 25}, {5, 45},  {23, 60}, {11, 78}, {27, 95}, {15, 108}};
int coins[20][2] = {{2, 8},   {2, 95},   {4, 55},  {5, 100}, {7, 18},   {8, 72},  {9, 112},
                    {11, 35}, {13, 90},  {16, 18}, {18, 40}, {19, 105}, {22, 65}, {24, 15},
                    {26, 83}, {28, 110}, {29, 42}, {31, 55}, {32, 95},  {33, 15}};
int enemies[10][2] = {{4, 20},  {6, 100},  {8, 50},  {12, 18}, {14, 75},
                      {17, 58}, {21, 105}, {23, 25}, {29, 85}, {32, 40}};
void Create_Maze(char maze[35][120], int playerRow, int playerCol)
{
    for (int i = 0; i < 35; i++)
        for (int j = 0; j < 120; j++)
            maze[i][j] = '.';
    for (int i = 0; i < 35; i++)
    {
        maze[i][0] = '#';
        maze[i][119] = '#';
    }
    for (int j = 0; j < 120; j++)
    {
        maze[0][j] = '#';
        maze[34][j] = '#';
    }
    for (auto& w : hWalls)
        for (int j = w[1]; j < w[2]; j++)
            maze[w[0]][j] = '#';
    for (auto& w : vWalls)
        for (int i = w[1]; i < w[2]; i++)
            maze[i][w[0]] = '#';
    for (auto& g : gates)
        maze[g[0]][g[1]] = '.';
    for (auto& c : coins)
        maze[c[0]][c[1]] = '$';
    for (auto& e : enemies)
        maze[e[0]][e[1]] = 'E';
    maze[33][118] = 'D';
    maze[31][110] = 'K';
}
void print_Maze(HANDLE h, char maze[35][120])
{
    cout << endl << endl;
    for (int i = 0; i < 35; i++)
    {
        for (int j = 0; j < 120; j++)
        {
            if (maze[i][j] == '#')
                SetConsoleTextAttribute(h, 11);
            else if (maze[i][j] == '.')
                SetConsoleTextAttribute(h, 15);
            else if (maze[i][j] == '$')
                SetConsoleTextAttribute(h, 14);
            else if (maze[i][j] == 'K')
                SetConsoleTextAttribute(h, 11);
            else if (maze[i][j] == 'E')
                SetConsoleTextAttribute(h, 12);
            else if (maze[i][j] == 'D')
                SetConsoleTextAttribute(h, 13);
            cout << maze[i][j];
        }
        cout << endl;
    }
    SetConsoleTextAttribute(h, 15);
}
void printFooter(HANDLE h, int minutes, int seconds)
{
    SetConsoleTextAttribute(h, 11);
    cout << "\n      Time Taken/Survived : " << minutes << "m " << seconds << "s" << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "      -------------------------------------------------" << endl;
    cout << endl;
    SetConsoleTextAttribute(h, 11);
    cout << "      PROJECT TEAM" << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "      ----------------------------------------" << endl;
    cout << "      Muhammad Arham Shafi Butt" << endl;
    cout << "      Yashfa Arfan Butt" << endl;
    cout << "      Seerat Fatima Butt" << endl;
    cout << endl;
    cout << "      Department : BS / ADP ITM" << endl;
    cout << "      Course     : Programming Fundamentals" << endl;
    cout << "      Semester   : Spring 2026" << endl;
    cout << "      Submitted To: Ms. Malaika Pasha" << endl;
    cout << endl;
    SetConsoleTextAttribute(h, 10);
    cout << "      Thank you for playing Maze Escape!" << endl;
    cout << "      Thank you for your time and attention." << endl;
    cout << endl;
    SetConsoleTextAttribute(h, 9);
    line(h);
    SetConsoleTextAttribute(h, 15);
    cout << "\n      PROJECT PRESENTATION COMPLETED" << endl;
}
void getElapsedTime(time_t startTime, int& minutes, int& seconds)
{
    time_t endTime = time(0);
    int timeTaken = (int)difftime(endTime, startTime);
    minutes = timeTaken / 60;
    seconds = timeTaken % 60;
}
int playAgainMenu(HANDLE h)
{
    SetConsoleTextAttribute(h, 9);
    line(h);
    SetConsoleTextAttribute(h, 11);
    cout << "\n\n                        ---  PLAY  AGAIN  ?  ---\n\n";
    SetConsoleTextAttribute(h, 9);
    line(h);
    cout << endl;
    SetConsoleTextAttribute(h, 10);
    cout << "                        [1] Play Again\n" << endl;
    SetConsoleTextAttribute(h, 12);
    cout << "                        [0] Exit\n" << endl;
    SetConsoleTextAttribute(h, 9);
    line(h);
    cout << endl;
    return getValidChoice(h);
}
void Maze(HANDLE h)
{
    char maze[35][120];
    int playerRow = 1;
    int playerCol = 1;
    int mazeStart_R;
    int mazeStart_C = 0;
    int score = 0;
    int lives = 3;
    bool hasKey = false;
    bool gameRunning = true;
    int scoreRow;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    system("cls"); // Game Screen
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(h, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(h, &cursorInfo);
    SetConsoleTextAttribute(h, 9);
    line(h);
    SetConsoleTextAttribute(h, 10);
    cout << "\n                                                      MAZE ESCAPE" << endl;
    SetConsoleTextAttribute(h, 11);
    cout << "                                                   THE LOST TEMPLE" << endl << endl;
    line(h);
    SetConsoleTextAttribute(h, 15);
    cout << "\n      Mission : Find the Key, Collect Coins and Escape Alive." << endl << endl;
    GetConsoleScreenBufferInfo(h, &csbi);
    scoreRow = csbi.dwCursorPosition.Y + 1;
    SetConsoleTextAttribute(h, 14);
    gotoxy(17, scoreRow);
    cout << "Coins : " << score << "/18";
    SetConsoleTextAttribute(h, 12);
    gotoxy(35, scoreRow);
    cout << "Lives : " << lives << "/3";
    SetConsoleTextAttribute(h, 11);
    gotoxy(50, scoreRow);
    cout << "Key : " << (hasKey ? "Yes" : "No");
    cout << endl << endl;
    SetConsoleTextAttribute(h, 9);
    line(h);
    SetConsoleTextAttribute(h, 8);
    cout << "      Controls : W = Up   S = Down   A = Left   D = Right";
    cout << endl;
    SetConsoleTextAttribute(h, 9);
    line(h);
    cout << endl;
    GetConsoleScreenBufferInfo(h, &csbi); // "abhi cursor kahan hai? — pucha
    mazeStart_R = csbi.dwCursorPosition.Y + 2;
    Create_Maze(maze, playerRow, playerCol);
    print_Maze(h, maze);
    gotoxy(mazeStart_C + playerCol, mazeStart_R + playerRow);
    SetConsoleTextAttribute(h, 10);
    cout << 'P';
    time_t startTime = time(0);
    while (gameRunning)
    {
        int move = _getch();
        char cell = maze[playerRow][playerCol];
        gotoxy(mazeStart_C + playerCol, mazeStart_R + playerRow);
        if (cell == 'E')
            SetConsoleTextAttribute(h, 12);
        else if (cell == 'D')
            SetConsoleTextAttribute(h, 13);
        else
            SetConsoleTextAttribute(h, 15);
        cout << cell;
        if (move == -32 || move == 224)
        {
            move = _getch();
        }
        switch (move)
        {
            case 'W':
            case 'w':
            case 72:
                if (maze[playerRow - 1][playerCol] != '#')
                    playerRow--;
                gotoxy(40, mazeStart_R + 36);
                cout << "                                                                "
                        "                          "
                        " ";
                break;
            case 'S':
            case 's':
            case 80:
                if (maze[playerRow + 1][playerCol] != '#')
                    playerRow++;
                gotoxy(40, mazeStart_R + 36);
                cout << "                                                                "
                        "                          "
                        " ";
                break;
            case 'A':
            case 'a':
            case 75:
                if (maze[playerRow][playerCol - 1] != '#')
                    playerCol--;
                gotoxy(40, mazeStart_R + 36);
                cout << "                                                                "
                        "                          "
                        " ";
                break;
            case 'D':
            case 'd':
            case 77:
                if (maze[playerRow][playerCol + 1] != '#')
                    playerCol++;
                gotoxy(40, mazeStart_R + 36);
                cout << "                                                                "
                        "                          "
                        " ";
                break;
            default:
                gotoxy(40, mazeStart_R + 36);
                SetConsoleTextAttribute(h, 12);
                cout << "Invalid Key! Use W A S D or Arrow Keys.      ";
                break;
        }
        if (maze[playerRow][playerCol] == 'E')
        {
            lives--;
            SetConsoleTextAttribute(h, 12);
            gotoxy(35, scoreRow);
            cout << "Lives : " << lives << "/3";
            if (lives == 0)
            {
                gameRunning = false;
                int minutes, seconds;
                getElapsedTime(startTime, minutes, seconds);
                system("cls");
                SetConsoleTextAttribute(h, 12);
                line(h);
                cout << "\n\n                    ***  G A M E   O V E R  ***\n\n";
                SetConsoleTextAttribute(h, 14);
                cout << "\n      You were caught in the Lost Temple... your journey "
                        "ends here.\n"
                     << endl;
                SetConsoleTextAttribute(h, 15);
                cout << "      -------------------------------------------------" << endl;
                SetConsoleTextAttribute(h, 14);
                cout << "      Coins Collected   : " << score << " / 18" << endl;
                SetConsoleTextAttribute(h, 12);
                cout << "      Lives Remaining   : 0 / 3" << endl;
                printFooter(h, minutes, seconds);
                return;
            }
        }
        else if (maze[playerRow][playerCol] == '$')
        {
            score++;
            maze[playerRow][playerCol] = '.';
            gotoxy(17, scoreRow);
            SetConsoleTextAttribute(h, 14);
            cout << "Coins : " << score << "/18";
        }
        else if (maze[playerRow][playerCol] == 'K')
        {
            hasKey = true;
            maze[playerRow][playerCol] = '.';
            SetConsoleTextAttribute(h, 11);
            gotoxy(50, scoreRow);
            cout << "Key : " << (hasKey ? "Yes" : "No");
        }
        else if (maze[playerRow][playerCol] == 'D')
        {
            if (hasKey)
            {
                int minutes, seconds;
                getElapsedTime(startTime, minutes, seconds);
                system("cls");
                SetConsoleTextAttribute(h, 9);
                line(h);
                SetConsoleTextAttribute(h, 10);
                cout << "\n\n                    ***  Y O U   W I N  ***\n\n";
                SetConsoleTextAttribute(h, 14);
                cout << "\n      CONGRATULATIONS! You escaped the Lost Temple with the "
                        "treasure!\n"
                     << endl;
                SetConsoleTextAttribute(h, 15);
                cout << "      -------------------------------------------------" << endl;
                SetConsoleTextAttribute(h, 14);
                cout << "      Coins Collected   : " << score << " / 18" << endl;
                SetConsoleTextAttribute(h, 12);
                cout << "      Lives Remaining   : " << lives << " / 3" << endl;
                printFooter(h, minutes, seconds);
                gameRunning = false;
                return;
            }
            else
            {
                gotoxy(40, mazeStart_R + 36);
                SetConsoleTextAttribute(h, 12);
                cout << "First collect the key!                              ";
            }
        }
        if (gameRunning)
        {
            gotoxy(mazeStart_C + playerCol, mazeStart_R + playerRow);
            SetConsoleTextAttribute(h, 10);
            cout << 'P';
        }
    }
}
void ExitGame(HANDLE h)
{
    system("cls");
    line(h);
    SetConsoleTextAttribute(h, 12);
    cout << "\n                                                    EXITING GAME\n" << endl;
    line(h);
    cout << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "\n      Thank you for playing Maze Escape!" << endl;
    cout << "      We hope you enjoyed your adventure." << endl;
    cout << endl;
    SetConsoleTextAttribute(h, 11);
    cout << "      Project Team :" << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "      ----------------------------------------" << endl;
    cout << "      Muhammad Arham Shafi Butt" << endl;
    cout << "      Yashfa Arfan Butt" << endl;
    cout << "      Seerat Fatima Butt" << endl;
    cout << "      Submited to: Ms Malaika Pasha\n\n";
    SetConsoleTextAttribute(h, 10);
    cout << "      Have a Great Day!" << endl;
    cout << "      See You Again..." << endl;
    cout << endl;
    line(h);
    Sleep(5000);
}
void GameStart(HANDLE h)
{
    do
    {
        loading(h);
        Maze(h);
    } while (playAgainMenu(h) == 1);
    ExitGame(h);
}
int main()
{
    int option;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\n\n";
    line(h);
    option = menu(h, option);
    (option == 1) ? GameStart(h) : ExitGame(h);
    cout << endl << endl;
    return 0;
}