#include<stdio.h>
#include<time.h>
#define X 7 
#define Y 8 

int chess[X][Y];
int nextxy(int *x,int *y,int count)
{
	switch(count)
	{
	case 0:
			if(*x+2<=X-1 && *y-1>=0 && chess[*x+2][*y-1]==0)
		{
			*x += 2;
			*y -= 1;
			return 1;
		}break;
	case 1:
			if(*x+2<=X-1 && *y+1<=Y-1 && chess[*x+2][*y+1]==0)
		{
			*x += 2;
			*y += 1;
			return 1;
		}break;
	case 2:
			if(*x-2>=0 && *y+1<=Y-1 && chess[*x-2][*y+1]==0)
		{
			*x -= 2;
			*y += 1;
			return 1;
		}break;
	case 3:
			if(*x-2>=0 && *y-1>=0 && chess[*x-2][*y-1]==0)
		{
			*x -= 2;
			*y -= 1;
			return 1;
		}break;
	case 4:
			if(*x+1<=X-1 && *y-2>=0 && chess[*x+1][*y-2]==0)
		{
			*x += 1;
			*y -= 2;
			return 1;
		}break;
	case 5:
			if(*x+1<=X-1 && *y+2<=Y-1 && chess[*x+1][*y+2]==0)
		{
			*x += 1;
			*y += 2;
			return 1;
		}break;
	case 6:
			if(*x-1>=0 && *y+2<=Y-1 && chess[*x-1][*y+2]==0)
		{
			*x -= 1;
			*y += 2;
			return 1;
		}break;
	case 7:
			if(*x-1>=0 && *y-2>=0 && chess[*x-1][*y-2]==0)
		{
			*x -= 1;
			*y -= 2;
			return 1;
		}break;
	default : break;
	}
	return 0;
} 

void print()
{
	int i,j;
	for(i=0; i<X; i++)
	{
		for(j=0; j<Y; j++)
		{
		  printf("%2d\t",chess[i][j]);
	    }
	    printf("\n");
	    printf("\n");
	}
	printf("\n");
}

int DFS(int x,int y,int tag)
{
	int x1=x,y1=y,flag=0,count=0;
	chess[x][y] = tag;

	if(tag == X*Y)
	{
		printf("\n");
		print();
		return 1;
	}
	//����һ�������ߵ����꣨x1��y1�����ҵ���flag==1
	/*for(; !flag && count<=7; count++)
	{
		flag = nextxy(&x1,&y1,count);  // ��һ����ˮ���ҵ���flag��Ϊ1���ı�x1��y1��ֵ �� 
	}*/
	flag = nextxy(&x1,&y1,count);
	while(!flag && count<=7)
	{
		count++;
		flag = nextxy(&x1,&y1,count);
	}
	while(flag)
	{
		if( DFS(x1,y1,tag+1) )
		{
			return 1;   //���ݹ� 
		}
		x1=x,y1=y;      //��ԭ�ϲ����ݣ�׼����һ��ѭ�� 
		/*for(count; !flag && count<=7; ++count)
		{
			flag = nextxy(&x1,&y1,count); 
		}*/
	    flag = nextxy(&x1,&y1,++count);
		while(!flag && count<=7)
		{
			count++;
			flag = nextxy(&x1,&y1,count);
		}
	}
		if( flag == 0)
		{
		    chess[x][y] = 0;
		}
    return 0;
}

main()
{
	int i,j;
	clock_t start,finish;
	start = clock();
	
	for(i=0; i<X; i++)
	{
		for (j=0; j<Y; j++)
		{
			chess[i][j] = 0;
		}
	}
	if( !DFS(0,0,1) )
	{
		printf("ʧ��\n");
	}
	finish = clock();
	printf("���μ����ʱ��%fs\n\n",(double)(finish-start)/CLOCKS_PER_SEC);
	return 0;
}
