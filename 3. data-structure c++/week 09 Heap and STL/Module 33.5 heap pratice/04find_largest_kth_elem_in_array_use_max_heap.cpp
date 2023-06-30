#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> findLargestKElements(int arr[], int n, int k)
{
    priority_queue<int> maxHeap;
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
    }

    for (int i = 0; i < k; i++)
    {
        res.push_back(maxHeap.top());
        maxHeap.pop();
    }

    return res;
}

int main()
{
    int n,k;
    cin >> n >> k;

    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    n = sizeof(arr) / sizeof(arr[0]);

    vector<int> largestKElements = findLargestKElements(arr, n, k);

    cout << "The largest " << k << " elements in the array are: ";
    for (int i = 0; i < largestKElements.size(); i++)
    {
        cout << largestKElements[i] << " ";
    }

    return 0;
}

