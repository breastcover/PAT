#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  int right_answer[m][5];
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<5;j++)
      right_answer[i][j]=0;
  }
  int score[m];
  int right_opt_num[m];
  for(int i=0;i<m;i++)
  {
    cin>>score[i]>>right_opt_num[i];
    int tmp;
    cin>>tmp;
    for(int j=0;j<tmp;j++)
    {
      char c;
      cin>>c;
      right_answer[i][c-'a']++;
    }
  }

  int max_wrong_opt[1005][5]={0};
  int maxx=0;
  int opt[m][5];
  for(int l=0;l<m;l++)
    for(int t=0;t<5;t++)
      opt[l][t]=0;
  double res[n];
  for(int i=0;i<n;i++)
    res[i]=0;

  char c;
  for(int i=0;i<n;i++)
  {
    for(int l=0;l<m;l++)
      for(int t=0;t<5;t++)
        opt[l][t]=0;
    int k=-1;
    while(cin>>c)
    {
      if(isdigit(c))
      {
        k++;
      }
      else if(isalpha(c))
      {
        opt[k][c-'a']=1;
      }
      if(c==')'&&k==m-1)
        break;
    }
    for(int j=0;j<m;j++)
    {
      int flag_sx=0,flag_dx=0;
      for(int p=0;p<5;p++)
      {
        if(opt[j][p]==1&&right_answer[j][p]==0)
        {
          flag_dx=1;
          max_wrong_opt[j][p]++;
          if(max_wrong_opt[j][p]>maxx)
            maxx=max_wrong_opt[j][p];
        }
        else if(opt[j][p]==0&&right_answer[j][p]==1)
        {
          flag_sx=1;
          max_wrong_opt[j][p]++;
          if(max_wrong_opt[j][p]>maxx)
            maxx=max_wrong_opt[j][p];
        }
      }
      if(flag_sx&&!flag_dx)
      {
        res[i]=res[i]+((double)score[j]/2);
      }else if(!flag_sx&&!flag_dx)
      {
        res[i]+=score[j];
      }
    }
  }
  for(int i=0;i<n;i++)
    printf("%.1f\n",res[i]);
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<5;j++)
    {
      if(max_wrong_opt[i][j]==maxx&&maxx!=0)
        printf("%d %d-%c\n",maxx,i+1,j+'a' );
    }
  }
  if(maxx==0)
    cout<<"Too simple"<<endl;
  return 0;
}
