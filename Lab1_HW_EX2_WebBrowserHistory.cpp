/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
Lab 1 - Homework - Exercise 2 - Web Browser back and next
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class link //create node of a link
{public:
    string url;
    link *next;
    link *prev;
    link(string n)
    {
        url = n;
        next = nullptr;
        prev = nullptr;
    }
};
class BrowserHistory 
{public:
    link *head;
    link *tail;
    link *crt;

    // Initialization the homepage
    BrowserHistory(string homepage) {
        head = new link(homepage);
        crt = head;
    }

    //visit a new URL
    void visit(string url)
    {
        link* newLink = new link(url);
        crt->next = newLink;
        newLink->prev = crt;
        crt = newLink;
    }
    //Navigating Back: go back in history by a specified number of steps
    string back(int step)
    {
        while(step > 0 && crt->prev != nullptr)
        {
            crt = crt->prev;
            step--;
        }
        return crt->url;
    }
    //Navigating Forward: go forward in history by a specified number of steps
    string forward(int step) {
        while(step > 0 && crt->next != nullptr) {
            crt = crt->next;
            step--;
        }
        return crt->url;
    }

};
int main()
{
    //freopen("exer.inp","r",stdin);
    vector<string> commands = {"BrowserHistory", "visit", "visit", "visit", "back", "back", "forward", "visit", "forward", "back", "back"};
    vector<vector<string>> inputs = {{"uit.edu.vn"}, {"google.com"}, {"facebook.com"}, {"youtube.com"}, {"1"}, {"1"}, {"1"}, {"linkedin.com"}, {"2"}, {"2"}, {"7"}};

    BrowserHistory* browserHistory = nullptr;
    cout << "[";
    for(size_t i = 0; i < commands.size(); ++i)
    {
        if (commands[i] == "BrowserHistory") {
            browserHistory = new BrowserHistory(inputs[i][0]);
            cout<<"null";
        } else if (commands[i] == "visit") {
            browserHistory->visit(inputs[i][0]);
            cout<<"null";
        } else if (commands[i] == "back") {
            cout<<browserHistory->back(stoi(inputs[i][0]));
        } else if (commands[i] == "forward") {
            cout<<browserHistory->forward(stoi(inputs[i][0]));
        }
        if(i < commands.size()-1) cout<<", ";
    }
    cout << "]" << std::endl;

    delete browserHistory;

    return 0;
}
