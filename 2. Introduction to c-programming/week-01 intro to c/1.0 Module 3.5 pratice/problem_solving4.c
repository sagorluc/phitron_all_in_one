#include<stdio.h>

int main(){

    //Write a C program to take two positive integers as input and show the summation, subtraction and
    //multiplication of those two numbers.

    int x , y ;

    scanf("%d%d",&x,&y);
    int sum = x + y;
    int sub = x - y;
    int mul = x * y;

    printf("This is summation %d \n", sum);

    printf("This is subtraction %d \n", sub);

    printf("This is multiplication %d", mul);


    return 0;

}
