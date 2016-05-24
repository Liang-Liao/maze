#pragma once
#ifndef STACK_H
#define STACK_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ElemType.h"

#define TRUE			1	/*函数结果状态代码*/
#define FALSE			0
#define ERROR			0
#define OK				1
#define OVERFLOW		-1
#define INFEASIBLE		-2
#define STACK_INIT_SIZE	100	/*存储空间初始分配量*/
#define STACKINCREMENT	10	/*存储空间分配增量*/

typedef int Status;			/*Status为函数返回值类型，其值为函数结果状态代码*/

typedef struct {			/*栈的顺序存储表示*/
	ElemType *base;
	int top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *S);/*构造一个空栈S*/
Status DestroyStack(SqStack *S);/*销毁栈S*/
Status StackEmpty(SqStack S);/*若S为空栈，则返回TRUE，否则返回FALSE*/
Status GetTop(SqStack S, ElemType *e);/*若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回FALSE*/
Status Push(SqStack *S, ElemType e);/*插入元素e为新的栈顶元素*/
Status Pop(SqStack *S, ElemType *e);/*若栈S不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR*/

#endif