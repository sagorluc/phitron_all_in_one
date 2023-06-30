#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int ara[n];

    int* ptr;

    ptr = (int*) malloc(n*sizeof(int));

    if(ptr == NULL)
        printf("Memory allocated failed \n");
    else
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&ara[i]);
        }

        printf("sample output\n");
        for(i=0; i<n; i++)
        {

            printf("%d-th position-> %d\n",i,ara[i]);
        }
    }
    free(ptr);


    return 0;
}

//What is the difference between malloc and calloc?

//malloc() indicates memory allocation.
//calloc() indicates contiguous allocation.
//malloc() is faster then calloc().
//calloc() is slower then malloc().
//malloc() has a garbage value.
//calloc() has the initialize value by zero.
//The main difference between malloc() and calloc() is that malloc()
//always require one argument and calloc() always require tow arguments.





