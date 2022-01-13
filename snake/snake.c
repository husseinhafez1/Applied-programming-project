#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// rows and columns
#define R 20
#define C 40

int i, j, field[R][C], x, y, Gy, head, tail, game, apples, a, b, userInput, direction;

// creates the body of the snake
void snakeInitialization() {
    // coordinate points for the snake which is center of the screen
    x = R/2; 
    y = C/2;
    Gy = y;
    head = 5;
    tail = 1;
    direction = 'd';
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

int getCharacter() {
    if (kbhit()) {
        return getch();
    }
    else {
        return -1;
    }
}

void movement() {
    userInput = getCharacter();
    userInput = tolower(userInput);

    if ((userInput == 'w' || userInput == 'a' || userInput == 's' || userInput == 'd') 
        && abs(direction - userInput) > 5) {
        direction = userInput;
    } 
    if (direction == 'w') {
        x--;
        if (field[x][y] != 0 && field[x][y] != -1) {
            gameOver();
        }
        if (x == 0) {
            x = R-1;
        }
        if (field[x][y] == -1) {
            apples = 0;
            tail -= 3;
        }
        head++;
        field[x][y] = head;
    }
    else if (direction == 'a') {
        y--;
        if (field[x][y] != 0 && field[x][y] != -1) {
            gameOver();
        }
        if (y==0) {
            y = C-1;
        }
        if (field[x][y] == -1) {
            apples = 0;
            tail -= 3;
        }
        head++;
        field[x][y] = head;
    }
    else if (direction == 's') {
        x++;
        if (field[x][y] != 0 && field[x][y] != -1) {
            gameOver();
        }
        if (x == R-1) {
            x = 0;
        }
        if (field[x][y] == -1) {
            apples = 0;
            tail -= 3;
        }
        head++;
        field[x][y] = head;
    }
    else if (direction == 'd') {
        y++;
        if (field[x][y] != 0 && field[x][y] != -1) {
            gameOver();
        }
        if (y == C-1) {
            y = 0;
        }
        if (field[x][y] == -1) {
            apples = 0;
            tail -= 3;
        }
        head++;
        field[x][y] = head;
    }
}

void updateTail() {
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (field[i][j] == tail) {
                field[i][j] = 0;
            }
        }
    }
    tail++;
}

void gameOver() {
    printf("\a");
    Sleep(1500);
    system("cls");

    printf("\n\n\t\tGAME OVER!");

    game = 1;
}

int main() {
    snakeInitialization();

    while (!game) {
        print();
        ResetScreenPosition();
        randomSpawner();
        movement();
        updateTail();
        Sleep(50);
    }
    return 0;
}