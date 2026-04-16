// stack.cpp -- Stack member functions
#include "stack.h"
Stack::Stack(int n)    // create an empty stack
{
    size = n;
    top = 0;
    items = new Item[top];
}
Stack::Stack(const Stack & st)
{
    size = st.size;
    top = st.top;
    items = new Item[top];
    for (int i = 0; i < top; i++)
    {
        items[i]=st.items[i];
    }
}

Stack & Stack::operator=(const Stack & st)
{
    if (this == &st) return *this;
    delete items;
    size = st.size;
    top = st.top;
    items = new Item[top];
    for (int i = 0; i < top; i++)
    {
        items[i]=st.items[i];
    }
    return *this;
}

Stack::~Stack()
{
    delete items;
}


bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item & item) 
{
    if (top < size)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false; 
}

