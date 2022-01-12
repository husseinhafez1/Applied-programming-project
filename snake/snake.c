#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// rows and columns
#define R 20
#define C 40

int i, j, field[R][C], x, y, Gy, head, tail, game, apples, a, b, userInput;

// creates the body of the snake
void snakeInitialization() {
    // coordinate points for the snake which is center of the screen
    x = R/2; 
    y = C/2;
    Gy = y;
    head = 5;
    tail = 1;
    // where to print the snakes body
    for (i = 0; i < head; i++) {
        Gy++;
        field[x][Gy-head] = i+1;
    }
}

void print() {
    // creating walls
    for (i = 0; i <= C + 1; i++) {
        if (i == 0) {
            printf("%c", 201); // ascii code for ╔ is 201
        }
        else if (i == C + 1) {
            printf("%c", 187); // ascii code for ╗ is 187
        }
        else {
            printf("%c", 205); // ascii code for ═ is 205
        }
    }
    printf("\n");
    for (i = 0; i<R; i++) {
        printf("%c", 186);
        for (j = 0; j<C; j++) {
            if (j == C-1) {
                printf(" %c", 186);
            }
            else if (field[i][j] > 0 && field[i][j] != head) {
                printf("%c", 176);
            }
            else if (field[i][j] == head) {
                printf("%c", 178);
            }
            else if (field[i][j] == 0) {
                printf(" ");
            }
            else if (field[i][j] == -1) {
                printf("%c", 15);
            }
        }
        printf("\n");
    }
    for (i = 0; i <= C + 1; i++) {
        if (i == 0) {
            printf("%c", 200);
        }
        else if (i == C + 1) {
            printf("%c", 188);
        }
        else {
            printf("%c", 205);
        }
    }
}

void ResetScreenPosition() {
    HANDLE hOut;
    COORD position;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    position.X = 0;
    position.Y = 0;
    // starts printing from the top left corner of screen and sets the cursor to the top left corner
    SetConsoleCursorPosition(hOut, position);
    // hides cursor
    SetConsoleCursorInfo(hOut, &ConCurInf);
}

void randomSpawner() {
    srand(time(0));
    // generates a number from 1:18
    a = 1 + rand() % 18;
    // generates a number from 1:38
    b = 1 + rand() % 38;
    if (!apples && field[a][b] == 0) {
        field[a][b] = -1;
        apples = 1;
    }
}

int getch_noblock() {
    if (kbhit()) {
        return getch();
    }
    else {
        return -1;
    }
}

void movement() {
    userInput = getch_noblock();
    userInput = tolower(userInput);

    if (userInput == 'w') {
        x--;
        head++;
        field[x][y] = head;
    }
    else if (userInput == 'a') {
        y--;
        head++;
        field[x][y] = head;
    }
    else if (userInput == 's') {
        x++;
        head++;
        field[x][y] = head;
    }
    else if (userInput == 'd') {
        y++;
        head++;
        field[x][y] = head;
    }
}

int main() {
    snakeInitialization();

    while (!game) {
        print();
        ResetScreenPosition();
        randomSpawner();
        movement();
        Sleep(99);
    }
    return 0;
}