#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  map<string,int> mmp;
  for(int i=0;i<n*m;i++)
  {
    string s;
    cin>>s;
    mmp[s]++;
  }
  int _max=0;
  string res;
  for(auto iter=mmp.begin();iter!=mmp.end();iter++)
  {
    if(iter->second>_max)
    {
      _max=iter->second;
      res=iter->first;
    }
  }
  cout<<res<<endl;
  return 0;
}
