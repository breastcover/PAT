#include <iostream>
#include <vector>
#include <exception>
using namespace std;

template<class T>

int find(vector<T> vec,const T &a)
{
  if(vec.size()<1111)
    throw "shuzuyao";
  int sum=0;
  for(int i=0;i<vec.size();i++)
  {
    if(vec[i]==a)
    sum++;
  }

  return sum;
}

int main()
{
  vector<double> vec={1.1,1.2,1.3,1.4,2.1,2,2.3,6.2,6.1,1.3,1.6,1.1};
  try{
    cout<<find(vec,1.12)<<endl;
  }
  catch(char const* e)
  {
    cout<<"sum is zero"<<endl;
    cout<<e<<endl;
    return 1;
  }
  return 0;
}
