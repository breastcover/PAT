#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int sum=0;
  vector<int> vec(13);
  for(int i=1;i<=12;i++)
    vec[i]=i;
  vector<int> res(6);
  for(int i=1;i<=12;i++)
  {
    res[0]=vec[i];
    for(int j=i+1;j<=12;j++)
    {
      res[1]=vec[j];
      for(int l=j+1;l<=12;l++)
      {
        res[2]=vec[l];
        for(int k=l+1;k<=12;k++)
        {
          res[3]=vec[k];
          for(int m=k+1;m<=12;m++)
          {
            res[4]=vec[m];
            for(int n=m+1;n<=12;n++)
            {
              res[5]=vec[n];
              do{
                for(auto e:res)
                cout<<e<<' ';
                cout<<endl;
                sum++;
                cout<<sum<<endl;
              }
              while(next_permutation(res.begin(),res.end()));

            }
          }
        }
      }
    }
  }
}
