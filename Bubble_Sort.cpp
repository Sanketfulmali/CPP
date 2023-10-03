#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

void print(vector<int> &arr)
{
    cout << endl;
    for (auto pr : arr)
    {
        cout << pr << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> arr = {4, 2, 6, 8, 1, 3, 9};

    bubbleSort(arr);

    print(arr);
    return 0;
}
