#include"list.h"
bool list::add_item(const Item & item)
{
    if (!is_full){
        items[top++]=item;
        return true;
    }else return false;
}

void list::visit(void (*pf)(Item &))
{
    for (int i = 0; i < top; i++)
    {
        pf(items[i]);
    }
}
