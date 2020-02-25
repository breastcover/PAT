#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct book
{
  int id;
  string title;
  string author;
  vector<string> keywords;
  string publisher;
  int years;
}Book;

bool cmp(book b1,book b2)
{
  return b1.id<b2.id;
}

int main()
{
  int n;
  cin>>n;
  vector<book> vec;
  for(int i=0;i<n;i++)
  {
    cin>>Book.id;
    getchar();
    getline(cin,Book.title);
    getline(cin,Book.author);
    string s;
    while(cin>>s)
    {
      Book.keywords.push_back(s);
      if(getchar()=='\n')
        break;
    }
    getline(cin,Book.publisher);
    cin>>Book.years;
    vec.push_back(Book);
    Book.keywords.clear();
  }
  // cout<<endl<<endl;
  // for(auto e:vec)
  // {
  //   cout<<e.id<<endl;
  //   cout<<e.title<<endl;
  //   cout<<e.author<<endl;
  //   for(auto v:e.keywords)
  //     cout<<v<<' ';
  //   cout<<endl;
  //   cout<<e.publisher<<endl;
  //   cout<<e.years<<endl;
  // }

  sort(vec.begin(),vec.end(),cmp);
  int m;
  cin>>m;
  for(int k=0;k<m;k++)
  {
    int flag=1;
    char type;
    string term;
    cin>>type;
    getchar();
    getchar();
    getline(cin,term);
    cout<<type<<": "<<term<<endl;
    switch (type) {
      case '1':
      {
        for(int i=0;i<n;i++)
        {
          if(vec[i].title==term)
          {
            flag=0;
            printf("%07d\n",vec[i].id);
          }
        }
        if(flag)
          cout<<"Not Found"<<endl;
        break;
      }
      case '2':
      {
        for(int i=0;i<n;i++)
        {
          if(vec[i].author==term)
          {
            flag=0;
            printf("%07d\n",vec[i].id);
          }
        }
        if(flag)
          cout<<"Not Found"<<endl;
        break;
      }
      case '3':
      {
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<vec[i].keywords.size();j++)
          {
            //cout<<vec[i].keywords[j]<<endl;
            if(vec[i].keywords[j]==term)
            {
              flag=0;
              printf("%07d\n",vec[i].id);
              break;
            }
          }
        }
        if(flag)
          cout<<"Not Found"<<endl;
        break;
      }
      case '4':
      {
        for(int i=0;i<n;i++)
        {
          if(vec[i].publisher==term)
          {
            flag=0;
            printf("%07d\n",vec[i].id);
          }
        }
        if(flag)
          cout<<"Not Found"<<endl;
        break;
      }
      case '5':
      {
        for(int i=0;i<n;i++)
        {
          if(to_string(vec[i].years)==term)
          {
            flag=0;
            printf("%07d\n",vec[i].id);
          }
        }
        if(flag)
          cout<<"Not Found"<<endl;
        break;
      }
      default:
        break;
    }
  }
  return 0;
}
