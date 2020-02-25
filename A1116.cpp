#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;

struct node
{
  int rank;
  bool checked;
  node()
  {
    rank=-1;
    checked=false;
  }
  ~node(){}
};

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
  int n;
  cin>>n;
  vector<node> vec(10000);
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    vec[tmp].rank=i+1;
    vec[tmp].checked=false;
  }
  int m;
  cin>>m;
  for(int i=0;i<m;i++)
  {
    int tmp;
    cin>>tmp;
    if(vec[tmp].rank==-1)
      cout<<setw(4)<<setfill('0')<<tmp<<": "<<"Are you kidding?"<<endl;
    else if(vec[tmp].checked==true)
    {
      cout<<setw(4)<<setfill('0')<<tmp<<": "<<"Checked"<<endl;
    }
    else if(vec[tmp].rank==1)
    {
      cout<<setw(4)<<setfill('0')<<tmp<<": "<<"Mystery Award"<<endl;
      vec[tmp].checked=true;
    }
    else if(isPrime(vec[tmp].rank))
    {
      cout<<setw(4)<<setfill('0')<<tmp<<": "<<"Minion"<<endl;
      vec[tmp].checked=true;
    }
    else
    {
      cout<<setw(4)<<setfill('0')<<tmp<<": "<<"Chocolate"<<endl;
      vec[tmp].checked=true;
    }
  }
  return 0;
}
