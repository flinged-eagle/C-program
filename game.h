#ifndef __GAME_H__
#define __GAME_H__

#define ROW 3
#define COL 3

#include<stdlib.h>
#include<time.h>
#include<windows.h>

void game();
void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL],int row,int col);
void ComputerMove(char board[ROW][COL],int row,int col);
void PlayerMove(char board[ROW][COL],int row,int col);
char Is_Win(char board[ROW][COL],int row,int col);
//返回值：>
//'Q' 继续
//'X' 电脑赢
//'Y' 玩家赢
//'L' 平局

int Is_full(char board[ROW][COL],int row,int col);

#endif //__GAME_H__