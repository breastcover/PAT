#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct node
{
  int id;
  int estate_num;
  int area;
};

int father[10010];
bool isRoot[10010];
void init()
{
  for(int i=0;i<10010;i++)
  {
    father[i]=i;
    isRoot[i]=false;
  }
  return ;
}

int findFather(int x)
{
  int a=x;
  while(x!=father[x])
  {
    x=father[x];
  }
  while(a!=father[a])
  {
    int z=a;
    a=father[a];
    father[z]=x;
  }
  return x;
}

void Union(int a,int b)
{
  int fa=findFather(a);
  int fb=findFather(b);
  if(fa!=fb)
  {
    father[fb]=fa;
  }

}

struct aver
{
  int id;
  int sum;
  double estate;
  double area;
}Aver;

bool cmp(aver a1,aver a2)
{
  if(a1.area==a2.area)
    return a1.id<a2.id;
  else
    return a1.area>a2.area;
}

int main()
{
  int n;
  cin>>n;
  vector<node> vec(10010);
  vector<int> ans;
  init();
  for(int i=0;i<n;i++)
  {
    int id,f_id,m_id,c_num,c_id;
    cin>>id>>f_id>>m_id>>c_num;
    if(find(ans.begin(),ans.end(),id)==ans.end())
      ans.push_back(id);
    if(find(ans.begin(),ans.end(),f_id)==ans.end()&&f_id!=-1)
      ans.push_back(f_id);
    if(find(ans.begin(),ans.end(),m_id)==ans.end()&&m_id!=-1)
      ans.push_back(m_id);
    if(f_id!=-1)
      Union(id,f_id);
    if(m_id!=-1)
      Union(id,m_id);
    for(int j=0;j<c_num;j++)
    {
      int tmp;
      cin>>tmp;
      if(find(ans.begin(),ans.end(),tmp)==ans.end())
        ans.push_back(tmp);
      Union(tmp,id);
    }
    cin>>vec[id].estate_num>>vec[id].area;
  }
  //cout<<2<<endl;
  vector<int> root;
  for(int i=0;i<ans.size();i++)
  {
    //cout<<3<<endl;
    //cout<<ans[i]<<endl;
    int k=findFather(ans[i]);
    if(find(root.begin(),root.end(),k)==root.end())
      root.push_back(k);
  }
  //cout<<1<<endl;
  int _min=15000;
  int sum=0;
  int estate_sum=0;
  int area_sum=0;
  cout<<root.size()<<endl;
  vector<aver> res;
  for(int i=0;i<root.size();i++)
  {
    for(int j=0;j<ans.size();j++)
    {
      if(findFather(ans[j])==root[i])
      {
        sum++;
        estate_sum+=vec[ans[j]].estate_num;
        area_sum+=vec[ans[j]].area;
        if(ans[j]<_min)
          _min=ans[j];
      }
    }
    aver t;
    t.sum=sum;
    t.area=(double)area_sum/sum;
    t.id=_min;
    t.estate=(double)estate_sum/sum;
    res.push_back(t);
    _min=15000;
    sum=0;
    estate_sum=0;
    area_sum=0;
  }
  sort(res.begin(),res.end(),cmp);
  for(auto e:res)
  printf("%04d %d %.3f %.3f\n",e.id,e.sum,e.estate,e.area);
  return 0;
}
