#include<bits/stdc++.h>
using namespace std;

int sum_of_digit(int n)
{
    if(n < 10)
        return n;

    return n%10 + sum_of_digit(n/10);

}

int main()
{
    int n;
    cin >> n;

    int ans = sum_of_digit(n);
    cout<< ans <<"\n";

    return 0;
}
