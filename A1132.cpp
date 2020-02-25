#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    string s1=s.substr(0,s.size()/2);
    string s2=s.substr(s.size()/2,s.size());
    if(stoi(s1)==0||stoi(s2)==0)
    {
      cout<<"No"<<endl;
      continue;
    }
    if(stoi(s)%(stoi(s1)*stoi(s2))==0)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
  return 0;
}
