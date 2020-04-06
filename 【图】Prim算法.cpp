//prim�㷨����С������ 
/*
��lowcast[k]��¼���б�k����СȨֵ��Ϊ0��δ������ 
��adjvex[i]=j ��ʾ��(i,j) 
�۹ؼ�������G.arcs[k][j].adj < lowcost[j] 
����� G.arcs[adjvex[k]][k].adj
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
	int adjvex[100];        //������¼һ���ߵ���������(�ڵڶ��γ�ʼ��ʱ��¼) 
    int lowcost[100];     //������¼��СȨֵ 
    for(i=1; i<G.vexnum; i++)       //��ʼ�������� 
    {
    	lowcost[i] = G.arcs[0][i].adj;
    	adjvex[i] = 0; 
	}
	adjvex[0] = 0;
	//ѭ�� 
	for(i=1; i<G.vexnum; i++)       //ϸ�ڣ�����ѭ�����ʼ������ 
	{
		min = MAX;       //��ʼ��min 
		//k = 0;          //��ʼ��k 
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
		
		lowcost[k] = 0;      //���0��ʾ������ 
		for(j=1; j<G.vexnum; j++)      //forѭ���ڸ��������� 
		{
			if(lowcost[j]>0 && G.arcs[k][j].adj < lowcost[j])
			{
				lowcost[j] = G.arcs[k][j].adj;
				adjvex[j] = k;
			}
		}
	}
	printf("��С·��Ȩֵ�ͣ�%d",sum);
}

main()
{
	AdjMatrix G;        //ע�����ﲻҪ����ָ�� 
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






