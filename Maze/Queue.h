#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ElemType.h"

#define TRUE		1 /*�������״̬����*/
#define FALSE		0
#define OK			1
#define ERROR		0
#define OVERFLOW	-1
#define INFEASIBLE	-2
#define QUEUE_INIT_SIZE	100
#define QUEUEINCREMENT	10

typedef int Status;			/*StatusΪ��������ֵ���ͣ���ֵΪ�������״̬����*/

typedef struct SqQueue {
	ElemType *e;
	int length;
	int size;
}SqQueue;

Status InitQueue(SqQueue *Q); //����һ���ն���Q
Status DestroyQueue(SqQueue *Q);//���ٶ���Q
int QueueEmpty(SqQueue Q);//������QΪ�գ�����1�����򷵻�0
int QueueLength(SqQueue Q);//���ض���Q�ĳ���
Status GetHead(SqQueue Q, ElemType *e);//������Q���գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
Status EnQueue(SqQueue *Q, ElemType e);//����Ԫ��eΪQ���¶�βԪ��
Status DeQueue(SqQueue *Q, ElemType *e);//������Q���գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR

#endif
