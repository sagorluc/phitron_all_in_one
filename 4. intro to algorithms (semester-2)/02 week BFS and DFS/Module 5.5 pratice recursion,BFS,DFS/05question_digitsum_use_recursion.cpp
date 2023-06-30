#include<bits/stdc++.h>
using namespace std;
int digitsum(int n)
{
    // base case
    if(n == 0 || n == 1)
        return n;

    return (n % 10) + digitsum(n / 10);



}
int main()
{
    int n;
    cin >> n;

    int sum = digitsum(n);
    cout<<"total sum is : "<< sum <<"\n";



    return 0;
}
