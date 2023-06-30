#include<bits/stdc++.h>
using namespace std;
// time complexity- O(n)
// space complexity- O(n*m)
int main()
{
    int a = 0, b = 0;

    int M,N;

    cin >> N >> M;

    int matrix[N][M];

    for (int i = 0; i < N; i++)
    {
        a = a + i;
        matrix[i][i] = a;
        cout<< matrix[i][i] <<" "<<"\n";
    }
    for (int j = 0; j < M; j++)
    {
        b = b + 2 * j;
        cout<<"line 22 "<< b << "\n";
    }

    //Calculate time and space complexity of the following code:
    // time complexity- O(n^2)
    // space complexity- O(1)

    int a = 0;
    for (i = 0; i < N; i++)
    {
        for (j = N; j > i; j--)
        {
            a = a + i + j;
        }
    }

//    Calculate time and space complexity of the following code:
//    time complexity- O(log n)
//    space complexity- O(log n)

    int a = 0, i = N;

    vector<int> vec;
    while (i > 0)
    {
        a += i;
        i /= 2;
        vec.push_back(a);
    }

    for(int i=0; i<N; i++)
        cout<< vec[i] <<"\n";



    return 0;
}
