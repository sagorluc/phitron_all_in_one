#include<stdio.h>

int main()
{
    int arr[5]={213,10,325,507,100};

    int max = arr[0];
    int i;

    for (i=1; i<5; i+=1)
    {
       if (arr[i]<max)
       {
         max=arr[i];
       }
    }
    printf("the maximum value of this array %d\n",max);

    return 0;
}
