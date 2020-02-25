#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct student
{
  string id;
  int c;
  int m;
  int e;
  int a;
  int best_rank;
  char best_project;
  student()
  {
    best_rank=1e8;
  }
};

bool cmp_c(student a,student b)
{
  return a.c>b.c;
}
bool cmp_m(student a,student b)
{
  return a.m>b.m;
}
bool cmp_e(student a,student b)
{
  return a.e>b.e;
}
bool cmp_a(student a,student b)
{
  return a.a>b.a;
}


int main()
{
  int n,m;
  cin>>n>>m;
  vector<student> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i].id>>vec[i].c>>vec[i].m>>vec[i].e;
    vec[i].a=round((vec[i].e+vec[i].c+vec[i].m)/3);
  }
  sort(vec.begin(),vec.end(),cmp_a);
  int t=0;
  int rank=1;
  for(int i=0;i<vec.size();i++)
  {
    if(vec[i].a==t)
    {
      if(rank<vec[i].best_rank)
      {
        vec[i].best_rank=rank;
        vec[i].best_project='A';
      }
    }else
    {
      rank=i+1;
      if(rank<vec[i].best_rank)
      {
        vec[i].best_rank=rank;
        vec[i].best_project='A';
      }
      t=vec[i].a;
    }
  }
  sort(vec.begin(),vec.end(),cmp_c);
  t=0;
  rank=1;
  for(int i=0;i<vec.size();i++)
  {
    if(vec[i].c==t)
    {
      if(rank<vec[i].best_rank)
      {
        vec[i].best_rank=rank;
        vec[i].best_project='C';
      }
    }else
    {
      rank=i+1;
      if(rank<vec[i].best_rank)
      {
        vec[i].best_rank=rank;
        vec[i].best_project='C';
      }

      t=vec[i].c;
    }
  }
  sort(vec.begin(),vec.end(),cmp_m);
  t=0;
  rank=1;
  for(int i=0;i<vec.size();i++)
  {
    if(vec[i].m==t)
    {
      if(rank<vec[i].best_rank)
      {
        vec[i].best_rank=rank;
        vec[i].best_project='M';
      }
    }else
    {
      rank=i+1;
      if(rank<vec[i].best_rank)
      {
        vec[i].best_rank=rank;
        vec[i].best_project='M';
      }

      t=vec[i].m;
    }
  }
  // for(auto e:vec)
  // {
  //   cout<<e.id<<' '<<e.best_rank<<' '<<e.best_project<<endl;
  // }
  sort(vec.begin(),vec.end(),cmp_e);
  t=0;
  rank=1;
  for(int i=0;i<vec.size();i++)
  {
    if(vec[i].e==t)
    {
      if(rank<vec[i].best_rank)
      {
        vec[i].best_rank=rank;
        vec[i].best_project='E';
      }
    }else
    {
      rank=i+1;
      if(rank<vec[i].best_rank)
      {
        vec[i].best_rank=rank;
        vec[i].best_project='E';
      }

      t=vec[i].e;
    }
  }
  string s;

  for(int i=0;i<m;i++)
  {
    int flag=0;
    cin>>s;
    for(int j=0;j<vec.size();j++)
    {
      if(vec[j].id==s)
      {
        flag=1;
        cout<<vec[j].best_rank<<' '<<vec[j].best_project<<endl;
      }
    }
    if(flag==0)
      cout<<"N/A"<<endl;
  }

  return 0;
}
