#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// rows and columns
#define R 20
#define C 40

int i, j, field[R][C], x, y, Gy, head, tail, game, apples, a, b, userInput, direction, score, highScore, speed = 100;

FILE *f;

// creates the body of the snake
void snakeInitialization() {
    // coordinate points for the snake which is center of the screen
    f = fopen("highScore.txt", "r");
    fscanf(f, "%d", &highScore);
    fclose(f);

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
    printf("\tCurrent Score: %d\tHigh Score: %d", score, highScore);
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
        if (speed > 10 && score != 0) {
            speed -= 5;
        }
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
            x = R;
        }
        if (field[x][y] == -1) {
            apples = 0;
            score += 10;
            tail -= 2;
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
            score += 10;
            tail -= 2;
        }
        head++;
        field[x][y] = head;
    }
    else if (direction == 's') {
        x++;
        if (field[x][y] != 0 && field[x][y] != -1) {
            gameOver();
        }
        if (x == R) {
            x = 0;
        }
        if (field[x][y] == -1) {
            apples = 0;
            score += 10;
            tail -= 2;
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
            score += 10;
            tail -= 2;
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

    if (score>highScore) {
        printf("\n\n\t\tNew High Score: %d!\n\n\t\t", score);
        system("pause");
        f = fopen("highScore.txt", "w");
        fprintf(f, "%d", score);
        fclose(f);
    }

    system("cls");
    printf("\n\n\t\tGAME OVER!");
    printf("\n\n\t\tscore: %d", score);

    system("cls");
}

int main() {
    snakeInitialization();

    while (!game) {
        print();
        ResetScreenPosition();
        randomSpawner();
        movement();
        updateTail();
        Sleep(speed);
    }
    return 0;
}