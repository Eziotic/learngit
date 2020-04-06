//prim�㷨����С������ 
//�ο����ϣ�https://blog.csdn.net/u011068702/article/details/79155571 
/*
�ٳ���v0������Ȩֵ��ʼ����D[v]
��һ��ѭ����w1��k��w2 ,parent[w] = k
�� 
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
//��������ͼ 
int CreateDN(AdjMatrix *G)
{
	int i,j,k,w;
	VertexData v1,v2;
	printf("������ͼ�Ķ������ͻ������ÿո����\n");
	scanf("%d %d",&G->vexnum, &G->arcnum);
	getchar();
	for(i=0; i<G->vexnum; i++)
	    for(j=0; j<G->vexnum; j++)
	    {
	    	G->arcs[i][j].adj = MAX;
    	}
	printf("������ͼ�Ķ���,�ÿո����\n");
	for(i=0; i<G->vexnum; i++)
	{
	    scanf("%c",&G->vertex[i]);
	    getchar();  //�������ַ�������ͨ��������ո���߻س��������� 
		            //�ַ����������ַ�ʱ������Ҫ��֮ǰ����Ŀո���߻�
		            //�����ӻ��������������Ҳ���ǳ�����getchar()���ô� 
	}
	printf("������һ���ߵ��������㣬�ÿո����\n");
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
		final[v] = 0;            //ȫ�������ʼ��Ϊδ�ҵ����·�� 
		D[v] = G.arcs[v0][v].adj;    //����v0�������ߵĶ������Ȩֵ 
		parent[v] = 0;           //��ʼ��·������pΪ 0  
	}
	D[v0] = 0;
	final[v0] = 1;
	//��ʼ��ѭ����ÿ�����v0��ĳ��v��������·�� 
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
		final[k] = 1;     //��Ŀǰ�ҵ�������Ķ�����1
		//������ǰ���·��������
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
		printf("��ǰλ�õ�%d�����Ϊ��%d\n",i,D[i-1]); 
	}
}

main()
{
	AdjMatrix G;        //ע�����ﲻҪ����ָ�� 
    CreateDN(&G);
    int n;
    printf("�����뵱ǰλ�ñ�ţ�");
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






