#include "Test4_2.h"
#include "time.h"

//设定方向数据
int direction[8][2]={{0,1},
					{1,1},
					{1,0},
					{1,-1},
					{0,-1},
					{-1,-1},
					{-1,0},
					{-1,1}};

//初始化迷宫
Status InitMaze(Maze *maze, int row, int col) {
	int i = 0, j = 0;

	maze->row = row + 2;
	maze->col = col + 2;
	maze->maze = (int *)malloc(sizeof(int) * maze->row * maze->col);
	maze->mark = (int *)malloc(sizeof(int) * maze->row * maze->col);
	memset(maze->mark, 0, sizeof(int) * maze->row * maze->col);

	//创建迷宫
	srand(time(NULL));
	for (i = 0; i < maze->row; i++) {
		for (j = 0; j < maze->col; j++) {
			if (i == 1 && j == 1 || i == row && j == col) {
				maze->maze[j + maze->col * i] = 0;
				continue;
			}
			if (i == 0 || i == (maze->row - 1) || j == 0 || j == (maze->col - 1)) {
				maze->maze[j + maze->col * i] = 1;
				continue;
			}
			maze->maze[j + maze->col * i] = rand() % 2;
		}
	}

	return OK;	
}
//销毁迷宫
Status DestroyMaze(Maze *maze) {
	if (!(maze->maze) || !(maze->mark)) {
		return ERROR;
	}
	free(maze->maze);
	free(maze->mark);
	maze->maze = NULL;
	maze->mark = NULL;
	maze->row = 0;
	maze->col = 0;
	return OK;
}

//打印迷宫
void PrintMaze(Maze maze) {
	int i = 0, j = 0;
	printf(" ");
	for (i = 0; i < maze.col; i++) {
		printf("%d", i);
	}
	printf("\n");
	for (i = 0; i < maze.row; i++) {
		printf("%d", i);
		for (j = 0; j < maze.col; j++) {
			if (maze.maze[j + maze.col * i]) {
				printf("*");
			}
			else {
				printf("O");
			}
		}
		printf("\n");
	}
	printf("\n");
}
//打印路径
Status PrintRoad(SqQueue Q) {
	int i = 0;

	if (!(Q.length)) {
		printf("No path\n");
	}
	else {
		for (i = 0; i < Q.length; i++) {
			printf("(%d,%d)", Q.e[i].x, Q.e[i].y);
		}
		printf("\n");
	}
	return OK;
}

Status findEnd(Maze maze, SqQueue *Q);
Status findStart(Maze maze, SqStack *S);
//计算最短路径
Status SearchMostShortRoad(Maze maze, SqQueue *Q) {
	Status ret = OK;

	//根据起点找到终点
	findEnd(maze, Q);
	//根据终点回溯找到起点,如果返回ERROR则表明没有找到路径，返回OK则找到了路径
	ret = findStart(maze, (SqStack *)Q);
	if (ret == ERROR) {
		return ERROR;
	}
	return OK;
}
//根据起点找到终点
Status findEnd(Maze maze, SqStack *stack) {
	SqQueue Queue;
	int  i = 0, flag = 1, pos = 0;
	ElemType temp1, temp2;
	
	InitQueue(&Queue);
	temp1.x = 1;
	temp1.y = 1;
	while (flag) {
		//在temp1位置的八个方向找路径，找到的入队
		for (i = 0; i < 8; i++) {
			temp2.x = temp1.x + direction[i][0];
 			temp2.y = temp1.y + direction[i][1];
			temp2.pre_dir = (i + 4) % 8;
			pos = temp2.y + temp2.x * maze.col;
			if (maze.mark[pos] || maze.maze[pos]) {
				continue;
			}
			if (temp2.x == maze.row - 2 && temp2.y == maze.col - 2) {
				Push(stack, temp1);
				Push(stack, temp2);
				DestroyQueue(&Queue);
				return OK;
			}
			EnQueue(&Queue, temp2);
			maze.mark[temp2.y + temp2.x * maze.col] = 1;
		}
		//将temp1标记为1
		maze.mark[temp1.y + temp1.x * maze.col] = 1;
		//如果队列为空则表明没有路能到终点
		if (QueueEmpty(Queue)) {
			DestroyQueue(&Queue);
			return ERROR;
		}
		Push(stack, temp1);
		DeQueue(&Queue, &temp1);
	}
	DestroyQueue(&Queue);
	return ERROR;
}
//根据终点回溯找到起点,如果返回ERROR则表明没有找到路径，返回OK则找到了路径
Status findStart(Maze maze, SqStack *first, SqStack *last) {
	ElemType temp1, temp2;

	Pop(first, &temp1);
	if (temp1.x != maze.row - 2 || temp1.y != maze.col - 2) {
		return ERROR;
	}
	temp2.x = temp1.x + direction[temp1.pre_dir][0];
	temp2.y = temp1.y + direction[temp1.pre_dir][1];
	Push(last, temp1);

	while (!StackEmpty(*first)) {
		Pop(first, &temp1);
		if (temp1.x == temp2.x && temp1.y == temp2.y) {
			Push(last, temp1);
			if (temp1.x == 1 && temp1.y == 1) {
				return OK;
			}
			temp2.x = temp1.x + direction[temp1.pre_dir][0];
			temp2.y = temp1.y + direction[temp1.pre_dir][1];
		}
	}
	return OK;
}
//将找到的路放到返回的队列中
Status lastRoad(SqStack *stack, SqQueue *Q) {
	ElemType temp;
	while (!StackEmpty(*stack)) {
		Pop(stack, &temp);
		EnQueue(Q, temp);
	}
	return OK;
}


