#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int prime[300];

bool isPrime(int n)
{
  for(int i=2;i<=sqrt(n);i++)
  {
    if(n%i==0)
      return false;
  }
  return true;
}

void Find_Prime()
{

  int num=0;
  int p=2;

  while(num<300)
  {
    if(isPrime(p)==true)
    {
      prime[num++]=p++;
    }
    else
      p++;
  }
}

struct fac
{
  int x;
  int count;
  fac()
  {
    x=0;
    count=0;
  }
};

int main()
{
  Find_Prime();
  // for(auto e:prime)
  // {
  //   cout<<e<<endl;
  // }
  long long n;

  cin>>n;
  if(n==1)
  {
    cout<<"1=1"<<endl;
    return 0;
  }
  long long res=n;
  vector<fac> vec;
  for(int i=0;i<300&&n!=1;i++)
  {
    if(n%prime[i]==0)
    {
      fac f;
      f.x=prime[i];
      while(n%prime[i]==0)
      {
        f.count++;
        n/=prime[i];
      }
      vec.push_back(f);
    }
  }
  if(n!=1)
  {
    fac f;
    f.x=n;
    f.count=1;
    vec.push_back(f);
  }
  cout<<res<<'=';
  for(int i=0;i<vec.size();i++)
  {

    if(i==0)
    {
      if(vec[i].count>1)
        cout<<vec[i].x<<'^'<<vec[i].count;
      else
        cout<<vec[i].x;
    }else
    {
      if(vec[i].count>1)
        cout<<'*'<<vec[i].x<<'^'<<vec[i].count;
      else
        cout<<'*'<<vec[i].x;
    }
  }
  return 0;
}
