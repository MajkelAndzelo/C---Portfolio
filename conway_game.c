#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 20

void initialize_board(bool board[][COLUMNS]);
void print_board(bool board[][COLUMNS]);
void update_board(bool board[][COLUMNS]);

int main() {
    bool board[ROWS][COLUMNS];
    srand(time(NULL));
    initialize_board(board);
    print_board(board);
    while (true) {
        printf("Press enter to generate next generation\n");
        getchar();
        update_board(board);
        print_board(board);
    }
    return 0;
}

void initialize_board(bool board[][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = rand() % 2 == 0;
        }
    }
}

void print_board(bool board[][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c ", board[i][j] ? '*' : '.');
        }
        printf("\n");
    }
}

void update_board(bool board[][COLUMNS]) {
    bool new_board[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int count = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) {
                        continue;
                    }
                    int row = i + x;
                    int column = j + y;
                    if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS) {
                        continue;
                    }
                    if (board[row][column]) {
                        count++;
                    }
                }
            }
            if (board[i][j]) {
                new_board[i][j] = count == 2 || count == 3;
            } else {
                new_board[i][j] = count == 3;
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}