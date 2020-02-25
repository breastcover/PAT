#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int digit_sum(int n)
{
  int sum=0;
  while(n)
  {
    sum+=(n%10);
    n/=10;
  }
  return sum;
}

int main()
{
  int n;
  cin>>n;
  set<int> s;
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    s.insert(digit_sum(tmp));
  }
  cout<<s.size()<<endl;
  for(auto iter=s.begin();iter!=s.end();iter++)
  {
    if(iter==s.begin())
      cout<<*iter;
    else
      cout<<' '<<*iter;
  }
  return 0;
}
