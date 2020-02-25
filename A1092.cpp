#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string s1,s2;
  cin>>s1>>s2;
  for(int i=0;i<s2.size();)
  {
    int flag=0;
    for(int j=0;j<s1.size();)
    {
      if(s2[i]==s1[j])
      {
        s2.erase(s2.begin()+i,s2.begin()+i+1);
        s1.erase(s1.begin()+j,s1.begin()+j+1);
        flag=1;
        j=0;
      }
      else
        j++;
    }
    if(flag==0)
      i++;
  }
  if(s2.size()==0)
    cout<<"Yes"<<' '<<s1.size()<<endl;
  else
    cout<<"No"<<' '<<s2.size()<<endl;
  return 0;
}
