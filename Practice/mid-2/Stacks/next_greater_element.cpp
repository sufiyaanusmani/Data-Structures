// Sufiyaan Usmani

#include <iostream>
#include <stack>
using namespace std;
stack<int> st;
void emptyStack()
{
    while (!st.empty())
    {
        st.pop();
    }
}

void fun(int arr[], int n)
{
    int num;
    for (int i = 0; i < n - 1; i++)
    {
        num = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                st.push(arr[j]);
            }
        }
        if (!st.empty())
        {
            num = st.top();
            emptyStack();
        }
        cout << arr[i] << " --> " << num << endl;
    }
    cout << arr[n - 1] << " --> -1" << endl;
}

int main()
{
    int arr[] = {4, 5, 2, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    fun(arr, size);
    return 0;
}