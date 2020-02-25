#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int father[10010];
bool isRoot[10010];

void init()
{
  for(int i=0;i<10010;i++)
  {
    father[i]=i;
    isRoot[i]=false;
  }
}

int findFather(int x)
{
  int a=x;
  while(x!=father[x])
  {
    x=father[x];
  }
  while(a!=father[a])
  {
    int z=a;
    a=father[a];
    father[z]=x;
  }
  return x;
}

void Union(int a,int b)
{
  int FaA=findFather(a);
  int FaB=findFather(b);
  if(FaA!=FaB)
  {
    father[FaB]=FaA;
  }
}

int main()
{
  int n;
  cin>>n;
  set<int> s;
  init();
  for(int i=0;i<n;i++)
  {
    int m;
    cin>>m;
    vector<int> tmp;
    for(int j=0;j<m;j++)
    {
      int index;
      cin>>index;
      tmp.push_back(index);
      s.insert(index);
    }
    for(int i=0;i<tmp.size()-1;i++)
    {
      Union(tmp[i],tmp[i+1]);
    }
  }
  int sum=0;
  for(int e:s)
  {
    if(father[e]==e)
      sum++;
  }
  cout<<sum<<' '<<s.size()<<endl;
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    int a,b;
    cin>>a>>b;
    if(findFather(a)==findFather(b))
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
  return 0;
}
