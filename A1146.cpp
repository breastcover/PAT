#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> G[1010];
vector<int> vec(1010,0);

int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    vec[b]++;
    G[a].push_back(b);
  }
  int k;
  cin>>k;
  vector<int> res;
  for(int i=0;i<k;i++)
  {
    vector<int> hv(vec.begin(),vec.end());
    int flag=0;
    for(int j=0;j<n;j++)
    {
      int tmp;
      cin>>tmp;
      if(hv[tmp]==0)
      {
        for(int l=0;l<G[tmp].size();l++)
        {
          hv[G[tmp][l]]--;
        }
      }
      else
      {
        if(flag==0)
          res.push_back(i);
        flag=1;
      }
    }
  }
  for(int i=0;i<res.size();i++)
  {
    if(i==0)
      cout<<res[i];
    else
      cout<<' '<<res[i];
  }
  cout<<endl;
  return 0;
}
