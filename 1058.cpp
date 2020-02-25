#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

struct xzt
{
  int score;
  int opt_num;
  int right_opt_num;
  char opt[10]="";
};

int main()
{
  int n,m;
  cin>>n>>m;
  vector<xzt> vec;
  for(int i=0;i<m;i++)
  {
    xzt x;
    cin>>x.score>>x.opt_num>>x.right_opt_num;
    for(int j=0;j<x.right_opt_num;j++)
      cin>>x.opt[j];
    vec.push_back(x);
  }
  vector<int> defen;
  int cwcs[1005]={0};
  int max=0;
  getchar();
  for(int i=0;i<n;i++)
  {
    int k;
    int p=0,times=0;
    char c[10]="";
    string s;
    getline(cin,s);
    int df=0;
    for(int j=0;j<s.size();j++)
    {
      if(isdigit(s[j]))
        k=s[j]-'0';
      else if(isalpha(s[j]))
        c[p++]=s[j];
      else if(s[j]==')')
      {
        sort(c,c+k);
        if(k==vec[times].right_opt_num&&strcmp(c,vec[times].opt)==0)
          df+=vec[times].score;
        else
        {
          cwcs[times]++;
          if(cwcs[times]>max)
            max=cwcs[times];
        }
        times=(times+1)%4;
        memset(c,'\0',10);
        p=0;
      }
    }
    defen.push_back(df);
    df=0;
  }
  for(int i=0;i<defen.size();i++)
    cout<<defen[i]<<endl;
  if(max==0)
    cout<<"Too simple"<<endl;
  else{
      cout<<max;
      for(int i=0;i<m;i++)
      {
        if(cwcs[i]==max)
          cout<<' '<<i+1;
      }
      cout<<endl;
    }
  return 0;
}
