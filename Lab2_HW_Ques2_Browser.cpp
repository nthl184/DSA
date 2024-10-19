/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
Lab2 - Homework - Question 2 - Browser History Management
*/
#include <iostream>
#include <string>

using namespace std;

class link //create node of a link
{public:
    string url;
    link *next; // Go forward to the next URL
    link *prev; // Go back to the previous URL
    link(string n)
    {
        url = n;
        next = nullptr;
        prev = nullptr;
    }
};
class browser
{
private:
    link *head;
    link *tail;
    link *crt;
public:
    // Initialization the homepage
    browser() {
        head = tail = crt = nullptr;
    }

    //visit a new URL
    void visit(string url)
    {
        link* newLink = new link(url);
        if(head == nullptr && tail == nullptr) head=tail=newLink;
        else {
            tail->next = newLink;
            newLink->prev = tail;
            tail = newLink;
        }
        crt = tail;
        cout << "Visited: " << crt->url << '\n';
    }
    // Go back to the previous URL
    void back()
    {
        if(head == nullptr && tail == nullptr) cout<< "No History.\n";
        else if(crt == head) cout<< "No previous page.\n";
        else {
            crt = crt->prev;
            cout<<"Back to: "<< crt->url<<'\n';
        }
    }
    // Go forward to the next URL
    void forward() {
        if(head == nullptr && tail == nullptr) cout<< "No History.\n";
        else if(crt == tail) cout<< "No next page.\n";
        else {
            crt = crt->next;
            cout<<"Forward to: "<< crt->url<<'\n';
        }
    }
};

int main()
{
    browser b;
    cout<<" 1.Visit a new URL \n";
    cout<<" 2.Go back to the previous URL \n";
    cout<<" 3.Go forward to the next URL \n";
    cout<<" 4.Exit \n";
    int choice;
    string s;
    do
    {
        cout<<"Choose 1 from above menu: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the new URL: ";
            cin>>s;
            b.visit(s);
            break;
        case 2:
            b.back();
            break;
        case 3:
            b.forward();
            break;
        case 4:
            return 0;
        default:
            cout<<"Invalid choice. Please try again! \n";
        }
    }
    while(choice>0);

//    b.visit("httt.uit.edu.vn");
//    b.visit("uit.edu.vn");
//    b.back(); // returns "httt.uit.edu.vn"
//    b.forward(); // returns "uit.edu.vn
//    b.visit("daa.uit.edu.vn");
//    b.back(); // returns "uit.edu.vn"

    return 0;
}
