//FLoyd�㷨������ͼ  +  ����ͼ��
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
//�����߼�

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
//����һ��ͼ 
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


void Floyd(AdjMatrix G,Pathmatrix *parent,Pathmatrix *D)
{
    int v,w,k;
    
    for(v=0; v<G.vexnum; v++)
    {
    	for(w=0; w<G.vexnum; w++)
    	{
    		(*D)[v][w] = G.arcs[v][w].adj;
    		(*parent)[v][w] = w;        //��ʼ��������ʹ��ָ������ 
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
	AdjMatrix G;        //ע�����ﲻҪ����ָ�� 
	int n;
    CreateDN(&G);
    int p[100][100];
    int D[100][100];
    Floyd(G,&p,&D);
    printf("�����뵱ǰλ�ñ�ţ�");
	scanf("%d",&n);
	n-=1;
	for(int i=0; i<G.vexnum; i++)
	{
		printf("��ǰλ�õ�%d�����Ϊ��%d",i,D[n][i]); 
	}
	return OK;
}



