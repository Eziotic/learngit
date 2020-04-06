//DFS+回溯算法构造二维数组输出拓扑排序的所有结果
//①相似之处：构造入度数组，是否访问数组
//②不同之处：DFS算法，数组代替邻接表模拟边弧
#include<stdio.h>
#include<string.h>

int mark[100] = {0};
int map[100][100] = {0};    //map[i][j]表示i→j 
int indegree[100] = {0};
int ans[100] = {0};
int n,m;

void DFS(int num)
{
	int i,j,k;
	
	if(num == n)
	{
		for(i=0; i<n-1; i++)
		{
			printf("%d->",ans[i]);
		}
		printf("%d\n",ans[i]);
		return;
	}
	for(i=0; i<n; i++)
	{
		if((!mark[i]) && (!indegree[i]))  //未被访问并且入度为0 
		{
			for(j=0; j<n; j++)           //被指的入度-1 
				if(map[i][j])
					indegree[j]--;      //万万不可把递归DFS再套循环 
			mark[i] = 1;
			ans[num] = i;
			DFS(num+1);
			
			for(k=0; k<n; k++)
				if(map[i][k])
					indegree[k]++;      //回溯入度重新+1 
			mark[i] = 0;
		}
	}
	return;
}
main()
{
	int a,b,i,j,num;
	scanf("%d %d",&n,&m);
	for(i=1; i<=m; i++)
	{
		scanf("%d %d",&a,&b);
		map[a][b] = 1;
		indegree[b]++;
	}
	DFS(0);
	
	return 0;
}
/*12 16
1 2 
1 4 
1 3 
1 12 
2 3 
3 5 
3 7 
3 8 
4 5 
5 7 
9 12 
9 10 
9 11 
10 12 
11 6 
6 8 
拓扑序列之一：1 2 3 4 5 7 9 10 11 12 6 8
*/

