//逆波兰计算器 
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
	*(s->top) = e;       //赋值 
	s->top++;            //top地址自增 
}
void Pop(sqStack *s,ElemType *e)
{
	if( s->top == s->base)
	return;
	
	*e = *--(s->top);              //提取被出栈的值，并使top地址自减 
}
int StackLen(sqStack s)
{
	return(s.top - s.base);        //返回容量   
}

int main()
{
	sqStack s;
	char c,e;

	InitStack(&s);
	
	printf("请输入逆波兰表达式，并以'#'作为结束标志：\n");
	scanf("%c",&c);
    
    while( c!='#')
	{
		while( c>='0'&&c<='9' )   //1.数字直接输出，标点符号进栈 
		{
			printf("%c",c);
			scanf("%c",&c);        //为数字之间加空格 （此此处可能接收到'#'） 
			if( c<'0' || c>'9' )
			{
				printf(" ");
			}
		}
		if( ')'== c)       //2.判断是否为右括号
		{
			Pop(&s,&e);        //右括号与括号内容出栈
			while( '('!=e )
			{
				printf("%c ",e);
				Pop(&s,&e);
			}
		} 
		else if( '+'==c||'-'==c ) //3.比较优先级
	    {
	    	if( !StackLen(s) )   //若是空栈，直接压栈
	    	{
	    		Push(&s,c);
			}
			else 
			{
				do          //因为需要先得到c前面的e 所以用do-while循环
				{           //使+、-前面的符号（除左括号）全出栈
					Pop(&s,&e);
					if( '('==e )
					{
						Push(&s,e);     //如果是左括号，将其放回
					}
					else
					{
						printf("%c ",e);
					}
				}while( StackLen(s)&&'('!=e ); //难点
				Push(&s,c);  //先出优先级高的，在将c入栈 
			}
		}
		else if( '*'==c || '/'==c || '('==c)     //4.三种情况直接入栈
		{
			Push(&s,c);
	    }
	    else if( '#'==c )
        {
        	break;
		}
	    else
	    {
	    	printf("\n出错");
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


