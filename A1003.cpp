#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

const int maxv=510;
const int INF=1E8;
int d[maxv];
bool vis[maxv]={false};
int n,m,st,ed;
int G[maxv][maxv];
int weight[maxv];
int w[maxv];
int num[maxv];

void Dijkstra(int st)
{
  fill(d,d+maxv,INF);
  fill(w,w+maxv,0);
  memset(num,0,sizeof(num));
  d[st]=0;
  num[st]=1;
  w[st]=weight[st];
  for(int i=0;i<n;i++)
  {
    int u=-1,MIN=INF;
    for(int j=0;j<n;j++)
    {
      if(vis[j]==false&&d[j]<MIN)
      {
        u=j;
        MIN=d[j];
      }
    }
    if(u==-1) return;
    vis[u]=true;
    for(int v=0;v<n;v++)
    {
      if(vis[v]==false&&G[u][v]!=INF&&G[u][v]+d[u]<d[v])
      {
        d[v]=G[u][v]+d[u];
        w[v]=w[u]+weight[v];
        num[v]=num[u];
      }else if(G[u][v]+d[u]==d[v])
      {
        if(w[v]<w[u]+weight[v])
          w[v]=w[u]+weight[v];
        num[v]+=num[u];
      }

    }
  }
}

int main()
{
  cin>>n>>m>>st>>ed;
  for(int i=0;i<n;i++)
    cin>>weight[i];
  fill(G[0],G[0]+maxv*maxv,INF);
  for(int i=0;i<m;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    G[a][b]=G[b][a]=c;
  }
  Dijkstra(st);
  cout<<num[ed]<<' '<<w[ed]<<endl;
  return 0;
}
