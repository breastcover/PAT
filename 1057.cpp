#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  string s;
  getline(cin,s);
  transform(s.begin(),s.end(),s.begin(),::tolower);
  int sum=0;
  //cout<<s<<endl;
  for(int i=0;i<s.size();i++)
  {
    if(isalpha(s[i]))
    {
      //cout<<s[i]<<endl;
      sum=sum+(s[i]-'a')+1;
    }
  }
  int num0=0,num1=0;
  while(sum!=0)
  {
    if(sum%2)
    {
      num1++;
    }
    else
    {
      num0++;
    }
    //cout<<sum<<endl;
    sum/=2;
  }
  cout<<num0<<' '<<num1<<endl;
  return 0;
}
