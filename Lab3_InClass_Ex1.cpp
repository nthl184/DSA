/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
Lab3 - In-Class - Exercise 1
*/
#include <iostream>
using namespace std;

//tìm chỉ số bên trái của phần tử bằng tìm kiếm nhị phân
int binarySearchLeft(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

//tìm chỉ số bên phải của phần tử bằng tìm kiếm nhị phân
int binarySearchRight(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}
//count how many times a specific element appears in a sorted array
int countOccurrences(int a[], int n, int x)
{
    int leftIndex = binarySearchLeft(a, n, x);
    int rightIndex = binarySearchRight(a, n, x);

    if (leftIndex <= rightIndex) {
        return rightIndex - leftIndex + 1;
    }
    return 0; // not found element
}

int main() {
    int n, x;
    cout<<"Enter the number of array: ";
    cin>>n;
    int a[n+1];
    cout<<"Enter the elements of array sorted: \n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter a specific element: ";
    cin>>x;
    cout << "Number of occurrences of " << x << " is " << countOccurrences(a, n, x) << " times\n";
    return 0;
}
