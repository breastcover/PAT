#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
  int ge;
  int gi;
  int id;
  double final_score;
  int rank;
  vector<int> choices;
};

struct school
{
  int quota;
  vector<int> admisson;
  int last_one_rank;
};

bool cmp(student s1,student s2)
{
  if(s1.final_score==s2.final_score)
    return s1.ge>s2.ge;
  return s1.final_score>s2.final_score;
}

int main()
{
  int n,m,k;
  cin>>n>>m>>k;
  vector<school> sch(m);
  vector<student> stu(n);
  for(int i=0;i<m;i++)
  {
    cin>>sch[i].quota;
  }
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>stu[i].ge>>stu[i].gi;
    for(int j=0;j<k;j++)
    {
      cin>>tmp;
      stu[i].choices.push_back(tmp);
    }
    stu[i].final_score=(double)(stu[i].ge+stu[i].gi)/2;
    stu[i].id=i;
  }
  sort(stu.begin(),stu.end(),cmp);
  int score=-1;
  for(int i=0;i<n;i++)
  {
    if(stu[i].final_score!=score)
    {
      stu[i].rank=i+1;
      score=stu[i].final_score;
    }else
    {
      if(stu[i].ge==stu[i-1].ge)
        stu[i].rank=stu[i-1].rank;
      else
        stu[i].rank=i+1;
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<k;j++)
    {
      int id=stu[i].choices[j];
      if(sch[id].quota>0)
      {
        sch[id].admisson.push_back(stu[i].id);
        sch[id].quota--;
        sch[id].last_one_rank=stu[i].rank;
        break;
      }else if(sch[id].quota==0&&stu[i].rank==sch[id].last_one_rank)
      {
        sch[id].admisson.push_back(stu[i].id);
        break;
      }
    }
  }
  for(int i=0;i<m;i++)
  {
    sort(sch[i].admisson.begin(),sch[i].admisson.end());
    for(int j=0;j<sch[i].admisson.size();j++)
    {
      cout<<sch[i].admisson[j];
      if(j<sch[i].admisson.size()-1)
        cout<<' ';
    }
    cout<<endl;
  }
  return 0;
}
