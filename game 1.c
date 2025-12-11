#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// Game Settings
#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 20
#define PIPE_GAP 5

// Global Variables
int birdY, birdX;
int pipeX, pipeGapY;
int score;
int gameOver;

// Function to move the cursor to a specific position (Prevents flickering)
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hide the blinking cursor for a cleaner look
void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void setup() {
    gameOver = 0;
    score = 0;

    // Initial Bird Position
    birdX = 5;
    birdY = SCREEN_HEIGHT / 2;

    // Initial Pipe Position
    pipeX = SCREEN_WIDTH - 2;
    srand(time(0)); // Seed random number generator
    pipeGapY = rand() % (SCREEN_HEIGHT - PIPE_GAP - 2) + 1;
}

void draw() {
    // Move cursor to top-left instead of clearing screen (Reduces flicker)
    gotoxy(0, 0);

    // Draw Top Border
    for (int i = 0; i < SCREEN_WIDTH + 2; i++) printf("#");
    printf("\n");

    // Draw Game Area
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            if (j == 0) printf("#"); // Left Border

            if (i == birdY && j == birdX) {
                printf("O"); // The Bird
            }
            else if (j == pipeX) {
                // Draw Pipe (leave gap empty)
                if (i < pipeGapY || i > pipeGapY + PIPE_GAP) {
                    printf("|");
                } else {
                    printf(" ");
                }
            }
            else {
                printf(" "); // Empty Space
            }

            if (j == SCREEN_WIDTH - 1) printf("#"); // Right Border
        }
        printf("\n");
    }

    // Draw Bottom Border
    for (int i = 0; i < SCREEN_WIDTH + 2; i++) printf("#");
    printf("\n");

    // Draw Score
    printf("Score: %d\n", score);
    printf("Controls: Press SPACE to jump. X to exit.\n");
}

void input() {
    if (_kbhit()) { // Check if a key is pressed
        char key = _getch();
        if (key == ' ') {
            birdY -= 3; // Jump up (negative Y is up)
        }
        if (key == 'x' || key == 'X') {
            gameOver = 1;
        }
    }
}

void logic() {
    // Gravity
    birdY++;

    // Move Pipe Left
    pipeX--;

    // Reset Pipe if it hits the left edge
    if (pipeX < 0) {
        pipeX = SCREEN_WIDTH - 1;
        pipeGapY = rand() % (SCREEN_HEIGHT - PIPE_GAP - 2) + 1;
        score += 10; // Increase score
    }

    // Collision Detection
    // 1. Hitting Floor or Ceiling
    if (birdY >= SCREEN_HEIGHT || birdY < 0) {
        gameOver = 1;
    }

    // 2. Hitting the Pipe
    if (birdX == pipeX) {
        if (birdY < pipeGapY || birdY > pipeGapY + PIPE_GAP) {
            gameOver = 1;
        }
    }
}

int main() {
    hideCursor();
    setup();

    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(100); // Control game speed (Lower is faster)
    }

    // Game Over Screen
    system("cls");
    printf("\n\n");
    printf("    #########################\n");
    printf("    #       GAME OVER       #\n");
    printf("    #########################\n");
    printf("    Final Score: %d\n", score);
    printf("\n    Press any key to exit...\n");
    _getch();

    return 0;
}
