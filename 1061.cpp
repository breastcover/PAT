#include <iostream>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  int xzt_score[m];
  for(int i=0;i<m;i++)
  {
    cin>>xzt_score[i];
  }
  int xzt_answer[m];
  for(int i=0;i<m;i++)
  {
    cin>>xzt_answer[i];
  }
  int students[n];
  for(int i=0;i<n;i++)
  {
    students[i]=0;
  }
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      int tmp;
      cin>>tmp;
      if(tmp==xzt_answer[j])
        students[i]+=xzt_score[j];
    }
  }
  for(int i=0;i<n;i++)
  cout<<students[i]<<endl;
  return 0;
}
