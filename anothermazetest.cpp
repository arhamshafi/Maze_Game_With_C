#include <conio.h>
#include <ctime>
#include <iostream>
#include <limits>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
  COORD p;
  p.X = x;
  p.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void line(HANDLE h) {
  SetConsoleTextAttribute(h, 14);
  cout << "===================================================================="
          "==========================================="
       << endl;
}

void projectTeam(HANDLE h) {
  SetConsoleTextAttribute(h, 9);
  line(h);
  SetConsoleTextAttribute(h, 11);
  cout << "\n      PROJECT TEAM" << endl;
  SetConsoleTextAttribute(h, 15);
  cout << "      ----------------------------------------" << endl;
  cout << "      Muhammad Arham Shafi Butt" << endl;
  cout << "      Yashfa Arfan Butt" << endl;
  cout << "      Seerat Fatima Butt" << endl << endl;
  cout << "      Department : BS / ADP ITM" << endl;
  cout << "      Course     : Programming Fundamentals" << endl;
  cout << "      Semester   : Spring 2026" << endl;
  cout << "      Submitted To: Ms. Malaika Pasha" << endl << endl;
}

void getTime(time_t startTime, int &minutes, int &seconds) {
  time_t endTime = time(0);
  int timeTaken = (int)difftime(endTime, startTime);
  minutes = timeTaken / 60;
  seconds = timeTaken % 60;
}

int inputChoice(HANDLE h, int &choice) {
  cin >> choice;
  while (cin.fail() || (choice != 0 && choice != 1)) {
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      SetConsoleTextAttribute(h, 12);
      cout << "\n      Invalid Input! Please enter numbers only\n";
    } else {
      SetConsoleTextAttribute(h, 12);
      cout << "\n      Invalid Choice! Please Enter 0 or 1\n";
    }
    SetConsoleTextAttribute(h, 15);
    cout << "\n      Enter Your Choice : ";
    cin >> choice;
  }
  return choice;
}

int menu(HANDLE h, int option) {
  SetConsoleTextAttribute(h, 10);
  cout << "\n                                           MAZE ESCAPE" << endl;
  SetConsoleTextAttribute(h, 11);
  cout << "                                         THE LOST TEMPLE\n" << endl;
  line(h);
  cout << endl;
  SetConsoleTextAttribute(h, 15);
  cout << "                                 Programming Fundamentals Project"
       << endl
       << endl;

  SetConsoleTextAttribute(h, 11);
  cout << "      STORY" << endl << endl;
  SetConsoleTextAttribute(h, 15);
  cout << "      Deep inside the Lost Temple lies a legendary treasure that"
       << endl;
  cout << "      has remained hidden for centuries. Many explorers entered"
       << endl;
  cout << "      the temple, but none of them ever returned." << endl << endl;
  cout << "      Now it is your turn to enter the mysterious maze." << endl;
  cout << "      Complete every challenge, survive every danger, and escape"
       << endl;
  cout << "      with the legendary treasure." << endl << endl;
  cout << "      Your Mission :" << endl << endl;

  SetConsoleTextAttribute(h, 13);
  cout << "         [K] Find the Hidden Key" << endl;
  SetConsoleTextAttribute(h, 14);
  cout << "         [$] Collect All Coins" << endl;
  SetConsoleTextAttribute(h, 12);
  cout << "         [E] Avoid Dangerous Enemies" << endl;
  SetConsoleTextAttribute(h, 9);
  cout << "         [D] Unlock the Exit Door" << endl;
  SetConsoleTextAttribute(h, 10);
  cout << "         [L] Escape the Temple Alive" << endl << endl;

  line(h);
  SetConsoleTextAttribute(h, 11);
  cout << "\n      GAME SYMBOLS\n\n";
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
  cout << "      D = Exit Door" << endl << endl;

  line(h);
  SetConsoleTextAttribute(h, 11);
  cout << "\n      Project Team :\n" << endl;
  SetConsoleTextAttribute(h, 15);
  cout << "      Muhammad Arham Shafi Butt" << endl;
  cout << "      Yashfa Arfan Butt" << endl;
  cout << "      Seerat Fatima Butt" << endl << endl;
  cout << "      Department    : BS / ADP ITM" << endl;
  cout << "      Course        : Programming Fundamentals" << endl;
  cout << "      Instructor    : Ms. Malaika Pasha" << endl;
  cout << "      Semester      : Spring 2026" << endl << endl;

  line(h);
  SetConsoleTextAttribute(h, 10);
  cout << "\n                        [1] Start Game\n";
  SetConsoleTextAttribute(h, 12);
  cout << "\n                        [0] Exit\n\n";
  line(h);
  SetConsoleTextAttribute(h, 15);
  cout << "\n      Enter Your Choice : ";
  return inputChoice(h, option);
}

void loading(HANDLE h) {
  system("cls");
  line(h);
  SetConsoleTextAttribute(h, 15);
  cout << "\nLoading : [ ";
  SetConsoleTextAttribute(h, 8);

  for (int i = 1; i <= 30; i++) {
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

void Create_Maze(char maze[35][120], int playerRow, int playerCol) {
  for (int i = 0; i < 35; i++)
    for (int j = 0; j < 120; j++)
      maze[i][j] = '.';

  for (int i = 0; i < 35; i++)
    maze[i][0] = maze[i][119] = '#';

  for (int j = 0; j < 120; j++)
    maze[0][j] = maze[34][j] = '#';

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

  maze[3][25] = maze[6][40] = maze[10][65] = maze[15][30] = '.';
  maze[20][88] = maze[25][55] = maze[30][90] = maze[8][12] = '.';
  maze[18][25] = maze[5][45] = maze[23][60] = maze[11][78] = '.';
  maze[27][95] = maze[15][108] = '.';

  maze[2][8] = maze[2][95] = maze[4][55] = maze[5][100] = '$';
  maze[7][18] = maze[8][72] = maze[9][112] = maze[11][35] = '$';
  maze[13][90] = maze[16][18] = maze[18][40] = maze[19][105] = '$';
  maze[22][65] = maze[24][15] = maze[26][83] = maze[28][110] = '$';
  maze[29][42] = maze[31][55] = maze[32][95] = maze[33][15] = '$';

  maze[4][20] = maze[6][100] = maze[8][50] = maze[12][18] = 'E';
  maze[14][75] = maze[17][58] = maze[21][105] = maze[23][25] = 'E';
  maze[29][85] = maze[32][40] = 'E';

  maze[33][118] = 'D';
  maze[31][110] = 'K';
}

void print_Maze(HANDLE h, char maze[35][120]) {
  cout << endl << endl;
  for (int i = 0; i < 35; i++) {
    for (int j = 0; j < 120; j++) {
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

int playAgainMenu(HANDLE h) {
  int choice;
  SetConsoleTextAttribute(h, 9);
  line(h);
  SetConsoleTextAttribute(h, 11);
  cout << "\n                                              ***  P L A Y  A G A "
          "I N  ***\n\n";

  SetConsoleTextAttribute(h, 9);
  line(h);
  SetConsoleTextAttribute(h, 10);
  cout << "\n                        [1] Play Again\n";
  SetConsoleTextAttribute(h, 12);
  cout << "\n                        [0] Exit\n\n";
  SetConsoleTextAttribute(h, 9);
  line(h);
  SetConsoleTextAttribute(h, 15);
  cout << "\n      Enter Your Choice : ";
  return inputChoice(h, choice);
}

void gameDetails(HANDLE h, int score, int lives, int minutes, int seconds,
                 bool win) {
  SetConsoleTextAttribute(h, 15);
  cout << "      -------------------------------------------------" << endl;
  SetConsoleTextAttribute(h, 14);
  cout << "      Coins Collected   : " << score << " / " << (win ? 18 : 20)
       << endl;
  SetConsoleTextAttribute(h, 12);
  cout << "      Lives Remaining   : " << (win ? lives : 0) << " / 3" << endl;
  SetConsoleTextAttribute(h, 11);
  cout << "      Time " << (win ? "Taken" : "Survived") << "        : "
       << minutes << "m " << seconds << "s" << endl;
  SetConsoleTextAttribute(h, 15);
  cout << "      -------------------------------------------------" << endl;
}

void Maze(HANDLE h) {
  char maze[35][120];
  int playerRow = 1, playerCol = 1, mazeStart_R, mazeStart_C = 0;
  int score = 0, lives = 3, scoreRow;
  bool hasKey = false, gameRunning = true;
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  system("cls");
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(h, &cursorInfo);
  cursorInfo.bVisible = false;
  SetConsoleCursorInfo(h, &cursorInfo);

  SetConsoleTextAttribute(h, 9);
  line(h);
  SetConsoleTextAttribute(h, 10);
  cout << "\n                                                      MAZE ESCAPE"
       << endl;
  SetConsoleTextAttribute(h, 11);
  cout << "                                                   THE LOST TEMPLE"
       << endl
       << endl;
  line(h);

  SetConsoleTextAttribute(h, 15);
  cout << "\n      Mission : Find the Key, Collect Coins and Escape Alive."
       << endl
       << endl;

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
  cout << "      Controls : W = Up   S = Down   A = Left   D = Right" << endl;
  SetConsoleTextAttribute(h, 9);
  line(h);
  cout << endl;

  GetConsoleScreenBufferInfo(h, &csbi);
  mazeStart_R = csbi.dwCursorPosition.Y + 2;

  Create_Maze(maze, playerRow, playerCol);
  print_Maze(h, maze);

  gotoxy(mazeStart_C + playerCol, mazeStart_R + playerRow);
  SetConsoleTextAttribute(h, 10);
  cout << 'P';

  time_t startTime = time(0);

  while (gameRunning) {
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
      move = _getch();

    switch (move) {
    case 'W':
    case 'w':
    case 72:
      if (maze[playerRow - 1][playerCol] != '#')
        playerRow--;
      gotoxy(40, mazeStart_R + 36);
      cout << string(100, ' ');
      break;
    case 'S':
    case 's':
    case 80:
      if (maze[playerRow + 1][playerCol] != '#')
        playerRow++;
      gotoxy(40, mazeStart_R + 36);
      cout << string(100, ' ');
      break;
    case 'A':
    case 'a':
    case 75:
      if (maze[playerRow][playerCol - 1] != '#')
        playerCol--;
      gotoxy(40, mazeStart_R + 36);
      cout << string(100, ' ');
      break;
    case 'D':
    case 'd':
    case 77:
      if (maze[playerRow][playerCol + 1] != '#')
        playerCol++;
      gotoxy(40, mazeStart_R + 36);
      cout << string(100, ' ');
      break;
    default:
      gotoxy(40, mazeStart_R + 36);
      SetConsoleTextAttribute(h, 12);
      cout << "Invalid Key! Use W A S D or Arrow Keys.      ";
      break;
    }

    if (maze[playerRow][playerCol] == 'E') {
      lives--;
      SetConsoleTextAttribute(h, 12);
      gotoxy(35, scoreRow);
      cout << "Lives : " << lives << "/3";

      if (lives == 0) {
        int minutes, seconds;
        getTime(startTime, minutes, seconds);
        gameRunning = false;
        system("cls");

        line(h);
        SetConsoleTextAttribute(h, 12);
        cout << "\n                                              ***  G A M E  "
                "O V E R  ***\n\n";
        line(h);
        SetConsoleTextAttribute(h, 14);
        cout << "\n      You were caught in the Lost Temple... your journey "
                "ends here.\n"
             << endl;
        gameDetails(h, score, lives, minutes, seconds, false);
        projectTeam(h);
        SetConsoleTextAttribute(h, 10);
        cout << "      Thank you for playing Maze Escape!" << endl;
        cout << "      Thank you for your time and attention." << endl << endl;
        SetConsoleTextAttribute(h, 9);
        line(h);
        SetConsoleTextAttribute(h, 15);
        cout << "\n      PROJECT PRESENTATION COMPLETED" << endl;
        return;
      }
    } else if (maze[playerRow][playerCol] == '$') {
      score++;
      maze[playerRow][playerCol] = '.';
      gotoxy(17, scoreRow);
      SetConsoleTextAttribute(h, 14);
      cout << "Coins : " << score << "/18";
    } else if (maze[playerRow][playerCol] == 'K') {
      hasKey = true;
      maze[playerRow][playerCol] = '.';
      SetConsoleTextAttribute(h, 11);
      gotoxy(50, scoreRow);
      cout << "Key : " << (hasKey ? "Yes" : "No");
    } else if (maze[playerRow][playerCol] == 'D') {
      if (hasKey) {
        int minutes, seconds;
        getTime(startTime, minutes, seconds);
        system("cls");

        SetConsoleTextAttribute(h, 9);
        line(h);
        SetConsoleTextAttribute(h, 10);
        cout << "\n                                              ***  Y O U  W "
                "I N  ***\n\n";

        SetConsoleTextAttribute(h, 9);
        line(h);
        SetConsoleTextAttribute(h, 14);
        cout << "\n      CONGRATULATIONS! You escaped the Lost Temple with the "
                "treasure!\n"
             << endl;
        gameDetails(h, score, lives, minutes, seconds, true);
        projectTeam(h);
        SetConsoleTextAttribute(h, 10);
        cout << "      Thank you for playing Maze Escape!" << endl;
        cout << "      Thank you for your time and attention." << endl << endl;
        SetConsoleTextAttribute(h, 9);
        line(h);
        SetConsoleTextAttribute(h, 15);
        cout << "\n      PROJECT PRESENTATION COMPLETED" << endl;
        gameRunning = false;
        return;
      } else {
        gotoxy(40, mazeStart_R + 36);
        SetConsoleTextAttribute(h, 12);
        cout << "First collect the key!                              ";
      }
    }

    if (gameRunning) {
      gotoxy(mazeStart_C + playerCol, mazeStart_R + playerRow);
      SetConsoleTextAttribute(h, 10);
      cout << 'P';
    }
  }
}

void ExitGame(HANDLE h) {
  system("cls");
  line(h);
  SetConsoleTextAttribute(h, 12);
  cout << "\n                                                    EXITING GAME\n"
       << endl;
  line(h);
  SetConsoleTextAttribute(h, 15);
  cout << "\n      Thank you for playing Maze Escape!" << endl;
  cout << "      We hope you enjoyed your adventure." << endl << endl;
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
  cout << "      See You Again..." << endl << endl;
  line(h);
  Sleep(5000);
}

void GameStart(HANDLE h) {
  do {
    loading(h);
    Maze(h);
  } while (playAgainMenu(h) == 1);

  ExitGame(h);
}

int main() {
  int option;
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  cout << "\n\n";
  line(h);
  option = menu(h, option);
  (option == 1) ? GameStart(h) : ExitGame(h);
  cout << endl << endl;
  return 0;
}