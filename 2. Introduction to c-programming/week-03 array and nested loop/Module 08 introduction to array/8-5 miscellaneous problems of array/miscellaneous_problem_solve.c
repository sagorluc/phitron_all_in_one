#include<stdio.h>

int main ()
{

   int n;
   int ara[200001];//200000+1];
   int i;
   int x; // missing number will stor in this x variable.

   scanf("%d",&n);

   for(i=1; i<n; i++)
   { //ara[i] = 0;//makeing sure to arrays value to 0.
     //printf("%d",ara[i]);//testing arrays velue .

     scanf("%d",&x);
     ara[x] = 1;
   }

   for (i=1; i<=n; i++)
   {

    if (ara[i] == 0)
    {
      printf("the missing number is %d\n",i);
      break;
    }


   }




    return 0;
}
