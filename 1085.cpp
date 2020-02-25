#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

struct node
{
  string school_name;
  int score;
  int student_num;
};

bool cmp(node &n1,node &n2)
{
  if(n1.score!=n2.score)
  {
    //return n1.student_num<n2.student_num;
    return n1.score>n2.score;
  }
  else if(n1.student_num!=n2.student_num)
  {
    //return n1.school_name<n2.school_name;
    return n1.student_num<n2.student_num;
  }
  else
    return n1.school_name<n2.school_name;
}


int main()
{
  int n;
  cin>>n;
  string candidate_num;
  double score;
  string school="";
  map<string,double> m;
  map<string,int> mmp;
  for(int i=0;i<n;i++)
  {
    cin>>candidate_num>>score>>school;
    transform(school.begin(),school.end(),school.begin(),::tolower);
    mmp[school]++;
    if(candidate_num[0]=='B')
    {
      m[school]+=(score/1.5);
    }
    else if(candidate_num[0]=='A')
    {
      m[school]+=score;
    }
    else
    {
      m[school]+=(score*1.5);
    }
  }
  vector<node> vec;

  for(auto iter=m.begin();iter!=m.end();iter++)
  {
    node tmp;
    tmp.school_name=iter->first;
    tmp.score=(int)iter->second;
    tmp.student_num=mmp[iter->first];
    vec.push_back(tmp);
  }

  sort(vec.begin(),vec.end(),cmp);
  cout<<vec.size()<<endl;
  int plac=0;
  int zf=0;
  for(int i=0;i<vec.size();i++)
  {
    if(zf!=vec[i].score)
    {
      zf=vec[i].score;
      plac=i+1;
    }
    cout<<plac<<' ';
    cout<<vec[i].school_name<<' ';
    cout<<vec[i].score<<' ';
    cout<<vec[i].student_num<<endl;
  }
  return 0;
}
