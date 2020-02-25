#include <iostream>
using namespace std;

enum result{win,tie,lose};

int jiaWin(int a,int b,int c,int d)
{
  bool j_win=false,y_win=false;
  if(a+c==b)
    j_win=true;
  if(a+c==d)
    y_win=true;
  if(j_win==true&&y_win==false)
    return win;
  if(j_win==true&&y_win==true)
    return tie;
  if(j_win==false&&y_win==true)
    return lose;
  if(j_win==false&&y_win==false)
    return  tie;
}

int main()
{
  int n;
  cin>>n;
  int jw=0,yw=0;
  int a,b,c,d;
  for(int i=0;i<n;i++)
  {
    cin>>a>>b>>c>>d;
    if(jiaWin(a,b,c,d)==win)
      jw++;
    if(jiaWin(a,b,c,d)==lose)
      yw++;
  }
  cout<<yw<<' '<<jw<<endl;
  return 0;
}
