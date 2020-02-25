#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
  string id;
  string name;
  int grade;
}student;

bool cmp_id(Student s1,Student s2)
{
  return s1.id<s2.id;
}

bool cmp_name(Student s1,Student s2)
{
  if(s1.name==s2.name)
    return s1.id<s2.id;
  return s1.name<s2.name;
}

bool cmp_grade(Student s1,Student s2)
{
  if(s1.grade==s2.grade)
    return s1.id<s2.id;
  return s1.grade<s2.grade;
}

int main()
{
  int n,c;
  cin>>n>>c;
  vector<Student> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i].id>>vec[i].name>>vec[i].grade;
  }
  if(c==1)
    sort(vec.begin(),vec.end(),cmp_id);
  else if(c==2)
    sort(vec.begin(),vec.end(),cmp_name);
  else
    sort(vec.begin(),vec.end(),cmp_grade);
  for(auto e:vec)
    cout<<e.id<<' '<<e.name<<' '<<e.grade<<endl;
  return 0;
}
