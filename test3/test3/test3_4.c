#include "queue.h"

//typedef struct QueueNode {
//	int value;
//	struct QueueNode* next;
//} QueueNode, * List;
//
//typedef struct Queue {
//	QueueNode* rear;
//}*Queue;

////��ʼ��
//Queue initQueue() {
//	List list = (List) malloc(sizeof(QueueNode));
//	list->next = list;
//	Queue q = (Queue) malloc(sizeof(struct Queue));
//	q->rear = list;
//	return q;
//}
//
////���
//void clear(Queue q) {
//	while (!isEmpty(q)) {
//		deQueue(q);
//	}
//}
//
////�Ƿ�Ϊ��
//int isEmpty(Queue q) {
//	if (q->rear->next == q->rear) {
//		return 1;
//	} else {
//		return 0;
//	}
//}
//
////���
//void enQueue(Queue q, int value) {
//	QueueNode* newNode = (QueueNode*) malloc(sizeof(QueueNode));
//	newNode->value = value;
//	newNode->next = q->rear->next;
//	q->rear->next = newNode;
//	q->rear = newNode;
//}
//
////����
//int deQueue(Queue q) {
//	if (!isEmpty(q)) {
//		QueueNode* headNode = q->rear->next;
//		QueueNode* nodeToDel = q->rear->next->next;
//		int valueToReturn = nodeToDel->value;
//		headNode->next = headNode->next->next;
//		if (nodeToDel == q->rear) {
//			q->rear = headNode;
//		}
//		free(nodeToDel);
//		return valueToReturn;
//	}
//}

//int main() {
//	Queue q = initQueue();
//	enQueue(q, 1);
//	enQueue(q, 2);
//	clear(q);
//	enQueue(q, 3);
//	enQueue(q, 4);
//	deQueue(q);
//	enQueue(q, 5);
//
//	List headNode = q->rear->next;
//	QueueNode* temp = headNode->next;
//	if (temp->next == temp) {
//		printf("����Ϊ�գ�");
//	}
//	while (temp != headNode) {
//		printf("%d\t", temp->value);
//		temp = temp->next;
//	}
//}