#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);

    if (n%3==0 && n%10==5)
    {
        printf("N is beautiful\n");

    }
    else
    {
     printf("not \n");
    }



    return 0;
}
