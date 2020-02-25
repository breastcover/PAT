#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int a,b;
  cin>>a>>b;
  string s=to_string(a+b);
  reverse(s.begin(),s.end());
  for(int i=3;i<s.size();i+=4)
  {
    if(s[i]!='-')
    s.insert(i,",");
    cout<<s<<endl;
    
  }
  reverse(s.begin(),s.end());
  cout<<s<<endl;
  return 0;
}
