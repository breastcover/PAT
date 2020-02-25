#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin>>s;
  int n1=(s.size()+2)/3;
  int n3=s.size()-2*n1+2;
  for(int i=0;i<n1-1;i++)
  {
    for(int j=0;j<n3;j++)
    {
      if(j==0)
        cout<<s[i];
      else if(j==n3-1)
        cout<<s[s.size()-1-i];
      else
        cout<<' ';
    }
    cout<<endl;
  }
  for(int i=0;i<n3;i++)
  {
    cout<<s[i+n1-1];
  }
  return 0;
}
