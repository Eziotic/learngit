#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 20
typedef char VertexType;

//�߱��� 
typedef struct EdgeNode{
    int adjvex;
    struct EdgeNode *next;
}EdgeNode;

//�������
typedef struct VertexNode{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct{
    AdjList adjlist;
    int numVertexes,numEdges;
}GraphAdjList;

//�����ڽӱ�
void Create(GraphAdjList *G){

    int i,j,k;
    EdgeNode *p;

    printf("���붥�����ͱ���:\n");
    scanf("%d%d",&G->numVertexes,&G->numEdges);

    //���붥����Ϣ
    printf("���붥����Ϣ:\n");
    for(i=0;i<G->numVertexes;i++){
        getchar();
        scanf("%c",&G->adjlist[i].data);
        G->adjlist[i].firstedge=NULL;           //��ָ��߱��ָ���ʼ�� 
    } 

    //�����߱�
    printf("�����(Vi,Vj)�е��±�i,j:\n"); 
    for(k=0;k<G->numEdges;k++){
        scanf("%d %d",&i,&j);
        p=(EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex=j;                                //�洢��ͷ 
        p->next=G->adjlist[i].firstedge;            //ͷ�巨����߽�� 
        G->adjlist[i].firstedge=p;

        //�����������ͼ��,����ͼ�� 
        p=(EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex=i;                                //�洢��ͷ 
        p->next=G->adjlist[j].firstedge;            //ͷ�巨����߽�� 
        G->adjlist[j].firstedge=p;
    }

    //��ӡ�ڽӱ�
    printf("�ڽӱ�Ϊ:\n");
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

typedef int Boolean;	// �������Ƕ���BooleanΪ�������ͣ���ֵΪTRUE��FALSE
Boolean visited[MAX];	// ���ʱ�־������

void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
	
	visited[i] = TRUE;
	printf("%c ",GL.adjlist[i].data);
	p = GL.adjlist[i].firstedge;    //ÿ�ζ���first��ʼ 
	
	while(p)
	{
		if( !visited[p->adjvex] )      //���ģ��Ƿ����adjvex
		{
			DFS(GL, p->adjvex);        //DFS�ӽ�� 
		}
		p = p->next;        //�൱��ɾ��������ԭ����firstedge���
	}
}

// �ڽӱ����ȱ�������
void DFSTraverse(GraphAdjList GL)
{
	int i;
	
	for( i=0; i < GL.numVertexes; i++ )
	{
		visited[i] = FALSE;		// ��ʼ�����ж���״̬����δ���ʹ�״̬
	}
	
	for( i=0; i < GL.numVertexes; i++ )
	{
		if( !visited[i] )		// ������ͨͼ��ֻ��ִ��һ��
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
