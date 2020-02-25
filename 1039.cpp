#include <iostream>
#include <string>
#include <string.h>
using namespace std;


int main()
{
  string s1;
  string s2;
  cin>>s1>>s2;
  for(int i=0;i<s1.size();)
  {
    int flag=0;
    for(int j=0;j<s2.size();)
    {
      if(s2[j]==s1[i])
      {
        flag=1;
        //cout<<s1<<" "<<s2<<endl;
        s1.erase(s1.begin()+i);
        s2.erase(s2.begin()+j);
        break;
      }
      else{
        j++;
      }
    }
    if(flag==0)
      i++;
  }
  //cout<<s1.size()<<' '<<s2.size()<<endl;
  if(s1.size()==0&&s2.size()==0)
    cout<<"Yes"<<" "<<"0"<<endl;
  else if(s1.size()!=0&&s2.size()!=0)
    cout<<"No"<<" "<<to_string(s2.size())<<endl;
  else if(s2.size()==0)
    cout<<"Yes"<<" "<<to_string(s1.size())<<endl;
  return 0;
}
