/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
Homework - Exercise 3 - AuthenticationManager Class
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX_TOKENS = 2000;

class Token
{public:
    string tokenId;
    int expireTime;
    Token *next;
    Token(string id, int time)
    {
        tokenId = id;
        expireTime = time;
        next = nullptr;
    }
};

class AuthenticationManager
{public:
    int timeToLive;
    Token *head;
    Token *tail;

    //initialize the AuthenticationManager with the given timeToLive
    AuthenticationManager(int timeToLive)
    {
        this->timeToLive = timeToLive;
        head = tail = nullptr;

    }

    //Token Generation: creates a new token associated with the specified tokenId
    //at the given currentTime in seconds.
    void generate(string tokenId, int crtTime)
    {
        if(tokenId.length()>5) return;
        Token *newToken = new Token(tokenId,crtTime+timeToLive);
        if(head == nullptr && tail == nullptr) {
            head = tail = newToken;
        }
        else {
            tail->next = newToken;
            tail = newToken;
        }
        cout<<"null"<<'\n';
    }

    //Token Renewal:  renewal of an unexpired token identified by tokenId
    //at the specified currentTime.
    void renew(string tokenId, int crtTime)
    {
        Token *tmp = head;

        while(tmp != nullptr)
        {

            if(tokenId == tmp->tokenId && crtTime < tmp->expireTime) //renewed
            {
                tmp->expireTime = crtTime + timeToLive;

                break;
            }

            tmp = tmp->next;
        }
        cout<<"null"<<'\n';
    }

    //Counting Unexpired Tokens: returns the total number of tokens that
    //remain unexpired at the specified currentTime
    int countUnexpiredTokens(int crtTime)
    {
        Token *tmp = head;
        int cnt=0;
        while(tmp)
        {
            if(tmp->expireTime > crtTime) cnt++;
            tmp = tmp->next;
        }
        return cnt;
    }
};

int main()
{

    AuthenticationManager authManager(5);
    cout<<"null"<<'\n';
    authManager.renew("aaa", 1);
    authManager.generate("aaa", 2);
    cout << authManager.countUnexpiredTokens(6) << '\n'; // Output: 1
    authManager.generate("bbb", 7);
    authManager.renew("aaa",8);
    authManager.renew("bbb", 10);
    cout << authManager.countUnexpiredTokens(15) << '\n'; // Output: 0
    return 0;
}
