/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
Lab2 - In-Class Part 1
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class node
{public:
    char data;
    int value;
    node *next;
    node(char x) { data=x; next=nullptr; }
    node(int x) { value=x; next=nullptr; }
};

class Stack
{
private:
    node *top;
public:
    // initialize the stack using linked list
    Stack()
    {
        top = nullptr;
    }
    // check if the stack is empty
    bool isEmpty()
    {
        if(top == nullptr) return true;
        return false;
    }
    //check if the stack is full (if applicable)
    bool full()
    {
        return false; //A linked list-based stack is never full unless memory is exhausted
    }
    void push(char x) //push char x into stack
    {
        node *tmp = new node(x);
        if(top==nullptr) //stack is empty
            top = tmp;
        else
        {
            tmp->next = top;
            top = tmp;
        }
    }
    void push(int x) //push integer x into stack
    {
        node *tmp = new node(x);
        if(top==nullptr) //stack is empty
            top = tmp;
        else
        {
            tmp->next = top;
            top = tmp;
        }
    }
    void pop() //remove the latest element has inserted into the stack
    {
        if(top == nullptr) return throw runtime_error("Stack is empty.");;
        node *tmp = top;
        top = top->next;
        delete tmp;
    }
    char get_top() //get the value of the latest element has inserted into the stack
    {
        if(top == nullptr) throw runtime_error("Stack is empty.");
        return top->data;
    }
    void display() // display all element of the stack
    {
        if(isEmpty()) cout<<"The stack is empty. \n";
        else {
            node *tmp = top;
            while(tmp)
            {
                cout<<tmp->value<<" ";
                tmp = tmp->next;
            }
            delete tmp;
            cout<<'\n';
        }
    }
};

//reverse of each individual word of a string str
string Reverse(string s)
{
    Stack a;
    for(char c:s)
        a.push(c);
    string c="";
    while(!a.isEmpty())
    {
        c = c + a.get_top();
        a.pop();
    }
    return c;
}
// Confirm whether the input string is valid.
// Consider a string s that consists solely of the characters ’(’, ’)’, ’{’, ’}’, ’[’ and ’]’.
bool isValid(string s)
{
    Stack a;
    for(char c:s)
    {
        if(c=='(' || c=='{' || c=='[')
            a.push(c);
        else
        {
            if(a.isEmpty()) return false;
            if((a.get_top()=='(' && c==')') || (a.get_top()=='{' && c=='}') || (a.get_top()=='[' && c==']'))
                a.pop();
            else return false;
        }
    }
    return a.isEmpty();
}


int main()
{
    //freopen("exer.inp","r",stdin);
    //display menu
    cout<<"1.Initialize the stack \n";
    cout<<"2.Input the stack \n";
    cout<<"3.Check if stack is empty \n";
    cout<<"4.Check if stack if full \n";
    cout<<"5.Ascertain whether the input string is valid \n";
    cout<<"6.Reverse the input string \n";
    cout<<"7.Done \n";

    Stack st;
    string s;
    int choice;
    do
    {
        cout<<"Enter the number from above menu: \n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"OK \n";
                break;
            case 2: {
                int n;
                cout<<"Enter the elements (0 to stop): \n";
                cin>>n;
                while(n!=0)
                {
                    st.push(n);
                    cin>>n;
                }
                st.display();
                break;
            }
            case 3:
                cout<< ((st.isEmpty()) ? "Empty" : "Not Empty") <<'\n';
                break;
            case 4:
                cout<< ((st.full()) ? "Full" : "Not Full") <<'\n';
                break;
            case 5:
                cout<<"Enter the string: ";
                cin>>s;
                cout<< ((isValid(s)) ? "The string is valid" : "The string is invalid") <<'\n';
                break;
            case 6:
                cout<<"Enter the string: ";
                cin>>s;
                cout<<"The string after reverse is: "<<Reverse(s)<<'\n';
                break;
            case 7:
                cout<<"Exit";
                return 0;
            default: cout<<"The input number is invalid. Please try again! \n";
        }
    } while(choice>0);

    return 0;
}
