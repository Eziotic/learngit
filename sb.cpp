#include <iostream>
#include <cstring>
#include <cstdio>
 using namespace std;
 int n,m;
 int s[100][100];
 int visit[100];
 int indegree[100];
 int ans[100];
 void DFS(int num)
 {
     int i,j,k;
     if (num==n)
    {
         for (i=0;i<n;i++)
         printf("%d ",ans[i]);
         printf("\n");
         return;
    }
    for (i=0;i<n;i++)
   {
    if ((!indegree[i])&&(!visit[i]))
    {
       for (j=0;j<n;j++)
            if (s[i][j])
             indegree[j]--;
             visit[i]=1;
             ans[num]=i;
             DFS(num+1);
     for (k=0;k<n;k++)///回溯，恢复现场，将入度重新加一，并且将该顶点标记为未访问
        if (s[i][k])
        indegree[k]++;
        visit[i]=0;
    }
   }
        return;
 }
  int main()
  {
 
      int a,b,i,j,num;
      scanf("%d%d",&n,&m);
      memset(indegree,0,sizeof(indegree));
      memset(s,0,sizeof(s));
      memset(visit,0,sizeof(visit));
      memset(ans,0,sizeof(ans));
      for (i=1;i<=m;i++)
      {
          scanf("%d%d",&a,&b);
          s[a][b]=1;
          indegree[b]++;
      }
      DFS(0);
      return  0;
 
  }
