/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
Lab3 - In-Class - Exercise 4
*/
#include <iostream>
using namespace std;
//int const NMAX = 1e3;
void swap(int *x, int *y)
{
    int c = *x;
    *x = *y;
    *y = c;
}
void selectionSort(int arr[], int n)
{
    int min_i;
    for(int i=0; i<n-1; i++)
    {
        min_i=i;
        for(int j=i+1; j<n; j++)
           if(arr[j] < arr[min_i]) {
                min_i=j;
           }
         swap(&arr[min_i], &arr[i]);
    }
}
int missingNum(int arr[], int n) //array sorted
{
    int left = 0, right = n;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == mid) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
int main()
{
    int n;
    cout<<"Enter the number of array: ";
    cin>>n;
    int a[n+1];
    cout<<"Enter the elements of array: \n";
    for(int i=0; i<n; i++)
        cin>>a[i];
    selectionSort(a,n);
    cout<<"Missing number is: " << missingNum(a,n);
    return 0;
}
