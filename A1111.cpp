#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=501;
const int INF=1e8;

int n,m;
int st,ed;
int G[MAX][MAX];
int W[MAX][MAX];
bool vis[MAX];
int d[MAX];
int t[MAX];
vector<int> path[MAX];
vector<int> t_path[MAX];
vector<int> tm[MAX];
vector<int> path1,tmp;
vector<int> path2,tmp2;
int min_time=INF,fewest_intersections=INF;
int min_inters=INF;

void DijkstraP(int s)
{
  fill(d,d+MAX,INF);
  fill(vis,vis+MAX,false);
  d[s]=0;
  for(int i=0;i<n;i++)
  {
    int u=-1,_min=INF;
    for(int j=0;j<n;j++)
    {
      if(d[j]<_min&&vis[j]==false)
      {
        u=j;
        _min=d[j];
      }
    }
    if(u==-1)
      return ;
    vis[u]=true;
    for(int v=0;v<n;v++)
    {
      if(G[u][v]!=INF&&vis[v]==false)
      {
        if(d[v]>d[u]+G[u][v])
        {
          d[v]=d[u]+G[u][v];
          path[v].clear();
          path[v].push_back(u);
        }
        else if(d[v]==d[u]+G[u][v])
        {
          path[v].push_back(u);
        }
      }
    }
  }
}

void DijkstraT(int s)
{
  fill(t,t+MAX,INF);
  fill(vis,vis+MAX,false);
  t[s]=0;
  for(int i=0;i<n;i++)
  {
    int u=-1,_min=INF;
    for(int j=0;j<n;j++)
    {
      if(t[j]<_min&&vis[j]==false)
      {
        u=j;
        _min=t[j];
      }
    }
    if(u==-1)
      return ;
    vis[u]=true;
    for(int v=0;v<n;v++)
    {
      if(W[u][v]!=INF&&vis[v]==false)
      {
        if(t[v]>t[u]+W[u][v])
        {
          t[v]=t[u]+W[u][v];
          t_path[v].push_back(u);
        }
        else if(t[v]==t[u]+W[u][v])
        {
          t_path[v].push_back(u);
        }
      }
    }
  }
}

void dfs1(int s)
{
  tmp.push_back(s);
  if(s==st)
  {
    int times=0;
    for(int i=tmp.size()-1;i>=1;i--)
    {

      times+=W[tmp[i]][tmp[i-1]];
      //cout<<W[i][i-1]<<endl;
    }
    //cout<<times<<endl;
    if(times<min_time)
    {
      min_time=times;
      path1=tmp;
    }
    else if(times==min_time&&min_inters>tmp.size())
    {
      min_inters=tmp.size();
      path1=tmp;
    }
    tmp.pop_back();
    return ;
  }
  for(int i=0;i<path[s].size();i++)
  {
    dfs1(path[s][i]);
  }
  tmp.pop_back();
}

void dfs2(int s)
{
  tmp2.push_back(s);
  if(s==st)
  {
    int intersections=tmp.size();

    if(intersections<fewest_intersections)
    {
      fewest_intersections=intersections;
      path2=tmp2;
    }
    tmp2.pop_back();
    return ;
  }
  for(int i=0;i<path[s].size();i++)
  {
    dfs2(t_path[s][i]);
  }
  tmp2.pop_back();
}

int main()
{
  cin>>n>>m;
  fill(G[0],G[0]+MAX*MAX,INF);
  fill(W[0],W[0]+MAX*MAX,INF);
  for(int i=0;i<m;i++)
  {
    int v1,v2,one_way,length,_time;
    cin>>v1>>v2>>one_way>>length>>_time;
    if(one_way==0)
    {
      G[v1][v2]=length;
      G[v2][v2]=length;
      W[v1][v2]=_time;
      W[v2][v1]=_time;
    }else
    {
      G[v1][v2]=length;
      W[v1][v2]=_time;
    }
  }
  cin>>st>>ed;
  DijkstraP(st);
  dfs1(ed);

  DijkstraT(st);
  dfs2(ed);

  //cout<<path1.size()<<endl;
  if(path1==path2)
  {
    cout<<"Distance = "<<d[ed]<<"; Time = "<<t[ed]<<": ";
    for(int i=path1.size()-1;i>=0;i--)
    {
      cout<<path1[i];
      if(i!=0)
        cout<<" -> ";
    }
  }
  else
  {
    cout<<"Distance = "<<d[ed]<<": ";
    for(int i=path1.size()-1;i>=0;i--)
    {
      cout<<path1[i];
      if(i!=0)
        cout<<" -> ";
    }
    cout<<endl;
    cout<<"Time = "<<t[ed]<<": ";
    for(int i=path2.size()-1;i>=0;i--)
    {
      cout<<path2[i];
      if(i!=0)
        cout<<" -> ";
    }
    cout<<endl;
  }
  return 0;
}
