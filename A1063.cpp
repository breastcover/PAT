#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<set<int>> vec(n);
  for(int i=0;i<n;i++)
  {
    int k;
    cin>>k;
    for(int j=0;j<k;j++)
    {
      int tmp;
      cin>>tmp;
      vec[i].insert(tmp);
    }
  }
  int m;
  cin>>m;

  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    a-=1,b-=1;
    double same=0;
    for(auto iter=vec[b].begin();iter!=vec[b].end();iter++)
    {
      if(vec[a].find(*iter)!=vec[a].end())
        same++;
    }

    printf("%.1f%%\n",(double)(same/(vec[a].size()+vec[b].size()-same))*100);
  }
  return 0;
}
