#include "game.h"

void game() {
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//显示棋盘
	DisplayBoard(board, ROW, COL);
	//玩家下棋
	while (1) {
		PlayerGo(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		char Winer = Result(board, ROW, COL);
		if (Winer == '*') {
			printf("你赢了！\n");
			break;
		}
		else if(Winer == '#'){
			printf("你输了！\n");
			break;
		}
		else if(Winer == 'e'){
			printf("平局！\n");
			break;
		}
		printf("\n");
		printf("------------\n");
		printf("电脑正在下棋\n");
		printf("------------\n");
		printf("\n");
		Sleep(2000);
		ComperterGo(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		Winer = Result(board, ROW, COL);
		if (Winer == '*') {
			printf("你赢了！\n");
			break;
		}
		else if (Winer == '#') {
			printf("你输了！\n");
			break;
		}
		else if (Winer == 'e') {
			printf("平局！\n");
			break;
		}
	}
	
}


void menu() {
	int index;
	//时间戳
	srand((unsigned int)time(NULL));
	printf("-----------------------------------\n");
	printf("------------井字棋游戏-------------\n");
	printf("-----------------------------------\n");
	printf("------1.开始游戏    2.结束游戏-----\n");
	printf("-----------------------------------\n");
	printf("输入>");
	scanf("%d", &index);
	switch (index) {
		case 1:
			system("cls");
			printf("--------\n");
			printf("开始游戏\n");
			printf("--------\n");
			printf("\n");
			game();
		case 0:
			printf("--------\n");
			printf("结束游戏\n");
			printf("--------\n");
			break;
		default:
			printf("--------\n");
			printf("输入有误\n");
			printf("--------\n");
			break;
	}

}


int main() {
	menu();
	return 0;
}


