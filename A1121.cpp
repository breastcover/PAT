#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> couple(100001,-1);
  vector<bool> flag(100001,false);
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    couple[a]=b;
    couple[b]=a;
  }
  int m;
  cin>>m;
  vector<int> party(m);
  for(int i=0;i<m;i++)
  {
    cin>>party[i];
    flag[party[i]]=true;
  }
  vector<int> res;
  for(int i=0;i<m;i++)
  {
    if(couple[party[i]]==-1)
    {
      res.push_back(party[i]);
    }else if(flag[couple[party[i]]]==false)
    {
      res.push_back(party[i]);
    }
  }
  sort(res.begin(),res.end());
  cout<<res.size()<<endl;
  for(int i=0;i<res.size();i++)
  {
    if(i==0)
     printf("%05d",res[i]);
    else
      printf(" %05d",res[i]);
  }

  return 0;
}
