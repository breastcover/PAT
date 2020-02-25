#include <iostream>
using namespace std;

int main()
{
  int total,n;
  cin>>total>>n;
  for(int i=0;i<n;i++)
  {
    int n1,b,t,n2;
    cin>>n1>>b>>t>>n2;
    if(t>total)
    {
      printf("Not enough tokens.  Total = %d.\n",total);
    }
    else if((n2>n1&&b==1)||(n2<n1&&b==0))
    {
      total+=t;
      printf("Win %d!  Total = %d.\n",t,total);
    }
    else if((n2>n1&&b==0)||(n2<n1&&b==1))
    {
      total-=t;
      printf("Lose %d.  Total = %d.\n",t,total);
      if(total<=0)
      {
        cout<<"Game Over."<<endl;
        break;
      }
    }
  }
  return 0;
}
