/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
Lab2 - In-Class Part 2
*/
#include <iostream>
#include <string>

using namespace std;

class node
{public:
    string data;
    int value;
    node *next;
    node(string x) { data=x; next=nullptr; }
    node(int x) { value=x; next=nullptr; }
};

class Queue
{
private:
    node *head;
    node *tail;
public:
    // initialize the queue using linked list
    Queue()
    {
        head = nullptr;
        tail = nullptr;
    }
    // check if the queue is empty
    bool isEmpty()
    {
        if(head == nullptr && tail == nullptr) return true;
        return false;
    }
    //check if the queue is full (if applicable)
    bool full()
    {
        return false; //A linked list-based stack is never full unless memory is exhausted
    }
    void push(string x) //push string x into queue
    {
        node *tmp = new node(x);
        if(isEmpty()) //stack is empty
            head = tail = tmp;
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }
    void push(int x) //push integer x into queue
    {
        node *tmp = new node(x);
        if(isEmpty()) //stack is empty
            head = tail = tmp;
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }
    void pop() //remove the latest element has inserted into the queue
    {
        if(isEmpty()) throw runtime_error("Stack is empty.");
        node *tmp = head;
        head = head->next;
        if(head == nullptr) tail = nullptr;
        delete tmp;
    }
    string front_str() //get the data of the first element in the queue
    {
        if(head == nullptr) throw runtime_error("Queue is empty.");
        return head->data;
    }
    int front_int()
    {
        if(head == nullptr) throw runtime_error("Queue is empty.");
        return head->value;
    }
    void display() // display all element of the queue
    {
        if(isEmpty()) cout<<"The queue is empty. \n";
        else {
            node *tmp = head;
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
//4. Simulate the bank queue scenario
void Bank() {
    Queue bank;
    srand(time(0)); // Seed for random number generation

    // Simulate customers arriving at the bank
    for(int i = 1; i <= 10; ++i) {
        bank.push(i);
    }

    cout<<"Initial queue: ";
    bank.display();

    // Simulate the teller assisting customers
    for(int i = 0; i < 10; ++i)
    {
        int customer = bank.front_int();
        bank.pop();
        if (customer != -1)
        {
            // 25% chance the customer has insufficient paperwork
            if (rand() % 4 == 0)
            {
                cout<<"Customer "<< customer <<" has insufficient paperwork, returning to the end of the queue.\n";
                bank.push(customer);
            }
            else cout<<"Customer "<< customer <<" is being assisted.\n";
        }
    }
    cout << "Final queue: ";
    bank.display();
}

//5. Pairing on the dance floor
void Enter(Queue &q)
{
    string s;
    while(true)
    {
        cin>>s;
        if(s=="0") break;
        q.push(s);
    }
}
void pairDancers()
{
    Queue male, female;
    cout<<"Enter the male's name (0 to stop): \n";
    Enter(male);
    cout<<"Enter the female's name (0 to stop): \n";
    Enter(female);

    while(!male.isEmpty() && !female.isEmpty())
    {
        cout<<"Pairing: "<<male.front_str()<<" with "<<female.front_str()<<'\n';
        male.pop();
        female.pop();
    }
    //A queue of ”spares” should be maintained, consisting of men without corresponding women or vice versa
    //List the spare elements, that is, list the male or female queue that is not empty
    if(!male.isEmpty()) cout<<"Spares of male: ";
    else if(!female.isEmpty()) cout<<"Spares of female: ";

    while(!male.isEmpty())
    {
        cout<<male.front_str()<<" ";
        male.pop();
    }
    while(!female.isEmpty())
    {
        cout<<female.front_str()<<" ";
        female.pop();
    }
    cout<<'\n';
}

int main()
{
    //freopen("exer.inp","r",stdin);
    //display menu
    cout<<"The menu: \n";
    cout<<"1.Implement a queue \n";
    cout<<"2.Input the queue and display \n";
    cout<<"3.Check if the queue is empty \n";
    cout<<"4.Check if the queue if full \n";
    cout<<"5.Simulate the bank queue scenario \n";
    cout<<"6.Pairing on the dance floor \n";
    cout<<"7.Done \n";

    Queue st;
    int choice;
    do
    {
        cout<<"Enter the number from the menu: \n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"OK \n";
                break;
            case 2: {
                int n;
                cout<<"Enter the integer elements (0 to stop): \n";
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
                Bank();
                break;
            case 6:
                pairDancers();
                break;
            case 7:
                cout<<"Exit";
                return 0;
            default: cout<<"The input number is invalid. Please try again! \n";
        }
    } while(choice>0);

    return 0;
}
