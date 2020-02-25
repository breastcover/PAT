#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=1111;
int father[MAX];
int isRoot[MAX];

int findFater(int x)
{
  int a=x;
  while(x!=father[x])
  {
    x=father[x];
  }
  while(a!=father[x])
  {
    int z=a;
    a=father[a];
    father[z]=x;
  }
  return x;
}

void Union(int a,int b)
{
  int faA=findFater(a);
  int faB=findFater(b);
  if(faA!=faB)
  {
    father[faA]=faB;
  }
}

bool cmp(int a,int b)
{
  return a>b;
}

int main()
{
  for(int i=1;i<MAX;i++)
  {
    father[i]=i;
  }
  fill(isRoot,isRoot+MAX,0);
  int course[MAX]={0};
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int k;
    scanf("%d: ",&k);
    for(int j=0;j<k;j++)
    {
      int tmp;
      cin>>tmp;
      if(course[tmp]==0)
        course[tmp]=i;
      Union(i,findFater(course[tmp]));
    }
  }
  int sum=0;
  for(int i=1;i<=n;i++)
  {
    isRoot[findFater(i)]++;
  }
  sort(isRoot,isRoot+MAX,cmp);
  for(int i=0;i<n;i++)
  {
    //cout<<isRoot[i]<<' ';
    if(isRoot[i]!=0)
      sum++;
  }
  //cout<<endl;
  cout<<sum<<endl;
  for(int i=0;i<sum;i++)
  {
    cout<<isRoot[i];
    if(i<sum-1)
      cout<<' ';
  }
  return 0;
}
