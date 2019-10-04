#include "Stack.h"
#include <iostream>
using namespace std;

// Stack::Stack()
// {
//     top = 0;
// }
bool Stack::isEmpty()
{
    if(top <= 0)
        return true;
    else
        return false;
    
}
bool Stack::isFull()
{
    if(top>=MAX)
        return true;
    else
        return false;
    
}
bool Stack::push(int num)
{
    if(!isFull())
    {
        
        stack[top]=num;
        top++;
        return true;
    }
    return false;
}
bool Stack::push(string str)
{
    if(!isFull())
    {
         
        string data =str;
        stack[top] = TAG_STRING;
        cout <<data << "pushed " <<"at "<<top<< endl;  
        stringarr.push_back(data);
        top++;
    }
}
int Stack::pop()
{
    if(!isEmpty())
    {
        int num = stack[top];
        cout << "top is"<<top <<" and num is " <<num << endl;
        top--;
        return num;
    }
    return ERROR_TAG;
}
int Stack::peek()
{
    if(!isEmpty())
        return stack[top];
    else
        return ERROR_TAG;
}
string Stack::showString()
{
    string str = stringarr.back();
    stringarr.pop_back();
    return str;
}