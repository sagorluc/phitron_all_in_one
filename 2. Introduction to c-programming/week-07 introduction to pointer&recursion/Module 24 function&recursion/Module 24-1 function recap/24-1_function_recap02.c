#include<stdio.h>
void solve();

int main()
{
    int t,i;
    printf("Enter input \n");
    scanf("%d",&t);

    for(i=0; i<t; i++)
    {
        printf("Enter tow numbers\n");
        solve();

    }


    return 0;
}

void solve()//this type of function,kicu pathbe nah and kicu recived korbe nah.
{
    int a,b;

    scanf("%d %d",&a,&b);
    printf("sum of tow numbers %d\n",a+b);
}
