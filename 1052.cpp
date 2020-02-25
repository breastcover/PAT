#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  string s;
  vector<vector<string>> vec(3);
  for(int i=0;i<3;i++)
  {
    getline(cin,s);
    //cout<<s<<endl;
    string tmp;
    for(int j=0;j<s.size();j++)
    {
        if(s[j]=='['||s[j]==' ')
        {
          continue;
        }
        if(s[j]==']')
        {
          vec[i].push_back(tmp);
          tmp="";
          continue;
        }
        else
          tmp+=s[j];

    }
  }

  int n;
  cin>>n;
  int a,b,c,d,e;
  while(n--)
  {
    cin>>a>>b>>c>>d>>e;
    if(a>vec[0].size()||e>vec[0].size()||b>vec[1].size()||d>vec[1].size()||c>vec[2].size()||a<=0||b<=0||c<=0||d<=0||e<=0)
      cout<<"Are you kidding me? @\\/@"<<endl;
    else
    {
      cout<<vec[0][a-1]<<"("<<vec[1][b-1]<<vec[2][c-1]<<vec[1][d-1]<<")"<<vec[0][e-1]<<endl;
    }
  }
  return 0;
}
