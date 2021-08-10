#pragma warning(disable : 4996)
#include <stdio.h>
#include <time.h>
#include <windows.h>
#define ROW 3
#define COL 3

//函数声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerGo(char board[ROW][COL], int row, int col);
void ComperterGo(char board[ROW][COL], int row, int col);
char Result(char board[ROW][COL], int row, int col);
