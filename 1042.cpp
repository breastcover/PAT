#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;


int main()
{
  map<char,int> m;
  string s;
  getline(cin,s);
  transform(s.begin(),s.end(),s.begin(),::tolower);
  for(int i=0;i<s.size();i++)
  {
    if(isalpha(s[i]))
    m[s[i]]++;
  }


  int max=0;
  map<char,int>::iterator iter;
  for(auto i=m.begin();i!=m.end();i++)
  {
    if(i->second>max)
    {
      max=i->second;
      iter=i;
    }
  }
  cout<<iter->first<<' '<<iter->second<<endl;
  return 0;
}
