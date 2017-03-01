#include"stdafx.h"
#include"LinkList.h"
void test1()
{
	LinkList plist;
	Init_LinkList(&plist);
	Push_back(&plist, 1);
	Push_back(&plist, 2);
	Push_back(&plist, 3);
	Push_back(&plist, 4);
	Push_back(&plist, 5);
	Print_LinkList(&plist);   //1->2->3->4->5->over  
	Pop_back(&plist);
	Print_LinkList(&plist);   //1->2->3->4->over  
	Pop_back(&plist);
	Print_LinkList(&plist);   //1->2->3->over  
	Pop_back(&plist);
	Print_LinkList(&plist);   //1->2->over  
	Pop_back(&plist);
	Print_LinkList(&plist);   //1->over  
	Pop_back(&plist);
	Print_LinkList(&plist);    //over  
	Free_LinkList(&plist);
}

void test2()
{
	LinkList plist;
	Init_LinkList(&plist);
	Push_Front(&plist, 1);
	Push_Front(&plist, 2);
	Push_Front(&plist, 3);
	Push_Front(&plist, 4);
	Push_Front(&plist, 5);
	Print_LinkList(&plist);   //5->4->3->2->1->over  
	Pop_Front(&plist);
	Print_LinkList(&plist);   //4->3->2->1->over  
	Pop_Front(&plist);
	Print_LinkList(&plist);   //3->2->1->over  
	Pop_Front(&plist);
	Print_LinkList(&plist);   //2->1->over  
	Pop_Front(&plist);
	Print_LinkList(&plist);   //1->over  
	Pop_Front(&plist);
	Print_LinkList(&plist);   //over  
	Free_LinkList(&plist);
}

void test3()
{
	LinkList plist;
	Init_LinkList(&plist);
	Push_back(&plist, 1);
	Push_back(&plist, 2);
	Push_back(&plist, 3);
	Print_LinkList(&plist);   //1->2->3->over  
	Insert_Back(&plist, Find_NUM(&plist, 2), 5);
	Print_LinkList(&plist);   //1->2->5->3->over  
	Insert_Front(&plist, Find_NUM(&plist, 2), 5);
	Print_LinkList(&plist);  //1->5->2->5->3->over  
	Remove_LinkList(&plist, 5);
	Print_LinkList(&plist);  //1->5->5->3->over  
	Free_LinkList(&plist);
}

void test4()
{
	LinkList plist;
	Init_LinkList(&plist);
	Push_back(&plist, 1);
	Push_back(&plist, 2);
	Push_back(&plist, 3);
	Print_LinkList(&plist);   //1->2->3->over  
	Insert_Back(&plist, Find_NUM(&plist, 2), 5);
	Insert_Front(&plist, Find_NUM(&plist, 2), 5);
	Print_LinkList(&plist);   //1->5->2->5->3->over  
	RemoveAll_LinkList(&plist, 5);
	Print_LinkList(&plist);  //1->2->3->over  
	Push_back(&plist, 6);
	Push_back(&plist, 5);
	Bubble_Sort(&plist);
	Print_LinkList(&plist);  //1->2->3->5->6->over   
	Erase_LinkList(&plist, Find_NUM(&plist, 3));
	Print_LinkList(&plist);    //1->2->5->6->over   
	Free_LinkList(&plist);
}
int main()
{
	//test1();  
	//test2();  
	//test3();  
	test4();
	system("pause");
	return 0;
}