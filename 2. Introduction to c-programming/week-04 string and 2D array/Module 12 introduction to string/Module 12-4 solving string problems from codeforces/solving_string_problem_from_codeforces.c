#include<stdio.h>
#include<string.h>
int main()
{

   char name[100];//TAKING INPUT HIGHST 100 USING ARRAY.

   fgets(name,sizeof(name),stdin);//TAKING USER INPUT.


   int L = strlen(name);//TOTAL LENGTH OF USER INPUT.
   int LS = L-1;//COUNT TOTAL LENGTH OF INPUT AND SUBSTRACTION 1.

   if (LS>10)//IF MORE THEN 10 CHAR: THEN WILL ABBREVIATION.USING CONDITION.
   {
      //abbreviation
      printf("%c%d%c",name[0],LS-2,name[LS-1]);
   }
   else
   {
       //printf(name);
       puts(name);
   }


    return 0;
}
