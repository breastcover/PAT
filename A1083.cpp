#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct student
{
  string name;
  string id;
  int grade;
}St;

bool cmp(student s1,student s2)
{
  return s1.grade>s2.grade;
}

int main()
{
  int n;
  cin>>n;
  vector<student> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i].name>>vec[i].id>>vec[i].grade;
  }
  int l,h;
  cin>>l>>h;
  vector<student> res;
  sort(vec.begin(),vec.end(),cmp);
  for(int i=0;i<vec.size();i++)
  {
    if(vec[i].grade>h)
      continue;
    if(vec[i].grade>=l)
    {
      res.push_back(vec[i]);
    }
  }
  if(res.size()==0)
    cout<<"NONE"<<endl;
  for(auto e:res)
    cout<<e.name<<" "<<e.id<<endl;
  return 0;
}
