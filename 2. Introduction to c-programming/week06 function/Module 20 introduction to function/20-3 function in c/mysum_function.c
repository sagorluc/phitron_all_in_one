#include<stdio.h>

int mysum(int x, int y)
{
    printf("Adding/multiply tow numbers...\n");
    return x*y;//jekhane return korbe sekhanei code ses hoye jabe.


}

int main()
{
   int a,b,c,d;
   a = mysum(5,5);
   printf("%d\n",a);

   a = mysum(45,205);
   printf("%d",a);


    return 0;
}
