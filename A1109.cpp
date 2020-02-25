#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct student
{
  string name;
  int heigth;
}S;

bool cmp(student s1,student s2)
{
  if(s1.heigth==s2.heigth)
    return s1.name<s2.name;
  return s1.heigth>s2.heigth;
}

int main()
{
  int n,row;
  cin>>n>>row;
  vector<student> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i].name>>vec[i].heigth;
  }
  sort(vec.begin(),vec.end(),cmp);
  int k=n/row;
  //cout<<k<<endl;
  vector<vector<string>> res;

  int flag=0;
  vector<string> tmp;
  int index=0;
  for(int i=(row-1)*k;i<n;i++)
  {
    if(flag==0)
    {
      tmp.push_back(vec[index].name);
      flag=1;
    }
    else
    {
      tmp.insert(tmp.begin(),vec[index].name);
      flag=0;
    }
    index++;
  }
  res.push_back(tmp);

  for(int i=0;i<row-1;i++)
  {
    flag=0;
    tmp.clear();
    for(int j=0;j<k;j++)
    {
      if(flag==0)
      {
        tmp.push_back(vec[index].name);
        flag=1;
      }
      else
      {
        tmp.insert(tmp.begin(),vec[index].name);
        flag=0;
      }
      index++;
    }
    res.push_back(tmp);
  }


  for(int i=0;i<res.size();i++)
  {
    for(int j=0;j<res[i].size();j++)
    {
      if(j==0)
        cout<<res[i][j];
      else
        cout<<' '<<res[i][j];
    }
    cout<<endl;
  }
  return 0;
}
