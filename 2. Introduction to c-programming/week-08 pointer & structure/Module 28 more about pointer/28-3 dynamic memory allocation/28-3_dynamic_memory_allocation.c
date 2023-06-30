#include<stdio.h>
#include<stdlib.h>//this libery for malloc() function.
int main()
{
       int n,i;
       scanf("%d",&n);
       //int ptr[n];//it will work same thing by array.

       int* ptr;

       ptr = (int*) malloc(n*sizeof(int));//built_in function malloc(). run time allocated.
                                          //dynamic memory allocated.means
                                          //input deoyar por jototuku memory dorkar tototukoi nebe.
       for(i=0; i<n; i++)
       {
           scanf("%d",(ptr+i));
       }

       for(i=0; i<n; i++)
       {
           printf("%d-th position-> %d\n",i,*(ptr+i));
       }
       free(ptr);//free or clean memory.it's a good practice.


    return 0;
}
