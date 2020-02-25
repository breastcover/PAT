#include <iostream>
using namespace std;

int main()
{
  int g,s,k,g1,s1,k1;
  scanf("%d.%d.%d",&g,&s,&k);
  scanf("%d.%d.%d",&g1,&s1,&k1);
  g+=g1;
  s+=s1;
  k+=k1;
  s+=k/29;
  k%=29;
  g+=s/17;
  s%=17;
  printf("%d.%d.%d\n",g,s,k);
  return 0;
}
