#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
// Character................................
char heli1[14] = {' ', ' ', ' ', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-'};
char heli2[12] = {'*', '>', '=', '=', '=', '=', '=', '[', '_', ']', 'L', ')'};
char heli3[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ',', ' ', ','};
int bulletX[100];
int bulletY[100];
int index = 0;
int timer = 0;
// ........................... Character

// enemy 1...........

char c1 = 219;
char c2 = 185;
char aero1[5] = {' ', ' ', '/', '|', ' '};
char aero2[6] = {'C', c1, c1, c1, c1, c2};
char aero3[5] = {' ', ' ', '|', '/', ' '};
int enemy1X = 155;
int enemy1Y = 39;
//  enemy 1........

// enemy 2.........

char e1 = 178;
char e2 = 185;
char enemy1[5] = {' ', ' ', '/', '|', ' '};
char enemy2[6] = {'C', e1, e1, e1, e1, e2};
char enemy3[5] = {' ', ' ', '|', '/', ' '};
int enemy2X = 155;
int enemy2Y = 10;

//  enemy 2......

// enemy 3.............
char b1 = 219;
char b2 = 186;
char box1[3] = {b1, b1, b1};
char box2[3] = {' ', b2, ' '};
int enemy3X = 10;
int enemy3Y = 3;

// enemy 3 .......

// enemy1 bullets.............
int enemy1BulletX[100];
int enemy1BulletY[100];
int index1 = 0;

// enemy1 bullets...........

// enemy2 bullets...........
int enemy2BulletX[100];
int enemy2BulletY[100];
int index2 = 0;

// enemy2 bullets...........

// enemy3 bullets...........
int enemy3BulletX[100];
int enemy3BulletY[100];
int index3 = 0;

// enemy3 bullets...........

// Function..................................
int heliX = 10;
int heliY = 10;
string direction = "up";
string direction2 = "left";
string direction3 = "right";
int health = 9;

int score = 0;
void menu();
void instruction();
void printHeli();
void maze();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void removeHeli();
void bullets();
void moveBullet();
void printEnemy1();
void printEnemy2();
void printEnemy3();
void eraseEnemy1();
void eraseEnemy2();
void eraseEnemy3();
void moveEnemy1();
void moveEnemy2();
void moveEnemy3();
void enemy1Bullet();
void moveEnemy1Bullet();
void enemy2Bullet();
void moveEnemy2Bullet();
void enemy3Bullet();
void moveEnemy3Bullet();
void addScore();
void printAddScore();
void collisionHeli();
void collisionEnemy3();
void printHealth();
//......................................Function

// keys...............
void goLeft();
void goRight();
void goDown();
void goUp();

main()
{
  bool gameRunning = true;
  int option;

  while (true)
  {
    system("cls");
    menu();
    cout << "Enter the option : ";
    cin >> option;
    if (option == 1)
    {
      system("cls");
      cout << ".......................Welcome to Heli Havoc Game................" << endl;
      cout << endl;
      maze();
      printHeli();
      printEnemy1();
      printEnemy2();
      printEnemy3();
      enemy1Bullet();
      while (gameRunning)
      {
        if (GetAsyncKeyState(VK_UP))
        {
          goUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
          goDown();
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
          goLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
          goRight();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
          bullets();
        }
        if (timer == 20)
        {
          enemy1Bullet();
          enemy2Bullet();
        }
        if (timer == 25)
        {
          enemy3Bullet();
          timer = 0;
        }

        moveBullet();
        moveEnemy1();
        moveEnemy3();
        Sleep(30);
        moveEnemy1Bullet();
        if (timer % 10 == 0)
        {
          moveEnemy2();
        }
        moveEnemy2Bullet();
        moveEnemy3Bullet();
        // Sleep(50);
        collisionHeli();
        printHealth();
        printAddScore();
        if(score == 50)
        {
          cout<<"................YOU WIN..........."<<endl;
          Sleep(500);
          score = 0;
          break;
        }
        timer++;
        // Sleep(50);
      }
    }
    if (option == 2)
    {
      instruction();
    }
    if (option == 3)
    {
      break;
    }
    cout << "Press any character to continue....................." << endl;
    getch();
  }
}
void menu()
{
  int k = 1;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  system("cls");
  cout << "  /$$   /$$ /$$$$$$$$ /$$       /$$$$$$       /$$   /$$  /$$$$$$  /$$    /$$  /$$$$$$   /$$$$$$  " << endl;
  cout << " | $$  | $$| $$_____/| $$      |_  $$_/      | $$  | $$ /$$__  $$| $$   | $$ /$$__  $$ /$$__  $$ " << endl;
  cout << " | $$  | $$| $$      | $$        | $$        | $$  | $$| $$  \\ $$| $$   | $$| $$  \\ $$| $$  \\__/ " << endl;
  cout << " | $$$$$$$$| $$$$$   | $$        | $$        | $$$$$$$$| $$$$$$$$|  $$ / $$/| $$  | $$| $$       " << endl;
  cout << " | $$__  $$| $$__/   | $$        | $$        | $$__  $$| $$__  $$ \\  $$ $$/ | $$  | $$| $$       " << endl;
  cout << " | $$  | $$| $$      | $$        | $$        | $$  | $$| $$  | $$  \\  $$$/  | $$  | $$| $$    $$ " << endl;
  cout << " | $$  | $$| $$$$$$$$| $$$$$$$$ /$$$$$$      | $$  | $$| $$  | $$   \\  $/   |  $$$$$$/|  $$$$$$/ " << endl;
  cout << " |__/  |__/|________/|________/|______/      |__/  |__/|__/  |__/    \\_/     \\______/  \\______/  " << endl;
  cout << endl;
  cout << endl;
  cout << "_________________Loading...";
  Sleep(500);
  cout << "********   ";
  Sleep(500);
  cout << "********   ";
  Sleep(500);
  cout << "********   ";
  cout << endl;
  int option;
  cout << "1.  .......START------------ " << endl;
  cout << "2.  --------INSTRUCTION..............." << endl;
  cout << "3.  ......EXIT...... " << endl;
}
void instruction()
{
  system("cls");
  int k = 7;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  cout << "........Hello! These are the instruction of the Hali Havoc.......... " << endl;
  cout << endl;
  cout << "1. Upper Arrow key used to move the helicopter upward." << endl;
  cout << "2. Down Arrow key is used to move the helicopter downward." << endl;
  cout << "3. Left Arrow key is used to move the helicopter left side." << endl;
  cout << "4. Right Arrow key is used to move the helicopter right side." << endl;
  cout << "5. Space key is used to fire the enemies." << endl;
}
void printHeli()
{
  int k = 5;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  for (int i = 0; i < 14; i++)
  {
    gotoxy(heliX + i, heliY);
    cout << heli1[i];
  }
  cout << endl;
  for (int i = 0; i < 12; i++)
  {
    gotoxy(heliX + i, heliY + 1);
    cout << heli2[i];
  }

  cout << endl;
  for (int i = 0; i < 10; i++)
  {
    gotoxy(heliX + i, heliY + 2);
    cout << heli3[i];
  }

  cout << endl;
}
void removeHeli()
{
  for (int i = 0; i < 14; i++)
  {
    gotoxy(heliX + i, heliY);
    cout << " ";
  }
  cout << endl;
  for (int i = 0; i < 12; i++)
  {
    gotoxy(heliX + i, heliY + 1);
    cout << " ";
  }

  cout << endl;
  for (int i = 0; i < 10; i++)
  {
    gotoxy(heliX + i, heliY + 2);
    cout << " ";
  }

  cout << endl;
}
void maze()
{
  int k = 7;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  cout << "#####################################################################################################################################################################" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "##                                                                                                                                                                 ##" << endl;
  cout << "#####################################################################################################################################################################" << endl;
}
void gotoxy(int x, int y)
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
  COORD coordBufSize;
  coordBufSize.X = 1;
  coordBufSize.Y = 1;
  return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
                                                                                          : ' ';
}
void bullets()
{
  bulletX[index] = heliX + 13;
  bulletY[index] = heliY + 1;
  gotoxy(bulletX[index], bulletY[index]);
  cout << ".";
  index++;
}
void moveBullet()
{
  int k = 5;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  for (int i = 0; i < index; i++)
  {
    char next = getCharAtxy(bulletX[i] + 1, bulletY[i]);
    if (next == ' ')
    {
      gotoxy(bulletX[i], bulletY[i]);
      cout << " ";
      bulletX[i]++;
      cout << ".";
    }
    if (next == 'C' || next == '/' || next == '|' || next == b2 || next == b1)
    {
      addScore();
    }
    if (next != ' ')
    {
      gotoxy(bulletX[i], bulletY[i]);
      cout << " ";
      for (int j = i; j < index - 1; j++)
      {
        bulletX[j] = bulletX[j + 1];
        bulletY[j] = bulletY[j + 1];
      }
      index--;
    }
  }
}
void printEnemy1()
{
  int k = 9;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  for (int i = 0; i < 5; i++)
  {
    gotoxy(enemy1X + i, enemy1Y);
    cout << aero1[i];
  }
  cout << endl;
  for (int i = 0; i < 6; i++)
  {
    gotoxy(enemy1X + i, enemy1Y + 1);
    cout << aero2[i];
  }
  cout << endl;
  for (int i = 0; i < 5; i++)
  {
    gotoxy(enemy1X + i, enemy1Y + 2);
    cout << aero3[i];
  }
}
void printEnemy2()
{
  int k = 4;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  for (int i = 0; i < 5; i++)
  {
    gotoxy(enemy2X + i, enemy2Y);
    cout << enemy1[i];
  }
  cout << endl;
  for (int i = 0; i < 6; i++)
  {
    gotoxy(enemy2X + i, enemy2Y + 1);
    cout << enemy2[i];
  }
  cout << endl;
  for (int i = 0; i < 5; i++)
  {
    gotoxy(enemy2X + i, enemy2Y + 2);
    cout << enemy3[i];
  }
}
void eraseEnemy2()
{
  for (int i = 0; i < 5; i++)
  {
    gotoxy(enemy2X + i, enemy2Y);
    cout << " ";
  }
  cout << endl;
  for (int i = 0; i < 6; i++)
  {
    gotoxy(enemy2X + i, enemy2Y + 1);
    cout << " ";
  }
  cout << endl;
  for (int i = 0; i < 5; i++)
  {
    gotoxy(enemy2X + i, enemy2Y + 2);
    cout << " ";
  }
}
void eraseEnemy1()
{
  for (int i = 0; i < 5; i++)
  {
    gotoxy(enemy1X + i, enemy1Y);
    cout << " ";
  }
  cout << endl;
  for (int i = 0; i < 6; i++)
  {
    gotoxy(enemy1X + i, enemy1Y + 1);
    cout << " ";
  }
  cout << endl;
  for (int i = 0; i < 5; i++)
  {
    gotoxy(enemy1X + i, enemy1Y + 2);
    cout << " ";
  }
}

void moveEnemy1()
{
  if (direction == "up")
  {
    // getCharAtxy(enemy1X, enemy1Y - 1);
    if (getCharAtxy(enemy1X, enemy1Y - 1) == ' ')
    {
      if (enemy1Y > 21)
      {
        // gotoxy(enemy1X,enemy1Y);
        eraseEnemy1();
        enemy1Y = enemy1Y - 1;
        gotoxy(enemy1X, enemy1Y);
        printEnemy1();
      }
      else
      {
        direction = "down";
      }
    }
  }
  if (direction == "down")
  {

    if (getCharAtxy(enemy1X, enemy1Y + 3) == ' ')
    {
      if (enemy1Y < 38)
      {
        eraseEnemy1();
        enemy1Y = enemy1Y + 1;

        gotoxy(enemy1X, enemy1Y);
        printEnemy1();
      }
      else
      {
        direction = "up";
      }
    }
  }
}
void moveEnemy2()
{
  // int next = getCharAtxy(enemy2X - 1, enemy2Y);
  if (direction2 == "left")
  {
    if (getCharAtxy(enemy2X - 1, enemy2Y) == ' ')
    {
      if (enemy2X > 100)
      {
        eraseEnemy2();
        enemy2X = enemy2X - 1;
        gotoxy(enemy2X, enemy2Y);
        printEnemy2();
      }
      else
      {
        direction2 = "right";
      }
    }
  }
  if (direction2 == "right")
  {
    if (getCharAtxy(enemy2X + 4, enemy2Y) == ' ')
    {
      if (enemy2X < 155)
      {
        eraseEnemy2();
        enemy2X = enemy2X + 1;
        gotoxy(enemy2X, enemy2Y);
        printEnemy2();
      }
      else
      {
        direction2 = "left";
      }

      // Sleep(100);
    }
  }
}
void goLeft()
{
  getCharAtxy(heliX - 1, heliY);
  if (getCharAtxy(heliX - 1, heliY + 1) == ' ')
  {
    removeHeli();
    heliX = heliX - 1;
    gotoxy(heliX, heliY);
    printHeli();
  }
}
void goRight()
{
  getCharAtxy(heliX + 14, heliY);
  if (getCharAtxy(heliX + 14, heliY) == ' ' && getCharAtxy(heliX + 13, heliY + 1) == ' ' && getCharAtxy(heliX + 11, heliY + 3) == ' ' && getCharAtxy(heliX + 13, heliY + 3) == ' ')
  {
    removeHeli();
    heliX = heliX + 1;
    gotoxy(heliX, heliY);
    //  Sleep(100);
    printHeli();
  }
}
void goDown()
{

  getCharAtxy(heliX, heliY + 2);
  if (getCharAtxy(heliX, heliY + 3) == ' ' && getCharAtxy(heliX + 2, heliY + 3) == ' ' && getCharAtxy(heliX + 5, heliY + 3) == ' ' && getCharAtxy(heliX + 11, heliY + 2) == ' ' && getCharAtxy(heliX + 7, heliY + 3) == ' ' && getCharAtxy(heliX + 8, heliY + 3) == ' ' && getCharAtxy(heliX + 13, heliY + 1) == ' ' && getCharAtxy(heliX + 3, heliY + 3) == ' ')
  {
    removeHeli();
    heliY = heliY + 1;
    gotoxy(heliX, heliY);
    printHeli();
  }
}
void goUp()
{
  getCharAtxy(heliX, heliY - 1);
  if (getCharAtxy(heliX, heliY - 1) == ' ' && getCharAtxy(heliX + 1, heliY - 1) == ' ' && getCharAtxy(heliX + 2, heliY - 1) == ' ' && getCharAtxy(heliX + 3, heliY - 1) == ' ' && getCharAtxy(heliX + 4, heliY - 1) == ' ' && getCharAtxy(heliX + 5, heliY - 1) == ' ' && getCharAtxy(heliX + 6, heliY - 1) == ' ' && getCharAtxy(heliX + 7, heliY - 1) == ' ' && getCharAtxy(heliX + 8, heliY - 1) == ' ' && getCharAtxy(heliX + 9, heliY - 1) == ' ' && getCharAtxy(heliX + 10, heliY - 1) == ' ' && getCharAtxy(heliX + 11, heliY - 1) == ' ' && getCharAtxy(heliX + 12, heliY - 1) == ' ' && getCharAtxy(heliX + 13, heliY - 1) == ' ')
  {
    removeHeli();
    heliY = heliY - 1;
    gotoxy(heliX, heliY);
    printHeli();
  }
}

// enemy 1 bullets...
void enemy1Bullet()
{
  enemy1BulletX[index1] = enemy1X - 1;
  enemy1BulletY[index1] = enemy1Y + 1;
  gotoxy(enemy1BulletX[index1], enemy1BulletY[index1]);
  cout << "-";
  index1++;
}
void moveEnemy1Bullet()
{
  int k = 9;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  for (int i = 0; i < index1; i++)
  {
    char next = getCharAtxy(enemy1BulletX[i] - 1, enemy1BulletY[i]);
    if (next == ' ')
    {
      gotoxy(enemy1BulletX[i], enemy1BulletY[i]);
      cout << " ";
      enemy1BulletX[i]--;
      gotoxy(enemy1BulletX[i], enemy1BulletY[i]);
      cout << "-";
    }
    if (next != ' ')
    {
      gotoxy(enemy1BulletX[i], enemy1BulletY[i]);
      cout << " ";
      for (int j = i; j < index1 - 1; j++)
      {
        enemy1BulletX[j] = enemy1BulletX[j + 1];
        enemy1BulletY[j] = enemy1BulletY[j + 1];
      }
      index1--;
    }
  }
}

// enemy 1 bullets ....

// enemy 2 .....

void enemy2Bullet()
{
  enemy2BulletX[index2] = enemy2X - 3;
  enemy2BulletY[index2] = enemy2Y + 1;
  gotoxy(enemy2BulletX[index2], enemy2BulletY[index2]);
  cout << "*";
  index2++;
}
void moveEnemy2Bullet()
{
  int k = 4;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  for (int i = 0; i < index2; i++)
  {
    // cout << "Index @" << index2;
    char next = getCharAtxy(enemy2BulletX[i] - 1, enemy2BulletY[i]);
    if (next == ' ')
    {
      gotoxy(enemy2BulletX[i], enemy2BulletY[i]);
      cout << " ";
      enemy2BulletX[i]--;
      gotoxy(enemy2BulletX[i], enemy2BulletY[i]);
      cout << "*";
    }

    if (next != ' ')
    {
      gotoxy(enemy2BulletX[i], enemy2BulletY[i]);
      cout << " ";
      for (int j = i; j < index2 - 1; j++)
      {
        enemy2BulletX[j] = enemy2BulletX[j + 1];
        enemy2BulletY[j] = enemy2BulletY[j + 1];
      }
      index2--;
    }
  }
}

// enemy 2.......

// enemy 3...
void printEnemy3()
{
  int k = 2;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  for (int i = 0; i < 3; i++)
  {
    gotoxy(enemy3X + i, enemy3Y);
    cout << box1[i];
  }
  cout << endl;
  for (int i = 0; i < 3; i++)
  {
    gotoxy(enemy3X + i, enemy3Y + 1);
    cout << box2[i];
  }
  cout << endl;
}
void eraseEnemy3()
{
  for (int i = 0; i < 3; i++)
  {
    gotoxy(enemy3X + i, enemy3Y);
    cout << " ";
  }
  cout << endl;
  for (int i = 0; i < 3; i++)
  {
    gotoxy(enemy3X + i, enemy3Y + 1);
    cout << " ";
  }
  cout << endl;
}
void moveEnemy3()
{
  if (direction3 == "right")
  {
    if (getCharAtxy(enemy3X + 3, enemy3Y) == ' ')
    {
      if (enemy3X < 50)
      {
        eraseEnemy3();
        enemy3X = enemy3X + 1;
        gotoxy(enemy3X, enemy3Y);
        printEnemy3();
      }
      else
      {
        direction3 = "left";
      }
    }
  }
  if (direction3 == "left")
  {
    if (getCharAtxy(enemy3X - 2, enemy3Y) == ' ')
    {
      if (enemy3X > 10)
      {
        eraseEnemy3();
        enemy3X = enemy3X - 1;
        gotoxy(enemy3X, enemy3Y);
        printEnemy3();
      }
      else
      {
        direction3 = "right";
      }
    }
  }
}
void enemy3Bullet()
{
  enemy3BulletX[index3] = enemy3X + 1;
  enemy3BulletY[index3] = enemy3Y + 2;
  gotoxy(enemy3BulletX[index3], enemy3BulletY[index3]);
  cout << b1;
  index3++;
}
void moveEnemy3Bullet()
{
  int k = 10;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  for (int i = 0; i < index3; i++)
  {
    // cout << "Index @" << index2;
    char next = getCharAtxy(enemy3BulletX[i], enemy3BulletY[i] + 1);
    if (next == ' ')
    {
      gotoxy(enemy3BulletX[i], enemy3BulletY[i]);
      cout << " ";
      enemy3BulletY[i]++;
      gotoxy(enemy3BulletX[i], enemy3BulletY[i]);
      cout << b1;
    }

    if (next != ' ')
    {
      // enemy2BulletX[i] = enemy2BulletX[i] - 1;
      gotoxy(enemy3BulletX[i], enemy3BulletY[i]);
      cout << " ";
      for (int j = i; j < index3 - 1; j++)
      {
        enemy3BulletX[j] = enemy3BulletX[j + 1];
        enemy3BulletY[j] = enemy3BulletY[j + 1];
      }
      index3--;
    }
  }
}

// enemy3.............

// Score ..........................

void addScore()
{
  score = score + 1;
}
void printAddScore()
{
  int k = 6;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  gotoxy(23, 43);
  cout << "Score : " << score << endl;
}
void printHealth()
{
  int k = 6;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, k);
  gotoxy(50, 43);
  cout << "Health : " << health;
}
void collisionHeli()
{
  getCharAtxy(heliX + 14, heliY);
  if (getCharAtxy(heliX + 14, heliY) == '-' || getCharAtxy(heliX + 13, heliY + 1) == '-' || getCharAtxy(heliX + 11, heliY + 3) == '-' || getCharAtxy(heliX + 13, heliY + 3) == '-')
  {
    health--;
    gotoxy(51, 45);
  }
  else if (getCharAtxy(heliX + 14, heliY) == '*' || getCharAtxy(heliX + 13, heliY + 1) == '*' || getCharAtxy(heliX + 11, heliY + 3) == '*' || getCharAtxy(heliX + 13, heliY + 3) == '*')
  {
    health--;
    gotoxy(51, 47);
  }
  else if (getCharAtxy(heliX, heliY - 1) == b1 || getCharAtxy(heliX + 1, heliY - 1) == b1 || getCharAtxy(heliX + 2, heliY - 1) == b1 || getCharAtxy(heliX + 3, heliY - 1) == b1 || getCharAtxy(heliX + 4, heliY - 1) == b1 || getCharAtxy(heliX + 5, heliY - 1) == b1 || getCharAtxy(heliX + 6, heliY - 1) == b1 || getCharAtxy(heliX + 7, heliY - 1) == b1 || getCharAtxy(heliX + 8, heliY - 1) == b1 || getCharAtxy(heliX + 9, heliY - 1) == b1 || getCharAtxy(heliX + 10, heliY - 1) == b1 || getCharAtxy(heliX + 11, heliY - 1) == b1 || getCharAtxy(heliX + 12, heliY - 1) == b1 || getCharAtxy(heliX + 13, heliY - 1) == b1)
  {
    health--;
    gotoxy(51, 48);
  }
  // if(health < 0)
  // {
  //   cout<<"Game end :";

  // }
}

// score.......................................