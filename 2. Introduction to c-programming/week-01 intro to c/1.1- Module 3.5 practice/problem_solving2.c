#include<stdio.h>

int main(){

    //Wirte a C program to take three non-negative integers and show who is bigger.if they are equal print as it is.see the sample input/output
    //for more clearification.

    int a , b , c;

    scanf("%d%d%d",&a,&b,&c);

    if (a > b && a > c){

     printf("A is big \n");

    }else if (b > a && b > c){

     printf("B is big \n");

    }else if (c > a && c > b){


     printf("C is big \n ");

    }else if (b > a && c > a){

     printf("b and c both are bigger \n");

    }else if(a > b && c > b){

     printf("a and c both are bigger \n");
    }else if(a > c && b > c){

     printf("a and b both are bigger ");


    }


    return 0;
}
