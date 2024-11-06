/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
Lab3 - In-Class - Exercise 2
*/
#include <iostream>
#include <cmath>
using namespace std;

//Jump Search
int jumpSearch(int arr[], int n, int x, int step_size) 
{
    // Start index  0
    int crt = 0;
    int prev = 0;
    // Jump over blocks with size = step_size
    while(arr[min(crt, n) - 1] < x && crt < n)
    {
        //cout<<"Jump from "<<prev<<" to "<<crt<<endl;
        prev = crt;
        crt = min(crt + step_size, n - 1);  //Make sure not to exceed n-1
    }

    // After jump, Linear search from prev in this block until = x
    while(arr[prev] < x)
    {
        prev++;
        if (prev == min(crt, n)) return -1; //nếu prev nằm ngoài block
    }
    if (arr[prev] == x) return prev;
    return -1;  // Nếu không tìm thấy
}

int main() 
{
    int n, x, step_size;
    cout<< "Enter the number of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the element of array: \n";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<< "Enter a target value: ";
    cin>>x;

    cout<< "Enter an adjustable step size: ";
    cin>>step_size;

    int result = jumpSearch(arr, n, x, step_size);
    if (result != -1) {
        cout << "Element found at the index: " << result;
    } else {
        cout << "Element not found.";
    }

    return 0;
}

