#include "game.h"

//初始化棋盘
void InitBoard(char board[ROW][COL] , int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			//每个格初始化空格
			board[i][j] = ' ';
		}
	}
}

//显示棋盘
void DisplayBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

//玩家下棋
void PlayerGo(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	while (1) {
		printf("\n");
		printf("请输入坐标轴>");
		scanf("%d,%d", &x, &y);
		//判断输入是否正确，以及该位置是否给占用
		if ((x >= 1 && x <= row) && (y >= 1 && y <= row) && board[x - 1][y - 1] == ' ') {
			//printf("输入没问题");
			board[x - 1][y - 1] = '*';
			break;
		}
		else {
			printf("输入有问题，请重新输入\n");
		}
	}
}

//电脑下棋
void ComperterGo(char board[ROW][COL], int row, int col) {
	//检测下棋的位置是否为空
	while (1) {
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}

//判断胜负
char Result(char board[ROW][COL], int row, int col) {
	//第一种情况：横排都是相同字符
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			return board[i][0];
		}
	}
	//第二种情况：竖排都是相同字符
	for (j = 0; j < row; j++) {
		if (board[0][j] == board[1][j] && board[1][j]  == board[2][j] && board[0][j] != ' ') {
			return board[0][j];
		}
	}
	//第三种情况：两条斜线相同字符
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
		return board[1][1];
	}
	//判断平局
	int l = 0;
	int m = 0;
	for (l = 0; l < row; l++) {
		for (m = 0; m < col; m++) {
			if (board[l][m] == ' ') {
				return 'q';
			}
		}
	}
	return 'e';
}



