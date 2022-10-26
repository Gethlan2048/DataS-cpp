#pragma once
#include <iostream>
using namespace std;


enum RelationType{LESS,GREATER, EQUAL};
const int MAX_ITEMS = 5;
class ItemType
{
public:
ItemType();
RelationType ComparedTo(ItemType) const;
void Print() const;
void Initilize (int number);
private:
int value;


};

ItemType :: ItemType(){
value=0;
}

RelationType ItemType :: ComparedTo(ItemType otherItem) const{
if(value<otherItem.value)
{
return LESS;
}
else if(value>otherItem.value)
{
return GREATER;
}
else return EQUAL;


}


void ItemType:: Initilize(int number)
{

value=number;
}

void ItemType:: Print() const
{

cout<<value<<endl;
}