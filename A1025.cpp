#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct student
{
  string registration_num="";
  int score=0;
  int location_num=0;
  int location_rank=0;
};

bool cmp(student a,student b)
{
  if(a.score==b.score)
  return a.registration_num<b.registration_num;
  return a.score>b.score;
}


int main()
{
  int n,m;
  cin>>n;
  int sum=0;
  vector<student> vec;
  for(int i=1;i<=n;i++)
  {
    cin>>m;
    for(int j=0;j<m;j++)
    {
      student s;
      cin>>s.registration_num>>s.score;
      vec.push_back(s);
    }
    sort(vec.begin()+sum,vec.begin()+sum+m,cmp);
    int tmp=-1;
    int rank;
    for(int k=sum;k<sum+m;k++)
    {
      vec[k].location_num=i;
      if(tmp!=vec[k].score)
      {
        vec[k].location_rank=k-sum+1;
        tmp=vec[k].score;
        rank=k-sum+1;
      }
      else
        vec[k].location_rank=rank;
    }
    sum+=m;
  }
  sort(vec.begin(),vec.end(),cmp);
  cout<<sum<<endl;
  int tmp=-1;
  int rank;
  for(int i=0;i<sum;i++)
  {
    cout<<vec[i].registration_num;
    if(tmp!=vec[i].score)
    {
      tmp=vec[i].score;
      rank=i+1;
    }
    cout<<" "<<rank<<" "<<vec[i].location_num<<" "<<vec[i].location_rank<<endl;
  }
  return 0;
}
