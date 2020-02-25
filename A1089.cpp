#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> p1;

void _insertion(vector<int> v)
{
  for(int i=0;i<v.size()-1;i++)
  {
    if(v[i+1]<v[i])
    for(int j=i+1;j>=1;j--)
    {
      if(v[j]<v[j-1])
      {
        swap(v[j],v[j-1]);
      }
    }
    p1.push_back(v);
  }
  p1.push_back(v);
}

vector<vector<int>> p2;
void _merge(vector<int> vec)
{
  int n=vec.size();
  for(int i=1;i<2*n;i*=2)
  {
    for(int j=0;j<n/i;j++)
    {
      sort(vec.begin()+i*j,vec.begin()+(j+1)*i);
    }
    sort(vec.begin()+i*(n/i),vec.end());
    p2.push_back(vec);
  }
  //sort(vec.begin(),vec.end());
}

int main()
{
  int n;
  cin>>n;
  vector<int> vec(n);
  vector<int> res(n);
  for(int i=0;i<n;i++)
    cin>>vec[i];
  for(int i=0;i<n;i++)
    cin>>res[i];

  int flag=0;
  _insertion(vec);
  for(int i=0;i<p1.size()-1;i++)
  {
    if(p1[i]==res)
    {
      flag=1;
      cout<<"Insertion Sort"<<endl;
      for(int j=0;j<p1[i+1].size();j++)
      {
        if(j==0)
          cout<<p1[i+1][j];
        else
          cout<<' '<<p1[i+1][j];
      }
      cout<<endl;
    }
  }
  if(!flag)
  {
    _merge(vec);
    for(int i=0;i<p2.size()-1;i++)
    {
      if(p2[i]==res)
      {
        cout<<"Merge Sort"<<endl;
        for(int j=0;j<p2[i+1].size();j++)
        {
          if(j==0)
            cout<<p2[i+1][j];
          else
            cout<<' '<<p2[i+1][j];
        }
        cout<<endl;
      }
    }
  }
  return 0;
}
