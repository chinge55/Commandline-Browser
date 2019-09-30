#include <iostream>
#include <cstring>
using namespace std;
const string str = "1abc2";
int pointer = 0;
int main()
{
  cout << str[pointer]<< endl;
  int a = (int)str[pointer];
  cout << a << endl;
  switch(str[pointer])
  {
    case ('1'||'2'):
      cout << "done" << endl;
  }
}