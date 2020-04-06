#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 20
typedef char VertexType;

//边表结点 
typedef struct EdgeNode{
    int adjvex;
    struct EdgeNode *next;
}EdgeNode;

//顶点表结点
typedef struct VertexNode{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct{
    AdjList adjlist;
    int numVertexes,numEdges;
}GraphAdjList;

//创建邻接表
void Create(GraphAdjList *G){

    int i,j,k;
    EdgeNode *p;

    printf("输入顶点数和边数:\n");
    scanf("%d%d",&G->numVertexes,&G->numEdges);

    //输入顶点信息
    printf("输入顶点信息:\n");
    for(i=0;i<G->numVertexes;i++){
        getchar();
        scanf("%c",&G->adjlist[i].data);
        G->adjlist[i].firstedge=NULL;           //将指向边表的指针初始化 
    } 

    //建立边表
    printf("输入边(Vi,Vj)中的下标i,j:\n"); 
    for(k=0;k<G->numEdges;k++){
        scanf("%d %d",&i,&j);
        p=(EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex=j;                                //存储弧头 
        p->next=G->adjlist[i].firstedge;            //头插法插入边结点 
        G->adjlist[i].firstedge=p;

        //下面代码有向图无,无向图有 
        p=(EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex=i;                                //存储弧头 
        p->next=G->adjlist[j].firstedge;            //头插法插入边结点 
        G->adjlist[j].firstedge=p;
    }

    //打印邻接表
    printf("邻接表为:\n");
    for(i=0;i<G->numVertexes;i++){
        p=G->adjlist[i].firstedge;
        while(p){
            printf("(%c,%c)",G->adjlist[i].data,G->adjlist[p->adjvex].data);
            p=p->next;
        }
        printf("\n");
    } 
} 

#define TRUE 1
#define FALSE 0
#define MAX 256

typedef int Boolean;	// 这里我们定义Boolean为布尔类型，其值为TRUE或FALSE
Boolean visited[MAX];	// 访问标志的数组

void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
	
	visited[i] = TRUE;
	printf("%c ",GL.adjlist[i].data);
	p = GL.adjlist[i].firstedge;    //每次都从first开始 
	
	while(p)
	{
		if( !visited[p->adjvex] )      //核心：是否访问adjvex
		{
			DFS(GL, p->adjvex);        //DFS子结点 
		}
		p = p->next;        //相当于删除并更新原来的firstedge结点
	}
}

// 邻接表的深度遍历操作
void DFSTraverse(GraphAdjList GL)
{
	int i;
	
	for( i=0; i < GL.numVertexes; i++ )
	{
		visited[i] = FALSE;		// 初始化所有顶点状态都是未访问过状态
	}
	
	for( i=0; i < GL.numVertexes; i++ )
	{
		if( !visited[i] )		// 若是连通图，只会执行一次
		{
			DFS(GL, i);
		}
	}
}

int main(){

    GraphAdjList G;

    Create(&G);
    DFSTraverse(G); 
}
