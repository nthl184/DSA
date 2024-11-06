/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
Lab3 - In-Class - Exercise 3
*/
#include <iostream>
using namespace std;

int interpolationSearch(string arr[], int n, string x)
{
    int low = 0;
    int high = n - 1;

    while(low <= high && x >= arr[low] && x <= arr[high])
    {
        if(low == high)
        {
            if (arr[low] == x)
                return low;
            return -1;
        }

        // Tính toán vị trí của phần tử cần tìm
        int pos = low + ((double)(x.compare(arr[low])) * (high - low) / (arr[high].compare(arr[low])));
        if(arr[pos] == x) {
            return pos;
        }

        if (arr[pos].compare(x) < 0)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main()
{
    string arr[1000], x;
    int n;
    cout << "Enter the number of an array of strings: ";
    cin >> n;
    cout << "Enter the element of array: \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter a target string: ";
    cin >> x;

    int index = interpolationSearch(arr, n, x);

    if (index != -1)
        cout << "Element found at the index " << index;
    else
        cout << "Element not found." ;

    return 0;
}

