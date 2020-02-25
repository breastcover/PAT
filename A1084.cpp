#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string s1,s2;
  cin>>s1>>s2;
  transform(s1.begin(),s1.end(),s1.begin(),::toupper);
  transform(s2.begin(),s2.end(),s2.begin(),::toupper);
  string res;
  for(int i=0;i<s1.size();i++)
  {
    if(s2.find(s1[i])==-1&&res.find(s1[i])==-1)
      res+=s1[i];
  }
  cout<<res<<endl;
  return 0;
}
