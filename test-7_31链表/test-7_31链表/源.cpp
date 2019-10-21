#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int val;
	struct Node *next;  //��һ�ڵ������
}Node;


struct Node* reverseList(struct Node* head){
	struct Node *resultHead = NULL;
	struct Node *cur = head;
	while (cur != NULL) {
		struct Node *next = cur->next;

		// ͷ��
		cur->next = resultHead; // ���� cur->next
		resultHead = cur;

		// ��ѭ��������
		cur = next;
	}

	return resultHead;
}

Node * ListPushFront(Node *head, int val){
	Node *node = (Node *)malloc(sizeof(node));
	node->val = val;
	node->next = head;
	return node;
}

Node * ListPushBack(Node *head, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	if (head != NULL){
		Node *cur = head;
		while (cur->next != NULL){
			cur = cur->next;
		}
       cur ->next = node;
	}
	else{
		head = node;
	}
	return head;

}

//��������
void ListPrint(Node *head){
	for (Node *cur = head; cur != NULL; cur = cur->next){
		printf("%d -->  ", cur->val);
	}
	printf("NULL\n");
}

#include<assert.h>
Node * ListPopBack(Node *head){
	assert(head != NULL);
	if (head->next == NULL){
		free(head);
		head = NULL;
	}
	else{
		Node *cur = head;
		while (cur->next->next != NULL){
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
	return head;
}

Node * ListPopFront(Node *head) {
	assert(head != NULL);
	/*
	Node *oldHead = head;
	free(oldHead);
	return head->next;
	*/

	Node *next = head->next;
	free(head);
	return next;
}

void Test() {
	Node *head = NULL;	// ����ĳ�ʼ��

	// ��������ͷ��
	ListPrint(head);
	head = ListPushFront(head, 1);
	ListPrint(head);
	head = ListPushFront(head, 2);
	ListPrint(head);
	head = ListPushFront(head, 3);
	ListPrint(head);
	head = ListPushFront(head, 4);
	ListPrint(head);
	head = ListPushBack(head, 10);
	head = ListPushBack(head, 20);
	head = ListPushBack(head, 30);
	ListPrint(head);


	head = ListPopFront(head);
	head = ListPopFront(head);
	head = ListPopFront(head);
	ListPrint(head);
	head = ListPopBack(head);
	head = ListPopBack(head);
	head = ListPopBack(head);
	head = ListPopBack(head);
	ListPrint(head);

	// ֮ǰ�Ľ���ڴ�й©�ˣ�û���ͷ�
	head = NULL;
	head = ListPushBack(head, 10);
	head = ListPushBack(head, 20);
	ListPrint(head);
	// head ��Ӧ���� NULL ��
	printf("�������\n");
}

#include<iostream>
using namespace std;

class Date {
public:    Date(int year = 1900, int month = 1, int day = 1)    { _year = year;        _month = month;        _day = day; }
		   bool operator==(const Date& d2)    {
			   return _year == d2._year&& _month == d2._month            && _day == d2._day;
		   } private:    int _year;    int _month;    int _day;
};


void st() { Date d1(2018, 9, 26);    Date d2(2018, 9, 27);    cout << (d1 == d2) << endl; };


int main()
{
	st();
	system("pause");
	return 0;
}