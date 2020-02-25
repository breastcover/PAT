#include <iostream>
#include <vector>
#include <iostream>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

struct student
{
  string stu_id;
  double online_score;
  double mid_score;
  double final_score;
  int G;
  student()
  {
    online_score=-1;
    mid_score=-1;
    final_score=-1;
    G=-1;
  }
  ~student(){};
};

bool cmp(student s1,student s2)
{
  if(s1.G==s2.G)
    return s1.stu_id<s2.stu_id;
  return s1.G>s2.G;
}

int main()
{
  int p,m,n;
  cin>>p>>m>>n;
  map<string,student> s;
  vector<student> vec;
  for(int i=0;i<p;i++)
  {
    string id;
    cin>>id;
    s[id].stu_id=id;
    cin>>s[id].online_score;
  }
  for(int i=0;i<m;i++)
  {
    string id;
    cin>>id;
    cin>>s[id].mid_score;
  }
  for(int i=0;i<n;i++)
  {
    string id;
    cin>>id;
    cin>>s[id].final_score;
  }
  for(auto iter=s.begin();iter!=s.end();iter++)
  {
    if(iter->second.online_score>=200)
    {
      if(iter->second.mid_score>iter->second.final_score)
        iter->second.G=round(iter->second.mid_score*0.4+iter->second.final_score*0.6);
      else
        iter->second.G=iter->second.final_score;
      if(iter->second.G>=60)
        vec.push_back(iter->second);
    }
  }
  sort(vec.begin(),vec.end(),cmp);
  for(int i=0;i<vec.size();i++)
  {
    cout<<vec[i].stu_id<<' '<<vec[i].online_score<<' '<<vec[i].mid_score<<' '<<vec[i].final_score<<' '<<vec[i].G<<endl;
  }
  return 0;
}
