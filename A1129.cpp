#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct node
{
  int id;
  int ac_times;
}Node;

bool cmp(node n1,node n2)
{
  if(n1.ac_times==n2.ac_times)
    return n1.id<n2.id;
  else
    return n1.ac_times>n2.ac_times;
}

void _prinf(vector<node> res)
{
  sort(res.begin(),res.end(),cmp);
  for(int j=0;j<res.size();j++)
  {
      cout<<' '<<res[j].id;
  }
  cout<<endl;
}

int main()
{
  int n,k;
  cin>>n>>k;
  map<int,int> mmp;
  vector<node> res;
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    mmp[tmp]++;
    if(i!=0)
    {
      cout<<tmp<<":";
      _prinf(res);
    }
    if(res.size()<k)
    {
      Node.id=tmp;
      Node.ac_times=mmp[tmp];
      res.push_back(Node);
    }
    else
    {
      sort(res.begin(),res.end(),cmp);
      bool flag=0;
      if(mmp[tmp]>res[k-1].ac_times)
      {
        //查找res中是否有这个点
        for(int l=0;l<res.size();l++)
        {
          if(res[l].id==tmp)
            flag=true;
        }
        //没有就替换
        if(!flag)
        {
          Node.id=tmp;
          Node.ac_times=mmp[tmp];
          res[k-1]=Node;
        }
        //有就更新ac_times
        else
        {
          for(node &e:res)
          {
            if(e.id==tmp)
              e.ac_times++;
          }
        }
      }
      //相等的情况替换
      else if(mmp[tmp]==res[k-1].ac_times&&!flag&&res[k-1].id>tmp)
      {
        res[k-1].id=tmp;
      }
    }

  }
  return 0;
}
