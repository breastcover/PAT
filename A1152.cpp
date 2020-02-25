#include <iostream>
#include <vector>
#include <math.h>
#include <string>
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
  int l,k;
  cin>>l>>k;
  string s;
  cin>>s;
  string res;
  int flag=0;
  for(int i=0;i<s.size()-k+1;i++)
  {
    res=s.substr(i,k);
    //cout<<res<<endl;
    int tmp=stoi(res);
    if(isPrime(tmp))
    {
      flag=1;
      break;
    }

  }
  if(flag)
  cout<<res<<endl;
  else
  cout<<404<<endl;
  return 0;
}
