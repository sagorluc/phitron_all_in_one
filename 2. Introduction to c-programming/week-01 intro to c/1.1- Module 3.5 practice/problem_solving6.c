#include<stdio.h>

int main(){


    //you have got X marks in your exam.as your a good and regular student.if you ask your teacher h/she can give you at most Y bonus marks.
    //now you need to tell if you take bonus marks will your number become 100?
    //write a C program to take two no-negative integers X and Y as input and print YES or NO.

    int x , y ;
    scanf("%d%d",&x,&y);

    int sum = x + y;

    if(sum >= 100){

      printf("YES ");

    }else {printf("NO ");}


    return 0;

}
