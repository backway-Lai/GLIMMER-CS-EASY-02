#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node* next;
}node;

node a = { 0, NULL };
node* Head = &a;

//创建节点的函数。n为输入值，代表该节点的数据域值；输出为newnode，一个新的节点。（n是数据）
node* createnode(int n) {
	node* newnode = malloc(sizeof(node));

	newnode -> data = n;
	newnode -> next = NULL;
	 
	return newnode;
}


//头插函数，将待插节点A数据域赋予输入值，并将A插入头节点后前。（n是数据）
node* inserthead(node* Head, int n) {
	node* A = createnode(n);

	Head->next = A;

	return Head;
}

//尾插函数，将待查节点A数据域赋予输出值，并用p指针遍布链表找到最后一个节点，将A插入最后一个节点与NUll中（n是数据）
node* inserttail(node* Head, int n) {
	node* A = createnode(n);

	node* p = Head;

	while (p->next != NULL) {
		p = p->next;
	}
	p->next = A;
	return Head;
}

//通过位置查找元素，通过i来计算位置，直到找到想要的节点，打印数据域。（n是希望找的位置）
void search(node* Head, int n) {
	int i = 1;
	node* p = Head;

	while (i < n && p->next != NULL) {
		p = p->next;
		i++;
	}
	if (i == n) printf("The %dth data is %d\n:", n, p->data);
	else printf("false");
}

//寻找含特定数据的节点所在位置。(只输出整数，通过另一个函数来判断最后输出false还是位置)（n是链表节点数，t是寻找的值）
int Search(node* Head, int n, int t) {
	int i = 1;
	node* p = Head;

	while (i <= n && t != p->data) {//跳出条件是查找到或者已经越界了都找不到
		p = p->next;
		i++;
	}

	if (i > n) {//判断是哪种条件导致的跳出循环
		return 0;
	}
	else {
		return i;
	}
}

//查找函数，若Search函数返回0则输出false，否则输出查找值的位置（n是节点数，t是寻找值）
void Find(node* Head, int n) {
	int t;
	printf("Which number you wanna find?");
	scanf("%d", &t);

	int i = Search(Head, n, t);

	if (!i) {
		printf("false");
	}
	else {
		printf("%d is in the %dth node", t, i);
	}
}



//打印链表函数，遍布链表并打印所有数据（n是节点数）
void test(node* Head, int n) {
	int i;
	node* p = Head;

	for (i = 1;i <= n;i++) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//更改函数，通过调用Search函数得到被更改值的位置，再遍历找到。（n是节点数，t是寻找值，k是修改值）
node* Change(node* Head, int n, int t, int k) {
	int j;
	int i = Search(Head, n, t);
	node* p = Head;

	if (i == 0) {
		printf("false\n");
	}
	else {
		for (j = 1;j < i; j++) {
			p = p->next;
		}
		p->data = k;
	}
	
	return Head;
}

//删除函数（与提示的做法略有不同，我采用pq分开向前，分开做判断的方式）
bool Delete(node* Head, int n) {
	int i = 1;
	int j = 1;
	node* p = Head;
	node* q = Head;

	while (i < n && p->next != NULL) {
		p = p->next;
		i++;
	}

	if (i != n) {
		printf("false\n");
		return false;
	}
	else {
		while (j < n - 1) {
			q = q->next;//此时p指向被删除节点，q指向被删除的前一个节点
			j++;
		}
		q->next = p->next;
		free(p);
		return true;
	}
}

//反转函数
node* Reverse(node* Head) {

	int i, j;
	node* p = Head;
	node* q = p->next;
	node* m = Head;
	node* n = q->next;

	for (i = 1;m->next != NULL;i++) {//计算链表中节点个数，决定后续反转次数
		m = m->next;
	}

	p->next = NULL;

	for (j = 1;j < i-2;j++) {
		q->next = p;
		p = q;
		q = n;
		n = n->next;
	}
	q->next = p;//防止n变成野指针
	p = q;
	q = n;
	q->next = p;

	Head = n;

	return Head;
}


//希望做一个有十一个节点的函数，前五个用头插法，后五个用尾插法，并正确使用查找元素函数。
int main() {

	int i, j, n, m;

	printf("How much nodes you want?\n");
	scanf("%d", &n);

	for (i = 0;i < n;i++) {
		printf("The data of this node is:\n");
		scanf("%d", &m);
		Head = inserttail(Head, m);
	}

	test(Head, n+1);

	Head = Reverse(Head);

	test(Head, n + 1);

	return 0;
}


