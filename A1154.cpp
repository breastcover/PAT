#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct node
{
  int t1,t2;
};

int main()
{
  int n,m;
  cin>>n>>m;
  vector<node> e(m);
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    e[i].t1=a;
    e[i].t2=b;
  }
  int k;
  cin>>k;
  for(int j=0;j<k;j++)
  {
    set<int> s;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
      int tmp;
      cin>>tmp;
      s.insert(tmp);
      vec.push_back(tmp);
    }
    int flag=0;
    for(int i=0;i<m;i++)
    {
      if(vec[e[i].t1]==vec[e[i].t2])
      flag=1;
    }
    if(flag)
      cout<<"No"<<endl;
    else
      cout<<s.size()<<"-coloring"<<endl;

  }
  return 0;
}
