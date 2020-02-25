#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  char date[99999];
  int next[99999];
  int h1,h2,n;
  cin>>h1>>h2>>n;
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    cin>>date[tmp]>>next[tmp];
  }
  int times[99999]={0};
  int tmp;
  for(tmp=h1;tmp!=-1;tmp=next[tmp])
  {
    times[tmp]=1;
  }
  for(tmp=h2;tmp!=-1;tmp=next[tmp])
  {
    times[tmp]++;
    if(times[tmp]==2)
      break;
  }
  if(tmp!=-1)
    printf("%05d\n",tmp);
  else
    cout<<-1<<endl;
  return 0;
}
