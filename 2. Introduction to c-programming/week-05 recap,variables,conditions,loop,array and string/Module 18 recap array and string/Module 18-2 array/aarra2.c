#include<stdio.h>
int main()
{
    int i,ara[10];

    for(i=0; i<10; i++)
    {
        scanf("%d",&ara[i]);

    }
    int  maxx = 0,print;
    for(i=0; i<10; i++)
    {
        if(ara[i]>maxx)
        {
            print=ara[i];

        }


    }
    printf("%d ",print);

    return 0;
}

// 12 5 9 26  2 7 3 27 11 254
