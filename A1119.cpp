#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

int n,index=0;
int flag=false;
vector<int> pre(31);
vector<int> in(31);
vector<int> post(31);

void in_order(int preL,int preR,int postL,int postR)
{
  if(preL>preR)
    return ;
  if(preL==preR)
  {
    in[++index]=pre[preL];
    return ;
  }
  int cnt=0;
  while(pre[preL+1]!=post[postL+cnt])
    cnt++;
  cnt++;
  if(cnt==1&&preL+cnt==preR)
    flag=true;
  in_order(preL+1,preL+cnt,postL,postL+cnt-1);
  in[++index]=pre[preL];
  in_order(preL+cnt+1,preR,postL+cnt,postR-1);
}

int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>pre[i];
  for(int i=1;i<=n;i++)
    cin>>post[i];
  in_order(1,n,1,n);
//  cout<<1<<endl;
  if(flag==true)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
  for(int i=1;i<=n;i++)
  {
    cout<<in[i];
    if(i!=n)
      cout<<" ";
  }
  return 0;
}
