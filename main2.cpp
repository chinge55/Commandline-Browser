#include <iostream>
#include <cstring>
using namespace std;
const string str = "<html> </html> sangamkhanal <!fuck!>";
int pointer = 0;
void checkforh()
{
  switch(str[pointer])
  {
    case 't':
      cout << "html found"<< endl;
  }
}
void isopen()
{
  switch(str[pointer])
  {
    case 'h':
      pointer++;
      checkforh();
  }
}
int main()
{
  switch(str[pointer])
  {
    case '<':
      pointer++;
      isopen();

  }

}