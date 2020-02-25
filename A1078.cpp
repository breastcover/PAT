#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

bool isPrime(int n)
{
  if(n<=1)
    return false;
  for(int i=2;i<=sqrt(n);i++)
  {
    if(n%i==0)
      return false;
  }
  return true;
}

int main()
{
  int m,n;
  cin>>m>>n;
  while(!isPrime(m))
    m++;
  vector<int> vec(10010,-1);
  vector<int> res(10010,-1);
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    int k=tmp%m;
    if(vec[k]==-1)
    {
      vec[k]=tmp;
      res[i]=k;
    }
    else
    {
      for(int step=1;step<m;step++)
      {
        int index=(tmp+step*step)%m;
        if(vec[index]==-1)
        {
          vec[index]=tmp+step*step;
          res[i]=index;
          break;
        }
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    if(i==0)
    {
      if(res[i]!=-1)
        cout<<res[i];
      else
        cout<<'-';
    }
    else
    {
      if(res[i]!=-1)
        cout<<' '<<res[i];
      else
        cout<<' '<<'-';
    }
  }
  return 0;
}
