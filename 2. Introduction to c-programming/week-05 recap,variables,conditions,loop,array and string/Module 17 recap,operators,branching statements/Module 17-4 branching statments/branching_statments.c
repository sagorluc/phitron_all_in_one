#include<stdio.h>
int main()
{
     int a,b,ans;

     scanf("%d %d",&a,&b);

     char c;
     getchar();
     c = getchar();


     if(c == '+')
     {
        ans = a+b;
        printf("the adition is %d\n",ans);

     }
     else if(c == '-')
     {
        ans = a-b;
        printf("the substraction is %d",ans);
     }
     else
     {
       printf("Invalit number ",ans);
     }







    return 0;
}
