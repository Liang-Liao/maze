#pragma once
#ifndef TEST4_2_H
#define TEST4_2_H

#include "Queue.h"
#include "Stack.h"

typedef struct Maze {//�Թ�����
	int		*maze; //�Թ���ά����
	int		row;	//��
	int		col;	//��
	int		*mark;//����߹���λ��
}Maze;


Status InitMaze(Maze *maze, int row, int col);//��ʼ���Թ�
Status DestroyMaze(Maze *maze);//�����Թ�
void PrintMaze(Maze maze);//��ӡ�Թ�
Status PrintRoad(SqQueue Q);//��ӡ·��
Status SearchMostShortRoad(Maze maze, SqQueue *Q);//�������·��


#endif
