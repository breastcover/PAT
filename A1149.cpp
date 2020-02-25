#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<int> vec[100010];
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  for(int i=0;i<m;i++)
  {
    int pn;
    cin>>pn;
    vector<int> p;
    for(int j=0;j<pn;j++)
    {
      int tmp;
      cin>>tmp;
      p.push_back(tmp);
    }
    int flag=1;
    for(int j=0;j<pn;j++)
    {
      if(vec[p[j]].size()!=0)
      {
        for(int k=0;k<vec[p[j]].size();k++)
        {
          if(find(p.begin()+j,p.end(),vec[p[j]][k])!=p.end())
          {
            flag=0;
            cout<<"No"<<endl;
            break;
          }
        }
      }
      if(!flag)
        break;
    }
    if(flag)
      cout<<"Yes"<<endl;
  }
  return 0;
}
