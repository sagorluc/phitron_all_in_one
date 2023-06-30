#include<stdio.h>
int add();

int main()
{
    int result;
    result = add();
    printf("%d",result*2);


    return 0;
}

int add()
{
    int num1=10, num2=5;

    return num1 + num2;
}
