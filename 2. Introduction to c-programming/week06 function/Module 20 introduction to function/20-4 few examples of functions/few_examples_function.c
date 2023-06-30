#include<stdio.h>
int main()
{
    int a,b,i,ans;

    scanf("%d %d",&a,&b);

    for(i=a; i>=1; i--)
    {
        if(a%i==0 && b%i==0)
        {
            ans = i;
            break;
        }

    }
    printf("The gcd is = %d\n",ans);


    return 0;
}
