#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INLCUDED

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#define fps 90
#define LEN 40000
#define N 700

void initGrid(int, int);
void drawGrid();
void drawSnake();
void drawFood();
void random(int&, int&);

#endif