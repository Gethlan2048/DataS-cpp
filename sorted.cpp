#include<iostream>
#include<string.h>
#include"sortedlinkedlist_t.h"
int main()
{
    using namespace std;
    SortedType<int> list1;
    SortedType<string> list2;
 
    list2.PutItem("Blaine");
    cout<< list2.GetItem("Blaine");
    list1.PutItem(121212);
    list1.PutItem(32);
    list1.GetItem(121212);
    cout<<list1.GetItem(32) << endl;
    list1.DeleteItem(32);
    std::cout<<list1.GetItem(121212)<<std::endl;
}