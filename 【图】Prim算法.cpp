//prim算法求最小生成树 
/*
①lowcast[k]记录带有边k的最小权值，为0则未被访问 
②adjvex[i]=j 表示边(i,j) 
③关键条件：G.arcs[k][j].adj < lowcost[j] 
④输出 G.arcs[adjvex[k]][k].adj
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
//创建一个图 
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
		G->arcs[j][i].adj = w;         
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

void Prim(AdjMatrix G)
{
	int i,j,min,k,sum = 0;
	int adjvex[100];        //用来记录一条边的两个顶点(在第二次初始化时记录) 
    int lowcost[100];     //用来记录最小权值 
    for(i=1; i<G.vexnum; i++)       //初始化两数组 
    {
    	lowcost[i] = G.arcs[0][i].adj;
    	adjvex[i] = 0; 
	}
	adjvex[0] = 0;
	//循环 
	for(i=1; i<G.vexnum; i++)       //细节：两次循环间初始化操作 
	{
		min = MAX;       //初始化min 
		//k = 0;          //初始化k 
	    for(j=1; j<G.vexnum; j++)
	    {
	    	if(lowcost[j]>0 && lowcost[j]<min)
	    	{
	    		min = lowcost[j];
	    		k = j;
			}
		}
		sum += min;
		printf("%c %c %d\n",G.vertex[adjvex[k]], G.vertex[k], G.arcs[adjvex[k]][k].adj);
		
		lowcost[k] = 0;      //标记0表示被访问 
		for(j=1; j<G.vexnum; j++)      //for循环内更新两数组 
		{
			if(lowcost[j]>0 && G.arcs[k][j].adj < lowcost[j])
			{
				lowcost[j] = G.arcs[k][j].adj;
				adjvex[j] = k;
			}
		}
	}
	printf("最小路径权值和：%d",sum);
}

main()
{
	AdjMatrix G;        //注意这里不要建立指针 
    CreateDN(&G);
    Prim(G);
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






