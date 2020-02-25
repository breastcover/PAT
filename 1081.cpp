#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string check_password(string s)
{
  int alpha_num=0;
  int digit_num=0;
  if(s.size()<6)
    return "Your password is tai duan le.";
  for(int i=0;i<s.size();i++)
  {
    if(!isalpha(s[i])&&!isdigit(s[i])&&s[i]!='.')
    {
      return "Your password is tai luan le.";
    }
    if(isdigit(s[i]))
      digit_num++;
    else if(isalpha(s[i]))
      alpha_num++;
  }
  if(!alpha_num&&digit_num)
    return "Your password needs zi mu.";
  else if(alpha_num&&!digit_num)
    return "Your password needs shu zi.";
  else if(alpha_num&&digit_num)
    return "Your password is wan mei.";
  return "-1";
}

int main()
{
  int n;
  cin>>n;
  getchar();
  for(int i=0;i<n;i++)
  {
    string s;
    getline(cin,s);
    cout<<check_password(s)<<endl;
  }
  return 0;
}
