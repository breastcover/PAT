#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct in_out
{
  string ID_number;
  string Sign_in_time;
  string Sign_out_time;
};

bool cmp_in(in_out a,in_out b)
{
  return a.Sign_in_time<b.Sign_in_time;
}

bool cmp_out(in_out a,in_out b)
{
  return a.Sign_out_time>b.Sign_out_time;
}

int main()
{
  int n;
  cin>>n;
  vector<in_out> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i].ID_number>>vec[i].Sign_in_time>>vec[i].Sign_out_time;
  }
  sort(vec.begin(),vec.end(),cmp_in);
  cout<<vec[0].ID_number<<" ";
  sort(vec.begin(),vec.end(),cmp_out);
  cout<<vec[0].ID_number<<endl;
  return 0;
}
