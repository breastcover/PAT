#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=510;
const int INF=1E8;
int c,n,sp,m;
int s[MAX];
int weight[MAX];
int w[MAX];
int G[MAX][MAX];
int d[MAX];
bool vis[MAX];
vector<int> path[MAX],path1,tmp;
int minback=INF,minneed=INF;

void Dijkstra(int start)
{
  fill(d,d+MAX,INF);
  fill(w,w+MAX,0);
  fill(vis,vis+MAX,false);
  d[start]=0;
  for(int i=0;i<=n;i++)
  {
    int u=-1,min=INF;
    for(int j=0;j<=n;j++)
    {
      if(vis[j]==false&&d[j]<min)
      {
        u=j;
        min=d[j];
      }
    }
    if(u==-1)
      return ;
    vis[u]=true;
    for(int v=0;v<=n;v++)
    {
      if(vis[v]==false&&G[u][v]!=INF)
      {
        if(d[v]>d[u]+G[u][v])
        {
          d[v]=d[u]+G[u][v];
          path[v].clear();
          path[v].push_back(u);
        }
        else if(vis[v]==false&&d[u]+G[u][v]==d[v])
          path[v].push_back(u);
      }
    }
  }
}

void dfs(int v)
{
  tmp.push_back(v);
  if(v==0)
  {
    int need=0,back=0;
    for(int i=tmp.size()-1;i>=0;i--)
    {
      
      int id=tmp[i];

      if(weight[id]>0)
        back+=weight[id];
      else
      {
        if(back>(0-weight[id]))
          back-=(0-weight[id]);
        else
          need+=((0-weight[id])-back);
          back=0;
      }
    }
    if(need<minneed)
    {
      minneed=need;
      path1=tmp;
      minback=back;
    }else if(minneed==need&&minback>back)
    {
      minback=back;
      path1=tmp;
    }
    tmp.pop_back();
    return ;
  }
  for(int i=0;i<path[v].size();i++)
    dfs(path[v][i]);
  tmp.pop_back();
}


int main()
{
  cin>>c>>n>>sp>>m;
  fill(weight,weight+MAX,0);
  int cc;
  for(int i=1;i<=n;i++)
  {
    cin>>cc;
    weight[i]=cc-c/2;
  }
  fill(G[0],G[0]+MAX*MAX,INF);
  for(int i=1;i<=m;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    G[a][b]=G[b][a]=c;
  }
  Dijkstra(0);
  dfs(sp);
  printf("%d 0",minneed);
  for(int i=path1.size()-2;i>=0;i--)
    printf("->%d",path1[i]);
    printf(" %d\n",minback);
  return 0;
}
