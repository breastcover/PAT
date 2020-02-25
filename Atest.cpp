#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getid(string s)
{
  if(s[0]=='G')
  {
    string p=s.substr(1,s.size()-1);
    return stoi(p);
  }
  else
  {
    int k=stoi(s);
    return k;
  }
}

int main()
{
  string s;
  cin>>s;
  cout<<getid(s)<<endl;
  return 0;
}
