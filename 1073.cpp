#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

struct xzt
{
  int xzt_score;
  int xzt_max_opt;
  int xzt_right_opt;
  string answer;
};


int main()
{
  int n,m;
  cin>>n>>m;
  vector<xzt> vec(m);
  for(int i=0;i<m;i++)
  {
    cin>>vec[i].xzt_score>>vec[i].xzt_max_opt>>vec[i].xzt_right_opt;
    for(int j=0;j<vec[i].xzt_right_opt;j++)
    {
      char tmp;
      cin>>tmp;
      vec[i].answer+=tmp;
    }

  }

  int max_wrong_opt[1001][5]={0};
  int maxx=0;
  double score[n];
  for(int i=0;i<n;i++)
    score[i]=0;
  getchar();
  for(int i=0;i<n;i++)
  {
    string s;
    getline(cin,s);
    int times=-1;
    string one;
    int length;
    for(int j=0;j<s.size();j++)
    {
      if(isdigit(s[j]))
      {
        length=s[j]-'0';
        times++;
        one="";
      }
      else if(isalpha(s[j]))
        one+=s[j];
      if(s[j]==')'&&vec[times].answer==one)
      {
        score[i]+=vec[times].xzt_score;
      }
      else if(s[j]==')'&&length<vec[times].answer.size())
      {
        int flag=0;
        for(int k=0;k<length;k++)
        {
          if(vec[times].answer.find(one[k])==-1)
          {
            max_wrong_opt[times][one[k]-'a']++;
            if(max_wrong_opt[times][one[k]-'a']>maxx)
              maxx=max_wrong_opt[times][one[k]-'a'];
            flag=1;
          }

        }
        for(int p=0;p<vec[times].answer.size();p++)
        {
          if(one.find(vec[times].answer[p])==-1)
          {
            max_wrong_opt[times][vec[times].answer[p]-'a']++;
            if(max_wrong_opt[times][vec[times].answer[p]-'a']>maxx)
              maxx=max_wrong_opt[times][vec[times].answer[p]-'a'];
          }
        }
        if(!flag)
        score[i]+=((double)vec[times].xzt_score/2);

      }
      else if(s[j]==')'&&length>=vec[times].answer.size())
      {
        for(int k=0;k<length;k++)
        {
          if(vec[times].answer.find(one[k])==-1)
          {
            max_wrong_opt[times][one[k]-'a']++;
            if(max_wrong_opt[times][one[k]-'a']>maxx)
              maxx=max_wrong_opt[times][one[k]-'a'];
          }
        }
        for(int p=0;p<vec[times].answer.size();p++)
        {
          if(one.find(vec[times].answer[p])==-1)
          {
            max_wrong_opt[times][vec[times].answer[p]-'a']++;
            if(max_wrong_opt[times][vec[times].answer[p]-'a']>maxx)
              maxx=max_wrong_opt[times][vec[times].answer[p]-'a'];
          }
        }
      }
    }

  }
  for(int i=0;i<n;i++)
    printf("%.1f\n",score[i]);
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<5;j++)
    {
      //cout<<max_wrong_opt[i][j]<<' ';
      if(max_wrong_opt[i][j]==maxx&&maxx!=0)
        printf("%d %d-%c\n",maxx,i+1,j+'a');
    }

  }
  if(maxx==0)
    cout<<"Too simple"<<endl;
  return 0;
}
