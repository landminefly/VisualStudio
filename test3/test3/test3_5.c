#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode {
	int value;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode, * Tree;

//===========================================================

typedef struct QueueNode {
	TreeNode* node;
	struct QueueNode* next;
} QueueNode, * List;

typedef struct Queue {
	QueueNode* rear;
}*Queue;

Queue initQueue() {
	List list = (List) malloc(sizeof(QueueNode));
	list->next = list;
	Queue q = (Queue) malloc(sizeof(struct Queue));
	q->rear = list;
	return q;
}

int isEmpty(Queue q) {
	if (q->rear->next == q->rear) {
		return 1;
	} else {
		return 0;
	}
}

void enQueue(Queue q, TreeNode* node) {
	QueueNode* newNode = (QueueNode*) malloc(sizeof(QueueNode));
	newNode->node = node;
	newNode->next = q->rear->next;
	q->rear->next = newNode;
	q->rear = newNode;
}

TreeNode* deQueue(Queue q) {
	if (!isEmpty(q)) {
		QueueNode* headNode = q->rear->next;
		QueueNode* nodeToDel = q->rear->next->next;
		TreeNode* valueToReturn = nodeToDel->node;
		headNode->next = headNode->next->next;
		if (nodeToDel == q->rear) {
			q->rear = headNode;
		}
		free(nodeToDel);
		return valueToReturn;
	}
}

//===========================================================
void preorder(Tree tree) {
	if (tree == NULL) {
		return;
	}
	printf("%d\t", tree->value);
	preorder(tree->left);
	preorder(tree->right);
}

//�ж������Ƿ���ȣ�0��ʾ����ȣ�1��ʾ��ȣ�
int isEqual(Tree t1, Tree t2) {
	int flag = ((t1 == NULL ? t1 : t1->value) == (t2 == NULL ? t2 : t2->value));
	if (flag) {
		if (t1 == NULL && t2 == NULL) {
			return 1;
		}
		return isEqual(t1->left, t2->left) & isEqual(t1->right, t2->right);
	} else {
		return 0;
	}
}

int maxWidth(Tree t) {
	if (t == NULL) {
		return 0;
	}
	//��¼����ȣ���ʼ��Ϊ��һ��Ŀ��1
	int max = 1;
	//��¼��һ��Ŀ�ȣ���ʼ��Ϊ0
	int cur_count = 0;
	//��¼��ǰ������һ���ڵ㣬��ʼ��Ϊ��һ������һ���ڵ㣬������
	TreeNode* end = t;
	//ʹ��BFS��˼����б���
	Queue q = initQueue();
	enQueue(q, t);
	while (!isEmpty(q)) {
		TreeNode* temp = deQueue(q);
		if (temp->left != NULL) {
			enQueue(q, temp->left);
			cur_count++;
		}
		if (temp->right != NULL) {
			enQueue(q, temp->right);
			cur_count++;
		}
		//����endʱ����ʱ��cur_count������һ��Ľڵ����
		//����max��end������cur_count��Ȼ�������һ���ѭ��
		if (temp == end) {
			//��һ������һ���ڵ���ǵ�ǰ�Ķ�βԪ��
			end = q->rear->node;
			max = max > cur_count ? max : cur_count;
			cur_count = 0;
		}
	}
	return max;
}

int main() {
	Tree tree1 = (TreeNode*)malloc(sizeof(TreeNode));
	tree1->value = 1;

	tree1->left = (TreeNode*)malloc(sizeof(TreeNode));
	tree1->left->value = 2;
	tree1->right = (TreeNode*) malloc(sizeof(TreeNode));
	tree1->right->value = 3;

	tree1->left->left = (TreeNode*) malloc(sizeof(TreeNode));
	tree1->left->left->value = 4;
	tree1->left->right = (TreeNode*) malloc(sizeof(TreeNode));
	tree1->left->right->value = 5;
	tree1->right->left = NULL;
	tree1->right->right = NULL;

	tree1->left->left->left = NULL;
	tree1->left->left->right = NULL;
	tree1->left->right->left = NULL;
	tree1->left->right->right = NULL;

	Tree tree2 = (TreeNode*) malloc(sizeof(TreeNode));
	tree2->value = 1;

	tree2->left = (TreeNode*) malloc(sizeof(TreeNode));
	tree2->left->value = 2;
	tree2->right = (TreeNode*) malloc(sizeof(TreeNode));
	tree2->right->value = 3;

	tree2->left->left = NULL;
	tree2->left->right = NULL;
	tree2->right->left = NULL;
	tree2->right->right = NULL;

	printf("%d\n", isEqual(tree1, tree2));
	printf("%d\n", maxWidth(tree2));
}