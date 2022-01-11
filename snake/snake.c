#include <stdio.h>

// rows and columns
#define R 20
#define C 40

int i, j, field[R][C], x, y, Gy, head, tail;

// creates the body of the snake
void snakeInitialization() {
    // coordinate points for the snake which is center of the screen
    x = R/2; 
    y = C/2;
    Gy = y;
    head = 5;
    tail = 1;
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
            if (field[i][j] > 0 && field[i][j] != head) {
                printf("%c", 176);
            }
            if (field[i][j] == head) {
                printf("%c", 178);
            }
            if (field[i][j] == 0) {
                printf(" ");
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

int main() {
    snakeInitialization();
    print();
    return 0;
}