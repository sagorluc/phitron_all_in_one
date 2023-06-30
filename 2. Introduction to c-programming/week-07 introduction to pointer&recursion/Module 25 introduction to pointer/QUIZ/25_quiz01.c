#include<stdio.h>
void fun(int x);
int main()
{

    int y = 50;

    fun(y);
    printf("%d",y);


    return 0;
}
void fun(int x)
{
  x = 80;
}

