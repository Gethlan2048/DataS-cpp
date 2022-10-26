#include <iostream>

enum RelationType
{
    LESS,
    EQUAL,
    GREATER
};
struct NodeType;
struct ItemType;
struct ItemType
{
    int firstNumber;
    int secondNumber;

    RelationType ItemType::ComparedTo(ItemType item)
    {
        if (firstNumber < item.firstNumber)
        {
            return LESS;
        }
        else if (firstNumber > item.firstNumber)
        {
            return GREATER;
        }
        else if (firstNumber == item.firstNumber)
        {
            return EQUAL;
        }
    }
};

class SortedType
{
public:
    SortedType();  // class constructor
    ~SortedType(); // class destructor

    bool IsFull() const;
    int GetLength() const;
    void MakeEmpty();
    ItemType GetItem(ItemType item, bool &found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem();

private:
    NodeType *listData;
    int length;
    NodeType *currentPos;
};
struct NodeType
{
    ItemType info;
    NodeType *next;
};

SortedType::SortedType()
{
    length = 0;
    listData = NULL;
}

bool SortedType::IsFull() const
{
    NodeType *location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

int SortedType::GetLength() const
{
    return length;
}

void SortedType::MakeEmpty()
{
    NodeType *tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

ItemType SortedType::GetItem(ItemType item, bool &found)
{
    bool moreToSearch;
    NodeType *location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        switch (item.CompareTo(location->info))
        {
        case GREATER:
            location = location->next;
            moreToSearch = (location != NULL);
            break;
        case EQUAL:
            found = true;
            item = location->info;
            break;
        case LESS:
            moreToSearch = false;
            break;
        }
    }
    return item;
}

void SortedType::PutItem(ItemType item)
{
    NodeType *newNode;
    NodeType *predLoc;
    NodeType *location;
    bool moreToSearch;

    location = listData;
    predLoc = NULL;
    moreToSearch = (location != NULL);
    // find insertion point
    while (moreToSearch)
    {
        switch (item.ComparedTo(item))
        {
        case GREATER:
            predLoc = location;
            location = location->next;
            moreToSearch = (location != NULL);
            break;
        case LESS:
            moreToSearch = false;
            break;
        }
    }
    newNode = new NodeType;
    newNode->info = item;
    if (predLoc == NULL)
    {
        newNode->next = listData;
        listData = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}
void SortedType::DeleteItem(ItemType item)
{
    NodeType* location = listData;
    NodeType* tempLocation;

    //Locate node to be deleted.
    if (item.ComparedTo(listData->info) == EQUAL)
    {
        tempLocation = location;
        listData = listData->next; //Delete first Node
        length--;
    }
    else
    while (location->next != NULL)
    {
        while (item.ComparedTo((location->next)->info) != EQUAL || location->next != NULL)
        {
            location = location->next;
        }
        if (item.ComparedTo((location->next)->info) == EQUAL)
        {
        tempLocation = location->next;
        location->next = (location->next)->next;
        length--;
    }
    }
    delete tempLocation;   
}





void MergeList(SortedType list1, SortedType list2, SortedType &result)
{
    // Get List Lengths
    int list1Length = list1.GetLength();
    int list2Length = list2.GetLength();
    // set locations to 0
    int list1Location = 0;
    int list2Location = 0;
    // set current position to beginning of list
    list1.ResetList();
    list2.ResetList();

    // declare temporary item types and get values
    ItemType tempItem1 = list1.GetNextItem();
    ItemType tempItem2 = list2.GetNextItem();

    while (list1Length >= list1Location && list2Length >= list2Location)
    {
        switch (tempItem1.ComparedTo(tempItem2))
        {
        case LESS:
            result.PutItem(tempItem1);
            if (list1Location < list1Length)
            {
                tempItem1 = list1.GetNextItem();
                list1Location++;
            }
            break;
        case GREATER:
            result.PutItem(tempItem2);
            if (list1Location < list2Length)
            {
                tempItem2 = list2.GetNextItem();
                list2Location++;
            }
            break;
        }
    }
}