#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct _user
{
  int id;
  int _perfect;
  bool p[6];
  int  _problem[6];
  int total;
  bool submisson[6];
  bool isshown;
};

bool cmp(_user u1,_user u2)
{
  if(u1.total==u2.total)
  {
    if(u1._perfect==u2._perfect)
      return u1.id<u2.id;
    return u1._perfect>u2._perfect;
  }
  return u1.total>u2.total;
}

int main()
{
  int n,k,m;
  cin>>n>>k>>m;
  int problem_score[k+1];
  for(int i=1;i<=k;i++)
  {
    cin>>problem_score[i];
  }
  vector<_user> vec(n+1);
  for(int i=0;i<m;i++)
  {
    int id,p,score;
    cin>>id>>p>>score;
    vec[id].id=id;
    vec[id].submisson[p]=true;
    if(score>=0)
      vec[id].isshown=true;
    if(score>vec[id]._problem[p])
    {
      vec[id].total+=(score-vec[id]._problem[p]);
      vec[id]._problem[p]=score;
    }
    if(score==problem_score[p])
      vec[id].p[p]=true;
    int _perfect=0;
    for(int i=1;i<=k;i++)
    {
      if(vec[id].p[i]==true)
        _perfect++;
    }
    vec[id]._perfect=_perfect;
  }

  vector<_user> res;
  for(int i=1;i<=n;i++)
  {
    if(vec[i].total>=0&&vec[i].isshown==true)
      res.push_back(vec[i]);
  }
  // for(auto e:res)
  // {
  //   cout<<e.id<<' '<<e.total<<endl;
  // }
  sort(res.begin(),res.end(),cmp);
  int ss=0;
  int rank=1;
  for(int i=0;i<res.size();i++)
  {
    if(ss==res[i].total)
    {
      cout<<rank<<' ';
    }else
    {
       cout<<i+1<<' ';
       rank=i+1;
       ss=res[i].total;
     }
    printf("%05d %d",res[i].id,res[i].total);
    for(int j=1;j<=k;j++)
    {
      int tmp=res[i]._problem[j];
      //cout<<tmp<<endl;
      if(res[i].submisson[j])
      {
        cout<<' '<<tmp;
      }
      else
        cout<<" -";
    }
     cout<<endl;
  }
  return 0;
}
