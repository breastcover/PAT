#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
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
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  for(int i=0;i<=n-k;i++)
  {
    string tmp=s.substr(i,k);
    //cout<<tmp<<endl;
    if(isPrime(stoi(tmp)))
    {
        
        cout<<tmp<<endl;
        return 0;
    }
  }
  cout<<"404"<<endl;
  return 0;
}
