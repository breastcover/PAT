#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double p,r;

struct node
{
  int level;
  double price;
  vector<int> child;
}Node;



vector<node> vec(100010);

double _max=-1;
int num=0;

void dfs(int root)
{
  if(vec[root].child.size()==0)
  {
    if(vec[root].price==_max)
      num++;
    if(vec[root].price>_max)
    {
      _max=vec[root].price;
      num=1;
    }
    return ;
  }
  for(int i=0;i<vec[root].child.size();i++)
  {
    vec[vec[root].child[i]].price=vec[root].price*(1+r/100);
    vec[vec[root].child[i]].level=vec[root].level+1;
    dfs(vec[root].child[i]);
  }
}

bool cmp(node n1,node n2)
{
  return n1.price<n2.price;
}

int main()
{
  int n;
  cin>>n>>p>>r;
  int root=0;
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    if(tmp==-1)
    {
      root=i;
    }
    else
      vec[tmp].child.push_back(i);
  }

  vec[root].price=p;
  vec[root].level=0;

  dfs(root);
  printf("%.2f %d\n",_max,num);
  return 0;
}
