// LinkList.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"

#include"LinkList.h"
void Init_LinkList(pLinkList plist)
{
	assert(plist);
	plist->phead = NULL;
}
pLinkNode Create_Node(DataType x)
{
	pLinkNode newNode = (pLinkNode)malloc(sizeof(LinkNode));
	if (NULL == newNode)
	{
		printf("out of memory\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void Free_LinkList(pLinkList plist)
{
	pLinkNode cur = plist->phead;
	assert(plist);
	while (cur != NULL)
	{
		pLinkNode tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}
	plist->phead = NULL;
}
void Push_back(pLinkList plist, DataType x)
{
	pLinkNode cur = NULL;
	pLinkNode newNode = NULL;
	assert(plist);
	cur = plist->phead;
	newNode = Create_Node(x);
	if (NULL == cur)
	{
		plist->phead = newNode;
	}
	else
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}
void Pop_back(pLinkList plist)
{
	pLinkNode tmp = NULL;
	pLinkNode cur = plist->phead;
	assert(plist);
	if (NULL == plist->phead)
	{
		return;
	}
	else if (NULL==plist->phead->next)
	{
		free(plist->phead);
		plist->phead = NULL;
	}
	else
	{
		while (cur->next != NULL)
		{
			tmp = cur;
			cur = cur->next;
		}
		free(cur);
		cur = NULL;
		tmp->next = NULL;
	}
}
void Push_Front(pLinkList plist, DataType x)
{
	pLinkNode newNode = NULL;
	assert(plist);
	newNode->next = plist->phead;
	plist->phead = newNode;
}
void Pop_Front(pLinkList plist)
{
	pLinkNode tmp = NULL;
	if (NULL == plist->phead)
	{
		return;
	}
	else
	{
		tmp = plist->phead;
		plist->phead = tmp->next;
		free(tmp);
		tmp = NULL;
	}
}
void Print_LinkList(pLinkList plist)
{
	pLinkNode cur = plist->phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}
pLinkNode Find_NUM(pLinkList plist, DataType x)
{
	pLinkNode cur = plist->phead;
	assert(plist);
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void Insert_Back(pLinkList plist, pLinkNode pos, DataType x)
{
	pLinkNode newNode = NULL;
	pLinkNode cur = plist->phead;
	assert(plist);
	newNode = Create_Node(x);
	if (NULL == plist->phead->next)
	{
		//空链表直接头插
		Push_Front(plist, x);
	}
	else
	{
		while (cur != pos)
		{
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode->next;
	}
}
void Insert_Front(pLinkList plist, pLinkNode pos, DataType x)
{
	pLinkNode newNode = NULL;
	pLinkNode cur = plist->phead;
	assert(plist);
	newNode = Create_Node(x);
	if (NULL == plist->phead->next)
	{
		Push_Front(plist, x);
	}
	else
	{
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
	}
}
void Remove_LinkList(pLinkList plist, DataType x)
{
	pLinkNode ret = NULL;
	pLinkNode cur = plist->phead;
	assert(plist);
	if (NULL == plist->phead)
	{
		//空
		return;
	}
	else
	{
		ret = Find_NUM(plist, x);
		while (cur->next != ret)
		{
			cur = cur->next;
		}
		cur->next = ret->next;
		free(ret);
		ret = NULL;
	}
}
void RemoveAll_LinkList(pLinkList plist, DataType x)
{
	pLinkNode ret = NULL;
	pLinkNode cur = plist->phead;
	assert(plist);
	if (NULL == plist->phead)
	{
		return;
	}
	else
	{
		while (cur->next != NULL)
		{
			ret = Find_NUM(plist, x);
			while (cur->next != ret)
			{
				cur = cur->next;
			}
			if (ret != NULL)
			{
				cur->next = ret->next;
				free(ret);
				ret = NULL;
				cur = cur->next;
			}
		}
	}
}
void Bubble_Sort(pLinkList plist)
{
	//错误
	pLinkNode cur = plist->phead;
	pLinkNode cmp = plist->phead;
	DataType flag = 0;
	while (cur->next != NULL)
	{
		flag = 0;
		while (cmp->next != NULL)
		{
			if (cmp->data > cmp->next->data)
			{
				DataType tmp = cmp->data;
				cmp->data = cmp->next->data;
				cmp->next->data = tmp;
				flag = 1;
			}
			cmp = cmp->next;
		}
		cur = cur->next;
		if (flag == 0)
			break;
	}
}
void Erase_LinkList(pLinkList plist, pLinkNode pos)
{
	pLinkNode cur = plist->phead;
	assert(plist);
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
	pos = NULL;
}