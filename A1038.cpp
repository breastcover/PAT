#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a,string b)
{
  return a+b<b+a;
}
int main()
{
  int n;
  cin>>n;
  vector<string> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i];
  }
  sort(vec.begin(),vec.end(),cmp);
  string res;
  for(auto s:vec)
    res+=s;
  while(res[0]=='0'&&res.size()>1)
    res.erase(res.begin(),res.begin()+1);
  cout<<res<<endl;
  return 0;
}
