#include <string.h>
#include "StackTypeTemplate.h"
#include <iostream>

int main()
{
    using namespace std;
    StackType<int> myStack;
    StackType<string> sStack;

    sStack.Push("Blaine");
    sStack.Push("Jessica");
    cout<<sStack.Top() + " ";
    sStack.Pop();
    cout<<sStack.Top()<<endl;
    myStack.Push(20);
    cout << myStack.Top() << endl;
    myStack.Push(34);

    cout << myStack.Top() << endl;
    myStack.Pop();
    cout << myStack.Top() << endl;
    myStack.Pop();
    cout << myStack.IsEmpty() << endl;
}