#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void downAdjust(vector<int> &v,int low,int high)
{
  int i=1,j=2*i;
  while(j<=high)
  {
    if(j+1<=high&&v[j]<=v[j+1])
      j+=1;
    if(v[i]>=v[j])
      break;
    swap(v[i],v[j]);
    i=j;
    j*=2;
  }
}

int main()
{
  int n;
  cin>>n;
  vector<int> a(n+1);
  vector<int> b(n+1);
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
  }
  for(int i=1;i<=n;i++)
  {
    cin>>b[i];
  }
  int p=2;
  while(b[p]>=b[p-1]&&p<=n)
  {
    p++;
  }
  int index=p;
  while(a[p]==b[p]&&p<=n)
    p++;
  if(p==n+1)
  {
    cout<<"Insertion Sort"<<endl;
    sort(b.begin()+1,b.begin()+1+index);
  }else
  {
    p=n;
    while(b[p]>=b[1]&&p>2)
      p--;
    swap(b[p],b[1]);
    downAdjust(b,0,p-1);
    cout<<"Heap Sort"<<endl;
  }
  for(int i=1;i<=n;i++)
  {
    if(i==1)
      cout<<b[i];
    else
      cout<<' '<<b[i];
  }
  return 0;
}
