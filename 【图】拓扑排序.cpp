/*Directed Acyclic Graph��Ȩ����ͼ 
��������������G->adjlist[i].in 
AOV���������ڶ��� �������Ϊ�������
AOE���������ڱ��ϣ��������Ϊ�������*/ 
//�ο����ӣ�https://www.cnblogs.com/bigsai/p/11489260.html 
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 20

typedef int VertexType;

//�߱��� 
typedef struct EdgeNode{
    int adjvex;
    struct EdgeNode *next;
}EdgeNode;

//�������
typedef struct VertexNode{
    VertexType data;
    int in;
    EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct{
    AdjList adjlist;
    int numVertexes,numEdges;
}GraphAdjList;

//�����ڽӱ�
void Create(GraphAdjList *G)
{
    int i,j,k;
    EdgeNode *p;

    printf("���붥�����ͱ���:\n");
    scanf("%d%d",&G->numVertexes,&G->numEdges);

	for(i=0; i<G->numVertexes; i++)
	{
		G->adjlist[i].in = 0;
    }//��ʼ�� 
    
    printf("���붥����Ϣ:\n");
    for(i=0;i<G->numVertexes;i++)
	{
        getchar();
        scanf("%d",&G->adjlist[i].data);
        G->adjlist[i].firstedge=NULL;           //��ָ��߱��ָ���ʼ�� 
    }

    //�����߱�
    printf("�����(Vi,Vj)�е��±�i,j:\n"); 
    for(k=0; k<G->numEdges; k++){
        scanf("%d %d",&i,&j);
        p = (EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex = j;                                //�洢��ͷ 
        G->adjlist[j].in++;
        p->next = G->adjlist[i].firstedge;            //ͷ�巨����߽�� 
        G->adjlist[i].firstedge = p;
    }

    //��ӡ�ڽӱ�
    printf("�ڽӱ�Ϊ:\n");
    for(i=0;i<G->numVertexes;i++){
        p=G->adjlist[i].firstedge;
        while(p){
            printf("(%d,%d)",G->adjlist[i].data,G->adjlist[p->adjvex].data);
            p=p->next;
        }
        printf("\n");
    } 
} 
//��������
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
			stack[++top] = i;     //����Ϊ0�Ķ����±���ջ 
		}
	}
		while(0 != top)       //ѭ���������������Ϊ0�Ķ����ջ��û���µ����0�����ջ 
		{
			gettop = stack[top--];
			printf("%d ",G->adjlist[gettop].data);
			count++;
			
			for(e=G->adjlist[gettop].firstedge; e; e=e->next)
			{
				k = e->adjvex;
				//k�Ŷ�������-1���ж�-1������Ƿ�Ϊ0����������ջ
				if(!(--G->adjlist[k].in))
				{
					stack[++top] = k;     //ÿ������Ķ�ֻ��һ��Ϊ0�Ļ��� 
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
�������У�1 2 3 4 5 7 9 10 11 12 6 8
*/
