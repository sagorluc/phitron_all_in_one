#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    int summ = 0;
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d",&a);
        summ += a;

    }
    printf("total summ is = %d",summ);


    return 0;
}
