#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin>>s;
  int num_t=0;
  int num_at=0;
  int num_pat=0;
  for(int i=s.size()-1;i>=0;i--)
  {
    if(s[i]=='T')
      num_t++;
    else if(s[i]=='A')
      num_at=(num_at+num_t)%1000000007;
    else if(s[i]=='P')
      num_pat=(num_pat+num_at)%1000000007;
  }
  cout<<num_pat<<endl;
  return 0;
}
