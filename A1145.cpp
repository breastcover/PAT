#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

bool isPrime(int n)
{
  for(int i=2;i<=sqrt(n);i++)
  {
    if(n%i==0)
      return false;
  }
  return true;
}

int main()
{
  int ms,n,m;
  cin>>ms>>n>>m;
  while(!isPrime(ms))
    ms++;
  vector<int> vec(ms,-1);
  vector<int> fail;
  for(int i=0;i<n;i++)
  {
    int j=0;
    int tmp;
    cin>>tmp;
    while(j<=ms)
    {
      int k=tmp+j*j;
      if(vec[k%ms]==-1)
      {
        vec[k%ms]=tmp;
        break;
      }
      else
      {
        j++;
      }
    }
    if(j==ms+1)
      fail.push_back(tmp);
  }
  int sum=0;
  for(int i=0;i<m;i++)
  {
    int tmp;
    cin>>tmp;
    int j=0;
    while(j<=ms)
    {
      sum++;
      int k=tmp+j*j;
      if(vec[k%ms]==tmp||vec[k%ms]==-1)
      {
        break;
      }
      else
      {
        j++;
      }
    }
  }
  for(auto e:fail)
    cout<<e<<" cannot be inserted."<<endl;
  printf("%.1f\n",(double)sum/m);
  return 0;
}
