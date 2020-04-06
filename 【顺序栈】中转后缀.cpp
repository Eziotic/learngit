//�沨�������� 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define STACKSIZE 20
#define STACKINCREMENT 10
#define MAXBUFFER 10 

typedef char ElemType;
typedef struct {
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;
 
void InitStack(sqStack *s)
{
	s->base = (ElemType *)malloc(STACKSIZE*sizeof(ElemType));
	if( !s->base )
    {
    	exit(0);
	}
	
	s->top = s->base;
	s->stackSize = STACKSIZE;
}

void Push(sqStack *s,ElemType e)
{
	if( s->top - s->base >= s->stackSize )
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT)*sizeof(ElemType));
		if( !s->base )
		{
			exit(0);
	    }
    }
	*(s->top) = e;       //��ֵ 
	s->top++;            //top��ַ���� 
}
void Pop(sqStack *s,ElemType *e)
{
	if( s->top == s->base)
	return;
	
	*e = *--(s->top);              //��ȡ����ջ��ֵ����ʹtop��ַ�Լ� 
}
int StackLen(sqStack s)
{
	return(s.top - s.base);        //��������   
}

int main()
{
	sqStack s;
	char c,e;

	InitStack(&s);
	
	printf("�������沨�����ʽ������'#'��Ϊ������־��\n");
	scanf("%c",&c);
    
    while( c!='#')
	{
		while( c>='0'&&c<='9' )   //1.����ֱ������������Ž�ջ 
		{
			printf("%c",c);
			scanf("%c",&c);        //Ϊ����֮��ӿո� ���˴˴����ܽ��յ�'#'�� 
			if( c<'0' || c>'9' )
			{
				printf(" ");
			}
		}
		if( ')'== c)       //2.�ж��Ƿ�Ϊ������
		{
			Pop(&s,&e);        //���������������ݳ�ջ
			while( '('!=e )
			{
				printf("%c ",e);
				Pop(&s,&e);
			}
		} 
		else if( '+'==c||'-'==c ) //3.�Ƚ����ȼ�
	    {
	    	if( !StackLen(s) )   //���ǿ�ջ��ֱ��ѹջ
	    	{
	    		Push(&s,c);
			}
			else 
			{
				do          //��Ϊ��Ҫ�ȵõ�cǰ���e ������do-whileѭ��
				{           //ʹ+��-ǰ��ķ��ţ��������ţ�ȫ��ջ
					Pop(&s,&e);
					if( '('==e )
					{
						Push(&s,e);     //����������ţ�����Ż�
					}
					else
					{
						printf("%c ",e);
					}
				}while( StackLen(s)&&'('!=e ); //�ѵ�
				Push(&s,c);  //�ȳ����ȼ��ߵģ��ڽ�c��ջ 
			}
		}
		else if( '*'==c || '/'==c || '('==c)     //4.�������ֱ����ջ
		{
			Push(&s,c);
	    }
	    else if( '#'==c )
        {
        	break;
		}
	    else
	    {
	    	printf("\n����");
	    	return -1; 
	    }
	scanf("%c",&c);
	} 
	while( StackLen(s) )
	{
		Pop(&s,&e);
		printf("%c ",e);
	}
	return 0;
}


