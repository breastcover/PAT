#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void to_lower(string &s)
{
  for(int i=0;i<s.size();i++)
  {
    s[i]=tolower(s[i]);
  }
}

struct node
{
  string school;
  int total_score;
  int num;
}Node;

bool cmp(node n1,node n2)
{
  if(n1.total_score==n2.total_score)
  {
    if(n1.num==n2.num)
      return n1.school<n2.school;
    return n1.num<n2.num;
  }
  return n1.total_score>n2.total_score;
}

int main()
{
  int n;
  cin>>n;
  map<string,double> twc;
  map<string,int> ns;
  for(int i=0;i<n;i++)
  {
    string id,school;
    double score;
    cin>>id>>score>>school;
    to_lower(school);
    if(id[0]=='T')
      score*=1.5;
    else if(id[0]=='B')
      score/=1.5;
    twc[school]+=score;
    ns[school]++;
  }
  vector<node> vec;
  for(auto iter=twc.begin();iter!=twc.end();iter++)
  {
    Node.school=iter->first;
    Node.total_score=iter->second;
    Node.num=ns[iter->first];
    vec.push_back(Node);
  }
  sort(vec.begin(),vec.end(),cmp);
  cout<<vec.size()<<endl;
  int rank=1;
  int score=0;
  for(int i=0;i<vec.size();i++)
  {
    if(vec[i].total_score!=score)
    {
      rank=i+1;
      score=vec[i].total_score;
    }
    cout<<rank<<' '<<vec[i].school<<' '<<vec[i].total_score<<' '<<vec[i].num<<endl;
  }
  return 0;
}
