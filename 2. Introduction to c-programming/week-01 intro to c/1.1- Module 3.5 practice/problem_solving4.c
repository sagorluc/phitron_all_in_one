#include<stdio.h>

int main(){

    //write a C program to one take non-negative interger as input and print the grade according to that input.the grade system is show below.

    int a ;
    scanf("%d",&a);


    if (a >= 0 && a <= 32  ){

       printf("you are : F");


    }else if (a >= 33 && a <= 39){

       printf("you are : D");

    }else if (a >= 40 && a <= 49){

       printf("you are : C");
    }else if (a >= 50 && a <= 59){

       printf("you are : B");
    }else if (a >= 60 && a <= 69){

       printf("you are : A-");

    }else if (a >= 70 && a <= 79){

       printf("you are : A");

    }else if (a >= 80 && a <= 100){

       printf("you are : A+");

    }else{("nothing ");}

    return 0;
}

