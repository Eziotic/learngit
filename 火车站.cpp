#include<stdio.h>
#include<stdlib.h>

typedef struct tagNode{
    int data;
    struct tagNode *prev, *next;
}Node, *LinkList;

int Judge(int a[])
{
    int i=0,j=1;
    LinkList L, p=L=(LinkList)malloc(sizeof(Node)), s;
    while(a[i]!=0)
    {
        if(j==a[i]) j++, i++;
        if(a[i]==0) break;
        if(j<a[i])
        {
            for(; j!=a[i]; j++)
            {
                s =(LinkList)malloc(sizeof(Node));
	    		s->data=j,s->prev=p,s->next=NULL,p->next=s,p=s;
            }
            i++, j++;
        }
        if(a[i]==0) break;
        if(j>=a[i])
        {
            if(p->data!=a[i]) return 0;
            else{
                p->prev->next = NULL, s=p->prev;
                free(p), p=s;
            }
            i++;
        }
        if(a[i]==0) break;
    }
    if(a[i]==0) return 1;
}