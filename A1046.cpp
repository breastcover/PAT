#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> vec(n+1);
  vec[0]=0;
  for(int i=1;i<=n;i++)
    cin>>vec[i];
  int m;
  cin>>m;
  int min=1e8;
  int dis=0;
  for(int i=0;i<m;i++)
  {
    int st,ed;
    cin>>st>>ed;
    if(st>ed)
      swap(st,ed);
    //cout<<"CASE 1:"<<endl;
    for(int i=st;i<ed;i++)
    {
      dis+=vec[i];
      //cout<<dis<<endl;
    }
    if(dis<min)
    {
      min=dis;
      dis=0;
    }
    //cout<<"CASE 2:"<<endl;
    for(int i=ed;;i++)
    {
      dis+=vec[i%(n+1)];
      if(i%n==st)
        break;
      //cout<<dis<<endl;
    }
    if(min>dis)
    {
      min=dis;
    }
    cout<<min<<endl;
    min=1e8;
    dis=0;
  }
  return 0;
}
