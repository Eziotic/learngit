#include<stdio.h>
#include<stdlib.h>
//创建单链表
typedef struct tagElemType{
	int i;
	int r;
}ElemType;        //数据结构体 

struct tagLNode{
	ElemType data;
	tagLNode *next;
}LNode,*LinkList;         //链表结构体 

void input(ElemType *ep)
{
	scanf("%d",ep);     //输出的已经是指针指向的内容，故没有& 
}

void CreateLinkF(tagLNode *L,int n,void (*input)(ElemType*))
{
	tagLNode s;
	L=(tagLNode*)malloc(sizeof(tagLNode));   //sizeof 括号里的是结构体而不是指针 
	L->next=NULL;
	for(;n>0;n--)
	{
		s=(tagLNode*)malloc(sizeof(tagLNode));     //s = (int *)malloc(sizeof(int)) 
		input(&s->data);
		s->next=L->next;            //头插法 演示：http://www.nowamagic.net/librarys/veda/detail/1810 
		L->next=s;
	}
} 
main()
{
	tagLNode L,p;  //创建单链表 
	L->next = NULL;
	CreateLinkF(&L,5,input); 
	p=L->next; 
	for(int i=0;i<5&&p!=NULL;i++)
	{
	    printf("%d",p->data);
	    p=p->next;
	}
	return 0;
} 

