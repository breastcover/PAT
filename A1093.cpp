#include <iostream>
#include <vector>
using namespace std;

int main()
{
  string s;
  cin>>s;
  vector<int> vec(s.size(),0);
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='P')
      vec[i]=vec[i-1]+1;
    else if(i>0)
      vec[i]=vec[i-1];
  }
  int ans=0;
  int rightNum=0;
  for(int i=s.size()-1;i>=0;i--)
  {
    if(s[i]=='T')
      rightNum++;
    else if(s[i]=='A')
      ans=(rightNum*vec[i]+ans)%1000000007;
  }
  cout<<ans<<endl;
  return 0;
}
