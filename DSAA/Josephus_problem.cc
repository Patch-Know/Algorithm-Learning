#include<new>
#include<iostream>

using namespace std;

struct Person
{
    int number;
    Person * next;
};


int main()
{
    int M,N,n,m;
    cout << "Enter M & N: ";
    cin >> M >> N;
    Person * pre = nullptr,* cur ,* head,* temp;
    head = new Person;
    head ->number =1;
    pre=head;
    for (int i = 2; i <= N; i++)
    {
        cur = new Person;
        cur -> number=i;
        pre -> next=cur;
        pre = cur;
    }
    pre ->next=head;
    Person * ptPerson = head,* ptPre = pre;
    n=N;m=M;
    while(n>1){
        if(m==0){
            temp=ptPerson;
            cout << temp ->number << "\tOut~"<< endl;
            ptPerson=temp->next;
            ptPre->next=ptPerson;
            delete temp; 
            m=M;
            --n;
        }else{
            --m;
            ptPre=ptPerson;
            ptPerson=ptPerson->next;
        }
    }
    cout << ptPerson->number << "\tWin!" << endl;
    delete ptPerson;

    
    return 0;
}