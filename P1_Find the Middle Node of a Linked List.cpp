/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
In-Class Exercise - Part 1 - Problem 1
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
//Insert a Node to LinkedList
void addNode(LinkedList &l, int x) //add a Node with data x
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
int elementNode(LinkedList l) //return the number element of LinkedList
{
    int cnt = 1;
    node *tmp=l.Head;
    while(tmp->next != nullptr)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
//Find the Middle Node of a Linked List
void MiddleNode(LinkedList l) 
{
    int num = elementNode(l);
    node *tmp=l.Head;
    for(int i=0; i< (num-1)/2; i++)
    {
        //cout<<tmp->data<<'\n';
        tmp = tmp->next;
    }
    if(num%2==0)
        cout<<tmp->data<<" "<<tmp->next->data<<'\n';
    else
        cout<<tmp->data<<'\n';

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
    cout << "The Middle Node is: ";
    MiddleNode(l);
    return 0;
}