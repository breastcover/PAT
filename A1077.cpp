#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<string> vec;
  string s1;
  string s2;
  getchar();
  getline(cin,s1);
  getline(cin,s2);
  string res;
  for(int i=s1.size()-1,j=s2.size()-1;i>=0&&j>=0;i--,j--)
  {
    if(s1[i]!=s2[j])
      break;
    res=s1[i]+res;
  }
  //cout<<res<<endl;
  for(int i=2;i<n;i++)
  {
    string s;
    getline(cin,s);

    if(s.find(res)!=-1)
      continue;
    else
    {
      while(s.find(res)==string::npos)
        res.erase(res.begin());
    }

    if(res.size()==0)
    {
      cout<<"nai"<<endl;
      break;
    }
  }
  if(res.size()!=0)
    cout<<res<<endl;

  return 0;
}
