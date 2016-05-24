
#include "Queue.h"

Status InitQueue(SqQueue *Q) {
	Q->e = (ElemType *)malloc(sizeof(ElemType) * QUEUE_INIT_SIZE);
	if (!(Q->e)) {
		return ERROR;
	}
	Q->length = 0;
	Q->size = QUEUE_INIT_SIZE;
	return OK;
}
Status DestroyQueue(SqQueue *Q) {
	if (!(Q->e)) {
		return ERROR;
	}
	free(Q->e);
	Q->length = 0;
	Q->size = 0;
	return OK;
}
int QueueEmpty(SqQueue Q) {
	if (Q.length) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}
int QueueLength(SqQueue Q) {
	return Q.length;
}
Status GetHead(SqQueue Q, ElemType *e) {
	if (!Q.length) {
		return ERROR;
	}
	*e = Q.e[0];
	return OK;
}
Status EnQueue(SqQueue *Q, ElemType e) {
	if (Q->length == Q->size) {
		Q->e = (ElemType *)realloc(Q->e, sizeof(ElemType) * (Q->size + QUEUEINCREMENT));
		if (!(Q->e)) {
			return ERROR;
		}
		Q->size += QUEUEINCREMENT;
	}
	Q->e[Q->length] = e;
	Q->length++;
	return OK;
}
Status DeQueue(SqQueue *Q, ElemType *e) {
	int i = 0;
	if (!(Q->length)) {
		return ERROR;
	}
	*e = Q->e[0];
	for (i = 1; i < Q->length; i++) {
		Q->e[i - 1] = Q->e[i];
	}
	Q->length--;
	return OK;
}
