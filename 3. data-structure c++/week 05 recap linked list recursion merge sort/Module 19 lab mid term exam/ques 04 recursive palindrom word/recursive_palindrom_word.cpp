#include <bits/stdc++.h>
using namespace std;
int is_palindrom(char str[], int a, int b)
{


    if (a < b+1)
    {
        a++;
        b--;
        return is_palindrom(str, a, b);
    }

    if (a == b)
    {
        return 1;
    }
    else if(str[a] != str[b])
    {
        return 0;
    }
    return 1;
}


int main(){
   char arr[50];
   cin >> arr;

   int result = 0;

   int len = strlen(arr)-1;

    if (len == 0)
    {
        result = 1;
    }

    else
    {
        result = is_palindrom(arr, result, len);
    }

    if (result==1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
