#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
    Stack *s = new Stack();
    s->push(1);
    s->push(2);
    s->push("Sangam");
    s->push(1);
    s->push("DAI");
    while(!s->isEmpty())
    {
        int i = s->pop();
         if(i==21)
        {
            cout << s->showString()<<endl;
        }
        else 
        {
            cout << i<<endl;
        }

    }
}