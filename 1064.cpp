#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int friend_Num(string s)
{
  int sum=0;
  for(int i=0;i<s.size();i++)
  {
    sum+=(s[i]-'0');
  }
  return sum;
}


int main()
{
    set<int> res;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      string s;
      cin>>s;
      int tmp=friend_Num(s);
      res.insert(tmp);
    }
    cout<<res.size()<<endl;
    for(auto iter=res.begin();iter!=res.end();iter++)
    {
      if(iter==res.begin())
        cout<<*iter;
      else
        cout<<' '<<*iter;
    }
    cout<<endl;
    return 0;
}
