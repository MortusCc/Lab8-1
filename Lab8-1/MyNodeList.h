#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 50
typedef char DATA;
typedef struct node
{
	DATA data[LEN + 1];
	struct node* next;
}NODE;
#define MAX 100
NODE* HeadInsertBuild(NODE* head);
NODE* LastInsertBuild(NODE* head);
NODE* FindLast(NODE* head);
NODE* FindIndexNode(NODE* head, int index);
NODE* InsertLast(NODE* head);
NODE* InsertIndexNode(NODE* head, int index);
NODE* Delete(NODE* head, int index);
void PrintLinkList(NODE* head);
NODE* FindMaxLen(NODE* head);
void PutFile(NODE* head);