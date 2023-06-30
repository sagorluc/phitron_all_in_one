#include<stdio.h>
int main()
{
   int n,i,j,a,solved,count;

   scanf("%d",&n);
   solved=0;
   for (i=0; i<n; i++)
   {
     count=0;
     //count korbo koyy jon pare.
     for(j=0; j<3; j++)
     {
       scanf("%d",&a);
       count+= a;
     }
     if(count>=2)
       solved++;

   }
    printf("%d",solved);


    return 0;
}
