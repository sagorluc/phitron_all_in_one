#include<stdio.h>
void swap(int* x , int* y);

int main()
{
    int a=5,b=7;
    printf("a=%d b=%d\n",a,b);

    swap(&a,&b);//pass by refarance useing pointer address.

    printf("a=%d b=%d",a,b);//swaping the value a and b.

    return 0;
}


void swap(int* x,int* y)
{
    int temp;
    temp = *x;

     *x = *y;
     *y = temp;

}
