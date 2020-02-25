#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
  int id;
  int weighth;
  vector<int> children;
}Node;

int n,m,w;
vector<node> vec;
vector<int> path;
vector<vector<int>> paths;

void DFS(node root,int sum)
{
  sum+=root.weighth;
  path.push_back(root.weighth);
  if(root.children.empty())
  {
    if(sum==w)
    {
      paths.push_back(path);
    }
  }
  for(int i=0;i<root.children.size();i++)
  {
    DFS(vec[root.children[i]],sum);
  }
  path.pop_back();
}

bool cmp(const vector<int>& v1,const vector<int>& v2)
{
  int size=v1.size()>v2.size()?v2.size():v1.size();
  for(int i=0;i<size;i++)
  {
    if(v1[i]>v2[i])
      return true;
    else if(v1[i]<v2[i])
      return false;
  }
  if(v1.size()>v2.size())
    return true;
  return false;
}


int main()
{
  cin>>n>>m>>w;
  vec.resize(n);
  for(int i=0;i<n;i++)
    cin>>vec[i].weighth;
  for(int i=0;i<m;i++)
  {
    int child_num,id;
    cin>>id>>child_num;
    while(child_num--)
    {
      int tmp;
      cin>>tmp;
      vec[id].children.push_back(tmp);
    }
  }
  //cout<<"input_success"<<endl;
  DFS(vec[0],0);
  sort(paths.begin(),paths.end(),cmp);
  for(int i=0;i<paths.size();i++)
  {
    cout<<paths[i][0];
    for(int j=1;j<paths[i].size();j++)
      cout<<" "<<paths[i][j];
    cout<<endl;
  }
  return 0;
}
