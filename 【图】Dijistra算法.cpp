//prim算法求最小生成树 
//参考资料：https://blog.csdn.net/u011068702/article/details/79155571 
/*
①除了v0顶点外权值初始化到D[v]
②一次循环：w1→k→w2 ,parent[w] = k
③ 
*/ 
#include<stdio.h>
#include<stdlib.h>

#define MAX 65500
#define MAX_VERTEX_NUM   20
#define OK               1
#define ERROR            0

typedef enum {DG,DN,UDG,UDN}GraphKind;
typedef char VertexData;
typedef struct ArcNode{
	int adj;
}ArcNode;
typedef struct{
	VertexData vertex[MAX_VERTEX_NUM];
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum,arcnum;
}AdjMatrix;

int LocateVertex(AdjMatrix *G, VertexData v)
{
	int j=ERROR,k;
	for( k=0; k<G->vexnum; k++)
	{
		if(G->vertex[k] == v)
		{
			j=k;break;
		}
	}
	return j;
}
//创建有向图 
int CreateDN(AdjMatrix *G)
{
	int i,j,k,w;
	VertexData v1,v2;
	printf("请输入图的顶点数和弧数，用空格隔开\n");
	scanf("%d %d",&G->vexnum, &G->arcnum);
	getchar();
	for(i=0; i<G->vexnum; i++)
	    for(j=0; j<G->vexnum; j++)
	    {
	    	G->arcs[i][j].adj = MAX;
    	}
	printf("请输入图的顶点,用空格隔开\n");
	for(i=0; i<G->vexnum; i++)
	{
	    scanf("%c",&G->vertex[i]);
	    getchar();  //在输入字符后，我们通常回输出空格或者回车符，在向 
		            //字符变量输入字符时，我们要将之前输入的空格或者回
		            //车符从缓冲区中清楚，这也就是程序中getchar()的用处 
	}
	printf("请输入一条边的两个顶点，用空格隔开\n");
	for(k=0; k<G->arcnum; k++)
	{
		scanf("%c %c %d",&v1, &v2, &w);
		getchar();
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		G->arcs[i][j].adj = w;      
	}
/*		for(i=0; i<G->vexnum; i++)
		{
		    for(j=0; j<G->vexnum; j++)
		    {
		    	printf("%d ",G->arcs[i][j].adj);
	    	}
	    	printf("\n");
	    }*/
	return OK;
}

void Dijkstra(AdjMatrix G,int v0)
{
	int v,k,w,min;
	int final[100];
	int parent[100];
	int D[v];
	
	for(v=0; v<G.vexnum; v++)
	{
		final[v] = 0;            //全部顶点初始化为未找到最短路径 
		D[v] = G.arcs[v0][v].adj;    //将与v0点有连线的顶点加上权值 
		parent[v] = 0;           //初始化路径数组p为 0  
	}
	D[v0] = 0;
	final[v0] = 1;
	//开始主循环，每次求得v0到某个v顶点的最短路径 
	for(v=0; v<G.vexnum; v++)
	{
		min = MAX;
		for(w=0; w<G.vexnum; w++)
		{
			if( !final[w] && D[w]<min )
			{
				k = w;
				min = D[w];
			}
		}
		final[k] = 1;     //将目前找到的最近的顶点置1
		//修正当前最短路径及距离
		for(w=0; w<G.vexnum; w++)
		{
			if( !final[w] && (min+G.arcs[k][w].adj < D[w]))
			{
				D[w] = min + G.arcs[k][w].adj;
				parent[w] = k;
			}
		}
	}
	for(int i=1; i<=G.vexnum; i++)
	{
		printf("当前位置到%d点距离为：%d\n",i,D[i-1]); 
	}
}

main()
{
	AdjMatrix G;        //注意这里不要建立指针 
    CreateDN(&G);
    int n;
    printf("请输入当前位置编号：");
	scanf("%d",&n);
	n-=1;
    Dijkstra(G,n);
	return OK;
}
/* 
7 9
1 2 3 4 5 6 7
1 2 28
1 6 10
2 3 16
2 7 14
3 4 12
4 5 22
4 7 18
5 6 25
5 7 24
*/ 






