#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct node
{
  int dis;
  string name;
  node()
  {
    dis=1e8;
  }
  node(int d,string s)
  {
    dis=d;
    name=s;
  }
  ~node(){};
};

const int INF=1e8;

int n,k;
string st;
map<string,int> happiness;
map<string,vector<node>> m;
map<string,vector<string>> path;
map<string,bool> vis;
map<string,int> d;
vector<string> path1,tmp;
int max_happiness=0;
int path_num=0;

void Dijkstra(string s)
{
  d[s]=0;
  for(int i=0;i<n;i++)
  {
    string u="1";
    int _min=INF;
    for(auto j=d.begin();j!=d.end();j++)
    {
      if(d[j->first]<_min&&vis[j->first]==false)
      {
        _min=d[j->first];
        u=j->first;
      }
    }
    if(u=="1")
      return ;
    vis[u]=true;
    for(int v=0;v<m[u].size();v++)
    {
      string id=m[u][v].name;
      if(m[u][v].dis!=INF&&d[id]>d[u]+m[u][v].dis&&vis[id]==false)
      {
        d[id]=d[u]+m[u][v].dis;
        path[id].clear();
        path[id].push_back(u);
      }else if(m[u][v].dis!=INF&&d[id]==d[u]+m[u][v].dis&&vis[id]==false)
      {
        path[id].push_back(u);
      }
    }
  }
}

void dfs(string s)
{
  tmp.push_back(s);
  if(s==st)
  {
    path_num++;
    int sum=0;
    for(int i=0;i<tmp.size();i++)
    {
      sum+=happiness[tmp[i]];
    }
    if(max_happiness<sum)
    {
      max_happiness=sum;
      path1=tmp;
    }
    tmp.pop_back();
    return ;
  }
  for(int i=0;i<path[s].size();i++)
  {
    dfs(path[s][i]);
  }
  tmp.pop_back();
}



int main()
{
  cin>>n>>k>>st;
  vis[st]=false;
  for(int i=1;i<n;i++)
  {
    string city;
    cin>>city;
    cin>>happiness[city];
    vis[city]=false;
    d[city]=INF;
  }
  for(int i=0;i<k;i++)
  {
    string c1,c2;
    int d;
    cin>>c1>>c2>>d;
    m[c1].push_back(node(d,c2));
    m[c2].push_back(node(d,c1));
  }
  Dijkstra(st);
  dfs("ROM");
  cout<<path_num<<' '<<d["ROM"]<<' '<<max_happiness<<' '<<max_happiness/2<<endl;;
  for(auto iter=path1.rbegin();iter!=path1.rend();iter++)
  {
    cout<<*iter;
    if(iter!=path1.rend()-1)
      cout<<"->";
  }
  cout<<endl;
  return 0;
}
