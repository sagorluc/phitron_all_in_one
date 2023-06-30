#include<stdio.h>
void fun(int x);
int main()
{
    int n=4;
    fun(n);

    return 0;
}
void fun(int x)
{
 if(x>0)
 {
     fun(x-1);
     printf("%d ",x);
 }
}
