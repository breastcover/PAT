#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vec;
vector<int> tmp;

void bierase(int n)
{
  int left=0;
  int right=tmp.size()-1;
  while(left<=right)
  {
    int mid=(left+right)/2;
    if(tmp[mid]==n)
    {
      tmp.erase(tmp.begin()+mid);
      break;
    }
    else if(tmp[mid]>n)
    {
      right=mid-1;
    }
    else
      left=mid+1;
  }
}

void binsert(int n)
{
  int left=0;
  int right=tmp.size();
  while(left<right)
  {
    int mid=(left+right)/2;
    if(tmp[mid]>=n)
    {
      right=mid;
    }
    else
      left=mid+1;
  }
  //cout<<"Left:"<<left<<endl;
  tmp.insert(tmp.begin()+left,n);
}

void _pop()
{
  if(vec.size()==0)
    cout<<"Invalid"<<endl;
  else
  {
    int k=vec[vec.size()-1];
    cout<<k<<endl;
    vec.pop_back();
    bierase(k);
  }
}

void _peekMedian()
{
  if(vec.size()==0)
  {
    cout<<"Invalid"<<endl;
    return ;
  }
  if(vec.size()%2==0)
  {
    cout<<tmp[tmp.size()/2-1]<<endl;
  }
  else
  {
    cout<<tmp[(tmp.size()+1)/2-1]<<endl;
  }
}

void _push(int n)
{
  vec.push_back(n);
  binsert(n);
}

int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    string s;
    cin>>s;
    if(s=="Pop")
      _pop();
    else if(s=="PeekMedian")
      _peekMedian();
    else if(s=="Push")
    {
      int tmp;
      cin>>tmp;
      _push(tmp);
    }

  }
  return 0;
}
