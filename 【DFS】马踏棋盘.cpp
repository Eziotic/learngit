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
	//找下一个可以走的坐标（x1，y1），找到则flag==1
	/*for(; !flag && count<=7; count++)
	{
		flag = nextxy(&x1,&y1,count);  // 第一次试水（找到则将flag置为1，改变x1，y1的值 ） 
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
			return 1;   //层层递归 
		}
		x1=x,y1=y;      //还原上层数据，准备下一次循环 
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
		printf("失败\n");
	}
	finish = clock();
	printf("本次计算耗时：%fs\n\n",(double)(finish-start)/CLOCKS_PER_SEC);
	return 0;
}
