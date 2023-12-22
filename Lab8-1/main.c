#define _CRT_SECURE_NO_WARNINGS 1
#include "MyNodeList.h"
int main()
{
	NODE* head = NULL;
	head = LastInsertBuild(head);
	NODE* max = FindMaxLen(head);
	printf("%s", max->data);
	PutFile(head);
	return 0;
}