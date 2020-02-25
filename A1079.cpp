#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


vector<int> vec[100010];
double p,r;
double _price[100010];


void DFS(int n)
{
  stack<int> s;
  s.push(n);
  _price[n]=p;
  while(!s.empty())
  {
    int _top=s.top();
    s.pop();
    for(int i=0;i<vec[_top].size();i++)
    {
      s.push(vec[_top][i]);
      _price[vec[_top][i]]=_price[_top]*(1+r/100);
    }
  }
}

struct retail
{
  int id;
  int num;
}Retail;

int main()
{
  int n;
  cin>>n;
  cin>>p>>r;
  vector<retail> re;
  for(int i=0;i<n;i++)
  {
    int next_num;
    cin>>next_num;
    if(next_num==0)
    {
      cin>>Retail.num;
      Retail.id=i;
      re.push_back(Retail);
    }
    for(int j=0;j<next_num;j++)
    {
      int next_id;
      cin>>next_id;
      vec[i].push_back(next_id);
    }
  }

  DFS(0);

  double sum=0;
  for(int i=0;i<re.size();i++)
  {
    sum+=_price[re[i].id]*re[i].num;
  }
  printf("%.1f\n",sum);
  return 0;
}
