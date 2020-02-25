#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> _transbase(int n,int b)
{
  vector<string> res;
  while(n)
  {
    int tmp=n%b;
    res.push_back(to_string(tmp));
    n/=b;
  }
  return res;
}

int main()
{
  int n,b;
  cin>>n>>b;
  vector<string> s=_transbase(n,b);
  vector<string> rs=s;
  reverse(rs.begin(),rs.end());
  
  if(rs==s)
  {
    cout<<"Yes"<<endl;
  }
  else
    cout<<"No"<<endl;
  for(int i=0;i<rs.size();i++)
  {
    if(i==0)
      cout<<rs[i];
    else
      cout<<' '<<rs[i];
  }
  cout<<endl;

  return 0;
}
