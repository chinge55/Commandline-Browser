/*
html = 1
head = 2
body = 3
title = 4
h1-h9 = 10-20
p = 5
br = 6
string = 21
*/
#include <vector> 
#include <iostream>
using namespace std;
#define ERROR_TAG 0
#define TAG_HTML 1
#define TAG_HTMLEND -1
#define TAG_HEAD 2
#define TAG_HEADEND -2
#define TAG_BODY 3
#define TAG_BODYEND -3
#define TAG_TITLE 4
#define TAG_TITLEEND -4
#define TAG_P 5
#define TAG_PEND -5
#define TAG_BR 6
#define TAG_BREND -6
#define TAG_H 10
#define TAG_HEND -10
#define TAG_STRING 21
#define MAX 1000
class Stack
{
    private:
        int stack[MAX];
        int top = 0;
        vector<string> stringarr;
       

    public:
       // Stack();
        bool push(int num);
        int pop();
        int peek();
        bool push(string str);
        string showString();
         bool isEmpty();
        bool isFull();

};