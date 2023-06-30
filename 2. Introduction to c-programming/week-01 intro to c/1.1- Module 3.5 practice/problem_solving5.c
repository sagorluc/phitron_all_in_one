#include<stdio.h>

int main(){

    //Write a C program to take three non-negative integers as input and tell if it is forms a valid triangle.A triangle is valid it sum of it's two sides
    //is greater than the third side.print YES or NO. All sides must be valid (greater than 0).


    int a , b , c;
    scanf("%d%d%d",&a,&b,&c);

    int sum = a + b ;
    int sum1 = a + c ;
    int sum2 = c + b ;

        if (sum > c && sum1 > b && sum2 > a  ){


            printf("YES \n");

        }else {printf("NO ");}


    return 0;
}
