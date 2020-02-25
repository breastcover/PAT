#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int n,k;
map<string,vector<string>> adjlist;
map<string,int> weigt;
map<string,int> res;
map<string,bool> vis;
int sum=0,aw=0,max_w=0;
string head;

void dfs(string s)
{
  sum++;
  aw+=weigt[s];
  vis[s]=true;
  if(weigt[s]>max_w)
  {
    max_w=weigt[s];
    head=s;
  }
  if(adjlist[s].size()==0)
  {
    return ;
  }
  for(int i=0;i<adjlist[s].size();i++)
  {
    if(vis[adjlist[s][i]]==false)
      dfs(adjlist[s][i]);
  }
}

int main()
{
  cin>>n>>k;
  for(int i=0;i<n;i++)
  {
    string a,b;
    int w;
    cin>>a>>b>>w;
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
    weigt[a]+=w;
    weigt[b]+=w;
    vis[a]=vis[b]=false;
  }
  for(auto iter=adjlist.begin();iter!=adjlist.end();iter++)
  {
    dfs(iter->first);
    if(sum>2&&aw/2>k)
    {
      res[head]=sum;
    }
    sum=0;
    aw=0;
    max_w=0;
  }
  cout<<res.size()<<endl;
  for(auto iter=res.begin();iter!=res.end();iter++)
  {
    cout<<iter->first<<' '<<iter->second<<endl;
  }
  return 0;
}
