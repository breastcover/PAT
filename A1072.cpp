#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const int MAX=1020;
const int INF=1e8;

int n,m,k,range;
int G[MAX][MAX];
int CG[MAX][MAX];
int d[MAX];
int vis[MAX];

void Dijkstra(int s)
{
  fill(vis,vis+MAX,false);
  fill(d,d+MAX,INF);
  d[s]=0;
  for(int i=1;i<=n+m;i++)
  {
    int u=-1,_min=INF;
    for(int j=1;j<=n+m;j++)
    {
      if(vis[j]==false&&d[j]<_min)
      {
        u=j;
        _min=d[j];
      }
    }
    if(u==-1)
      return ;
    vis[u]=true;
    for(int v=1;v<=n+m;v++)
    {
      if(G[u][v]!=INF&&d[v]>d[u]+G[u][v])
        d[v]=d[u]+G[u][v];
    }
  }
}

void init(int G[MAX][MAX],int CG[MAX][MAX])
{
  for(int i=1;i<=n+m;i++)
  {
    for(int j=1;j<=n+m;j++)
      CG[i][j]=G[i][j];
  }
}

int getid(string s)
{
  if(s[0]=='G')
  {
    string p=s.substr(1,s.size()-1);
    return stoi(p)+n;
  }
  else
  {
    int k=stoi(s);
    return k;
  }
}

int main()
{
  cin>>n>>m>>k>>range;
  fill(G[0],G[0]+MAX*MAX,INF);
  for(int i=0;i<k;i++)
  {
    string a,b;
    cin>>a>>b;
    int d;
    cin>>d;
    if(d<G[getid(a)][getid(b)])
    {
      G[getid(a)][getid(b)]=d;
      G[getid(b)][getid(a)]=d;
    }
  }
  init(G,CG);
  double min_to_solution=INF,min_to_houses=0;
  string location=" ";
  for(int i=n+1;i<=n+m;i++)
  {
    Dijkstra(i);
    int tmp_h=0,tmp=INF;
    int j;
    //cout<<'G'<<i-n<<endl;
    for(j=1;j<=n;j++)
    {
      //cout<<d[j]<<endl;
      if(d[j]>range)
        break;
      if(d[j]<tmp)
        tmp=d[j];
      tmp_h+=d[j];
    }
    if(j==n+1&&tmp>min_to_houses)
    {
      location='G'+to_string(i-n);
      min_to_solution=tmp;
      min_to_houses=tmp_h;
    }else if(j==n+1&&tmp==min_to_solution&&tmp_h<min_to_houses)
    {
      location='G'+to_string(i-n);
      min_to_solution=tmp;
      min_to_houses=tmp_h;
    }
    init(CG,G);
  }
  if(location!=" ")
  {
    cout<<location<<endl;
    printf("%.1f",min_to_solution);
    printf(" %.1f\n",min_to_houses/n);
  }
  else
    cout<<"No Solution"<<endl;
  return 0;
}
