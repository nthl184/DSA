/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
In-Class Exercise - Part 1 - Problem 3
*/
#include <iostream>

using namespace std;
class node
{public:
    int data;
    node *next;
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
node *createNode(int x)
{
    node *p;
    p = new node;
    if(p == nullptr) exit(1);
    p->data = x;
    p->next = nullptr;
    return p;
}
void addNode(LinkedList &l, int x) //add a Node with data x (add to tail of list)
{
    node *newNode = createNode(x);
    if(l.Head == nullptr)
    {
        l.Head = l.Tail = newNode;
        return;
    }
    l.Tail->next = newNode;
    l.Tail = newNode;
}
//Combine Two Sorted Linked Lists
node *combine_2List(LinkedList &l, LinkedList &k)
{
    // List is empty so don't need combine
    if(l.Head == nullptr) return l.Head;
    if(k.Head == nullptr) return k.Head;
    //Combine 2 List
    node *tmp1 = l.Head;
    node *tmp2 = k.Head;
    node *start = new node();
    node *crt = start;
    while(tmp1 != nullptr && tmp2 != nullptr)
    {
        if(tmp1->data < tmp2->data)
        {
            crt->next = tmp1;
            tmp1= tmp1->next;
        }
        else
        {
            crt->next = tmp2;
            tmp2 = tmp2->next;
        }
        crt = crt->next;
    }
    //kiem tra 1 trong 2 list nao con phan tu
    if(tmp1 != nullptr)
        crt->next = tmp1;
    if(tmp2 != nullptr)
        crt->next = tmp2;

    return start->next;
}
int main()
{
    //freopen("exer.inp","r",stdin);
    LinkedList l,k;
    int x;
    cout<<"Enter the data element of First LinkedList until enter 0: \n";
    cin>>x;
    while(x!=0)
    {
        addNode(l,x);
        cin>>x;
    }
    cout<<"Enter the data element of Second LinkedList until enter 0: \n";
    cin>>x;
    while(x!=0)
    {
        addNode(k,x);
        cin>>x;
    }
    node *p=combine_2List(l,k);
    while(p!=nullptr)
    {
        cout<<p->data<<" ";
        p= p->next;
    }
    cout<<'\n';
    return 0;
}
