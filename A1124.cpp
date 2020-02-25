#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int m,n,s;
  cin>>m>>n>>s;
  vector<string> vec(m+1);
  for(int i=1;i<=m;i++)
  {
    cin>>vec[i];
  }
  vector<string> res;
  for(int i=1;i<=m;i++)
  {
    if(i==s)
    {
      if(find(res.begin(),res.end(),vec[i])!=res.end())
      {
        s+=1;
        continue;
      }
      res.push_back(vec[i]);
      s+=n;
    }
  }
  for(string str:res)
    cout<<str<<endl;
  if(res.size()==0)
    cout<<"Keep going..."<<endl;
  return 0;
}
