#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
using namespace std;

bool isPrime(int n)
{
  if(n<2)
    return false;
  for(int i=2;i<=sqrt(n);i++)
  {
    if(n%i==0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int n;
  cin>>n;
  bool check[n];
  for(int i=0;i<=n;i++)
  {
    check[i]=false;
  }
  map<string,int> m;
  for(int i=1;i<=n;i++)
  {
    string s;
    cin>>s;
    m[s]=i;
  }
  int t;
  cin>>t;
  vector<string> tmp;

  for(int i=0;i<t;i++)
  {
    string s;
    cin>>s;
    tmp.push_back(s);
  }
  for(int i=0;i<t;i++)
  {
    string s=tmp[i];
    map<string,int>::iterator iter=m.find(s);
    int rank;
    if(iter!=m.end())
      rank=iter->second;
    else
      rank=0;
    if(check[rank]==true&&rank!=0)
      cout<<s<<": Checked"<<endl;
    else
    {
      check[rank]=true;
      if(isPrime(rank))
      {
        cout<<s<<": Minion"<<endl;
      }
      else if(rank==1)
      {
        cout<<s<<": Mystery Award"<<endl;
      }
      else if(rank==0)
      {
        cout<<s<<": Are you kidding?"<<endl;
      }
      else
        cout<<s<<": Chocolate"<<endl;
    }
  }
  return 0;
}
