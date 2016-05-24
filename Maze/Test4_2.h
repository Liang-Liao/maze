#pragma once
#ifndef TEST4_2_H
#define TEST4_2_H

#include "Queue.h"
#include "Stack.h"

typedef struct Maze {//迷宫类型
	int		*maze; //迷宫二维数组
	int		row;	//行
	int		col;	//列
	int		*mark;//标记走过的位置
}Maze;


Status InitMaze(Maze *maze, int row, int col);//初始化迷宫
Status DestroyMaze(Maze *maze);//销毁迷宫
void PrintMaze(Maze maze);//打印迷宫
Status PrintRoad(SqQueue Q);//打印路径
Status SearchMostShortRoad(Maze maze, SqQueue *Q);//计算最短路径


#endif
