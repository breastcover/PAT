#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
  int np,ng;
  cin>>np>>ng;
  vector<int> vec(np);
  vector<int> res(np);
  deque<int> q;
  for(int i=0;i<np;i++)
  {
    cin>>vec[i];
  }
  for(int i=0;i<np;i++)
  {
    int tmp;
    cin>>tmp;
    q.push_back(tmp);
  }

  int n=np,group;
  while(q.size()!=1)
  {
    if(n%ng==0)
      group=n/ng;
    else
      group=n/ng+1;
    for(int i=0;i<group;i++)
    {
      int _max=-1,candidate=0;
      for(int j=0;j<ng;j++)
      {
        if(i*ng+j>=n) break;
        int tmp=q.front();
        if(vec[tmp]>_max)
        {
          _max=vec[tmp];
          candidate=tmp;
        }
        res[tmp]=group+1;
        q.pop_front();
      }
      q.push_back(candidate);
    }
    n=group;
  }
  res[q.front()]=1;
  for(int i=0;i<res.size();i++)
  {
    if(i==0)
      cout<<res[i];
    else
      cout<<' '<<res[i];
  }
  return 0;
}
