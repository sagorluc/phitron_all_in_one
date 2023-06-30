#include<stdio.h>

int myfriend(int x)
{
  printf("pera nai! chill!");
  return 2*x;

}


int main()
{
int a,b;
a = myfriend(15);
printf("\n%d\n",a);

b = myfriend(18);
printf("\n%d",b);


    return 0;
}
