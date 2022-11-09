// Sufiyaan Usmani

#include <iostream>
#include <stack>
using namespace std;

int getMin(int arr[], int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(arr[i]);
        }
        else if (arr[i] < st.top())
        {
            st.pop();
            st.push(arr[i]);
        }
    }
    return st.top();
}

int main()
{
    int arr[] = {4, 2, 1, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << getMin(arr, size) << endl;
    return 0;
}