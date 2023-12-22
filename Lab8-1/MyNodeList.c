#define _CRT_SECURE_NO_WARNINGS 1
#include "MyNodeList.h"
NODE* HeadInsertBuild(NODE* head)
{
	head = (NODE*)malloc(sizeof(NODE));
	NODE* node = NULL;
	head->next = NULL;
	DATA temp[LEN + 1] = "\0";
	for (int i = 0; i < MAX; i++)
	{
		scanf(" %[^\n]", temp);
		if (temp[0] == '*' && temp[1] == '*' && temp[2] == '*' && temp[3] == '*' && temp[4] == '*' && temp[5] == '*' && temp [6] == '\0')
		{
			goto END;
		}
		node = (NODE*)malloc(sizeof(NODE));
		strcpy(node->data, temp);
		node->next = head->next;
		head->next = node;
	}
	head = node;
END:
	return head;
}
NODE* LastInsertBuild(NODE* head)
{
	head = (NODE*)malloc(sizeof(NODE));
	NODE* node, * tail;
	tail = head;
	DATA temp[LEN + 1] = "\0";
	for (int i = 0; i < MAX; i++)
	{
		scanf(" %[^\n]", temp);
		if (temp[0] == '*' && temp[1] == '*' && temp[2] == '*' && temp[3] == '*' && temp[4] == '*' && temp[5] == '*' && temp[6] == '\0')
		{
			goto END;
		}
		node = (NODE*)malloc(sizeof(NODE));
		strcpy(node->data, temp);
		node->next = NULL;
		tail->next = node;
		tail = node;
	}
END:
	return head;
}
NODE* FindLast(NODE* head)
{
	NODE* pt = NULL;
	pt = head;
	while (pt->next != NULL)
	{
		pt = pt->next;
	}
	return pt;
}
NODE* FindIndexNode(NODE* head, int index)
{
	NODE* pt = NULL;
	pt = head;
	int i = 1;
	while (i < index && pt != NULL)
	{
		pt = pt->next;
		i++;
	}
	return pt;
}
NODE* InsertLast(NODE* head)
{
	NODE* prePt = NULL, * pt = NULL;
	pt = (NODE*)malloc(sizeof(NODE));
	scanf(" %[^\n]", pt->data);
	prePt = FindLast(head);
	prePt->next = pt;
	pt->next = NULL;
	return head;
}
NODE* InsertIndexNode(NODE* head,int index)
{
	NODE* prePt = NULL, * pt = NULL;
	pt = (NODE*)malloc(sizeof(NODE));
	scanf(" %[^\n]", pt->data);
	prePt = FindIndexNode(head, index);
	if (prePt != NULL)
	{
		pt->next = prePt->next;
		prePt->next = pt;
	}
	else
	{
		printf("There is no such a node!\n");
	}
	return head;
}
NODE* Delete(NODE* head, int index)
{
	NODE* prePt = NULL, * pt = NULL;
	prePt = FindIndexNode(head, index - 1);
	pt = prePt->next;
	if (pt != NULL)
	{
		prePt = pt->next;
		free(pt);
	}
	else
	{
		printf("There is no such a node!\n");
	}
	return head;
}
void PrintLinkList(NODE* head)
{
	NODE* pt = NULL;
	pt = head->next;
	while (pt != NULL)
	{
		printf("%s\n", pt->data);
		pt = pt->next;
	}
}
NODE* FindMaxLen(NODE* head)
{
	NODE* max = head->next;
	NODE* pt = NULL;
	pt = head->next;
	while (pt != NULL)
	{
		if (strlen(max->data) < strlen(pt->data))
		{
			max = pt;
		}
		pt = pt->next;
	}
	return max;
}
void PutFile(NODE* head)
{
	FILE* fp = fopen("Input.txt", "w");
	if (fp == NULL)
	{
		printf("Can't open this file!\n");
		exit(1);
	}
	NODE* pt = NULL;
	pt = head->next;
	while (pt != NULL)
	{
		fputs(pt->data, fp);
		fputc('\n', fp);
		pt = pt->next;
	}
	fclose(fp);
}