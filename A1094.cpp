#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> members(101,0);
int _max=1;
vector<vector<int>> vec(101);

void dfs(int id,int level)
{
  if(vec[id].size()==0)
    return ;
  members[level+1]+=vec[id].size();
  if(members[level+1]>_max)
    _max=members[level+1];
  for(int i=0;i<vec[id].size();i++)
  {
    dfs(vec[id][i],level+1);
  }
}

int main()
{
  int n,m;
  cin>>n>>m;

  for(int i=1;i<=m;i++)
  {
    int id,c_num;
    cin>>id>>c_num;
    while(c_num--)
    {
      int c_id;
      cin>>c_id;
      vec[id].push_back(c_id);
    }
  }
  dfs(1,1);
  members[1]=1;
  for(int i=1;i<=n;i++)
  {
    if(members[i]==_max)
    {
      cout<<_max<<' '<<i<<endl;
      break;
    }
  }
  return 0;
}
