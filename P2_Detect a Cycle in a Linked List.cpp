/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
In-Class Exercise - Part 1 - Problem 2
*/
#include <iostream>

using namespace std;
class node
{public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = nullptr;
    }
};
class LinkedList
{public:
    node *Head = nullptr;
    node *Tail = nullptr;
};
void printList(LinkedList l)
{
    if(l.Head == nullptr) cout<<"Linked List is empty."<<'\n';
    else
    {
        node *p = l.Head;
        cout<<"The Linked List is: ";
        while(p!=nullptr)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<'\n';
    }
}
//Insert a Node to LinkedList
void addNode(LinkedList &l, int x) //(add to tail of list)
{
    node *newNode = new node(x);
    if(l.Head == nullptr)
    {
        l.Head = l.Tail = newNode;
        return;
    }
    l.Tail->next = newNode;
    l.Tail = newNode;
}

//Detect a Cycle in a Linked List
bool hasCycle(LinkedList l)
{
    if(l.Head == nullptr || l.Head->next == nullptr) //the empty list or one node is not cycle
        return false;
    node *fast = l.Head;
    node *slow = l.Head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true; //has Cycle
    }
    return false; //not cycle
}
int main()
{
    LinkedList l;
    int x;
    cout<<"Enter the data element until enter 0: \n";
    cin>>x;
    while(x!=0)
    {
        addNode(l,x);
        cin>>x;
    }
    if(hasCycle(l)) cout<<"The LinkedList has cycle. \n";
    else cout<<"The LinkedList has not cycle. \n";
    return 0;
}