#include<stdio.h>
void solve(int i,int n)
{
    if(i > n) return;

    //solve((i+1),n);//ekhane reverse hobe.

    printf("%d\n",i);//dore neoya jak i = 1

    solve((i+1),n);//2 theke n porjonto print korbe.

}

int main()
{
    int n;
    scanf("%d",&n);

    solve(1,n);//1 theke n print korbe.`


    return 0;
}
