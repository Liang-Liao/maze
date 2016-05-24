#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ElemType.h"

#define TRUE		1 /*函数结果状态代码*/
#define FALSE		0
#define OK			1
#define ERROR		0
#define OVERFLOW	-1
#define INFEASIBLE	-2
#define QUEUE_INIT_SIZE	100
#define QUEUEINCREMENT	10

typedef int Status;			/*Status为函数返回值类型，其值为函数结果状态代码*/

typedef struct SqQueue {
	ElemType *e;
	int length;
	int size;
}SqQueue;

Status InitQueue(SqQueue *Q); //构造一个空队列Q
Status DestroyQueue(SqQueue *Q);//销毁队列Q
int QueueEmpty(SqQueue Q);//若队列Q为空，返回1，否则返回0
int QueueLength(SqQueue Q);//返回队列Q的长度
Status GetHead(SqQueue Q, ElemType *e);//若队列Q不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
Status EnQueue(SqQueue *Q, ElemType e);//插入元素e为Q的新队尾元素
Status DeQueue(SqQueue *Q, ElemType *e);//若队列Q不空，则删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR

#endif
