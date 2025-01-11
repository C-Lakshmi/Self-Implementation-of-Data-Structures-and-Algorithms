#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib> 
#include <ctime>   

using namespace std;

bool over;
const int height = 20;
const int width = 60;
string name1,name2;

int x1, y1, x2, y2, foodx1, foody1, foodx2, foody2, score1, score2;
enum edirection { STOP = 0, UP, DOWN, LEFT, RIGHT };
edirection dir1, dir2;

//snake1
int tailx1[100], taily1[100], ntail1;
//snake2
int tailx2[100], taily2[100], ntail2;

//obstacles
const int num = 5;
int obstacleX[num], obstacleY[num];

void setup(){
    over = false;
    x1 = width / 4;
    y1 = height / 2;
    x2 = 3 * width / 4;
    y2 = height / 2;
    foodx1 = rand() % width;
    foody1 = rand() % height;
    foodx2 = rand() % width;
    foody2 = rand() % height;
    score1 = 0;
    score2 = 0;
    dir1 = STOP;
    dir2 = STOP;
    ntail1 = 0;
    ntail2 = 0;

    // Seed random number generator
    srand(time(0));

    // Generate random obstacles
    for (int i = 0; i < num; i++)
    {
        obstacleX[i] = rand() % width;
        obstacleY[i] = rand() % height;
    }
}


void game(){
    
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
CONSOLE_CURSOR_INFO info;
info.dwSize = 100;
info.bVisible = false;
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

//horizontal border
for (int i = 0; i <= width; i++){
if (i == 0 || i == width)
cout<<"#";
else
cout<<"-";
}
cout << endl;

//area
for (int i = 0; i <= height; i++){
for (int j = 0; j <= width; j++){
    if (j == 0 || j == width)
    cout<< "|";
    //snake1
    else if (i == y1 && j == x1)
    cout<< "O";
    //snake2
    else if (i == y2 && j == x2)
    cout<<"0";
    //food1
    else if (i == foody1 && j == foodx1)
    cout<<"*";
    //food2
    else if (i == foody2 && j == foodx2)
    cout<<"*";
    //obstacles
    else{
    bool isObstacle = false;
    for (int k = 0; k < num; k++){
        if (i == obstacleY[k] && j == obstacleX[k]){
        isObstacle = true;
        break;
        }
        }
    if (isObstacle)
    cout<< "#";
    else{
        //snake1 tail
        bool tail = false;
        for (int k = 0; k < ntail1; k++){
        if (i == taily1[k] && j == tailx1[k]){
        cout<<"0";
        tail = true;
        }
        }
        //snake2 tail
        if (!tail){
        for (int k = 0; k < ntail2; k++){
        if (i == taily2[k] && j == tailx2[k]){
        cout<<"o";
        tail=true;
        }
        }
        }
                    
        if (!tail)
        cout<<" ";
        }
        }
    }
    cout << endl;
    }

    //horixontal border
    for (int i = 0; i <= width; i++){
    if (i == 0 || i == width)
            cout<<"#";
    else
            cout<<"-";
    }
    cout<<endl;
    cout<<name1<<"'s Score : " << score1 << " | "<<name2<<"'s Score : " << score2 << endl;
}

void controls(){
if (_kbhit()){
char key = _getch();
    switch (key){

    //player1
        case 'w':
        case 'W':
        if (dir1 != DOWN) dir1 = UP;
        break;
        case 's':
        case 'S':
        if (dir1 != UP) dir1 = DOWN;
        break;
        case 'a':
        case 'A':
        if (dir1 != RIGHT) dir1 = LEFT;
        break;
        case 'd':
        case 'D':
        if (dir1 != LEFT) dir1 = RIGHT;
        break;

    //player2
        case 72: //up arraow
        if (dir2 != DOWN) dir2 = UP;
        break;
        case 80: //down arrow
        if (dir2 != UP) dir2 = DOWN;
        break;
        case 75: //left arrow
        if (dir2 != RIGHT) dir2 = LEFT;
        break;
        case 77: //right arrow
        if (dir2 != LEFT) dir2 = RIGHT;
        break;
        case 'p': //pause
        while (_getch() != 's') {} //wait until 'p' is pressed again
        break;
        default:
            break;
        }
    }
}


void logic(){
for (int i=ntail1-1; i>0; --i){
        tailx1[i] = tailx1[i - 1];
        taily1[i] = taily1[i - 1];
}
tailx1[0] = x1;
taily1[0] = y1;

switch (dir1){
case UP: y1--; break;
case DOWN: y1++; break;
case LEFT: x1--; break;
case RIGHT: x1++; break;
default: break;
}

for (int i=ntail2-1; i>0; --i){
        tailx2[i] = tailx2[i - 1];
        taily2[i] = taily2[i - 1];
}
tailx2[0] = x2;
taily2[0] = y2;

switch (dir2){
case UP: y2--; break;
case DOWN: y2++; break;
case LEFT: x2--; break;
case RIGHT: x2++; break;
default: break;
}

//border-collision
if (x1<0 || x1>=width || y1<0 || y1>=height || x2<0 || x2>=width || y2<0 || y2>=height){
over = true;
}

//obstacles-collision
for (int k=0; k<num; k++){
if ((x1==obstacleX[k] && y1==obstacleY[k]) || (x2==obstacleX[k] && y2==obstacleY[k])){
over = true;
}
}

//tails collision
for (int i=0; i<ntail1; i++){
if (x1==tailx1[i] && y1==taily1[i]){
over = true;
}
}
for (int i=0; i<ntail2; i++){
if (x2==tailx2[i] && y2==taily2[i]){
over = true;
}
}

if (x1==foodx1 && y1==foody1){
score1 += 10;
foodx1 = rand() % width;
foody1 = rand() % height;
ntail1++;
}
if(x1==foodx2 && y1==foody2){
score1 += 10;
foodx2 = rand() % width;
foody2 = rand() % height;
ntail1++;
}
if(x2==foodx1 && y2==foody1){
score2 += 10;
foodx1 = rand() % width;
foody1 = rand() % height;
++ntail2;   
}
if (x2==foodx2 && y2==foody2){
score2 += 10;
foodx2 = rand() % width;
foody2 = rand() % height;
++ntail2;
}
}
void clearScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    DWORD charsWritten;
    DWORD consoleSize;
    COORD cursorHomeCoord = {0, 0};

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    consoleSize = consoleInfo.dwSize.X * consoleInfo.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, cursorHomeCoord, &charsWritten);
    FillConsoleOutputAttribute(hConsole, consoleInfo.wAttributes, consoleSize, cursorHomeCoord, &charsWritten);
    SetConsoleCursorPosition(hConsole, cursorHomeCoord);
}

int main(){
cout<<"* are fruits to collect while # are bolders to avoid"<<endl;
cout <<"Use WASD to move Player 1's snake.(O)"<< endl;
cout <<"Use arrow keys to move Player 2's snake.(0)"<< endl;
cout <<"Press 'p' to pause the game. Press 's' to restart the game."<< endl;
cout<<"Enter easy to play in easy mode and hard to play in hard mode"<<endl;
string mode;
cin>>mode;
cout<<"Enter Player-1's name"<<endl;
cin>>name1;
cout<<"Enter Player-2's name"<<endl;
cin>>name2;
int n;
if(mode=="easy") n=120;
if(mode=="hard") n=30;
else n=100;
clearScreen();
setup(); 

while (!over){
game();
controls();
logic();
Sleep(n); // Adjust sleep duration for game speed
}

cout << "GAME OVER" << endl;
return 0;
}