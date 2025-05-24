#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000
#define COLS 30
#define ROWS 30

//-------------------- Memory Management ----------------------//

int** createGrid(int cols, int rows) {
    int** grid = malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        grid[i] = calloc(rows, sizeof(int)); // initialize to 0
    }
    return grid;
}

void destroyGrid(int** grid, int cols) {
    for (int i = 0; i < cols; i++) {
        free(grid[i]);
    }
    free(grid);
}

//-------------------- Drawing ----------------------//

void drawGrid(int** grid, int cols, int rows) {
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            mvprintw(y, x * 2, "%d", grid[x][y]);
        }
    }
}

//-------------------- Simulation Logic ----------------------//

void applyGravity(int** grid, int cols, int rows) {
    for (int y = rows - 2; y >= 0; y--) {
        for (int x = 0; x < cols; x++) {
            if (grid[x][y] == 1 && grid[x][y + 1] == 0) {
                grid[x][y] = 0;
                grid[x][y + 1] = 1;
            }
        }
    }
}

//-------------------- Input Handling ----------------------//

void handleMouseInput(int** grid, int cols, int rows, MEVENT event, int* mouseDown) {
    int x = event.x / 2;
    int y = event.y;

    if (x < 0 || x >= cols || y < 0 || y >= rows) return;

    if (event.bstate & BUTTON1_PRESSED) {
        *mouseDown = 1;
        grid[x][y] = 1;
    } else if (event.bstate & BUTTON1_RELEASED) {
        *mouseDown = 0;
    } else if ((event.bstate & REPORT_MOUSE_POSITION) && *mouseDown) {
        grid[x][y] = 1;
    } else if (event.bstate & BUTTON1_CLICKED) {
        grid[x][y] = 1;
    }
}

//-------------------- Main ----------------------//

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    printf("\033[?1003h\n"); // Enable mouse move events

    int** grid = createGrid(COLS, ROWS);
    MEVENT event;
    int ch;
    int mouseDown = 0;

    while (1) {
        clear();
        drawGrid(grid, COLS, ROWS);
        refresh();

        timeout(0);
        ch = getch();

        if (ch == KEY_MOUSE && getmouse(&event) == OK) {
            handleMouseInput(grid, COLS, ROWS, event, &mouseDown);
        } else if (ch == 'q') {
            break;
        }

        applyGravity(grid, COLS, ROWS);
        usleep(DELAY);
    }

    printf("\033[?1003l\n"); // Disable mouse move events
    destroyGrid(grid, COLS);
    endwin();
    return 0;
}
