#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    map<int,int> m;

    for(int i=0; i<n; i++)
        m[a[i]] = i;

    for(auto it : m)
        cout<<"value "<<it.first<<","<<"Previus index "<<it.second<<"\n";


    return 0;
}




//#include <iostream>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//int main() {
//    int n;
//
//    cin >> n;
//
//    int arr[n];
//
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//
//    // Create a map to store the original indices of the elements
//    map<int, int> index_map;
//
//    // Insert each element and its index into the map
//    for (int i = 0; i < n; i++) {
//        index_map[arr[i]] = i;
//    }
//
//    // Sort the array in increasing order of values using the sort() function
//    sort(arr, arr + n);
//
//    // Print the sorted array and its original indices
//
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//
//    for (int i = 0; i < n; i++) {
//        cout << index_map[arr[i]] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
