#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;



int main()
{
  int n,m;
  cin>>n>>m;
  map<int,vector<int>> mmp;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    mmp[a].push_back(b);
    mmp[b].push_back(a);
  }
  for(int i=0;i<m;i++)
  {
    int s;
    cin>>s;
    int flag=0;
    vector<int> vec(s);
    for(int j=0;j<s;j++)
    {
      cin>>vec[j];
    }
    for(int j=0;j<s;j++)
    {
      for(int k=0;k<mmp[vec[j]].size();k++)
      {
        if(find(vec.begin(),vec.end(),mmp[vec[j]][k])!=vec.end())
        {
          flag=1;
          cout<<"No"<<endl;
          break;
        }
      }
      if(flag)
        break;
    }
    if(!flag)
    cout<<"Yes"<<endl;
  }
  return 0;
}
