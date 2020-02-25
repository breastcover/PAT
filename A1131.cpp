#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n,m,start,end1;
int min_distance=1e8,min_transfer=1e8;
vector<vector<int>> vec(10000);
unordered_map<int,int> line;
vector<int> path,tmp_path;
vector<bool> visit(10000,false);

int tranferNum()
{
  int cnt=-1,preLine=0;
  for(int i=1;i<tmp_path.size();i++)
  {
    if(line[tmp_path[i]*10000+tmp_path[i-1]]!=preLine)
    {
      cnt++;
      preLine=line[tmp_path[i]*10000+tmp_path[i-1]];
    }
  }

  return cnt;
}

void dfs(int s,int cnt)
{
  if(s==end1)
  {
    int transfer=tranferNum();

    if(cnt<min_distance)
    {
      path=tmp_path;
      min_distance=cnt;
      min_transfer=transfer;
    }
    else if(cnt==min_distance&&transfer<min_transfer)
    {
      path=tmp_path;
      min_transfer=transfer;
    }
    return ;
  }
  for(int i=0;i<vec[s].size();i++)
  {
    int next=vec[s][i];
    if(!visit[next])
    {
      tmp_path.push_back(next);
      visit[next]=true;
      dfs(next,cnt+1);
      visit[next]=false;
      tmp_path.pop_back();
    }
  }
}

int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int station_nums,pre;
    cin>>station_nums>>pre;
    for(int j=1;j<station_nums;j++)
    {
      int tmp;
      cin>>tmp;
      line[pre*10000+tmp]=line[tmp*10000+pre]=i;
      vec[pre].push_back(tmp);
      vec[tmp].push_back(pre);
      pre=tmp;
    }
  }
  cin>>m;
  for(int i=0;i<m;i++)
  {
    cin>>start>>end1;
    min_distance=min_transfer=1e8;
    tmp_path.clear();
    tmp_path.push_back(start);
    //cout<<start<<endl;
    visit[start]=true;
    dfs(start,0);
    visit[start]=false;
    cout<<path.size()-1<<endl;
    int pre=0,pretransfer=start;
    for(int j=1;j<path.size();j++)
    {
      if(line[path[j-1]*10000+path[j]]!=pre)
      {
        if(pre!=0)
          printf("Take Line#%d from %04d to %04d.\n",pre,pretransfer,path[j-1]);
        pre=line[path[j-1]*10000+path[j]];
        pretransfer=path[j-1];
      }
    }
    printf("Take Line#%d from %04d to %04d.\n",pre,pretransfer,end1);
  }
  return 0;
}
