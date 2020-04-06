//FLoyd算法（无向图  +  有向图）
//https://blog.csdn.net/ytuyzh/article/details/88617987 
#include<stdio.h>

#define MAX 65500
#define MAX_VERTEX_NUM   20
#define OK               1
#define ERROR            0
int parent[100];

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

typedef int Pathmatrix[100][100];
typedef int ShortPathTable[100][100];
//创建边集

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


void Floyd(AdjMatrix G,Pathmatrix *parent,Pathmatrix *D)
{
    int v,w,k;
    
    for(v=0; v<G.vexnum; v++)
    {
    	for(w=0; w<G.vexnum; w++)
    	{
    		(*D)[v][w] = G.arcs[v][w].adj;
    		(*parent)[v][w] = w;        //初始化各数组使其指向自身 
		}
	}
	
	for(k=0; k<G.vexnum; k++)
	{
		for(v=0; v<G.vexnum; v++)
		{
			for(w=0; w<G.vexnum; w++)
			{
				if((*D)[v][w] > (*D)[v][k] + (*D)[k][w])
				{
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
					(*parent)[v][w] = k;
				}
			}
		}
	} 
}

main()
{
	AdjMatrix G;        //注意这里不要建立指针 
	int n;
    CreateDN(&G);
    int p[100][100];
    int D[100][100];
    Floyd(G,&p,&D);
    printf("请输入当前位置编号：");
	scanf("%d",&n);
	n-=1;
	for(int i=0; i<G.vexnum; i++)
	{
		printf("当前位置到%d点距离为：%d",i,D[n][i]); 
	}
	return OK;
}



