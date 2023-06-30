#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    n = 5;

    int* pointer;

    pointer =(int*) malloc(n*sizeof(int));
    printf("%p\n",pointer);

    int i;

    if(pointer==NULL)
        printf("allocated failed \n");
    else
    {

        for(i=0; i<n; i++)
        {
            scanf("%d",(pointer+i));

        }
        for(i=0; i<n; i++)
        {
            printf("%d ",*(pointer+i));
        }

    }
    n = 10;
    int* pointer2;
    pointer2 = realloc(pointer,n*sizeof(int));
    printf("%p\n",pointer);

    if(pointer2==NULL)
        printf("allocated failed \n");
    else
    {
        for(i=5; i<n; i++)
        {
          scanf("%d",(pointer2+i));
        }
         for(i=0; i<n; i++)
        {
            printf("%d ",*(pointer2+i));
        }
    }
    free(pointer2);


    return 0;
}



