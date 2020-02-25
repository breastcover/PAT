#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int maxv=510;
const int INF=1E8;

int n,m,st,ed;
int d[maxv];
int pre[maxv];
int G[maxv][maxv];
int weight[maxv][maxv];
int w[maxv];
bool vis[maxv]={false};

void DFS(int s,int v)
{
  if(v==s)
  {
    printf("%d ",v);
    return ;
  }
  DFS(s,pre[v]);
  printf("%d ",v );
}

void Dijkstra(int st)
{
  fill(d,d+maxv,INF);
  fill(w,w+maxv,INF);
  d[st]=0;
  w[st]=0;
  for(int i=0;i<n;i++)
  {
    int u=-1,MIN=INF;
    for(int j=0;j<n;j++)
    {
      if(!vis[j]&&d[j]<MIN)
      {
        u=j;
        MIN=d[j];
      }
    }
    if(u==-1) return;
    vis[u]=true;
    for(int v=0;v<n;v++)
    {
      if(!vis[v]&&G[u][v]!=INF)
      {
        if(d[v]>G[u][v]+d[u])
        {
          d[v]=G[u][v]+d[u];
          w[v]=weight[u][v]+w[u];
          pre[v]=u;
        }
        else if(d[v]==G[u][v]+d[u]&&w[v]>weight[u][v]+w[u])
        {
          w[v]=weight[u][v]+w[u];
          pre[v]=u;
        }
      }
    }
  }
}

int main()
{
  cin>>n>>m>>st>>ed;
  fill(weight[0],weight[0]+maxv*maxv,INF);
  fill(G[0],G[0]+maxv*maxv,INF);
  for(int i=0;i<m;i++)
  {
    int c1,c2,dis,cost;
    cin>>c1>>c2>>dis>>cost;
    G[c1][c2]=G[c2][c1]=dis;
    weight[c1][c2]=weight[c2][c1]=cost;
  }
  Dijkstra(st);
  DFS(st,ed);
  cout<<d[ed]<<' '<<w[ed]<<endl;
  return 0;
}
