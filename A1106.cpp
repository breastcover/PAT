#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{

  double price;
  vector<int> child;
}node;

int n;
double p,r;
vector<Node> vec(100100);
double _min=1e8;
int num=0;

void dfs(int root)
{
  if(vec[root].child.size()==0)
  {
    if(vec[root].price<_min)
    {
      _min=vec[root].price;
      num=1;
    }
    else if(vec[root].price==_min)
      num++;
  }
  for(int i=0;i<vec[root].child.size();i++)
  {
    int k=vec[root].child[i];
    vec[k].price=vec[root].price*(1+r/100);
    dfs(k);
  }
}

int main()
{

  cin>>n>>p>>r;

  vec[0].price=p;
  for(int i=0;i<n;i++)
  {
    int child_num;
    cin>>child_num;
    for(int j=0;j<child_num;j++)
    {
      int c;
      cin>>c;
      vec[i].child.push_back(c);
    }
  }
  dfs(0);
  printf("%.4f %d\n",_min,num);
  return 0;
}
