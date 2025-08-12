#include <bits/stdc++.h>
using namespace std;

void printA(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return;
}
void printV(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return;
}


int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    vector<int> vec = {5,4,3,2,1};

    // the sort function requires two minimum inputs:
    // the pointer where the data type begins and the pointer where it ends
    // the third input is a fucntion determining the process of sorting -> true or false

    sort(arr, arr + (sizeof(arr) / sizeof(int)), [](int a, int b){ 
        return a > b; 
    });
    
    sort(&vec[0], &vec[0]+vec.size());

    printA(arr, (sizeof(arr) / sizeof(int)));
    printV(vec, vec.size());

}