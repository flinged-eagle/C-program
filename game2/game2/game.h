#ifndef __GAME_H__
#define __GAME_H__

#define EASY_CONDITION 10

#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void game();
int Is_Win(char arr[ROWS][COLS], int row, int col);
void Init(char arr[ROWS][COLS], int rows, int cols, char set);
void show(char arr[ROWS][COLS], int rows, int cols);
void GetMine(char arr[ROWS][COLS], int rows, int cols, int scale);
void FindMine(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int row, int col);
void Unwrap_Left(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y);
void Unwrap_Right(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y);
void Unwrap_Up(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y);
void Unwrap_Down(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int x, int y);


int GetMineCount(char arr[ROWS][COLS], int x, int y);

#endif //__GAME_H__