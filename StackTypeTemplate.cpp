class FullStack{};
class EmtpyStack{};

template<class ItemType>
class StackType
{
    public:
        StackType();
        bool IsEmpty() const;
        bool IsFull() const;
        void Push(ItemType item);
        void Pop();
        ItemType Top() const;
    private:
        int top;
        ItemType items<MAX_ITEMS>;

};

template<class ItemType> StackType<ItemType>::StackType()
{
    top = -1;
}
template<class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
    return (top==-1);
}
template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
    return (top == MAX_ITEMS-1);
}
template<class ItemType>
void StackType<ItemType>::Push(ItemType newitem)
{
    if(IsFull())
        throw FullStack();
    top++;
    items<top> = newItem;
}

template<class ItemType>
void StackType<ItemType>::Pop()
{
    if (IsEmpty())
        throw EmtpyStack();
    top--;
}
template<class ItemType>
ItemType StackType<ItemType>::Top() const
{
    if (IsEmpty())
        throw EmtpyStack();
    return items<top>
}