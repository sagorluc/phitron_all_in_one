#include<stdio.h>
int last_digit(int n)
{


}
int main()
{
    int n,res;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&n);
        res = last_digit(n);
    }

    printf("%d",res);

    return 0;
}
