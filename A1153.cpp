#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct node
{
  string id;
  int score;
};

bool cmp(const node &n1,const node &n2)
{
  if(n1.score==n2.score)
    return n1.id<n2.id;
  return n1.score>n2.score;
}



int main()
{
  int n,m;
  cin>>n>>m;
  vector<node> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i].id>>vec[i].score;
  }
  for(int i=0;i<m;i++)
  {
    string type;
    cin>>type;
    if(type=="1")
    {
      char term;
      cin>>term;
      sort(vec.begin(),vec.end(),cmp);
      int flag=0;
      //cout<<"Case "<<i+1<<": "<<type<<' '<<term<<endl;
      printf("Case %d: %s %c\n",i+1,type.c_str(),term);
      for(auto e:vec)
      {
        if(e.id[0]==term)
        {
          flag=1;
          printf("%s %d\n",e.id.c_str(),e.score);
          //cout<<e.id<<' '<<e.score<<endl;
        }
      }
      if(!flag)
        cout<<"NA"<<endl;
    }
    else if(type=="2")
    {
      string term;
      cin>>term;
      int sum=0,sum_score=0;
      printf("Case %d: %s %s\n",i+1,type.c_str(),term.c_str());
      for(auto e:vec)
      {
        string s=e.id.substr(1,3);
        if(s==term)
        {
          sum++;
          sum_score+=e.score;
        }
      }
      if(sum!=0)
        printf("%d %d\n",sum,sum_score);
      else
        cout<<"NA"<<endl;
    }else
    {
      string term;
      cin>>term;
      unordered_map<string,int> mmp;
      vector<node> mmv;
      printf("Case %d: %s %s\n",i+1,type.c_str(),term.c_str());
      for(auto e:vec)
      {
        string s=e.id.substr(4,6);
        if(s==term)
        {
          string tmp=e.id.substr(1,3);
          mmp[tmp]++;
        }
      }
      for(auto iter=mmp.begin();iter!=mmp.end();iter++)
      {
        node N;
        N.id=iter->first;
        N.score=iter->second;
        mmv.push_back(N);
      }
      sort(mmv.begin(),mmv.end(),cmp);
      for(auto e:mmv)
        printf("%s %d\n",e.id.c_str(),e.score);
      if(mmp.size()==0)
        cout<<"NA"<<endl;
    }
  }
  return 0;
}
