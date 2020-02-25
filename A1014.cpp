#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
  int poptime,endtime;
  queue<int> q;
};

int main()
{
  int n,m,k,q;
  cin>>n>>m>>k>>q;
  vector<node> windows(n+1);
  bool sorry[k+1];
  fill(sorry,sorry+k+1,false);
  int res[k+1];
  int times[k+1];
  for(int i=1;i<=k;i++)
  {
    cin>>times[i];
  }
  int index=1;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(index<=k)
      {
        windows[j].q.push(times[index]);
        if(windows[j].endtime>=540)
          sorry[index]=true;
        windows[j].endtime+=times[index];
        if(i==1)
          windows[j].poptime=windows[j].endtime;
        res[index]=windows[j].endtime;
        index++;
      }
    }
  }

  while(index<=k)
  {
    int tmp=1,tmpmin=windows[tmp].poptime;
    for(int i=2;i<=n;i++)
    {
      if(tmpmin>windows[i].poptime)
      {
        tmp=i;
        tmpmin=windows[i].poptime;
      }
    }
    if(windows[tmp].endtime>=540)
      sorry[index]=true;
    windows[tmp].q.pop();
    int qt=windows[tmp].q.front();

    windows[tmp].poptime+=qt;
    windows[tmp].endtime+=times[index];
    res[index]=windows[tmp].endtime;

    windows[tmp].q.push(times[index]);
    index++;

  }

  //cout<<endl;
  for(int i=0;i<q;i++)
  {
    int req;
    cin>>req;
    if(sorry[req])
    {
       cout<<"Sorry"<<endl;
    }else
    {
      printf("%02d:%02d\n",res[req]/60+8,res[req]%60);
    }
  }
  return 0;
}
