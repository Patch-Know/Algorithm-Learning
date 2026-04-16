#ifndef LIST_H_
#define LIST_H_

typedef double Item;

class list
{
private:
    static const int Max = 12;
    int top=0;
    Item items[Max];
public:
    list();
    bool is_empty() const{return top==0;}
    bool is_full() const{return top==Max;}
    bool add_item(const Item & item);
    void visit(void (*pf)(Item &));
};

list::list()
{
}



#endif
