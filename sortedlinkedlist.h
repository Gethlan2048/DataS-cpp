struct NodeType;
struct ItemType;
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