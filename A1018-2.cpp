#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF=1e9;
const int MAX=510;
int weight[MAX];
int cm,n,sp,m;
vector<int> current_num(510);
int G[510][510];
int d[510];
bool vis[510]={false};
vector<int> path[510],path1,tmp;
int minback=INF,minneed=INF;

void Dijkstra(int start)
{
  fill(d,d+510,INF);
  fill(vis,vis+MAX,false);
  d[start]=0;
  for(int i=0;i<=n;i++)
  {
    int u=-1,MIN=INF;
    for(int j=0;j<=n;j++)
    {
      if(vis[j]==false&&d[j]<MIN)
      {
        u=j;
        MIN=d[j];
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
        else if(vis[v]==false&&d[v]==d[u]+G[u][v])
        {
          path[v].push_back(u);
        }
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
      back+=weight[id];
    }
    //cout<<back<<endl;
    if(back>=0&&minback>back)
    {
      minback=back;
      path1=tmp;
    }else if(back<0&&minneed>-back)
    {
      minneed=-back;
      path1=tmp;
    }
    tmp.pop_back();
    return ;
  }

  for(int i=0;i<path[v].size();i++)
  {
    dfs(path[v][i]);
  }
  tmp.pop_back();
}

int main()
{
  cin>>cm>>n>>sp>>m;
  fill(weight,weight+MAX,0);
  for(int i=1;i<=n;i++)
  {
    cin>>current_num[i];
    weight[i]=current_num[i]-cm/2;
  }
  fill(G[0],G[0]+510*510,INF);
  for(int i=0;i<m;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    G[a][b]=c;
    G[b][a]=c;
  }
  Dijkstra(0);
  dfs(sp);

  if(minneed<INF)
    minback=0;
  else
    minneed=0;
  printf("%d 0",minneed);
  for(int i=path1.size()-2;i>=0;i--)
    printf("->%d",path1[i]);
    printf(" %d\n",minback);
  return 0;
}
