#include<stdio.h>
int main()
{
    int i,ara[5]={0,0,0,0,0};
    ara[3]=75;
    ara[2]=ara[3]-5;
    ara[0]=ara[2]+15;

    scanf("%d",&ara[4]);

    for(i=0; i<5; i++)
    {
      printf("%d ",ara[i]);
    }

    return 0;
}



