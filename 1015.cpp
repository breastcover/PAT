#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




struct score
{
  int num;
  int df;
  int cf;
};

bool cmp(score a,score b)
{
  if((a.df+a.cf)>(b.df+b.cf))
    return true;
  else if((a.df+a.cf)==(b.df+b.cf))
  {
    if(a.df>b.df)
      return true;
    else if(a.df==b.df)
      if(a.num<b.num)
        return true;
  }
  return false;
}

int main()
{
  int n,L,H;
  vector<score> vec0,vec1,vec2,vec3;
  cin>>n>>L>>H;
  for(int i=0;i<n;i++)
  {
    score s;
    cin>>s.num>>s.df>>s.cf;
    if(s.df>=L&&s.cf>=L)
    {
      if(s.df>=H&&s.cf>=H)
        vec0.push_back(s);
      else if(s.df>=H&&s.cf<H)
        vec1.push_back(s);
      else if(s.df>=s.cf&&s.cf<H&&s.df<H)
        vec2.push_back(s);
      else
        vec3.push_back(s);
    }
  }
  sort(vec0.begin(),vec0.end(),cmp);
  sort(vec1.begin(),vec1.end(),cmp);
  sort(vec2.begin(),vec2.end(),cmp);
  sort(vec3.begin(),vec3.end(),cmp);
  cout<<vec0.size()+vec1.size()+vec2.size()+vec3.size()<<endl;
  for(int i=0;i<vec0.size();i++)
  {
    cout<<vec0[i].num;
    cout<<" ";
    cout<<vec0[i].df;
    cout<<" ";
    cout<<vec0[i].cf<<endl;
  }
  for(int i=0;i<vec1.size();i++)
  {
    cout<<vec1[i].num;
    cout<<" ";
    cout<<vec1[i].df;
    cout<<" ";
    cout<<vec1[i].cf<<endl;
  }
  for(int i=0;i<vec2.size();i++)
  {
    cout<<vec2[i].num;
    cout<<" ";
    cout<<vec2[i].df;
    cout<<" ";
    cout<<vec2[i].cf<<endl;
  }
  for(int i=0;i<vec3.size();i++)
  {
    cout<<vec3[i].num;
    cout<<" ";
    cout<<vec3[i].df;
    cout<<" ";
    cout<<vec3[i].cf<<endl;
  }
}
