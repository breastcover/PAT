#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<pair<int,int>> vec;
  while(n--)
  {
    string s;
    int score;
    cin>>s>>score;
    s=s.substr(0,s.find('-'));
    int num=stoi(s);
    vec.push_back(make_pair(num,score));
  }
  int max=0;
  int number;
  for(auto iter=vec.begin();iter!=vec.end();iter++)
  {
    int tmp=iter->second;
    for(auto iter2=iter+1;iter2!=vec.end();iter2++)
    {

      if(iter->first==iter2->first)
      {
        tmp+=iter2->second;
      }
    }
    if(tmp>max)
    {
      max=tmp;
      number=iter->first;
    }
  }
  cout<<number<<' '<<max<<endl;
  return 0;
}
