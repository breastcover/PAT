#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Polynomials
{
  int exponents;
  double coefficients;
};

bool cmp(Polynomials p1,Polynomials p2)
{
  return p1.exponents>p2.exponents;
}



int main()
{
  int n;
  cin>>n;
  vector<Polynomials> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i].exponents>>vec[i].coefficients;
  }
  int m;
  cin>>m;
  vector<Polynomials> vec1(m);
  for(int i=0;i<m;i++)
  {
    cin>>vec1[i].exponents>>vec1[i].coefficients;
  }
  vector<Polynomials> res;
  for(int i=0;i<n;i++)
  {

    for(int j=0;j<m;j++)
    {
      Polynomials p;

      p.exponents=vec[i].exponents+vec1[j].exponents;
      p.coefficients=vec[i].coefficients*vec1[j].coefficients;
      res.push_back(p);
    }
  }
  if(res.size()==0)
  {
    cout<<0<<endl;
    return 0;
  }
  sort(res.begin(),res.end(),cmp);
  for(int i=0;i<res.size()-1;)
  {
    if(res[i].coefficients==(double)0||res[i+1].coefficients==(double)0)
      res.erase(res.begin()+i);
    else if(res[i].exponents==res[i+1].exponents)
    {
      res[i].coefficients+=res[i+1].coefficients;
      res.erase(res.begin()+i+1);
    }
    else
      i++;
  }

  cout<<res.size();
  for(int i=0;i<res.size();i++)
    printf(" %d %.1f",res[i].exponents,res[i].coefficients );
  return 0;
}
