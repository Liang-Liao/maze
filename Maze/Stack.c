#include "Stack.h"

Status InitStack(SqStack *S) {
	S->base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
	if (!S->base) {
		exit(OVERFLOW);
	}
	S->top = 0;
	S->stacksize = STACK_INIT_SIZE;	
	return OK;
}
Status DestroyStack(SqStack *S) {
	if (S->base) {
		free(S->base);
	}
	S->top = 0;
	S->base = NULL;
	return OK;
}
Status StackEmpty(SqStack S) {
	if (!S.top) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
Status GetTop(SqStack S, ElemType *e) {
	if (!S.top) {
		return ERROR;
	}
	*e = S.base[S.top - 1];
	return OK;
}
Status Push(SqStack *S, ElemType e) {
	if (S->top > S->stacksize) {
		S->base = (ElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType));
		if (!S->base) {
			exit(OVERFLOW);
		}
		S->stacksize += STACKINCREMENT;
	}
	S->base[S->top] = e;
	S->top++;
	return OK;
}
Status Pop(SqStack *S, ElemType *e) {
	if (!S->top) {
		return ERROR;
	}
	*e = S->base[--S->top];
	return OK;
}
