#include<stdio.h>
int s(int x);

int main()
{
    int n;
    scanf("%d",&n);

    int i,summ = s(n);

    printf("%d",summ);
//    for(i=0; i<n; i++)
//    {
//        summ += i;
//    }

    return 0;
}

//formula sum(jog) of number.
//1+2+3.....+n = (n(n+1))/2;
//
//s(n) = s(n-1) + n;
//s(1) = 1;

int s(int n)
{
    if(n==1)
        return 1;
    else
        return s(n-1) + n;
}
