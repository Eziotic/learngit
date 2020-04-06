/*Directed Acyclic Graph带权有向图 
新增结点入度数组G->adjlist[i].in 
AOV网：数据在顶点 可以理解为面向对象
AOE网：数据在边上，可以理解为面向过程*/ 
//参考链接：https://www.cnblogs.com/bigsai/p/11489260.html 
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 20

typedef int VertexType;

//边表结点 
typedef struct EdgeNode{
    int adjvex;
    struct EdgeNode *next;
}EdgeNode;

//顶点表结点
typedef struct VertexNode{
    VertexType data;
    int in;
    EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct{
    AdjList adjlist;
    int numVertexes,numEdges;
}GraphAdjList;

//创建邻接表
void Create(GraphAdjList *G)
{
    int i,j,k;
    EdgeNode *p;

    printf("输入顶点数和边数:\n");
    scanf("%d%d",&G->numVertexes,&G->numEdges);

	for(i=0; i<G->numVertexes; i++)
	{
		G->adjlist[i].in = 0;
    }//初始化 
    
    printf("输入顶点信息:\n");
    for(i=0;i<G->numVertexes;i++)
	{
        getchar();
        scanf("%d",&G->adjlist[i].data);
        G->adjlist[i].firstedge=NULL;           //将指向边表的指针初始化 
    }

    //建立边表
    printf("输入边(Vi,Vj)中的下标i,j:\n"); 
    for(k=0; k<G->numEdges; k++){
        scanf("%d %d",&i,&j);
        p = (EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex = j;                                //存储弧头 
        G->adjlist[j].in++;
        p->next = G->adjlist[i].firstedge;            //头插法插入边结点 
        G->adjlist[i].firstedge = p;
    }

    //打印邻接表
    printf("邻接表为:\n");
    for(i=0;i<G->numVertexes;i++){
        p=G->adjlist[i].firstedge;
        while(p){
            printf("(%d,%d)",G->adjlist[i].data,G->adjlist[p->adjvex].data);
            p=p->next;
        }
        printf("\n");
    } 
} 
//拓扑排序
int TopologicalSort(GraphAdjList *G)
{
	EdgeNode *e;
	int i,k,gettop;
	int top = 0;
	int count = 0;
	int *stack;
	stack = (int*)malloc(G->numVertexes * sizeof(int));
	
	for(i=0; i<G->numVertexes; i++)
	{
		if(0 == G->adjlist[i].in)
		{
			stack[++top] = i;     //将度为0的顶点下标入栈 
		}
	}
		while(0 != top)       //循环条件：所有入度为0的顶点出栈且没有新的入度0顶点进栈 
		{
			gettop = stack[top--];
			printf("%d ",G->adjlist[gettop].data);
			count++;
			
			for(e=G->adjlist[gettop].firstedge; e; e=e->next)
			{
				k = e->adjvex;
				//k号顶点的入读-1，判断-1后入度是否为0，如是则入栈
				if(!(--G->adjlist[k].in))
				{
					stack[++top] = k;     //每个顶点的度只有一次为0的机会 
				} 
			}
		} 
		if(count < G->numVertexes)
		{
			return 0;
		}
		else 
		{
			return 1;
		}
}

 
int main(){

    GraphAdjList G;

    Create(&G);
    TopologicalSort(&G);
}
/*12 16
1 2 3 4 5 6 7 8 9 10 11 12
0 1 
0 3
0 2
0 11
1 2
2 4
2 6
2 7
3 4
4 6
8 11
8 9
8 10
9 11
10 5
5 7
拓扑序列：1 2 3 4 5 7 9 10 11 12 6 8
*/
