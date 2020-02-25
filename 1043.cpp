#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
  string s;
  getline(cin,s);
  map<char,int> m;
  string str="PATest";
  for(int i=0;i<s.size();i++)
  {
    if(str.find(s[i])!=-1)
    {
      m[s[i]]++;
    }
  }
  while(1)
  {
    if(m['P']==0&&m['A']==0&&m['T']==0&&m['e']==0&&m['s']==0&&m['t']==0)
      break;
    if(m['P']>0)
    {
      cout<<'P';
      m['P']--;
    }
    if(m['A']>0)
    {
      cout<<'A';
      m['A']--;
    }
    if(m['T']>0)
    {
      cout<<'T';
      m['T']--;
    }
    if(m['e']>0)
    {
      cout<<'e';
      m['e']--;
    }
    if(m['s']>0)
    {
      cout<<'s';
      m['s']--;
    }
    if(m['t']>0)
    {
      cout<<'t';
      m['t']--;
    }

  }
  cout<<endl;
  return 0;
}
