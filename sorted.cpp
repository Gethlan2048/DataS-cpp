#include<iostream>
#include"ItemType.h"
#include"sortedlinkedlist.h"
int main()
{
    SortedType list1;
    ItemType one;
    ItemType two;

    one.Initilize(1);
    two.Initilize(2);
    list1.PutItem(one);
    list1.PutItem(two);
    list1.GetItem(one).Print();
    list1.GetItem(two).Print();
    list1.GetItem(one).Print();
    list1.DeleteItem(one);
}