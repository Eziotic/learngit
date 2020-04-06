//Kruskal�㷨
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
//�����߼�
typedef struct node{
	int begin;
	int end;
	int weight;
};
node edges[100];

void  insertionSort(node edges[],int m,int n)
{
	for(int i=m+1;i<n;i++)
    {
    	node get = edges[i];                 
    	int j = i-1;
    	while(j>=m && edges[j].weight > get.weight)
    	{
			edges[j+1] = edges[j];
	    	j--; 
		}
	edges[j+1] = get;  //���һ��j�ֽ�����һ���Լ� 
    }
}
 
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
		edges[k].begin = i;
		edges[k].end = j;
		edges[k].weight = w;
	}
	insertionSort(edges, 0, G->arcnum);
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

int find(int *parent, int f)
{
	int x = f;
	while(parent[f]>0)   //Ѱ��Boss 
	{
		f = parent[f];
	}
	while(parent[x] != x)   //ѹ��·�� 
	{
		parent[x] = find(parent,parent[x]);
	}
	return f;
}

void Kruskal(AdjMatrix G)
{
    int i,m,n,sum = 0;
    for(i=0; i<G.vexnum; i++)
    {
    	parent[i] = 0;
	}
	for(i=0; i<G.arcnum; i++)
	{
		n = find(parent,edges[i].begin);
		m = find(parent,edges[i].end);
		
		if(n!=m)
		{
			parent[n] = m;  //·��ѹ�� 
			printf("(%d, %d) %d\n",edges[i].begin,edges[i].end,edges[i].weight);
			sum+=edges[i].weight;
		}
	}
	printf("��С·��Ȩֵ�ͣ�%d",sum);
}

main()
{
	AdjMatrix G;        //ע�����ﲻҪ����ָ�� 
    CreateDN(&G);
    Kruskal(G);
	return OK;
}


