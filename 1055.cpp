#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<string,int> p1,pair<string,int> p2)
{
  if(p1.second==p2.second)
    return p1.first<p2.first;
  return p1.second>p2.second;
}

int main()
{
  vector<pair<string,int>> vec;
  int n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++)
  {
    string s;
    int tall;
    cin>>s>>tall;
    vec.push_back(make_pair(s,tall));
  }
  sort(vec.begin(),vec.end(),cmp);


  int lastcol=k+n%k;
  int flag=0;
  int times=0;
  vector<string> res;
      for(auto iter=vec.begin();iter!=vec.end();)
      {

        if(flag==0)
        {
          res.push_back(iter->first);
          vec.erase(vec.begin());
          flag=1;
        }
        else
        {
          res.insert(res.begin(),iter->first);
          vec.erase(vec.begin());
          flag=0;
        }
        times++;
        if(times==lastcol)
        {
          flag=0;
          times=0;
          break;
        }
      }
  for(int i=0;i<res.size()-1;i++)
  {
    cout<<res[i]<<' ';
  }
  cout<<res[res.size()-1]<<endl;
  res.clear();


  for(auto iter=vec.begin();iter!=vec.end();)
  {
    if(flag==0)
    {
      res.push_back(iter->first);
      vec.erase(vec.begin());
      flag=1;
    }
    else
    {
      res.insert(res.begin(),iter->first);
      vec.erase(vec.begin());
      flag=0;
    }

    times++;
    if(times==k)
    {
      for(int i=0;i<res.size()-1;i++)
      {
        cout<<res[i]<<' ';
      }
      cout<<res[res.size()-1]<<endl;
      res.clear();
      times=0;
      flag=0;
    }
  }
  return 0;
}
