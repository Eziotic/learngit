#include<stdio.h>
#include<stdlib.h>
//����������
typedef struct tagElemType{
	int i;
	int r;
}ElemType;        //���ݽṹ�� 

struct tagLNode{
	ElemType data;
	tagLNode *next;
}LNode,*LinkList;         //����ṹ�� 

void input(ElemType *ep)
{
	scanf("%d",ep);     //������Ѿ���ָ��ָ������ݣ���û��& 
}

void CreateLinkF(tagLNode *L,int n,void (*input)(ElemType*))
{
	tagLNode s;
	L=(tagLNode*)malloc(sizeof(tagLNode));   //sizeof ��������ǽṹ�������ָ�� 
	L->next=NULL;
	for(;n>0;n--)
	{
		s=(tagLNode*)malloc(sizeof(tagLNode));     //s = (int *)malloc(sizeof(int)) 
		input(&s->data);
		s->next=L->next;            //ͷ�巨 ��ʾ��http://www.nowamagic.net/librarys/veda/detail/1810 
		L->next=s;
	}
} 
main()
{
	tagLNode L,p;  //���������� 
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

