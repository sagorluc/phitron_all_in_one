#include<stdio.h>

int main(){


    int x ,a ,b , s;

    scanf("%d",&x,&a,&b);


    if (x % 2 == 0){

      a = 56;
      b = 61;

      s = a + b;

      printf("total plus is\n%d", s);

    }else {

      a = 30;
      b = 13;

      s = a - b;

      printf("total mins is \n %d", s );


    }


    return 0;

}
