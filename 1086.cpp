#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
  string res;
  int a,b;
  cin>>a>>b;
  res=to_string(a*b);

  reverse(res.begin(),res.end());
  while(res[0]=='0'&&res.size()>1)
  res.erase(res.begin(),res.begin()+1);
  cout<<res<<endl;
  return 0;
}
