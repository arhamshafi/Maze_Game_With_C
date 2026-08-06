#include <conio.h>
#include <iostream>
#include <limits>
#include <windows.h>

using namespace std;

void line(HANDLE h)
{
    SetConsoleTextAttribute(h, 14);
    cout << "=========================================================================================================="
            "=============="
         << endl;
}

int menu(HANDLE h, int option)
{
    SetConsoleTextAttribute(h, 10);
    cout << "\n                                           MAZE ESCAPE" << endl;

    SetConsoleTextAttribute(h, 11);
    cout << "                                         THE LOST TEMPLE\n" << endl;

    line(h);
    cout << endl;

    SetConsoleTextAttribute(h, 15);
    cout << "                                 Programming Fundamentals Project" << endl;

    cout << endl;

    SetConsoleTextAttribute(h, 11);
    cout << "      STORY" << endl;

    cout << endl;

    SetConsoleTextAttribute(h, 15);
    cout << "      Deep inside the Lost Temple lies a legendary treasure that" << endl;
    cout << "      has remained hidden for centuries. Many explorers entered" << endl;
    cout << "      the temple, but none of them ever returned." << endl;

    cout << endl;

    cout << "      Now it is your turn to enter the mysterious maze." << endl;
    cout << "      Complete every challenge, survive every danger, and escape" << endl;
    cout << "      with the legendary treasure." << endl;

    cout << endl;

    cout << "      Your Mission :" << endl;

    cout << endl;

    SetConsoleTextAttribute(h, 13);
    cout << "         [K] Find the Hidden Key" << endl;

    SetConsoleTextAttribute(h, 14);
    cout << "         [$] Collect All Coins" << endl;

    SetConsoleTextAttribute(h, 12);
    cout << "         [E] Avoid Dangerous Enemies" << endl;

    SetConsoleTextAttribute(h, 9);
    cout << "         [D] Unlock the Exit Door" << endl;

    SetConsoleTextAttribute(h, 10);
    cout << "         [L] Escape the Temple Alive" << endl;
    cout << endl;

    line(h);
    cout << endl;

    SetConsoleTextAttribute(h, 11);
    cout << "      GAME SYMBOLS" << endl;

    cout << endl;

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
    cout << "      D = Exit Door" << endl;

    SetConsoleTextAttribute(h, 4);
    cout << "      L = Lives" << endl;

    cout << endl;

    line(h);
    cout << endl;
    SetConsoleTextAttribute(h, 11);
    cout << "      Project Team :" << endl;

    cout << endl;

    SetConsoleTextAttribute(h, 15);
    cout << "      Muhammad Arham Shafi Butt" << endl;
    cout << "      Yashfa Arfan Butt" << endl;
    cout << "      Seerat Fatima Butt" << endl;

    cout << endl;

    cout << "      Department    : BS / ADP ITM" << endl;
    cout << "      Course        : Programming Fundamentals" << endl;
    cout << "      Instructor    : Ms. Malaika Pasha" << endl;
    cout << "      Semester      : Spring 2026" << endl;
    cout << endl;

    line(h);
    cout << endl;

    SetConsoleTextAttribute(h, 10);
    cout << "                        [1] Start Game" << endl;

    cout << endl;

    SetConsoleTextAttribute(h, 12);
    cout << "                        [0] Exit" << endl;

    cout << endl;

    line(h);
    cout << endl;

    SetConsoleTextAttribute(h, 15);
    cout << "      Enter Your Choice : ";
    cin >> option;
    while (cin.fail() || (option != 0 && option != 1))
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
        cin >> option;
    }
    return option;
}
void loading(HANDLE h)
{
    system("cls");

    // Loading Screen

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
void Create_Maze(char maze[35][120], int playerRow, int playerCol)
{

    // Fill Maze with Empty Path

    for (int i = 0; i < 35; i++)
    {
        for (int j = 0; j < 120; j++)
        {
            maze[i][j] = '.';
        }
    }

    // Outer Border Walls

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

    // Horizontal Walls

    for (int j = 5; j < 110; j++)
        maze[3][j] = '#';

    for (int j = 10; j < 80; j++)
        maze[6][j] = '#';

    for (int j = 30; j < 115; j++)
        maze[10][j] = '#';

    for (int j = 5; j < 95; j++)
        maze[15][j] = '#';

    for (int j = 40; j < 118; j++)
        maze[20][j] = '#';

    for (int j = 5; j < 70; j++)
        maze[25][j] = '#';

    for (int j = 15; j < 118; j++)
        maze[30][j] = '#';

    // Vertical Walls

    for (int i = 2; i < 25; i++)
        maze[i][12] = '#';

    for (int i = 5; i < 34; i++)
        maze[i][25] = '#';

    for (int i = 1; i < 20; i++)
        maze[i][45] = '#';

    for (int i = 8; i < 32; i++)
        maze[i][60] = '#';

    for (int i = 2; i < 27; i++)
        maze[i][78] = '#';

    for (int i = 10; i < 35; i++)
        maze[i][95] = '#';

    for (int i = 5; i < 30; i++)
        maze[i][108] = '#';

    // Open Gates

    maze[3][25] = '.';
    maze[6][40] = '.';
    maze[10][65] = '.';
    maze[15][30] = '.';
    maze[20][88] = '.';
    maze[25][55] = '.';
    maze[30][90] = '.';
    maze[8][12] = '.';
    maze[18][25] = '.';
    maze[5][45] = '.';
    maze[23][60] = '.';
    maze[11][78] = '.';
    maze[27][95] = '.';
    maze[15][108] = '.';

    // Coins

    maze[2][8] = '$';
    maze[2][95] = '$';
    maze[4][55] = '$';
    maze[5][100] = '$';
    maze[7][18] = '$';
    maze[8][72] = '$';
    maze[9][112] = '$';
    maze[11][35] = '$';
    maze[13][90] = '$';
    maze[16][18] = '$';
    maze[18][40] = '$';
    maze[19][105] = '$';
    maze[22][65] = '$';
    maze[24][15] = '$';
    maze[26][83] = '$';
    maze[28][110] = '$';
    maze[29][42] = '$';
    maze[31][55] = '$';
    maze[32][95] = '$';
    maze[33][15] = '$';

    // Enemies

    maze[4][20] = 'E';
    maze[6][100] = 'E';
    maze[8][50] = 'E';
    maze[12][18] = 'E';
    maze[14][75] = 'E';
    maze[17][58] = 'E';
    maze[21][105] = 'E';
    maze[23][25] = 'E';
    maze[29][85] = 'E';
    maze[32][40] = 'E';

    // Player

    maze[playerRow][playerCol] = 'P';

    // Exit Door

    maze[33][118] = 'D';

    // Key

    maze[31][110] = 'K';
}
void print_Maze(HANDLE h, char maze[35][120])
{
    // Print Maze
    cout << endl << endl;
    for (int i = 0; i < 35; i++)
    {
        for (int j = 0; j < 120; j++)
        {
            if (maze[i][j] == '#')
                SetConsoleTextAttribute(h, 11);

            else if (maze[i][j] == '.')
                SetConsoleTextAttribute(h, 15);

            else if (maze[i][j] == 'P')
                SetConsoleTextAttribute(h, 10);

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

    // switch (move)
    // {
    //     case 'w':
    //     case 'W':
    // }
}
void Maze(HANDLE h)
{
    char maze[35][120];
    int playerRow = 1;
    int playerCol = 1;

    // Game Screen

    system("cls");

    SetConsoleTextAttribute(h, 9);
    line(h);

    SetConsoleTextAttribute(h, 10);
    cout << "\n                                                      MAZE ESCAPE" << endl;

    SetConsoleTextAttribute(h, 11);
    cout << "                                                   THE LOST TEMPLE" << endl << endl;
    line(h);

    SetConsoleTextAttribute(h, 15);
    cout << "\n      Mission : Find the Key, Collect Coins and Escape Alive." << endl << endl;

    SetConsoleTextAttribute(h, 14);
    cout << "      Coins : 0/20";

    SetConsoleTextAttribute(h, 12);
    cout << "        Lives : 3";

    SetConsoleTextAttribute(h, 11);
    cout << "        Key : No";

    cout << endl << endl;

    SetConsoleTextAttribute(h, 9);
    line(h);

    SetConsoleTextAttribute(h, 8);
    cout << "      Controls : W = Up   S = Down   A = Left   D = Right";

    cout << endl;

    SetConsoleTextAttribute(h, 9);
    line(h);

    cout << endl;

    Create_Maze(maze, playerRow, playerCol);
    print_Maze(h, maze);
}
void GameStart(HANDLE h)
{
    loading(h);
    Maze(h);
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