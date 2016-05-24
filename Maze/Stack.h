#pragma once
#ifndef STACK_H
#define STACK_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ElemType.h"

#define TRUE			1	/*�������״̬����*/
#define FALSE			0
#define ERROR			0
#define OK				1
#define OVERFLOW		-1
#define INFEASIBLE		-2
#define STACK_INIT_SIZE	100	/*�洢�ռ��ʼ������*/
#define STACKINCREMENT	10	/*�洢�ռ��������*/

typedef int Status;			/*StatusΪ��������ֵ���ͣ���ֵΪ�������״̬����*/

typedef struct {			/*ջ��˳��洢��ʾ*/
	ElemType *base;
	int top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *S);/*����һ����ջS*/
Status DestroyStack(SqStack *S);/*����ջS*/
Status StackEmpty(SqStack S);/*��SΪ��ջ���򷵻�TRUE�����򷵻�FALSE*/
Status GetTop(SqStack S, ElemType *e);/*��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�FALSE*/
Status Push(SqStack *S, ElemType e);/*����Ԫ��eΪ�µ�ջ��Ԫ��*/
Status Pop(SqStack *S, ElemType *e);/*��ջS���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR*/

#endif