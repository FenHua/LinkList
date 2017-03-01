#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;
typedef struct LinkNode
{
	DataType data;
	struct LinkNode*next;
}LinkNode, *pLinkNode;
typedef struct LinkList
{
	LinkNode*phead;
}LinkList, *pLinkList;

void Init_LinkList(pLinkList plist);
void Free_LinkList(pLinkList plist);
void Push_back(pLinkList plist, DataType x);//β��
void Pop_back(pLinkList plist);
void Push_Front(pLinkList plist, DataType x);//ͷ��
void Pop_Front(pLinkList plist);
void Print_LinkList(pLinkList plist);
pLinkNode Find_NUM(pLinkList plist, DataType x);//�ҵ��ڵ�
void Insert_Back(pLinkList plist, pLinkNode pos, DataType x);//������һ����ͬԪ�أ����߲���
void Insert_Front(pLinkList plist, pLinkNode pos, DataType x);
void Remove_LinkList(pLinkList plist, DataType x);
void RemoveAll_LinkList(pLinkList plist, DataType x);
void Bubble_Sort(pLinkList plist);
void Erase_LinkList(pLinkList plist, pLinkNode pos);

#endif _LINKLIST_H_