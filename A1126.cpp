#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n,m;
vector<int> vec[510];
bool vis[510]={false};
int cnt=0;

void dfs(int n)
{
  vis[n]=true;
  cnt++;
  if(vec[n].size()==0)
    return ;
  for(int i=0;i<vec[n].size();i++)
  {
    if(!vis[vec[n][i]])
      dfs(vec[n][i]);
  }
}

int main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  int counter=0;
  for(int i=1;i<n+1;i++)
  {
    if(vec[i].size()%2!=0)
      counter++;
    if(i==1)
      cout<<vec[i].size();
    else
      cout<<' '<<vec[i].size();
  }
  cout<<endl;
  dfs(1);
  if(cnt!=n)
  {
    cout<<"Non-Eulerian"<<endl;
  }
  else
  {
    if(counter==0)
      cout<<"Eulerian"<<endl;
    else if(counter==2)
      cout<<"Semi-Eulerian"<<endl;
    else
      cout<<"Non-Eulerian"<<endl;
  }
  return 0;
}
