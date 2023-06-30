#include<stdio.h>

int main()
{
    int n = 8;
    int i,j,temp;
    int ara[8]= {12,7,9,3,15,2,6,5};


    for(i=0; i<n; i++)
    {
        printf("%d ",ara[i]);
    }
    printf("\n");

    for(j=0; j<n-3; j++) //sobar kace giye value change kore deoya holo.
    {
        for(i=0; i<(n-1); i++)
        {
            //compare korbo a=ara[i]=12 er shatha b=ara[i+1]=7.
            if(ara[i]>ara[i+1])
            {
                temp = ara[i];
                ara[i] = ara[i+1]; //for swaping.
                ara[i+1] = temp;
            }

        }
        for(i=0; i<n; i++)
        {
            printf("%d ",ara[i]);
        }
        printf("\n");


    }
    return 0;
}
