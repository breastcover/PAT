#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

struct student
{
  string name;
  int online_work=-1;
  int mid_term=-1;
  int final_score=-1;
  int g_score;
};

bool cmp(student a,student b)
{
  if(a.g_score!=b.g_score)
  return a.g_score>b.g_score;
  else
  return a.name<b.name;
}

int main()
{
  int p,m,n;
  cin>>p>>m>>n;
  map<string,student> mp;
  for(int i=0;i<p;i++)
  {
    string name;
    int score;
    cin>>name>>score;
    mp[name].online_work=score;
  }
  for(int i=0;i<m;i++)
  {
    string name;
    int score;
    cin>>name>>score;
    mp[name].mid_term=score;
  }
  for(int i=0;i<n;i++)
  {
    string name;
    int score;
    cin>>name>>score;
    mp[name].final_score=score;
  }
  vector<student> vec;
  for(auto iter=mp.begin();iter!=mp.end();iter++)
  {
    if(iter->second.online_work>=200)
    {
      int mid_score=iter->second.mid_term;
      int final_score=iter->second.final_score;
      int g_score;
      if(mid_score>final_score)
        g_score=round((double)mid_score*0.4+(double)final_score*0.6);
      else
        g_score=final_score;
      if(g_score>=60)
      {
        student good;
        good.name=iter->first;
        good.online_work=iter->second.online_work;
        good.mid_term=mid_score;
        good.final_score=final_score;
        good.g_score=g_score;
        vec.push_back(good);
      }
    }
  }
  sort(vec.begin(),vec.end(),cmp);
  for(int i=0;i<vec.size();i++)
  printf("%s %d %d %d %d\n",(vec[i].name).c_str(),vec[i].online_work,vec[i].mid_term,vec[i].final_score,vec[i].g_score );
  return 0;
}
