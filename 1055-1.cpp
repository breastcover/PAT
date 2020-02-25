#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

struct person
{
  string name;
  int height;
};

bool cmp(person a,person b)
{
  return a.height==b.height?(a.name<b.name):(a.height>b.height);
}

int main()
{
  int n,k;
  cin>>n>>k;
  vector<person> vec;
  for(int i=0;i<n;i++)
  {
    person p;
    cin>>p.name>>p.height;
    vec.push_back(p);
  }
  sort(vec.begin(),vec.end(),cmp);
  int row=n/k;
  int lastcol=n-(k-1)*row;
  vector<string> res;
  int times=0;
  int flag=0;
  for(auto i=0;i<vec.size();)
  {
    if(flag==0)
    {
      res.push_back(vec[i].name);
      vec.erase(vec.begin());
      flag=1;
    }
    else
    {
      res.insert(res.begin(),vec[i].name);
      vec.erase(vec.begin());
      flag=0;
    }
    times++;
    if(times==lastcol)
    {
      flag=0;
      times=0;
      for(int i=0;i<res.size()-1;i++)
      {
        cout<<res[i]<<' ';
      }
      cout<<res[res.size()-1]<<endl;
      res.clear();
      break;
    }
  }

  for(int i=0;i<vec.size();)
  {
    if(flag==0)
    {
      res.push_back(vec[i].name);
      vec.erase(vec.begin());
      flag=1;
    }
    else
    {
      res.insert(res.begin(),vec[i].name);
      vec.erase(vec.begin());
      flag=0;
    }
    times++;
    if(times==row)
    {
      flag=0;
      times=0;
      for(int i=0;i<res.size()-1;i++)
      {
        cout<<res[i]<<' ';
      }
      cout<<res[res.size()-1]<<endl;
      res.clear();
    }
  }
  return 0;
}
