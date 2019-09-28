#include <iostream>
using namespace std;
int main()
{
    char *a= "1234";
    cout << a << endl;
    cout << *a << endl;
    cout << &a << endl;
    a++;
    cout << a << endl;
    return 0;

}