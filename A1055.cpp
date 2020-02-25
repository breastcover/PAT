#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct richer
{
  string name;
  int ages;
  int worth;
};

bool cmp(richer r1,richer r2)
{
  return r1.ages<r2.ages;
}
int n,m;
vector<richer> vec;

int biseach(int left,int right,int m)
{
  int mid;
  while(left<right)
  {
    mid=(left+right)/2;
    if(vec[mid].ages<m)
      left=mid+1;
    else if(vec[mid].ages>=m)
      right=mid;
  }
  return left;
}

bool res_cmp(richer r1,richer r2)
{
  if(r1.worth==r2.worth)
  {
    if(r1.ages==r2.ages)
      return r1.name<r2.name;
    return r1.ages<r2.ages;
  }
  return r1.worth>r2.worth;
}

int main()
{
  cin>>n>>m;
  for(int i=0;i<n;i++)
  {
    richer r;
    cin>>r.name;
    scanf("%d%d",&r.ages,&r.worth);
    vec.push_back(r);
  }
  sort(vec.begin(),vec.end(),cmp);
  // cout<<"sorted:"<<endl<<endl;
  // for(int i=0;i<n;i++)
  //   cout<<vec[i].name<<' '<<vec[i].ages<<' '<<vec[i].worth<<endl;
  for(int i=0;i<m;i++)
  {
    int num,amin,amax,left;
    cin>>num>>amin>>amax;
    left=biseach(0,n-1,amin);
  //  cout<<left<<endl;
    vector<richer> res;
    if(left<n)
    {
      for(int j=left;vec[j].ages<=amax&&j<n;j++)
      {
        res.push_back(vec[j]);
      }
      sort(res.begin(),res.end(),res_cmp);
    }
    cout<<"Case #"<<i+1<<":"<<endl;
    if(res.size()==0)
      cout<<"None"<<endl;
    else
      for(int j=0;j<res.size()&&j<num;j++)
        //cout<<res[j].name<<' '<<res[j].ages<<' '<<res[j].worth<<endl;
        printf("%s %d %d\n",res[j].name.c_str(),res[j].ages,res[j].worth);
  }
  return 0;
}
