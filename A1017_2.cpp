#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
  int come;
  int time;
}Node;

bool cmp(node a,node b)
{
  return a.come<b.come;
}
int main()
{
  int n,m;
  cin>>n>>m;
  vector<node> vec;
  for(int i=0;i<n;i++)
  {
    int hh,mm,ss,tt;
    scanf("%d:%d:%d %d",&hh,&mm,&ss,&tt);
    int tmp=((hh*60)+mm)*60+ss;
    if(tmp<61200)
    {
      Node.come=tmp;
      Node.time=tt*60;
      vec.push_back(Node);
    }
  }
  sort(vec.begin(),vec.end(),cmp);
  double wait=0;
  vector<int> window(m,28800);
  for(int i=0;i<vec.size();i++)
  {
    int tmp=0,tmptime=window[0];
    for(int j=1;j<m;j++)
    {
      if(tmptime>window[j])
      {
        tmp=j;
        tmptime=window[j];
      }
    }
    if(vec[i].come<window[tmp])
    {
      wait+=(window[tmp]-vec[i].come);
      window[tmp]+=vec[i].time;
    }
    else
      window[tmp]=vec[i].come+vec[i].time;
  }
  if(vec.size()==0)
    cout<<"0.0"<<endl;
  else
    printf("%.1f\n",wait/60/vec.size());
}
