#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Student
{
  string name;
  string subject;
  int score;
}student;

bool cmp_f(Student s1,Student s2)
{
  return s1.score>s2.score;
}

bool cmp_m(Student s1,Student s2)
{
  return s1.score<s2.score;
}

int main()
{
  int n;
  cin>>n;
  vector<Student> male;
  vector<Student> female;
  for(int i=0;i<n;i++)
  {
    Student s;
    char c;
    cin>>s.name>>c>>s.subject>>s.score;
    if(c=='M')
      male.push_back(s);
    else
      female.push_back(s);
  }
  sort(male.begin(),male.end(),cmp_m);
  sort(female.begin(),female.end(),cmp_f);
  if(female.size()==0)
    cout<<"Absent"<<endl;
  else
    cout<<female[0].name<<' '<<female[0].subject<<endl;
  if(male.size()==0)
    cout<<"Absent"<<endl;
  else
    cout<<male[0].name<<' '<<male[0].subject<<endl;
  if(female.size()!=0&&male.size()!=0)
    cout<<abs(male[0].score-female[0].score)<<endl;
  else
    cout<<"NA"<<endl;
  return 0;
}
