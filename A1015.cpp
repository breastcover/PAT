#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int transfrom_radix(int n,int radix)
{
  string s;
  int res=0;
  while(n)
  {
    int tmp=n%radix;
    s+=to_string(tmp);
    n/=radix;
  }
  for(int i=0;i<s.size();i++)
  {
    res=res*radix+(s[i]-'0');
  }
  return res;
}

bool isPrime(int n)
{
  if(n==1)
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
  int n,d;
  while(1)
  {
    cin>>n;
    if(n<0)
      break;
    cin>>d;
    int res=transfrom_radix(n,d);
    //cout<<"res="<<res<<endl;
    if(isPrime(res)&&isPrime(n))
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
  return 0;
}
