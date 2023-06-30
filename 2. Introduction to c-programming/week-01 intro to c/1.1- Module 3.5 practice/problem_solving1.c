#include<stdio.h>

int main(){

    //write a C program to take two integers as input and show who is bigger.if they are equal print as it is.see the sample input/output
    //for more clearification.

    int a , b;

    scanf("%d%d",&a,&b);

    if (a > b){

      printf("a is bigger \n");

    }else if (a < b){

     printf("b is bigger \n");

    }else{

     printf("they are equal");

    }

    return 0;

}
