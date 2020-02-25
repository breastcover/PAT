#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int cmp(const pair<int,int>& a,const pair<int,int>& b)
{
  return a.second<b.second;
}

int main()
{
  int n,start;
  cin>>n>>start;
  int data[100000];
  int next[100000];

  fill(data,data+100000,-2);
  fill(next,next+100000,-2);
  for(int i=0;i<n;i++)
  {
    int s;
    cin>>s;
    cin>>data[s]>>next[s];
  }
  vector<pair<int,int>> vec;
  //cout<<1<<endl;
  while(start!=-1)
  {
    vec.push_back(make_pair(start,data[start]));
    start=next[start];
  }
  //cout<<1<<endl;
  sort(vec.begin(),vec.end(),cmp);
  if(vec.size()>0)
  {
    cout<<vec.size()<<" "<<setw(5)<<setfill('0')<<vec[0].first<<endl;
    for(int i=0;i<vec.size()-1;i++)
    {
      cout<<setw(5)<<setfill('0')<<vec[i].first<<" "<<data[vec[i].first]<<" "<<setw(5)<<setfill('0')<<vec[i+1].first<<endl;
    }
    cout<<setw(5)<<setfill('0')<<vec[vec.size()-1].first<<" "<<data[vec[vec.size()-1].first]<<" "<<-1<<endl;

  }
  else
    cout<<0<<" "<<-1<<endl;
  return 0;
}
