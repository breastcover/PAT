#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX=222;
const int INF=1e8;

int n,k;
string st;
map<string,int> city2index;
map<int,string> index2city;
map<string,int> happiness;
int G[MAX][MAX];
int d[MAX];
bool vis[MAX];
vector<int> path[MAX];
vector<int> tmp_path,path1;
int max_happiness=0,path_sum=0;

void Dijkstra(string st)
{
  fill(d,d+MAX,INF);
  fill(vis,vis+MAX,false);
  d[city2index[st]]=0;
  for(int i=0;i<n;i++)
  {
    int u=-1,_min=INF;
    for(int j=0;j<n;j++)
    {
      if(vis[j]==false&&d[j]<_min)
      {
        _min=d[j];
        u=j;
      }
    }

    if(u==-1)
      return ;
    vis[u]=true;
    for(int v=0;v<n;v++)
    {
      if(vis[v]==false&&G[u][v]!=INF)
      {
        if(d[v]>d[u]+G[u][v])
        {
          d[v]=d[u]+G[u][v];
          path[v].clear();
          path[v].push_back(u);
        }else if(d[v]==d[u]+G[u][v])
        {
          path[v].push_back(u);
        }
      }
    }
  }
}

void dfs(int s)
{
  tmp_path.push_back(s);
  if(s==city2index[st])
  {
    int tmp_happiness=0;
    path_sum++;
    for(int i=0;i<tmp_path.size();i++)
    {
      int l=tmp_path[i];
      tmp_happiness+=happiness[index2city[l]];
    }
    if(tmp_happiness>max_happiness)
    {
      max_happiness=tmp_happiness;
      path1=tmp_path;
    }
    tmp_path.pop_back();
    return ;
  }
  // cout<<path[s].size()<<endl;
  // cout<<s<<endl;
  for(int i=0;i<path[s].size();i++)
  {
    //cout<<path[s][i]<<endl;
    dfs(path[s][i]);
  }
  tmp_path.pop_back();
}

int main()
{
  cin>>n>>k>>st;
  city2index[st]=0;
  index2city[0]=st;
  for(int i=1;i<n;i++)
  {
    string city;
    int hp;
    cin>>city>>hp;
    happiness[city]=hp;
    city2index[city]=i;
    index2city[i]=city;
  }
  fill(G[0],G[0]+MAX*MAX,INF);
  for(int i=0;i<k;i++)
  {
    string c1,c2;
    int d;
    cin>>c1>>c2>>d;
    G[city2index[c1]][city2index[c2]]=d;
    G[city2index[c2]][city2index[c1]]=d;
  }
  // for(auto iter:city2index)
  //   cout<<iter.first<<' '<<iter.second<<endl;
  // for(int i=0;i<n;i++)
  // {
  //   for(int j=0;j<n;j++)
  //     printf("% 8d    ",G[i][j]);
  //   cout<<endl;
  // }
  Dijkstra(st);
  dfs(city2index["ROM"]);
  cout<<path_sum<<' '<<d[city2index["ROM"]]<<' '<<max_happiness<<' '<<max_happiness/(path1.size()-1)<<endl;
  for(auto iter=path1.rbegin();iter!=path1.rend();iter++)
  {
    cout<<index2city[*iter];
    if(iter!=path1.rend()-1)
      cout<<"->";
  }
  cout<<endl;
  return 0;
}
